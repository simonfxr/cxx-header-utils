#ifndef HU_FEATURES_H
#define HU_FEATURES_H

#ifndef __has_builtin
#    define HU_HAVE_has_builtin_P 0
#    define hu_has_builtin(x) 0
#else
#    define HU_HAVE_has_builtin_P 1
#    define HU_HAVE_has_builtin 1
#    define hu_has_builtin(x) __has_builtin(x)
#endif

#ifndef __has_include
#    define HU_HAVE_has_include_P 0
#    define hu_has_include(x) 0
#else
#    define HU_HAVE_has_include_P 1
#    define HU_HAVE_has_include 1
#    define hu_has_include(x) __has_include(x)
#endif

#ifndef __has_include_next
#    define HU_HAVE_has_include_next_P 0
#    define hu_has_include_next(x) 0
#else
#    define HU_HAVE_has_include_next_P 1
#    define HU_HAVE_has_include_next 1
#    define hu_has_include_next(x) __has_include_next(x)
#endif

#ifndef __has_cpp_attribute
#    define HU_HAVE_has_cpp_attribute_P 0
#    define hu_has_cpp_attribute(x) 0
#else
#    define HU_HAVE_has_cpp_attribute_P 1
#    define HU_HAVE_has_cpp_attribute 1
#    define hu_has_cpp_attribute(x) __has_cpp_attribute(x)
#endif

#ifndef __has_feature
#    define HU_HAVE_has_feature_P 0
#    define hu_has_feature(x) 0
#else
#    define HU_HAVE_has_feature_P 1
#    define HU_HAVE_has_feature 1
#    define hu_has_feature(x) __has_feature(x)
#endif

#ifndef __has_extension
#    define HU_HAVE_has_extension_P 0
#    define hu_has_extension(x) hu_has_feature(x)
#else
#    define HU_HAVE_has_extension_P 1
#    define HU_HAVE_has_extension 1
#    define hu_has_extension(x) __has_extension(x)
#endif

#ifndef __has_attribute
#    define HU_HAVE_has_attribute_P 0
#    define hu_has_attribute(x) 0
#else
#    define HU_HAVE_has_attribute_P 1
#    define HU_HAVE_has_attribute 1
#    define hu_has_attribute(x) __has_attribute(x)
#endif

#ifndef __has_declspec_attribute
#    define HU_HAVE_has_declspec_attribute_P 0
#    define hu_has_declspec_attribute(x) 0
#else
#    define HU_HAVE_has_declspec_attribute_P 1
#    define HU_HAVE_has_declspec_attribute 1
#    define hu_has_declspec_attribute(x) __has_declspec_attribute(x)
#endif

#endif
