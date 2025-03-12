#ifndef EIGHTY4_LEARNING_CPP_INLINE_MACRO_H
#define EIGHTY4_LEARNING_CPP_INLINE_MACRO_H

#if _WIN32
#define PLATFORM_INLINE __forceinline
#else
#define PLATFORM_INLINE __attribute__((always_inline))
#endif

#endif
