#ifndef HU_ARCH_H
#define HU_ARCH_H

#define HU_ARCH_X86_P 0
#define HU_ARCH_ARM_P 0
#define HU_ARCH_MIPS_P 0
#define HU_ARCH_PPC_P 0

#if defined(__x86_64__) || defined(__amd64__) || defined(_M_AMD64) ||          \
  defined(_M_X64)
#    undef HU_ARCH_X86_P
#    define HU_ARCH_X86_P 1
#    define HU_INTERNAL_BITS 64
#endif

#if defined(__i386__) || defined(__i386) || defined(_M_IX86) ||                \
  defined(__X86__) || defined(_X86_) || defined(__I86__)
#    undef HU_ARCH_X86_P
#    define HU_ARCH_X86_P 1
#    ifndef HU_INTERNAL_BITS
#        define HU_INTERNAL_BITS 32
#    endif
#endif

#ifdef __aarch64__
#    undef HU_ARCH_ARM_P
#    define HU_ARCH_ARM_P 1
#    ifndef HU_INTERNAL_BITS
#        define HU_INTERNAL_BITS 64
#    endif
#endif

#if defined(__arm__) || defined(__thumb__) || defined(_M_ARM) ||               \
  defined(_M_ARMT)
#    undef HU_ARCH_ARM_P
#    define HU_ARCH_ARM_P 1
#    ifndef HU_INTERNAL_BITS
#        define HU_INTERNAL_BITS 32
#    endif
#endif

#if defined(__mips__) || defined(__mips) || defined(__MIPS__) ||               \
  defined(__mips64)
#    undef HU_ARCH_MIPS_P
#    define HU_ARCH_MIPS_P 1
#    ifndef HU_INTERNAL_BITS
#        if (defined(__mips) && __mips == 64) || defined(__mips64)
#            define HU_INTERNAL_BITS 64
#        endif
#    endif
#endif

#if defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) ||    \
  defined(__ppc) || defined(__ppc__) || defined(__ppc64__) ||                  \
  defined(_M_PPC) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) ||             \
  defined(__PPC__) || defined(__PPC64__)
#    undef HU_ARCH_PPC_P
#    define HU_ARCH_PPC_P 1
#    ifndef HU_INTERNAL_BITS
#        if defined(__powerpc64__) || defined(__ppc64__) ||                    \
          defined(__PPC64__) || defined(_ARCH_PPC64)
#            define HU_INTERNAL_BITS 64
#        elif defined(__GNUC__)
#            define HU_INTERNAL_BITS 32
#        endif
#    endif
#endif

#if HU_ARCH_X86_P
#    define HU_ARCH_X86 1
#endif

#if HU_ARCH_ARM_P
#    define HU_ARCH_ARM 1
#endif

#if HU_ARCH_MIPS_P
#    define HU_ARCH_MIPS 1
#endif

#if HU_ARCH_PPC_P
#    define HU_ARCH_PPC 1
#endif

#if HU_ARCH_X86_P + HU_ARCH_ARM_P + HU_ARCH_MIPS_P + HU_ARCH_PPC_P != 1
#    error "BUG: HU_ARCH_*_P not properly defined"
#endif

#endif
