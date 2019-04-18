#ifndef HU_BITS_H
#define HU_BITS_H

#include <hu/arch.h>

#define HU_DATA_MODEL_ILP32_P 0
#define HU_DATA_MODEL_LLP64_P 0
#define HU_DATA_MODEL_LP64_P 0

#if defined(_LP64) || defined(__LP64__)
#    ifndef HU_INTERNAL_BITS
#        define HU_INTERNAL_BITS 64
#    endif
#    undef HU_DATA_MODEL_LP64_P
#    define HU_DATA_MODEL_LP64_P 1
#endif

#if defined(_ILP32) || defined(__ILP32__)
#    ifndef HU_INTERNAL_BITS
#        define HU_INTERNAL_BITS 32
#    endif
#    undef HU_DATA_MODEL_ILP32_P
#    define HU_DATA_MODEL_ILP32_P 1
#endif

#ifdef _WIN32
#    ifdef _WIN64
#        ifndef HU_INTERNAL_BITS
#            define HU_INTERNAL_BITS 64
#        endif
#        undef HU_DATA_MODEL_LLP64_P
#        define HU_DATA_MODEL_LLP64_P 1
#    else
#        ifndef HU_INTERNAL_BITS
#            define HU_INTERNAL_BITS 32
#        endif
#        undef HU_DATA_MODEL_ILP32_P
#        define HU_DATA_MODEL_ILP32_P 1
#    endif
#endif

#define HU_BITS HU_INTERNAL_BITS

#if HU_BITS == 32
#    define HU_BITS_32 1
#    define HU_BITS_32_P 1
#    define HU_BITS_64_P 0
#    undef HU_DATA_MODEL_ILP32_P
#    define HU_DATA_MODEL_ILP32_P 1
#elif HU_BITS == 64
#    define HU_BITS_64 1
#    define HU_BITS_32_P 0
#    define HU_BITS_64_P 1
#else
#    error "BUG: HU_BITS has invalid value"
#endif

#if HU_DATA_MODEL_ILP32_P
#    define HU_DATA_MODEL_ILP32 1
#    define HU_SIZEOF_PTR 4
#    define HU_SIZEOF_INT 4
#    define HU_SIZEOF_LONG 4
#    define HU_SIZEOF_LONGLONG 8
#endif

#if HU_DATA_MODEL_LP64_P
#    define HU_DATA_MODEL_LP64 1
#    define HU_SIZEOF_PTR 8
#    define HU_SIZEOF_INT 4
#    define HU_SIZEOF_LONG 8
#    define HU_SIZEOF_LONGLONG 8
#endif

#if HU_DATA_MODEL_LLP64_P
#    define HU_DATA_MODEL_LLP64 1
#    define HU_SIZEOF_PTR 8
#    define HU_SIZEOF_INT 4
#    define HU_SIZEOF_LONG 4
#    define HU_SIZEOF_LONGLONG 8
#endif

#if HU_DATA_MODEL_ILP32_P + HU_DATA_MODEL_LP64_P + HU_DATA_MODEL_LLP64_P != 1
#    error "BUG: HU_DATA_MODEL_*_P not properly detected"
#endif

#endif
