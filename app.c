#include <gtk/gtk.h>

#include "app.h"
#include "win.h"

struct _TokenizerApp
{
    GtkApplication parent;
};


static void
preferences_activated (GSimpleAction *action,
                       GVariant      *parameter,
                       gpointer       app)
{
}

static void
quit_activated (GSimpleAction *action,
                GVariant      *parameter,
                gpointer       app)
{
    g_application_quit (G_APPLICATION (app));
}

static GActionEntry app_entries[] =
{
        { "preferences", preferences_activated, NULL, NULL, NULL },
        { "quit", quit_activated, NULL, NULL, NULL }
};

G_DEFINE_TYPE(TokenizerApp, tokenizer_app, GTK_TYPE_APPLICATION);

static void
tokenizer_app_init (TokenizerApp *app)
{
}

static void
tokenizer_app_activate (GApplication *app)
{
    TokenizerAppWindow *win;

    win = tokenizer_app_window_new (TOKENIZER_APP (app));
    gtk_window_present (GTK_WINDOW (win));
}

static void
tokenizer_app_open (GApplication  *app,
                  GFile        **files,
                  int            n_files,
                  const char    *hint)
{
    GList *windows;
    TokenizerAppWindow *win;
    int i;

    windows = gtk_application_get_windows (GTK_APPLICATION (app));
    if (windows)
        win = TOKENIZER_APP_WINDOW (windows->data);
    else
        win = tokenizer_app_window_new (TOKENIZER_APP (app));

    for (i = 0; i < n_files; i++)
        tokenizer_app_window_open (win, files[i]);

    gtk_window_present (GTK_WINDOW (win));
}

static void
tokenizer_app_startup (GApplication *app)
{
    const char *quit_accels[2] = { "<Ctrl>Q", NULL };

    G_APPLICATION_CLASS (tokenizer_app_parent_class)->startup (app);

    g_action_map_add_action_entries (G_ACTION_MAP (app),app_entries, G_N_ELEMENTS (app_entries),app);
    gtk_application_set_accels_for_action (GTK_APPLICATION (app),"app.quit",quit_accels);
}


static void
tokenizer_app_class_init (TokenizerAppClass *class)
{
    G_APPLICATION_CLASS (class)->startup = tokenizer_app_startup;
    G_APPLICATION_CLASS (class)->activate = tokenizer_app_activate;
    G_APPLICATION_CLASS (class)->open = tokenizer_app_open;
}

TokenizerApp *
tokenizer_app_new (void)
{
    return g_object_new (TOKENIZER_APP_TYPE,
                         "application-id", "com.thisisericrobert.tokenizer",
                         "flags", G_APPLICATION_HANDLES_OPEN,
                         NULL);
}

