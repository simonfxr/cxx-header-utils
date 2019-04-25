#ifndef HU_OBJFMT_H
#define HU_OBJFMT_H

#ifndef HU_AMALGAMATED
#    include <hu/os.h>
#endif

#define HU_OBJFMT_ELF_P 0
#define HU_OBJFMT_MACHO_P 0
#define HU_OBJFMT_PE_P 0

#ifdef __ELF__
#    undef HU_OBJFMT_ELF_P
#    define HU_OBJFMT_ELF_P 1
#endif

#ifdef __MACH__
#    undef HU_OBJFMT_MACHO_P
#    define HU_OBJFMT_MACHO_P 1
#endif

#if HU_OS_WINDOWS_P
#    undef HU_OBJFMT_PE_P
#    define HU_OBJFMT_PE_P 1
#endif

#if HU_OBJFMT_ELF_P
#    define HU_OBJFMT_ELF 1
#endif

#if HU_OBJFMT_MACHO_P
#    define HU_OBJFMT_MACHO 1
#endif

#if HU_OBJFMT_PE_P
#    define HU_OBJFMT_PE 1
#endif

#if (HU_OBJFMT_ELF_P + HU_OBJFMT_MACHO_P + HU_OBJFMT_PE_P) != 1
#    error "BUG: HU_OBJFMT_*_P not properly detected"
#endif

#endif
