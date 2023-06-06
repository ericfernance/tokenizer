#include <stdio.h>
#include <glib.h>


char *jwt_decode(char *jwt) {
    gchar** data = g_strsplit(jwt, ".", 3);

    char *padded = data[1];
    int len = strlen(padded);
    printf("Len: %d\n", len);
    printf("Mod4 = %d\n", len%4);
    if (len%4 == 2) {
        padded = g_strconcat(padded, "==", NULL);
    } else if (len%4 == 1) {
        padded = g_strconcat(padded, "=", NULL);
    }

    printf("Padded: %s\n", padded);

    guchar *result;
    gsize result_len;
    result = g_base64_decode(padded, &result_len);
    printf("Result: ");
    for (gsize i = 0; i < result_len; i++) {
        printf("%02X ", result[i]);
    }
    printf("\n");
    return result;
}