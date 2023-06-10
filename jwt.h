#include <glib.h>

guchar *jwt_decode(char *jwt);
char *jwt_encode(char *header, char *payload, char *secretkey);
