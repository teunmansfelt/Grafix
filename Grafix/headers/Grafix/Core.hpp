#pragma once

#ifdef DEBUG
    #define GF_DEBUG(x) x
#else
    #define GF_DEBUG(x)
#endif

#ifdef DEBUG
    #define GF_ASSERT(x, ...) { if(!(x)) { GF_ERROR("Assertion failed: {0}", __VA_ARGS__); __asm__("int $3"); }}
    #define GF_CORE_ASSERT(x, ...) { if(!(x)) { GF_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __asm__("int $3"); }}
#else
    #define GF_ASSERT(x, ...)
    #define GF_CORE_ASSERT(x, ...)
#endif

#define GF_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)