#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "jwt.h"
#include <stdio.h>
#include <glib.h>

static void test_jwt_decode(void **state){
    (void)state; // Unused variable
    const char *jwt = jwt_decode("eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c");
    assert_string_equal(jwt, "{\"sub\":\"1234567890\",\"name\":\"John Doe\",\"iat\":1516239022}");
}

static void test_jwt_encode(void **state){
    char *header = "{\"alg\":\"HS256\",\"typ\":\"JWT\"}";
    char *payload = "{\"sub\":\"1234567890\",\"name\":\"John Doe\",\"iat\":1516239022}";
    char *jwt = jwt_encode(header, payload, "secretkey");
    gchar **segments = g_strsplit(jwt, ".", 3);
    assert_string_equal(segments[0], "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9");
    assert_string_equal(segments[1], "eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ");
    assert_true(strlen(segments[2])>0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_jwt_decode),
            cmocka_unit_test(test_jwt_encode),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
