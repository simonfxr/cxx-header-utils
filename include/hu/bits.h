#ifndef HU_BITS_H
#define HU_BITS_H

#ifndef HU_MACH_H
#    include <hu/mach.h>
#endif

#ifndef HU_INTERNAL_BITS
#    if defined(_LP64) || defined(__LP64__)
#        define HU_INTERNAL_BITS 64
#    endif

#    if defined(_ILP32) || defined(__ILP32__)
#        define HU_INTERNAL_BITS 32
#    endif
#endif

#if !defined(HU_INTERNAL_BITS) && defined(_WIN32)
#    ifdef _WIN64
#        define HU_INTERNAL_BITS 64
#    else
#        define HU_INTERNAL_BITS 32
#    endif
#endif

#define HU_BITS HU_INTERNAL_BITS

#if HU_BITS == 32
#    define HU_BITS_32 1
#    define HU_BITS_32_P 1
#    define HU_BITS_64_P 0
#elif HU_BITS == 64
#    define HU_BITS_64 1
#    define HU_BITS_32_P 0
#    define HU_BITS_64_P 1
#else
#    error "BUG: HU_BITS has invalid value"
#endif

#endif
