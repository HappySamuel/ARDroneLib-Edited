
#ifndef __INTRIN__H__
#define __INTRIN__H__

#include <VP_Os/vp_os_types.h>

// #undef always_inline
#if defined(__GNUC__)

static INLINE uint32_t _byteswap_ulong(uint32_t value)
{
  int32_t tmp;

  __asm __volatile(
    "eor %1, %2, %2, ror #16\n"
    "bic %1, %1, #0x00ff0000\n"
    "mov %0, %2, ror #8\n"
    "eor %0, %0, %1, lsr #8"
    : "=r" (value), "=r" (tmp)
    : "r" (value)
  );

  return value;
}

#define clz __builtin_clz
#define bswap _byteswap_ulong

#endif // __GNUC__

#endif // ! __INTRIN__H__
