#ifndef HU_OS_H
#define HU_OS_H

#define HU_OS_POSIX_P 0
#define HU_OS_LINUX_P 0     /* implies POSIX */
#define HU_OS_BSD_P 0       /* implies POSIX */
#define HU_OS_FREEBSD_P 0   /* implies BSD */
#define HU_OS_OPENBSD_P 0   /* implies BSD */
#define HU_OS_DRAGONFLY_P 0 /* implies BSD */
#define HU_OS_NETBSD_P 0    /* implies BSD */
#define HU_OS_MAC_P 0
#define HU_OS_OSX_P 0 /* implies MAC */
#define HU_OS_IOS_P 0 /* implies MAC */
#define HU_OS_WINDOWS_P 0
#define HU_OS_ANDROID_P 0

#if defined(__linux__) || defined(__linux) ||                                  \
  defined(__gnu_linux__) && !defined(__ANDROID__)
#    undef HU_OS_LINUX_P
#    define HU_OS_LINUX_P 1
#endif

#if defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
#    undef HU_OS_WINDOWS_P
#    define HU_OS_WINDOWS_P 1
#endif

#ifdef __APPLE__
#    include <TargetConditionals.h>
#    undef HU_OS_MAC_P
#    define HU_OS_MAC_P 1
#    if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#        undef HU_OS_IOS_P
#        define HU_OS_IOS_P 1
#    else
#        undef HU_OS_OSX_P
#        define HU_OS_OSX_P 1
#    endif
#endif

#ifdef __ANDROID__
#    undef HU_OS_ANDROID_P
#    define HU_OS_ANDROID_P 1
#endif

#ifdef __FreeBSD__
#    undef HU_OS_BSD_P
#    define HU_OS_BSD_P 1
#    undef HU_OS_FREEBSD_P
#    define HU_OS_FREEBSD_P 1
#endif

#ifdef __OpenBSD__
#    undef HU_OS_BSD_P
#    define HU_OS_BSD_P 1
#    undef HU_OS_OPENBSD_P
#    define HU_OS_OPENBSD_P 1
#endif

#ifdef __DragonFly__
#    undef HU_OS_BSD_P
#    define HU_OS_BSD_P 1
#    undef HU_OS_DRAGONFLY_P
#    define HU_OS_DRAGONFLY_P 1
#endif

#ifdef __NetBSD__
#    undef HU_OS_BSD_P
#    define HU_OS_BSD_P 1
#    undef HU_OS_NETBSD_P
#    define HU_OS_NETBSD_P 1
#endif

#if defined(_POSIX_VERSION) || defined(__unix__) || defined(__unix) ||         \
  HU_OS_MAC_P
#    undef HU_OS_POSIX_P
#    define HU_OS_POSIX_P 1
#endif

#if HU_OS_POSIX_P
#    define HU_OS_POSIX 1
#endif

#if HU_OS_LINUX_P
#    define HU_OS_LINUX 1
#endif

#if HU_OS_BSD_P
#    define HU_OS_BSD 1
#endif

#if HU_OS_FREEBSD_P
#    define HU_FREEOS_BSD 1
#endif

#if HU_OS_OPENBSD_P
#    define HU_OS_BSD 1
#endif

#if HU_OS_DRAGONFLY_P
#    define HU_OS_DRAGONFLY 1
#endif

#if HU_OS_NETBSD_P
#    define HU_OS_NETBSD_P 1
#endif

#if HU_OS_MAC_P
#    define HU_OS_MAC 1
#endif

#if HU_OS_OSX_P
#    define HU_OS_OSX 1
#endif

#if HU_OS_IOS_P
#    define HU_OS_IOS 1
#endif

#if HU_OS_WINDOWS_P
#    define HU_OS_WINDOWS 1
#endif

#if HU_OS_ANDROID_P
#    define HU_OS_ANDROID 1
#endif

#if HU_OS_LINUX_P + HU_OS_FREEBSD_P + HU_OS_OPENBSD_P + HU_OS_DRAGONFLY_P +    \
    HU_OS_NETBSD_P + HU_OS_OSX_P + HU_OS_IOS_P + HU_OS_WINDOWS_P +             \
    HU_OS_ANDROID_P !=                                                         \
  1
#    error "BUG: HU_OS_*_P not properly defined"
#endif

#endif
