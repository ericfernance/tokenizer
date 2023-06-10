#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "jwt.h"
#include <stdio.h>

static void test_jwt_decode(void **state){
    (void)state; // Unused variable
    const char *jwt = jwt_decode("eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c");
    assert_string_equal(jwt, "{\"sub\":\"1234567890\",\"name\":\"John Doe\",\"iat\":1516239022}");
}

int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_jwt_decode),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
