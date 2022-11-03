/**
 *--------------------------------------------
 * CoreDefines.h <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#pragma once

#ifndef SM_PLATFORM_WINDOWS
	#define SM_PLATFORM_WINDOWS         0
#endif // SM_PLATFORM_WINDOWS
#ifndef SM_PLATFORM_LINUX
	#define SM_PLATFORM_LINUX           0
#endif // SM_PLATFORM_LINUX
#ifndef SM_PLATFORM_MACOS
	#define SM_PLATFORM_MACOS           0
#endif // SM_PLATFORM_MACOS

#if !SM_PLATFORM_WINDOWS && !SM_PLATFORM_LINUX && !SM_PLATFORM_MACOS
	#error Unknown or unsupported platform! Spearmint currently only supports Windows.
#endif // !SM_PLATFORM_WINDOWS && !SM_PLATFORM_LINUX && !SM_PLATFORM_MACOS

#ifdef _MSC_BUILD
	#define SM_COMPILER_MSVC            1
#endif // _MSC_BUILD

#ifdef __clang__
	#define SM_COMPILER_CLANG           1
	#define SM_COMPILER_CLANG_GCC       1
#endif // __clang__

#ifdef __gcc__
	#define SM_COMPILER_GCC             1
	#define SM_COMPILER_CLANG_GCC       1
#endif // __gcc__

#ifndef SM_COMPILER_MSVC
	#define SM_COMPILER_MSVC            0
#endif // SM_COMPILER_MSVC
#ifndef SM_COMPILER_CLANG
	#define SM_COMPILER_CLANG           0
#endif // SM_COMPILER_CLANG
#ifndef SM_COMPILER_GCC
	#define SM_COMPILER_GCC             0
#endif // SM_COMPILER_GCC
#ifndef SM_COMPILER_CLANG_GCC
	#define SM_COMPILER_CLANG_GCC       0
#endif // SM_COMPILER_CLANG_GCC

#if !SM_COMPILER_MSVC && !SM_COMPILER_CLANG && !SM_COMPILER_GCC
	#error Unknown or unsupported compiler. Spearmint only supports MSVC, Clang and GCC.
#endif // !SM_COMPILER_MSVC && !SM_COMPILER_CLANG && !SM_COMPILER_GCC

#ifndef SM_CONFIGURATION_DEBUG
	#define SM_CONFIGURATION_DEBUG      0
#endif // SM_CONFIGURATION_DEBUG
#ifndef SM_CONFIGURATION_RELEASE
	#define SM_CONFIGURATION_RELEASE    0
#endif // SM_CONFIGURATION_RELEASE

#if !SM_CONFIGURATION_DEBUG && !SM_CONFIGURATION_RELEASE
	#error Unknown build configuration. You must define SM_CONFIGURATION_DEBUG=1 or SM_CONFIGURATION_RELEASE=1.
#endif // !SM_CONFIGURATION_DEBUG && !SM_CONFIGURATION_RELEASE

#if SM_COMPILER_MSVC
	#define SM_DEBUGBREAK __debugbreak()
	#define SM_INLINE     __forceinline
	#define SM_FUNCTION   __FUNCSIG__
#elif SM_COMPILER_CLANG_GCC
	#define SM_DEBUGBREAK __builtin_trap
	#define SM_INLINE     inline
	#define SM_FUNCTION   __PRETTY_FUNCTION__
#endif

#define SM_FILE         __FILE__
#define SM_LINE         __LINE__
#define SM_DATE         __DATE__

#define SM_NODISCARD    [[nodiscard]]
#define SM_MAYBE_UNUSED [[maybe_unused]]
#define SM_LIKELY       [[likely]]
#define SM_UNLIKELY     [[unlikely]]

#define internal static
#define out

#define ArrayCount(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))
#define Bit(X) (1 << (X))