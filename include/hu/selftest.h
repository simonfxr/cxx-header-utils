#ifndef HU_SELFTEST_H
#define HU_SELFTEST_H

#include <hu.h>

#if HU_BITS_32_P == 32
HU_STATIC_ASSERT(sizeof(void *) == 4);
#elif HU_BITS_64_P
HU_STATIC_ASSERT(sizeof(void *) == 8);
#endif

#if HU_DATA_MODEL_ILP32_P
HU_STATIC_ASSERT(HU_BITS_32_P);
HU_STATIC_ASSERT(sizeof(int) == 4);
HU_STATIC_ASSERT(sizeof(long) == 4);
HU_STATIC_ASSERT(sizeof(long long) == 8);
#elif HU_DATA_MODEL_LP64_P
HU_STATIC_ASSERT(HU_BITS_64_P);
HU_STATIC_ASSERT(sizeof(int) == 4);
HU_STATIC_ASSERT(sizeof(long) == 8);
HU_STATIC_ASSERT(sizeof(long long) == 8);
#elif HU_DATA_MODEL_LLP64_P
HU_STATIC_ASSERT(HU_BITS_64_P);
HU_STATIC_ASSERT(sizeof(int) == 4);
HU_STATIC_ASSERT(sizeof(long) == 4);
HU_STATIC_ASSERT(sizeof(long long) == 8);
#endif

HU_STATIC_ASSERT(HU_SIZEOF_PTR * 8 == HU_BITS);
HU_STATIC_ASSERT(HU_SIZEOF_INT == sizeof(int));
HU_STATIC_ASSERT(HU_SIZEOF_LONG == sizeof(long));
HU_STATIC_ASSERT(HU_SIZEOF_LONGLONG == sizeof(long long));

#if HU_ARCH_X86_P
HU_STATIC_ASSERT(HU_LITTLE_ENDIAN_P);
#endif

#if HU_OS_LINUX_P
HU_STATIC_ASSERT(HU_OBJFMT_ELF_P);
#elif HU_OS_MAC_P
HU_STATIC_ASSERT(HU_OBJFMT_MACHO_P);
#endif

#endif
