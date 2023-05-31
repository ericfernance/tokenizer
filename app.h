#ifndef __TOKENIZERAPP_H
#define __TOKENIZERAPP_H

#include <gtk/gtk.h>


#define TOKENIZER_APP_TYPE (tokenizer_app_get_type ())
G_DECLARE_FINAL_TYPE (TokenizerApp, tokenizer_app, TOKENIZER, APP, GtkApplication)

TokenizerApp     *tokenizer_app_new         (void);


#endif /* __TOKENIZERAPP_H */
