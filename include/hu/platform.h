#ifndef HU_PLATFORM_H
#define HU_PLATFORM_H

#define HU_COMP_GCC_P 0
#define HU_COMP_CLANG_P 0
#define HU_COMP_INTEL_P 0
#define HU_COMP_MSVC_P 0

#define HU_BITS_32_P 0
#define HU_BITS_64_P 0

#define HU_OS_POSIX_P 0
#define HU_OS_LINUX_P 0     // imples POSIX
#define HU_OS_BSD_P 0       // implies POSIX
#define HU_OS_FREEBSD_P 0   // implies BSD
#define HU_OS_OPENBSD_P 0   // implies BSD
#define HU_OS_DRAGONFLY_P 0 // implies BSD
#define HU_OS_NETBSD_P 0    // implies BSD
#define HU_OS_MAC_P 0
#define HU_OS_OSX_P 0 // implies MAC
#define HU_OS_IOS_P 0 // implies MAC
#define HU_OS_WINDOWS_P 0
#define HU_OS_ANDROID_P 0

#define HU_CXX_P 0
#define HU_CXX_11_P 0
#define HU_CXX_14_P 0
#define HU_CXX_17_P 0

#define HU_CXX_EXCEPTIONS_P 0
#define HU_CXX_RTTI_P 0

#define HU_LITTLE_ENDIAN_P 0
#define HU_BIG_ENDIAN_P 0

#ifdef __clang__
#undef HU_COMP_CLANG_P
#define HU_COMP_CLANG_P 1
#elif defined(__ICC) || defined(__INTEL_COMPILER)
#undef HU_COMP_INTEL_P
#define HU_COMP_INTEL_P 1
#elif defined(__GNUC__)
#undef HU_COMP_GCC_P
#define HU_COMP_GCC_P 1
#endif

#ifdef _MSC_VER
#undef HU_COMP_MSVC_P
#define HU_COMP_MSVC_P 1
#endif

#if defined(__x86_64__) || defined(__ppc64__) || defined(__aarch64__)
#undef HU_BITS_64_P
#define HU_BITS_64_P 1
#endif

#if defined(__i386) || defined(__i386__) ||                                    \
  defined(__arm__) && !defined(__aarch64__)
#undef HU_BITS_32_P
#define HU_BITS_32_P 1
#endif

#if defined(__linux__) || defined(__linux) ||                                  \
  defined(__gnu_linux__) && !defined(__ANDROID__)
#undef HU_OS_LINUX_P
#define HU_OS_LINUX_P 1
#endif

#ifdef _WIN32
#undef HU_LITTLE_ENDIAN_P
#define HU_LITTLE_ENDIAN_P 1
#undef HU_OS_WINDOWS_P
#define HU_OS_WINDOWS_P 1
#ifdef _WIN64
#undef HU_BITS_64_P
#define HU_BITS_64_P 1
#else
#undef HU_BITS_32_P
#define HU_BITS_32_P 1
#endif
#endif

#ifdef __APPLE__
#include <TargetConditionals.h>
#undef HU_OS_MAC_P
#define HU_OS_MAC_P 1
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#undef HU_OS_IOS_P
#define HU_OS_IOS_P 1
#else
#undef HU_OS_OSX_P
#define HU_OS_OSX_P 1
#endif
#endif

#ifdef __ANDROID__
#undef HU_OS_ANDROID_P
#define HU_OS_ANDROID_P 1
#endif

#ifdef __FreeBSD__
#undef HU_OS_BSD_P
#define HU_OS_BSD_P 1
#undef HU_OS_FREEBSD_P
#define HU_OS_FREEBSD_P 1
#endif

#ifdef __OpenBSD__
#undef HU_OS_BSD_P
#define HU_OS_BSD_P 1
#undef HU_OS_OPENBSD_P
#define HU_OS_OPENBSD_P 1
#endif

#ifdef __DragonFly__
#undef HU_OS_BSD_P
#define HU_OS_BSD_P 1
#undef HU_OS_DRAGONFLY_P
#define HU_OS_DRAGONFLY_P 1
#endif

#ifdef __NetBSD__
#undef HU_OS_BSD_P
#define HU_OS_BSD_P 1
#undef HU_OS_NETBSD_P
#define HU_OS_NETBSD_P 1
#endif

#if defined(_POSIX_VERSION) || defined(__unix__) || defined(__unix)
#undef HU_OS_POSIX_P
#define HU_OS_POSIX_P 1
#endif

#ifdef __GNUC__
#define HU_COMP_GNULIKE 1
#undef HU_COMP_GNULIKE_P
#define HU_COMP_GNULIKE_P 1
#endif

#ifdef _MSC_VER
#define HU_COMP_MSC 1
#endif

