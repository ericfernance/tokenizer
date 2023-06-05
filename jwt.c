#include <stdio.h>
#include <glib.h>


char *jwt_decode(char *jwt) {
    /**
     * No, the number of padding characters (equals signs) in Base64 encoding depends on the length of the input. The padding characters are used to ensure that the length of the encoded string is a multiple of 4.

In Base64 encoding, the padding characters can be one or two equals signs (=). The rules for adding padding characters are as follows:

If the input length is not a multiple of 3, padding is required.
If the input length is one character more than a multiple of 3, one equals sign is added as padding.
If the input length is two characters more than a multiple of 3, two equals signs are added as padding.
For example:

If the input length is 4, no padding is needed.
If the input length is 5, one equals sign is added as padding.
If the input length is 6, no padding is needed.
If the input length is 7, two equals signs are added as padding.
The equals signs in Base64 encoding do not represent any specific value. They are used solely for padding purposes.
     */
    gchar** data = g_strsplit(jwt, ".", 3);
    guchar *result;
    gsize result_len;
    result = g_base64_decode(data[1], &result_len);
    printf("Result: ");
    for (gsize i = 0; i < result_len; i++) {
        printf("%02X ", result[i]);
    }
    printf("\n");
    return result;
}