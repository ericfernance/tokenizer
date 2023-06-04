#include <gtk/gtk.h>

#include "app.h"
#include "win.h"
#include "jwt.h"

struct _TokenizerAppWindow
{
    GtkApplicationWindow parent;
    GtkWidget *menu;
    GtkButton *encode_button;
    GtkButton *decode_button;
    GtkTextView *text_view;
};

G_DEFINE_TYPE(TokenizerAppWindow, tokenizer_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
encode_button_clicked(GtkButton *button,gpointer user_data)
{
    g_print("Button clicked\n");
}

static void
decode_button_clicked(GtkButton *button,gpointer user_data)
{
    g_print("Button clicked\n");
    // Cast the user_data back to a GtkTextView pointer
    TokenizerAppWindow *win = TOKENIZER_APP_WINDOW(user_data);
    GtkTextView *text_view = win->text_view;

    // Get the text buffer associated with the text view
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);

    // Get the start and end iterator of the text buffer
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);

    // Extract the text from the buffer
    gchar *text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    jwt_decode(text);

    // Do something with the text
    g_print("Text value: %s\n", text);

    // Free the allocated text
    g_free(text);
}

static void
tokenizer_app_window_init (TokenizerAppWindow *win)
{
    GtkBuilder *builder;
    GMenuModel *menu;

    gtk_widget_init_template (GTK_WIDGET (win));
    builder = gtk_builder_new_from_resource ("/com/thisisericrobert/tokenizer/menu.ui");
    menu = G_MENU_MODEL (gtk_builder_get_object (builder, "menu"));
    gtk_menu_button_set_menu_model (GTK_MENU_BUTTON (win->menu), menu);
    g_object_unref (builder);

    g_signal_connect(win->encode_button,"clicked",G_CALLBACK(encode_button_clicked),NULL);
    g_signal_connect(win->decode_button,"clicked",G_CALLBACK(decode_button_clicked),win);

}

static void
tokenizer_app_window_class_init (TokenizerAppWindowClass *class)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),"/com/thisisericrobert/tokenizer/window.ui");
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), TokenizerAppWindow , menu);
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class),TokenizerAppWindow,encode_button);
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class),TokenizerAppWindow,decode_button);
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class),TokenizerAppWindow,text_view);
}

TokenizerAppWindow *
tokenizer_app_window_new (TokenizerApp *app)
{
    return g_object_new (TOKENIZER_APP_WINDOW_TYPE, "application", app, NULL);
}

void
tokenizer_app_window_open (TokenizerAppWindow *win,GFile *file)
{
}
