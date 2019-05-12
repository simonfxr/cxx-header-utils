#ifndef HU_LANG_H
#define HU_LANG_H

#ifndef HU_AMALGAMATED
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

#define HU_C_PREREQ(x) 0
#define HU_CXX_PREREQ(x) 0

#ifdef __STDC__

#    ifndef __cplusplus
#        define HU_BEGIN_EXTERN_C
#        define HU_END_EXTERN_C
#        define HU_EXTERN_C

#        if defined(__clang__) ||                                              \
          (defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ >= 403))
#            define hu_c_implicit_cast_(T, x, cnt)                             \
                __extension__({                                                \
                    T hu_c_implicit_cast_val##cnt = (x);                       \
                    hu_c_implicit_cast_val##cnt;                               \
                })
#            define hu_c_implicit_cast(T, x)                                   \
                hu_c_implicit_cast_(T, x, __COUNTER__)
#        else
#            define hu_c_implicit_cast(T, x) (x)
#        endif

#        define hu_cxx_static_cast(T, x) hu_c_implicit_cast(T, x)
#        define hu_cxx_const_cast(T, x) hu_c_implicit_cast(T, x)
#        define hu_cxx_reinterpret_cast(T, x) hu_c_implicit_cast(T, x)
#        define hu_cxx_cast(T, x) hu_c_implicit_cast(T, x)
#        define hu_static_cast(T, x) ((T) x)
#        define hu_const_cast(T, x) ((T) x)
#        define hu_reinterpret_cast(T, x) ((T) x)
#    endif

#    undef HU_C_P
#    define HU_C_P 1
#    define HU_C 1
#    undef HU_C_89_P
#    define HU_C_89_P 1
#    define HU_C_89 1

#    ifdef __STDC_VERSION__
#        define HU_STDC_VERSION __STDC_VERSION__
#    else
#        define HU_STDC_VERSION 198901L
#    endif

#    undef HU_C_PREREQ
#    define HU_C_PREREQ(x)                                                     \
        (HU_STDC_VERSION >= ((x) + ((x) < 80L) * 100L + 1900L) * 100L)

#    if HU_C_PREREQ(99)
#        undef HU_C_99_P
#        define HU_C_99_P 1
#        define HU_C_99 1
#    endif

#    if HU_C_PREREQ(11)
#        undef HU_C_11_P
#        define HU_C_11_P 1
#        define HU_C_11 1
#    endif

#    if HU_C_PREREQ(17)
#        undef HU_C_17_P
#        define HU_C_17_P 1
#        define HU_C_17 1
#    endif

#endif /* __STDC__ */

#ifdef __cplusplus

#    define HU_BEGIN_EXTERN_C extern "C" {
#    define HU_END_EXTERN_C }
#    define HU_EXTERN_C extern "C"

#    define hu_cxx_static_cast(T, x) static_cast<T>(x)
#    define hu_cxx_const_cast(T, x) const_cast<T>(x)
#    define hu_cxx_reinterpret_cast(T, x) reinterpret_cast<T>(x)
#    define hu_cxx_cast(T, x) ((T) x)
#    define hu_static_cast hu_cxx_static_cast
#    define hu_const_cast hu_cxx_const_cast
#    define hu_reinterpret_cast hu_cxx_reinterpret_cast

#    undef HU_CXX_P
#    define HU_CXX_P 1
#    define HU_CXX 1

#    undef HU_CXX_98_P
#    define HU_CXX_98_P 1

#    undef HU_CXX_EXCEPTIONS_P
#    define HU_CXX_EXCEPTIONS_P 1

#    undef HU_CXX_RTTI_P
#    define HU_CXX_RTTI_P 1

#    undef HU_CXX_PREREQ
#    define HU_CXX_PREREQ(x)                                                   \
        (__cplusplus >= ((x) + ((x) < 80L) * 100L + 1900L) * 100L)

#    if HU_CXX_PREREQ(11)
#        undef HU_CXX_11_P
#        define HU_CXX_11_P 1
#        define HU_CXX_11 1
#        define HU_CONSTEXPR constexpr
#        define HU_NOEXCEPT noexept
#        define HU_OVERRIDE override
#        define HU_CXX_11 1
#    else
#        define HU_CONSTEXPR
#        define HU_NOEXCEPT
#        define HU_OVERRIDE
#    endif

#    if HU_CXX_PREREQ(14)
#        undef HU_CXX_14_P
#        define HU_CXX_14_P 1
#        define HU_CXX_14 1
#        define HU_CONSTEXPR14 constexpr
#    else
#        define HU_CONSTEXPR14 constexpr
#    endif

#    if HU_CXX_PREREQ(17)
#        undef HU_CXX_17_P
#        define HU_CXX_17_P 1
#        define HU_CXX_17 1
#        define HU_CONSTEXPR17 constexpr
#    else
#        define HU_CONSTEXPR17
#    endif

#    if HU_COMP_MSVC_P && !defined(_CPPUNWIND) ||                              \
      HU_COMP_GNUC_P && !(defined(__cpp_exceptions) || defined(__EXCEPTIONS))
#        undef HU_CXX_EXCEPTIONS_P
#        define HU_CXX_EXCEPTIONS_P 0
#    endif
#    if HU_COMP_MSVC_P && !defined(_CPPRTTI) ||                                \
      HU_COMP_GNUC_P && !(defined(__cpp_rtti) || defined(__GXX_RTTI))
#        undef HU_CXX_RTTI_P
#        define HU_CXX_RTTI_P 0
#    endif

#    if HU_CXX_EXCEPTIONS_P
#        define HU_CXX_EXCEPTIONS 1
#    endif

#    if HU_CXX_RTTI_P
#        define HU_CXX_RTTI 1
#    endif

#endif /* __cplusplus */

#endif
