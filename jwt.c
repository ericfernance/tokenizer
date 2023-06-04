#include <stdio.h>
#include <string.h>
#include "deps/b64/b64.h"

/*int main() {
    char jwt[] = "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJleHAiOiIxNjg1ODY4ODMwIiwiaXNzIjoiU2ltcGxlQ2xpbmljIiwidXNlcl9pZCI6IjIiLCJidXNpbmVzc19pZCI6IjIiLCJlbWFpbCI6ImVyaWNAcGFzc2lvbjRoZWFsdGguY29tLmF1Iiwicm9sZSI6ImFkbWluIiwiZ3JvdXBzIjpbImFkbWluIiwibWVtYmVycyJdfQ.qRQwc3pwayWqHtVAT6UZLQpJVog5bsjRaJwbI6Usa41S9Ae9jFsISEfMjnaMEzeEcVToeUV9Uwny9sTotMNLreJzAF-wD8Kdd4DcK5mSh7vF7gfyqn_zuFzAgqUrXAQ3uigDCZtC91HRvmCLDnytjHh7RupVRKnzYS1hDfqqW-aXnpt739kjecueMMKrVeA54DZ6EmlbXusKtvFzcSM4vzmABM7gW655n_l1jvvm6_egY2ThrA3OCogloFPWhaGPNbK7ibPuXJYST-WN5l-sVWG-IlrzgTjGz7gXaq5qIP_e5MiE2CiE6zXxjgGTYvqoXuRa18VD5cquwyfa5wz_DG7iMoETGzyFssoymyD_xKfPF1unK_ho6nXYeXSEyNuhshoT9fHBcB4IXufnmHq0pOZvBuBeiX90h1LCS4OLsIZLmfPo9Xff-8e_oRCiBpk6z-JqbLE4kxOLWegtnbn5vGDHKSDSfMXJrD4g7W3_EqQilZYKyPg81Y1RVhhvQOLir_8wvCgwwfMM2AOAXYrUMT61f-cDNmkiEB30udvh_QZ2cNkzoHOnCrcZR0rm-9ZrsA7Dj0j48a2ayEF6UcSx_AeC3WjZLu3_uTCYQOvLinzP25o8LaKuqViNmW4SK9fPEctZ5xbO8LdP4D105m6EZZajTnFQnUt_xnqGhlDIeL8";
    char* tokens[3];
    // Subsequent calls to strtok to retrieve the remaining tokens
    tokens[0] = strtok(jwt, ".");
    tokens[1] = strtok(NULL, ".");
    tokens[2] = strtok(NULL, ".");

    printf("Token 1: %s\n", tokens[0]);
    printf("Token 2: %s\n", tokens[1]);
    printf("Token 3: %s\n", tokens[2]);

    printf(b64_decode(tokens[2], strlen(tokens[2])));

    return 0;
}*/
