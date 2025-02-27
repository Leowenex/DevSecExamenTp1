#include <string.h>
int get_and_verify_password(char *real_password) {
    int result; char user_password[64]; // Correction du tampon
    get_password_from_user_somehow(user_password, sizeof(user_password));
    result = !strcmp(user_password, real_password); // Utiliser memset_s
#if defined(__STDC_LIB_EXT1__)
    memset_s(user_password, sizeof(user_password), 0, strlen(user_password));
#else
    explicit_bzero(user_password, sizeof(user_password));
#endif
    return result;
}
