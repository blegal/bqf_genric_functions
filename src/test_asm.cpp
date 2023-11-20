
//              Copyright Catch2 Authors
// Distributed under the Boost Software License, Version 1.0.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.boost.org/LICENSE_1_0.txt)

// SPDX-License-Identifier: BSL-1.0

// 010-TestCase.cpp
// And write tests in the same file:
#include "catch_amalgamated.hpp"
#include "./functions/functions.hpp"
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
uint64_t rand_uint64(void) {
  uint64_t r = 0;
  for (int i=0; i<64; i += 15 /*30*/) {
    r = r*((uint64_t)RAND_MAX + 1) + rand();
  }
  return r;
}
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
#if defined(__SSE4_2__)
TEST_CASE( "Test pdep_u32_c function", "[pdep_u32_c]" )
{
    for(int i = 0; i < 65536; i += 1)
    {
        const uint32_t a = rand_uint64();
        const uint32_t b = rand_uint64() % 64;
        REQUIRE( pdep_u32_c(a, b) == pdep_u32_builtin(a, b) );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test pdep_u64_c function", "[pdep_u64_c]" )
{
    for(int i = 0; i < 65536; i += 1)
    {
        const uint64_t a = rand_uint64();
        const uint64_t b = rand_uint64() % 64;
        REQUIRE( pdep_u64_c(a, b) == pdep_u64_builtin(a, b) );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test pdep_u64_x86/builtin function", "[pdep_u64_x86/builtin]" )
{
    for(int i = 0; i < 65536; i += 1)
    {
        const uint64_t a = rand_uint64();
        const uint64_t b = rand_uint64() % 64;
        REQUIRE( pdep_u64_x86(a, b) == pdep_u64_builtin(a, b) );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test pdep_u64_x86/c function", "[pdep_u64_x86/c]" )
{
    for(int i = 0; i < 65536; i += 1)
    {
        const uint64_t a = rand_uint64();
        const uint64_t b = rand_uint64() % 64;
        REQUIRE( pdep_u64_x86(a, b) == pdep_u32_c(a, b) );
    }
}
#endif
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
TEST_CASE( "Test tzcnt_u32_c function", "[tzcnt_u32_c]" )
{
    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = (1 << i);
        REQUIRE( tzcnt_u32_c(v) == i );
    }
}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
TEST_CASE( "Test tzcnt_u64_c function", "[tzcnt_u64_c]" )
{
    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = (1ULL << i);
        REQUIRE( tzcnt_u64_c(v) == i );
    }
}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test tzcnt_u32_builtin function", "[tzcnt_u32_builtin]" )
{
    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = (1 << i);
        REQUIRE( tzcnt_u32_builtin(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test tzcnt_u64_builtin function", "[tzcnt_u64_builtin]" )
{
    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = (1ULL << i);
        REQUIRE( tzcnt_u64_builtin(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test tzcnt_u32_x86 function", "[tzcnt_u32_x86]" )
{
    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = (1 << i);
        REQUIRE( tzcnt_u32_x86(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test tzcnt_u64_x86 function", "[tzcnt_u64_x86]" )
{
    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = (1ULL << i);
        REQUIRE( tzcnt_u64_x86(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__aarch64__) || defined(_M_ARM64)
TEST_CASE( "Test tzcnt_u32_neon function", "[tzcnt_u32_neon]" )
{
    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = (1 << i);
        REQUIRE( tzcnt_u32_arm(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__aarch64__) || defined(_M_ARM64)
TEST_CASE( "Test tzcnt_u64_neon function", "[tzcnt_u64_neon]" )
{
    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = (1ULL << i);
        REQUIRE( tzcnt_u64_arm(v) == i );
    }
}
#endif
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
TEST_CASE( "Test popcount_u32_c function", "[popcount_u32_c]" )
{
    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = (1 << i);
        REQUIRE( popcount_u32_c(v) == 1 );
    }

    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = ((1 << i) - 1);
        REQUIRE( popcount_u32_c(v) == i );
    }
}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
TEST_CASE( "Test popcount_u64_c function", "[popcount_u64_c]" )
{
    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = (1ULL << i);
        REQUIRE( popcount_u64_c(v) == 1 );
    }

    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = ((1ULL << i) - 1);
        REQUIRE( popcount_u64_c(v) == i );
    }
}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test popcount_u32_x86 function", "[popcount_u32_x86]" )
{
    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = (1 << i);
        REQUIRE( popcount_u32_x86(v) == 1 );
    }

    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = ((1 << i) - 1);
        REQUIRE( popcount_u32_x86(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test popcount_u64_x86 function", "[popcount_u64_x86]" )
{
    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = (1ULL << i);
        REQUIRE( popcount_u64_x86(v) == 1 );
    }

    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = ((1ULL << i) - 1);
        REQUIRE( popcount_u64_x86(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__aarch64__) || defined(_M_ARM64)
TEST_CASE( "Test popcount_u32_arm function", "[popcount_u32_arm]" )
{
    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = (1 << i);
        REQUIRE( popcount_u32_arm(v) == 1 );
    }

    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = ((1 << i) - 1);
        REQUIRE( popcount_u32_arm(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__aarch64__) || defined(_M_ARM64)
TEST_CASE( "Test popcount_u64_arm function", "[popcount_u64_arm]" )
{
    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = (1ULL << i);
        REQUIRE( popcount_u64_arm(v) == 1 );
    }

    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = ((1ULL << i) - 1);
        REQUIRE( popcount_u64_arm(v) == i );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
TEST_CASE( "Test popcount_u32_builtin function", "[popcount_u32_builtin]" )
{
   for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = (1 << i);
        REQUIRE( popcount_u32_builtin(v) == 1 );
    }

    for(int i = 0; i < 32; i += 1)
    {
        const uint32_t v = ((1 << i) - 1);
        REQUIRE( popcount_u32_builtin(v) == i );
    }
}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
TEST_CASE( "Test popcount_u64_builtin function", "[popcount_u64_builtin]" )
{
    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = (1ULL << i);
        REQUIRE( popcount_u64_builtin(v) == 1 );
    }

    for(int i = 0; i < 64; i += 1)
    {
        const uint64_t v = ((1ULL << i) - 1);
        REQUIRE( popcount_u64_builtin(v) == i );
    }
}
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
#if defined(__SSE4_2__)
TEST_CASE( "Test bitrankasm_u64_x86 function", "[bitrankasm_u64_x86]" )
{
    for(int i = 0; i < 1024; i += 1)
    {
        const uint32_t a = rand_uint64();
        const uint32_t b = rand_uint64() % 64;
        REQUIRE( bitrankasm_u64_x86(a, b) == bitrankasm_u64_c(a, b) );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test bitrankasm_u64_builtin/x86 function", "[bitrankasm_u64_builtin/x86]" )
{
    for(int i = 0; i < 1024; i += 1)
    {
        const uint32_t a = rand_uint64();
        const uint32_t b = rand_uint64() % 64;
        REQUIRE( bitrankasm_u64_builtin(a, b) == bitrankasm_u64_x86(a, b) );
    }
}
#endif
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
#if defined(__SSE4_2__)
TEST_CASE( "Test bitselectasm_u64_x86/c function", "[bitselectasm_u64_x86/c]" )
{
    for(int i = 0; i < 65536; i += 1)
    {
        const uint64_t a = rand_uint64();
        const uint64_t b = rand_uint64() % 64;
        REQUIRE( bitselectasm_u64_x86(a, b) == bitselectasm_u64_c(a, b) );

    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test bitselectasm_u64_x86/builtin function", "[bitselectasm_u64_x86/builtin]" )
{
    for(int i = 0; i < 65536; i += 1)
    {
        const uint64_t a = rand_uint64();
        const uint64_t b = rand_uint64() % 64;
        REQUIRE( bitselectasm_u64_x86(a, b) == bitselectasm_u64_builtin(a, b) );

    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__SSE4_2__)
TEST_CASE( "Test bitrankasm_u64_builtin/c function", "[bitrankasm_u64_builtin/c]" )
{
    for(int i = 0; i < 65536; i += 1)
    {
        const uint64_t a = rand_uint64();
        const uint64_t b = rand_uint64() % 64;
        REQUIRE( bitselectasm_u64_builtin(a, b) == bitselectasm_u64_c(a, b) );
    }
}
#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(__aarch64__) || defined(_M_ARM64)
TEST_CASE( "Test bitrankasm_u64_arm/c function", "[bitrankasm_u64_arm/c]" )
{
    for(int i = 0; i < 65536; i += 1)
    {
        const uint64_t a = rand_uint64();
        const uint64_t b = rand_uint64() % 64;
        REQUIRE( bitselectasm_u64_arm(a, b) == bitselectasm_u64_c(a, b) );
    }
}
#endif
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
