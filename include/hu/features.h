#ifndef HU_FEATURES_H
#define HU_FEATURES_H

#ifndef __has_builtin
#    define HU_HAVE_has_builtin_P 0
#    define hu_has_builtin(x) 0
#else
#    define HU_HAVE_has_builtin_P 1
#    define HU_HAVE_has_builtin 1
#    define hu_has_builtin __has_builtin
#endif

#ifndef __has_include
#    define HU_HAVE_has_include_P 0
#    define hu_has_include(x) 0
#else
#    define HU_HAVE_has_include_P 1
#    define HU_HAVE_has_include 1
#    define hu_has_include __has_include
#endif

#ifndef __has_include_next
#    define HU_HAVE_has_include_next_P 0
#    define hu_has_include_next(x) 0
#else
#    define HU_HAVE_has_include_next_P 1
#    define HU_HAVE_has_include_next 1
#    define hu_has_include_next __has_include_next
#endif

#ifndef __has_cpp_attribute
#    define HU_HAVE_has_cpp_attribute_P 0
#    define hu_has_cpp_attribute(x) 0
#else
#    define HU_HAVE_has_cpp_attribute_P 1
#    define HU_HAVE_has_cpp_attribute 1
#    define hu_has_cpp_attribute __has_cpp_attribute
#endif

#ifndef __has_feature
#    define HU_HAVE_has_feature_P 0
#    define hu_has_feature(x) 0
#else
#    define HU_HAVE_has_feature_P 1
#    define HU_HAVE_has_feature 1
#    define hu_has_feature __has_feature
#endif

#ifndef __has_extension
#    define HU_HAVE_has_extension_P 0
#    define hu_has_extension hu_has_feature
#else
#    define HU_HAVE_has_extension_P 1
#    define HU_HAVE_has_extension 1
#    define hu_has_extension __has_extension
#endif

#ifndef __has_attribute
#    define HU_HAVE_has_attribute_P 0
#    define hu_has_attribute(x) 0
#else
#    define HU_HAVE_has_attribute_P 1
#    define HU_HAVE_has_attribute 1
#    define hu_has_attribute __has_attribute
#endif

#ifndef __has_declspec_attribute
#    define HU_HAVE_has_declspec_attribute_P 0
#    define hu_has_declspec_attribute(x) 0
#else
#    define HU_HAVE_has_declspec_attribute_P 1
#    define HU_HAVE_has_declspec_attribute 1
#    define hu_has_declspec_attribute __has_declspec_attribute
#endif

#endif
