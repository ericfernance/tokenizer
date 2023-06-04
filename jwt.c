#include <stdio.h>
#include <string.h>
#include <glib.h>


char *jwt_decode(char *jwt) {
    gchar** data = g_strsplit(jwt, ".", 3);
    guchar *result;
    gsize result_len;
    result = g_base64_decode(data[1], &result_len);
    printf("Result: %s\n", result);
    return (unsigned char*) result;
}