#ifdef __cplusplus__
#undef HU_CXX_P
#define HU_CXX_P 1
#undef HU_CXX_EXCEPTIONS_P
#define HU_CXX_EXCEPTIONS_P 1
#undef HU_CXX_RTTI_P
#define HU_CXX_RTTI_P 1
#if __cplusplus__ > 199711L
#undef HU_CXX_11_P
#define HU_CXX_11_P 1
#if __cplusplus__ >= 201402L
#undef HU_CXX_14_P
#define HU_CXX_14_P 1
#if __cplusplus__ >= 201703L
#undef HU_CXX_17_P
#define HU_CXX_17_P 1
#endif
#endif
#endif
#endif

#if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) ||  \
  (defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN)
#undef HU_LITTLE_ENDIAN_P
#define HU_LITTLE_ENDIAN_P 1
#endif

#if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) ||     \
  (defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN) ||                   \
  defined(__BIG_ENDIAN__)
#undef HU_BIG_ENDIAN_P
#define HU_BIG_ENDIAN_P 1
#endif

#if HU_COMP_GCC_P || HU_COMP_CLANG_P || HU_COMP_INTEL_P
#undef HU_COMP_GNULIKE_P
#define HU_COMP_GNULIKE_P 1
#elif HU_COMP_MSVC_P
#define HU_COMP_MSVC 1
#else
#error "failed to detect compiler"
#endif

#if HU_CXX_P
#if HU_COMP_MSVC_P && !defined(_CPPUNWIND) ||                                  \
  HU_COMP_GNULIKE_P && !(defined(__cpp_exceptions) || defined(__EXCEPTIONS))
#undef HU_CXX_EXCEPTIONS_P
#define HU_CXX_EXCEPTIONS_P 0
#endif
#if HU_COMP_MSVC_P && !defined(_CPPRTTI) ||                                    \
  HU_COMP_GNULIKE_P && !(defined(__cpp_rtti) || defined(__GXX_RTTI))
#undef HU_CXX_RTTI_P
#define HU_CXX_RTTI_P 0
#endif
#endif

#if HU_COMP_GCC_P
#define HU_COMP_GCC 1
#endif

#if HU_COMP_GCC_P
#define HU_COMP_GCC 1
#endif

#if HU_COMP_CLANG_P
#define HU_COMP_CLANG 1
#endif

#if HU_COMP_INTEL_P
#define HU_COMP_INTEL 1
#endif

#if HU_COMP_MSVC_P
#define HU_COMP_MSVC 1
#endif

#if HU_BITS_32_P
#define HU_BITS_32 1
#endif

#if HU_BITS_64_P
#define HU_BITS_64 1
#endif

#if HU_BITS_32_P && HU_BITS_64_P
#error "BUG: HU_BITS_32_P and HU_BITS_64_P are both true"
#endif

#if !HU_BITS_32_P && !HU_BITS_64_P
#error "failed to detect bitness of platform"
#endif

#if HU_OS_POSIX_P
#define HU_OS_POSIX 1
#endif

#if HU_OS_LINUX_P
#define HU_OS_LINUX 1
#endif

#if HU_OS_BSD_P
#define HU_OS_BSD 1
#endif

#if HU_OS_FREEBSD_P
#define HU_FREEOS_BSD 1
#endif

#if HU_OS_OPENBSD_P
#define HU_OS_BSD 1
#endif

#if HU_OS_DRAGONFLY_P
#define HU_OS_DRAGONFLY 1
#endif

#if HU_OS_NETBSD_P
#define HU_OS_NETBSD_P 1
#endif

#if HU_OS_MAC_P
#define HU_OS_MAC 1
#endif

#if HU_OS_OSX_P
#define HU_OS_OSX 1
#endif

#if HU_OS_IOS_P
#define HU_OS_IOS 1
#endif

#if HU_OS_WINDOWS_P
#define HU_OS_WINDOWS 1
#endif

#if HU_OS_ANDROID_P
#define HU_OS_ANDROID 1
#endif

#if HU_CXX_P
#define HU_CXX 1
#endif

#if HU_CXX_11_P
#define HU_CXX_11 1
#endif

#if HU_CXX_14_P
#define HU_CXX_14 1
#endif

#if HU_CXX_17_P
#define HU_CXX_17 1
#endif

#if HU_CXX_EXCEPTIONS_P
#define HU_CXX_EXCEPTIONS 1
#endif

#if HU_CXX_RTTI_P
#define HU_CXX_RTTI 1
#endif

#if HU_LITTLE_ENDIAN_P
#define HU_LITTLE_ENDIAN 1
#endif

#if HU_BIG_ENDIAN_P
#define HU_BIG_ENDIAN 1
#endif

#if HU_LITTLE_ENDIAN_P && HU_BIG_ENDIAN_P
#error "BUG: HU_LITTLE_ENDIAN_P and HU_BIG_ENDIAN_P are both true"
#endif

#if !HU_LITTLE_ENDIAN_P && !HU_BIG_ENDIAN_P
#error "failed to detect endianess of platform"
#endif

#endif
