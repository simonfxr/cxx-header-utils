#ifndef HU_LANG_H
#define HU_LANG_H

#ifndef HU_COMPILER_H
#    include <hu/compiler.h>
#endif

#define HU_C_P 0
#define HU_C_89_P 0
#define HU_C_99_P 0
#define HU_C_11_P 0
#define HU_C_17_P 0

#define HU_CXX_P 0
#define HU_CXX_98_P 0
#define HU_CXX_11_P 0
#define HU_CXX_14_P 0
#define HU_CXX_17_P 0

#define HU_CXX_EXCEPTIONS_P 0
#define HU_CXX_RTTI_P 0

#ifdef __STDC__

#    undef HU_C_P
#    define HU_C_P 1
#    undef HU_C_89_P
#    define HU_C_89_P 1

#    ifndef __STDC_VERSION__
#        define HU_C_VERS 1989
#    elif __STDC_VERSION__ == 199901L
#        define HU_C_VERS 1999
#    elif __STDC_VERSION__ == 201112L
#        define HU_C_VERS 2011
#    elif __STDC_VERSION__ == 201710L
#        define HU_C_VERS 2017
#    elif __STDC_VERSION__ > 201710L
#        define HU_C_VERS 9999
#    endif

#    if HU_C_VERS >= 1999
#        undef HU_C_99_P
#        define HU_C_99_P 1
#    endif

#    if HU_C_VERS >= 2011
#        undef HU_C_11_P
#        define HU_C_11_P 1
#    endif

#    if HU_C_VERS >= 2017
#        undef HU_C_17_P
#        define HU_C_17_P 1
#    endif

#    if HU_C_P
#        define HU_C 1
#    endif

#    if HU_C_89_P
#        define HU_C_89 1
#    endif

#    if HU_C_99_P
#        define HU_C_99 1
#    endif

#    if HU_C_11_P
#        define HU_C_11 1
#    endif

#    if HU_C_17_P
#        define HU_C_17 1
#    endif

#endif /* __STDC__ */

#ifdef __cplusplus

#    undef HU_CXX_P
#    define HU_CXX_P 1

#    undef HU_CXX_98_P
#    define HU_CXX_98_P 1

#    undef HU_CXX_EXCEPTIONS_P
#    define HU_CXX_EXCEPTIONS_P 1

#    undef HU_CXX_RTTI_P
#    define HU_CXX_RTTI_P 1

#    if __cplusplus == 199711L
#        define HU_CXX_VERS 1998
#    elif __cplusplus == 201103L
#        define HU_CXX_VERS 2011
#    elif __cplusplus == 201402L
#        define HU_CXX_VERS 2014
#    elif __cplusplus == 201703L
#        define HU_CXX_VERS 2017
#    elif __cplusplus > 201703L
#        define HU_CXX_VERS 9999
#    endif

#    if HU_CXX_VERS >= 2011
#        undef HU_CXX_11_P
#        define HU_CXX_11_P 1
#    endif

#    if HU_CXX_VERS >= 2014
#        undef HU_CXX_14_P
#        define HU_CXX_14_P 1
#    endif

#    if HU_CXX_VERS >= 2017
#        undef HU_CXX_17_P
#        define HU_CXX_17_P 1
#    endif

#    if HU_COMP_MSVC_P && !defined(_CPPUNWIND) ||                              \
      HU_COMP_GNULIKE_P &&                                                     \
        !(defined(__cpp_exceptions) || defined(__EXCEPTIONS))
#        undef HU_CXX_EXCEPTIONS_P
#        define HU_CXX_EXCEPTIONS_P 0
#    endif
#    if HU_COMP_MSVC_P && !defined(_CPPRTTI) ||                                \
      HU_COMP_GNULIKE_P && !(defined(__cpp_rtti) || defined(__GXX_RTTI))
#        undef HU_CXX_RTTI_P
#        define HU_CXX_RTTI_P 0
#    endif

#    if HU_CXX_P
#        define HU_CXX 1
#    endif

#    if HU_CXX_11_P
#        define HU_CONSTEXPR constexpr
#        define HU_NOEXCEPT noexept
#        define HU_OVERRIDE override
#        define HU_CXX_11 1
#    endif

#    if HU_CXX_14_P
#        define HU_CXX_14 1
#        define HU_CONSTEXPR14 constexpr
#    else
#        define HU_CONSTEXPR14
#    endif

#    if HU_CXX_17_P
#        define HU_CXX_17 1
#        define HU_CONSTEXPR17 constexpr
#    else
#        define HU_CONSTEXPR17
#    endif

#    if HU_CXX_EXCEPTIONS_P
#        define HU_CXX_EXCEPTIONS 1
#    endif

#    if HU_CXX_RTTI_P
#        define HU_CXX_RTTI 1
#    endif

#endif /* __cplusplus */

#endif
