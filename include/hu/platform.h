#pragma once

#define HU_GNULIKE_P 0

#define HU_BITS_32 1
#define HU_BITS_32_P 0
#define HU_BITS_64_P 0

#define HU_OS_LINUX_P 0
#define HU_OS_WINDOWS_P 0
#define HU_OS_MAC_P 0
#define HU_OS_BSD_P 0
#define HU_OS_POSIX_P 0

#if defined(__x86_64__) || defined(__ppc64__)
#undef HU_BITS_32_P
#undef HU_BITS_64_P
#undef HU_BITS_32
#define HU_BITS_32_P 0
#define HU_BITS_64_P 1
#define HU_BITS_64 1
#endif

#ifdef __linux__
#define HU_OS_LINUX 1
#undef HU_OS_LINUX_P
#define HU_OS_LINUX_P 1
#endif

#ifdef _WIN32
#define HU_OS_WINDOWS 1
#undef HU_OS_WINDOWS_P
#define HU_OS_WINDOWS_P 1
#undef HU_BITS_32
#undef HU_BITS_32_P
#undef HU_BITS_64_P
#ifdef _WIN64
#define HU_BITS_32_P 0
#define HU_BITS_64_P 1
#define HU_BITS_64 1
#else // _WIN64
#define HU_BITS_32_P 1
#define HU_BITS_64_P 0
#define HU_BITS_32 1
#endif // _WIN64
#endif

#ifdef __APPLE__
#define HU_OS_MAC 1
#undef HU_OS_MAC_P
#define HU_OS_MAC_P 1
#endif

#ifdef __FreeBSD__
#undef HU_OS_BSD
#define HU_OS_BSD 1
#define HU_OS_BSD_P 1
#endif

#ifdef _POSIX_VERSION
#define HU_OS_POSIX 1
#undef HU_OS_POSIX_P
#define HU_OS_POSIX_P 1
#endif

#ifdef __GNUC__
#define HU_GNULIKE 1
#undef HU_GNULIKE_P
#define HU_GNULIKE_P 1
#endif

#ifdef __cplusplus__
#define HU_CXX 1
#define HU_CXX_P 1
#if __cplusplus__ > 199711L
#define HU_CXX_11 1
#define HU_CXX_11_P 1
#else
#define HU_CXX_11_P 0
#endif
#else
#define HU_CXX_P 0
#define HU_CXX_11_P 0
#endif

#ifdef HU_CXX_11
static_assert((sizeof(void *) == 4) == HU_BITS_32_P, "HU_BITS_32_P inconsistent!");
static_assert((sizeof(void *) == 8) == HU_BITS_64_P, "HU_BITS_64_P inconsistent!");
#endif
