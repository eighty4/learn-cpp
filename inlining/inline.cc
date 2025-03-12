#include <cstdio>

#include "inline_linked.h"
#include "inline_macro.h"

inline int zero() {
    return 0;
}

int one() {
    return 1;
}

inline PLATFORM_INLINE int two() {
    return 2;
}

int main() {
    auto count = 0;
    for (int i = 0; i < 5; i++) {
        count += zero();
    }
    printf("%d really adds up\n", count);

    for (int i = 0; i < 3; i++) {
        count += one();
    }
    printf("%d blind mice\n", count);

    for (int i = 0; i < 2; i++) {
        count += two();
    }
    printf("%d days a week\n", count);

    count += three();
    printf("%d years gone\n", count);
}
