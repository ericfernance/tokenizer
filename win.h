#ifndef __TOKENIZERAPPWIN_H
#define __TOKENIZERAPPWIN_H

#include <gtk/gtk.h>
#include "app.h"


#define TOKENIZER_APP_WINDOW_TYPE (tokenizer_app_window_get_type ())
G_DECLARE_FINAL_TYPE (TokenizerAppWindow, tokenizer_app_window, TOKENIZER, APP_WINDOW, GtkApplicationWindow)


TokenizerAppWindow       *tokenizer_app_window_new          (TokenizerApp *app);
void                    tokenizer_app_window_open         (TokenizerAppWindow *win,
                                                         GFile            *file);


#endif /* __TOKENIZERAPPWIN_H */
