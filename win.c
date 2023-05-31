#include <gtk/gtk.h>

#include "app.h"
#include "win.h"

struct _TokenizerAppWindow
{
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(TokenizerAppWindow, tokenizer_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
tokenizer_app_window_init (TokenizerAppWindow *win)
{
    gtk_widget_init_template (GTK_WIDGET (win));
}

static void
tokenizer_app_window_class_init (TokenizerAppWindowClass *class)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                                 "/com/thisisericrobert/tokenizer/window.ui");
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
