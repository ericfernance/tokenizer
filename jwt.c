#include <stdio.h>
#include <glib.h>
#include <openssl/hmac.h>


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

char *jwt_encode(char *header, char *payload, char *secretkey){
    char *header64 = g_base64_encode(header, strlen(header));
    char *payload64 = g_base64_encode(payload, strlen(payload));
    char *result = g_strconcat(header64, ".", payload64, NULL);
    unsigned char hmac[32];
    unsigned int hmac_len;
    HMAC(EVP_sha256(), secretkey, strlen(secretkey), result, strlen(result), hmac, &hmac_len);
    char *signature = g_base64_encode(hmac, hmac_len);
    result = g_strconcat(result, ".", signature, NULL);
    GString *g_string = g_string_new(result);
    g_string_replace(g_string, "=", "", -1);
    return g_string->str;
}