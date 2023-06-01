#include <gtk/gtk.h>

#include "app.h"
#include "win.h"

struct _TokenizerAppWindow
{
    GtkApplicationWindow parent;
    GtkWidget *menu;
};

G_DEFINE_TYPE(TokenizerAppWindow, tokenizer_app_window, GTK_TYPE_APPLICATION_WINDOW);

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
}

static void
tokenizer_app_window_class_init (TokenizerAppWindowClass *class)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                                 "/com/thisisericrobert/tokenizer/window.ui");
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), TokenizerAppWindow , menu);
}

TokenizerAppWindow *
tokenizer_app_window_new (TokenizerApp *app)
{
    return g_object_new (TOKENIZER_APP_WINDOW_TYPE, "application", app, NULL);
}

void
tokenizer_app_window_open (TokenizerAppWindow *win,
                         GFile            *file)
{
}
