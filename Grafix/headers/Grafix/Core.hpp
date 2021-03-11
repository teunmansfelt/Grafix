#pragma once

#ifdef DEBUG
    #define GFX_DEBUG(x) x
#else
    #define GFX_DEBUG(x)
#endif

#ifdef DEBUG
    #define GFX_ASSERT(x, ...) { if(!(x)) { GFX_ERROR("Assertion failed: {0}", __VA_ARGS__); __asm__("int $3"); }}
    #define GFX_CORE_ASSERT(x, ...) { if(!(x)) { GFX_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __asm__("int $3"); }}
#else
    #define GFX_ASSERT(x, ...)
    #define GFX_CORE_ASSERT(x, ...)
#endif

#define GFX_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)