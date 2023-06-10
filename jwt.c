#include <stdio.h>
#include <glib.h>


char *jwt_decode(char *jwt) {
    gchar** data = g_strsplit(jwt, ".", 3);
    char *padded = data[1];
    int len = strlen(padded);
    if (len%4 == 2) {
        padded = g_strconcat(padded, "==", NULL);
    } else if (len%4 == 1) {
        padded = g_strconcat(padded, "=", NULL);
    }
    guchar *result;
    gsize result_len;
    result = g_base64_decode(padded, &result_len);
    return result;
}