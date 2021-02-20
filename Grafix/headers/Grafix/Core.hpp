#pragma once

#ifdef DEBUG
    #define GF_ASSERT(x, ...) { if(!(x)) { GF_ERROR("Assertion failed: {0}", __VA_ARGS__); __asm__("int $3"); }}
    #define GF_CORE_ASSERT(x, ...) { if(!(x)) { GF_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __asm__("int $3"); }}
#else
    #define GF_ASSERT(x, ...)
    #define GF_CORE_ASSERT(x, ...)
#endif