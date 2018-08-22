//-----------------------------------------------------------------------------
// MurmurHash3 was written by Austin Appleby, and is placed in the
// public domain. The author hereby disclaims copyright to this source
// code.

#ifndef _MURMURHASH3_H_
#define _MURMURHASH3_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------

uint32_t murmur3_x86_32 (const void *key, int len, uint32_t seed);

void MurmurHash3_x86_128(const void *key, int len, uint32_t seed, void *out);

void MurmurHash3_x64_128(const void *key, int len, uint32_t seed, void *out);

uint64_t murmur3_x64_64(const void *key, int len, uint32_t seed);

//-----------------------------------------------------------------------------

#endif // _MURMURHASH3_H_
