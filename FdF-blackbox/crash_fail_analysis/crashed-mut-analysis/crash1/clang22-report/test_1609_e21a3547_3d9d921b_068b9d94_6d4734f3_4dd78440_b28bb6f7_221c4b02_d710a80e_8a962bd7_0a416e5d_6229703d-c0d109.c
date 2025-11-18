# 1 "<built-in>"
# 1 "test_1609_e21a3547_3d9d921b_068b9d94_6d4734f3_4dd78440_b28bb6f7_221c4b02_d710a80e_8a962bd7_0a416e5d_6229703d.c"
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdint.h expanded by -frewrite-includes */
#include <stdint.h>
#else /* stdint.h expanded by -frewrite-includes */
# 1 "test_1609_e21a3547_3d9d921b_068b9d94_6d4734f3_4dd78440_b28bb6f7_221c4b02_d710a80e_8a962bd7_0a416e5d_6229703d.c"
# 1 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 1 3
/*===---- stdint.h - Standard header for sized integer types --------------===*\
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
\*===----------------------------------------------------------------------===*/

#ifndef __CLANG_STDINT_H
// AIX system headers need stdint.h to be re-enterable while _STD_TYPES_T
// is defined until an inclusion of it without _STD_TYPES_T occurs, in which
// case the header guard macro is defined.
#if 0 /* disabled by -frewrite-includes */
#if !defined(_AIX) || !defined(_STD_TYPES_T) || !defined(__STDC_HOSTED__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 14 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#define __CLANG_STDINT_H
#endif
# 16 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#if 0 /* disabled by -frewrite-includes */
#if defined(__MVS__) && __has_include_next(<stdint.h>)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 18 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#if 0 /* expanded by -frewrite-includes */
#include_next <stdint.h>
#endif /* expanded by -frewrite-includes */
# 18 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# 19 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#else
# 20 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* If we're hosted, fall back to the system's stdint.h, which might have
 * additional definitions.
 */
#if 0 /* disabled by -frewrite-includes */
#if __STDC_HOSTED__ && __has_include_next(<stdint.h>)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 25 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

// C99 7.18.3 Limits of other integer types
//
//  Footnote 219, 220: C++ implementations should define these macros only when
//  __STDC_LIMIT_MACROS is defined before <stdint.h> is included.
//
//  Footnote 222: C++ implementations should define these macros only when
//  __STDC_CONSTANT_MACROS is defined before <stdint.h> is included.
//
// C++11 [cstdint.syn]p2:
//
//  The macros defined by <cstdint> are provided unconditionally. In particular,
//  the symbols __STDC_LIMIT_MACROS and __STDC_CONSTANT_MACROS (mentioned in
//  footnotes 219, 220, and 222 in the C standard) play no role in C++.
//
// C11 removed the problematic footnotes.
//
// Work around this inconsistency by always defining those macros in C++ mode,
// so that a C library implementation which follows the C99 standard can be
// used in C++.
# ifdef __cplusplus
#if 0 /* disabled by -frewrite-includes */
#  if !defined(__STDC_LIMIT_MACROS)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 47 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#   define __STDC_LIMIT_MACROS
#   define __STDC_LIMIT_MACROS_DEFINED_BY_CLANG
#  endif
# 50 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#if 0 /* disabled by -frewrite-includes */
#  if !defined(__STDC_CONSTANT_MACROS)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 51 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#   define __STDC_CONSTANT_MACROS
#   define __STDC_CONSTANT_MACROS_DEFINED_BY_CLANG
#  endif
# 54 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# endif
# 55 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdint.h expanded by -frewrite-includes */
# include_next <stdint.h>
#else /* stdint.h expanded by -frewrite-includes */
# 56 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# 1 "/usr/include/stdint.h" 1 3 4
/* Copyright (C) 1997-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99: 7.18 Integer types <stdint.h>
 */

#ifndef _STDINT_H
#define _STDINT_H	1

#define __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* libc-header-start.h expanded by -frewrite-includes */
#include <bits/libc-header-start.h>
#else /* libc-header-start.h expanded by -frewrite-includes */
# 26 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
/* Handle feature test macros at the start of a header.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included.  */

#ifndef __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
# error "Never include <bits/libc-header-start.h> directly."
#endif
# 30 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

#undef __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION

#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* features.h expanded by -frewrite-includes */
#include <features.h>
#else /* features.h expanded by -frewrite-includes */
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef	_FEATURES_H
#define	_FEATURES_H	1

/* These are defined by the user (or the compiler)
   to specify the desired environment:

   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   _ISOC2X_SOURCE	Extensions to ISO C99 from ISO C2X.
   __STDC_WANT_LIB_EXT2__
			Extensions to ISO C99 from TR 27431-2:2010.
   __STDC_WANT_IEC_60559_BFP_EXT__
			Extensions to ISO C11 from TS 18661-1:2014.
   __STDC_WANT_IEC_60559_FUNCS_EXT__
			Extensions to ISO C11 from TS 18661-4:2015.
   __STDC_WANT_IEC_60559_TYPES_EXT__
			Extensions to ISO C11 from TS 18661-3:2015.
   __STDC_WANT_IEC_60559_EXT__
			ISO C2X interfaces defined only in Annex F.

   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _ATFILE_SOURCE	Additional *at interfaces.
   _DYNAMIC_STACK_SIZE_SOURCE Select correct (but non compile-time constant)
			MINSIGSTKSZ, SIGSTKSZ and PTHREAD_STACK_MIN.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _DEFAULT_SOURCE	The default set of features (taking precedence over
			__STRICT_ANSI__).

   _FORTIFY_SOURCE	Add security hardening to many library functions.
			Set to 1 or 2; 2 performs stricter checks than 1.

   _REENTRANT, _THREAD_SAFE
			Obsolete; equivalent to _POSIX_C_SOURCE=199506L.

   The `-ansi' switch to the GNU C compiler, and standards conformance
   options such as `-std=c99', define __STRICT_ANSI__.  If none of
   these are defined, or if _DEFAULT_SOURCE is defined, the default is
   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200809L, as well as enabling miscellaneous functions from BSD and
   SVID.  If more than one of these are defined, they accumulate.  For
   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
   give you ISO C, 1003.1, and 1003.2, but nothing else.

   These are defined by this file and are used by the
   header files to decide what to declare or define:

   __GLIBC_USE (F)	Define things from feature set F.  This is defined
			to 1 or 0; the subsequent macros are either defined
			or undefined, and those tests should be moved to
			__GLIBC_USE.
   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_ISOCXX11	Define ISO C++11 things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_MISC		Define things from 4.3BSD or System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_DYNAMIC_STACK_SIZE Define correct (but non compile-time constant)
			MINSIGSTKSZ, SIGSTKSZ and PTHREAD_STACK_MIN.
   __USE_GNU		Define GNU extensions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.

   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.

   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.

   ISO C feature test macros depend on the definition of the macro
   when an affected header is included, not when the first system
   header is included, and so they are handled in
   <bits/libc-header-start.h>, which does not have a multiple include
   guard.  Feature test macros that can be handled from the first
   system header included are handled here.  */


/* Undefine everything, so we get a clean slate.  */
#undef	__USE_ISOC11
#undef	__USE_ISOC99
#undef	__USE_ISOC95
#undef	__USE_ISOCXX11
#undef	__USE_POSIX
#undef	__USE_POSIX2
#undef	__USE_POSIX199309
#undef	__USE_POSIX199506
#undef	__USE_XOPEN
#undef	__USE_XOPEN_EXTENDED
#undef	__USE_UNIX98
#undef	__USE_XOPEN2K
#undef	__USE_XOPEN2KXSI
#undef	__USE_XOPEN2K8
#undef	__USE_XOPEN2K8XSI
#undef	__USE_LARGEFILE
#undef	__USE_LARGEFILE64
#undef	__USE_FILE_OFFSET64
#undef	__USE_MISC
#undef	__USE_ATFILE
#undef	__USE_DYNAMIC_STACK_SIZE
#undef	__USE_GNU
#undef	__USE_FORTIFY_LEVEL
#undef	__KERNEL_STRICT_NAMES
#undef	__GLIBC_USE_ISOC2X
#undef	__GLIBC_USE_DEPRECATED_GETS
#undef	__GLIBC_USE_DEPRECATED_SCANF

/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */
#ifndef _LOOSE_KERNEL_NAMES
# define __KERNEL_STRICT_NAMES
#endif
# 159 "/usr/include/features.h" 3 4

/* Convenience macro to test the version of gcc.
   Use like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was
   added in 2.0.  */
#if 0 /* disabled by -frewrite-includes */
#if defined __GNUC__ && defined __GNUC_MINOR__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 168 "/usr/include/features.h" 3 4
# define __GNUC_PREREQ(maj, min) \
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# 171 "/usr/include/features.h" 3 4
# define __GNUC_PREREQ(maj, min) 0
#endif
# 173 "/usr/include/features.h" 3 4

/* Similarly for clang.  Features added to GCC after version 4.2 may
   or may not also be available in clang, and clang's definitions of
   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such
   features can be queried via __has_extension/__has_feature.  */
#if 0 /* disabled by -frewrite-includes */
#if defined __clang_major__ && defined __clang_minor__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 179 "/usr/include/features.h" 3 4
# define __glibc_clang_prereq(maj, min) \
  ((__clang_major__ << 16) + __clang_minor__ >= ((maj) << 16) + (min))
#else
# 182 "/usr/include/features.h" 3 4
# define __glibc_clang_prereq(maj, min) 0
#endif
# 184 "/usr/include/features.h" 3 4

/* Whether to use feature set F.  */
#define __GLIBC_USE(F)	__GLIBC_USE_ ## F

/* _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
   issue a warning; the expectation is that the source is being
   transitioned to use the new macro.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined _BSD_SOURCE || defined _SVID_SOURCE) \
    && !defined _DEFAULT_SOURCE
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 194 "/usr/include/features.h" 3 4
# warning "_BSD_SOURCE and _SVID_SOURCE are deprecated, use _DEFAULT_SOURCE"
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
# 198 "/usr/include/features.h" 3 4

/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
#ifdef _GNU_SOURCE
# undef  _ISOC95_SOURCE
# define _ISOC95_SOURCE	1
# undef  _ISOC99_SOURCE
# define _ISOC99_SOURCE	1
# undef  _ISOC11_SOURCE
# define _ISOC11_SOURCE	1
# undef  _ISOC2X_SOURCE
# define _ISOC2X_SOURCE	1
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
# undef  _XOPEN_SOURCE
# define _XOPEN_SOURCE	700
# undef  _XOPEN_SOURCE_EXTENDED
# define _XOPEN_SOURCE_EXTENDED	1
# undef	 _LARGEFILE64_SOURCE
# define _LARGEFILE64_SOURCE	1
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
# undef  _DYNAMIC_STACK_SIZE_SOURCE
# define _DYNAMIC_STACK_SIZE_SOURCE 1
#endif
# 226 "/usr/include/features.h" 3 4

/* If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
   define _DEFAULT_SOURCE.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined _DEFAULT_SOURCE					\
     || (!defined __STRICT_ANSI__				\
	 && !defined _ISOC99_SOURCE && !defined _ISOC11_SOURCE	\
	 && !defined _ISOC2X_SOURCE				\
	 && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE	\
	 && !defined _XOPEN_SOURCE))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 235 "/usr/include/features.h" 3 4
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
# 238 "/usr/include/features.h" 3 4

/* This is to enable the ISO C2X extension.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined _ISOC2X_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ > 201710L))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 242 "/usr/include/features.h" 3 4
# define __GLIBC_USE_ISOC2X	1
#else
# 244 "/usr/include/features.h" 3 4
# define __GLIBC_USE_ISOC2X	0
#endif
# 246 "/usr/include/features.h" 3 4

/* This is to enable the ISO C11 extension.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined _ISOC11_SOURCE || defined _ISOC2X_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 250 "/usr/include/features.h" 3 4
# define __USE_ISOC11	1
#endif
# 252 "/usr/include/features.h" 3 4

/* This is to enable the ISO C99 extension.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE			\
     || defined _ISOC2X_SOURCE						\
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 257 "/usr/include/features.h" 3 4
# define __USE_ISOC99	1
#endif
# 259 "/usr/include/features.h" 3 4

/* This is to enable the ISO C90 Amendment 1:1995 extension.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE			\
     || defined _ISOC2X_SOURCE						\
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199409L))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 264 "/usr/include/features.h" 3 4
# define __USE_ISOC95	1
#endif
# 266 "/usr/include/features.h" 3 4

#ifdef __cplusplus
/* This is to enable compatibility for ISO C++17.  */
#if 0 /* disabled by -frewrite-includes */
# if __cplusplus >= 201703L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 270 "/usr/include/features.h" 3 4
#  define __USE_ISOC11	1
# endif
# 272 "/usr/include/features.h" 3 4
/* This is to enable compatibility for ISO C++11.
   Check the temporary macro for now, too.  */
#if 0 /* disabled by -frewrite-includes */
# if __cplusplus >= 201103L || defined __GXX_EXPERIMENTAL_CXX0X__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 275 "/usr/include/features.h" 3 4
#  define __USE_ISOCXX11	1
#  define __USE_ISOC99	1
# endif
# 278 "/usr/include/features.h" 3 4
#endif
# 279 "/usr/include/features.h" 3 4

/* If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE
   is defined, use POSIX.1-2008 (or another version depending on
   _XOPEN_SOURCE).  */
#ifdef _DEFAULT_SOURCE
#if 0 /* disabled by -frewrite-includes */
# if !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 285 "/usr/include/features.h" 3 4
#  define __USE_POSIX_IMPLICITLY	1
# endif
# 287 "/usr/include/features.h" 3 4
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
#endif
# 292 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if ((!defined __STRICT_ANSI__					\
      || (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500))	\
     && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 296 "/usr/include/features.h" 3 4
# define _POSIX_SOURCE	1
#if 0 /* disabled by -frewrite-includes */
# if defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 500
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 298 "/usr/include/features.h" 3 4
#  define _POSIX_C_SOURCE	2
#if 0 /* disabled by -frewrite-includes */
#if 0
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 600
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 300 "/usr/include/features.h" 3 4
#  define _POSIX_C_SOURCE	199506L
#if 0 /* disabled by -frewrite-includes */
#if 0
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 700
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 302 "/usr/include/features.h" 3 4
#  define _POSIX_C_SOURCE	200112L
# else
# 304 "/usr/include/features.h" 3 4
#  define _POSIX_C_SOURCE	200809L
# endif
# 306 "/usr/include/features.h" 3 4
# define __USE_POSIX_IMPLICITLY	1
#endif
# 308 "/usr/include/features.h" 3 4

/* Some C libraries once required _REENTRANT and/or _THREAD_SAFE to be
   defined in all multithreaded code.  GNU libc has not required this
   for many years.  We now treat them as compatibility synonyms for
   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with
   comprehensive support for multithreaded code.  Using them never
   lowers the selected level of POSIX conformance, only raises it.  */
#if 0 /* disabled by -frewrite-includes */
#if ((!defined _POSIX_C_SOURCE || (_POSIX_C_SOURCE - 0) < 199506L) \
     && (defined _REENTRANT || defined _THREAD_SAFE))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 317 "/usr/include/features.h" 3 4
# define _POSIX_SOURCE   1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 199506L
#endif
# 321 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if (defined _POSIX_SOURCE					\
     || (defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 1)	\
     || defined _XOPEN_SOURCE)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 325 "/usr/include/features.h" 3 4
# define __USE_POSIX	1
#endif
# 327 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 2 || defined _XOPEN_SOURCE
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 329 "/usr/include/features.h" 3 4
# define __USE_POSIX2	1
#endif
# 331 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199309L
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 333 "/usr/include/features.h" 3 4
# define __USE_POSIX199309	1
#endif
# 335 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199506L
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 337 "/usr/include/features.h" 3 4
# define __USE_POSIX199506	1
#endif
# 339 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200112L
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 341 "/usr/include/features.h" 3 4
# define __USE_XOPEN2K		1
# undef __USE_ISOC95
# define __USE_ISOC95		1
# undef __USE_ISOC99
# define __USE_ISOC99		1
#endif
# 347 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200809L
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 349 "/usr/include/features.h" 3 4
# define __USE_XOPEN2K8		1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
# 353 "/usr/include/features.h" 3 4

#ifdef	_XOPEN_SOURCE
# define __USE_XOPEN	1
#if 0 /* disabled by -frewrite-includes */
# if (_XOPEN_SOURCE - 0) >= 500
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 357 "/usr/include/features.h" 3 4
#  define __USE_XOPEN_EXTENDED	1
#  define __USE_UNIX98	1
#  undef _LARGEFILE_SOURCE
#  define _LARGEFILE_SOURCE	1
#if 0 /* disabled by -frewrite-includes */
#  if (_XOPEN_SOURCE - 0) >= 600
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 362 "/usr/include/features.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#   if (_XOPEN_SOURCE - 0) >= 700
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 363 "/usr/include/features.h" 3 4
#    define __USE_XOPEN2K8	1
#    define __USE_XOPEN2K8XSI	1
#   endif
# 366 "/usr/include/features.h" 3 4
#   define __USE_XOPEN2K	1
#   define __USE_XOPEN2KXSI	1
#   undef __USE_ISOC95
#   define __USE_ISOC95		1
#   undef __USE_ISOC99
#   define __USE_ISOC99		1
#  endif
# 373 "/usr/include/features.h" 3 4
# else
# 374 "/usr/include/features.h" 3 4
#  ifdef _XOPEN_SOURCE_EXTENDED
#   define __USE_XOPEN_EXTENDED	1
#  endif
# 377 "/usr/include/features.h" 3 4
# endif
# 378 "/usr/include/features.h" 3 4
#endif
# 379 "/usr/include/features.h" 3 4

#ifdef _LARGEFILE_SOURCE
# define __USE_LARGEFILE	1
#endif
# 383 "/usr/include/features.h" 3 4

#ifdef _LARGEFILE64_SOURCE
# define __USE_LARGEFILE64	1
#endif
# 387 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 389 "/usr/include/features.h" 3 4
# define __USE_FILE_OFFSET64	1
#endif
# 391 "/usr/include/features.h" 3 4

#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* features-time64.h expanded by -frewrite-includes */
#include <features-time64.h>
#else /* features-time64.h expanded by -frewrite-includes */
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
/* Features part to handle 64-bit time_t support.
   Copyright (C) 2021-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* We need to know the word size in order to check the time size.  */
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* wordsize.h expanded by -frewrite-includes */
#include <bits/wordsize.h>
#else /* wordsize.h expanded by -frewrite-includes */
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */

#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && !defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 4 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	64
#else
# 6 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	32
#define __WORDSIZE32_SIZE_ULONG		0
#define __WORDSIZE32_PTRDIFF_LONG	0
#endif
# 10 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4

#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32	1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE		64
#else
# 16 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE_TIME64_COMPAT32	0
#endif
# 18 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
#endif /* wordsize.h expanded by -frewrite-includes */
# 21 "/usr/include/features-time64.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* timesize.h expanded by -frewrite-includes */
#include <bits/timesize.h>
#else /* timesize.h expanded by -frewrite-includes */
# 21 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
/* Bit size of the time_t type at glibc build time, x86-64 and x32 case.
   Copyright (C) 2018-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* wordsize.h expanded by -frewrite-includes */
#include <bits/wordsize.h>
#else /* wordsize.h expanded by -frewrite-includes */
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */

#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && !defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 4 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	64
#else
# 6 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	32
#define __WORDSIZE32_SIZE_ULONG		0
#define __WORDSIZE32_PTRDIFF_LONG	0
#endif
# 10 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4

#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32	1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE		64
#else
# 16 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE_TIME64_COMPAT32	0
#endif
# 18 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
#endif /* wordsize.h expanded by -frewrite-includes */
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 22 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
/* For x32, time is 64-bit even though word size is 32-bit.  */
# define __TIMESIZE	64
#else
# 25 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
/* For others, time size is word size.  */
# define __TIMESIZE	__WORDSIZE
#endif
# 28 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
#endif /* timesize.h expanded by -frewrite-includes */
# 22 "/usr/include/features-time64.h" 2 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _TIME_BITS
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 24 "/usr/include/features-time64.h" 3 4
#if 0 /* disabled by -frewrite-includes */
# if _TIME_BITS == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 25 "/usr/include/features-time64.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if ! defined (_FILE_OFFSET_BITS) || _FILE_OFFSET_BITS != 64
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 26 "/usr/include/features-time64.h" 3 4
#   error "_TIME_BITS=64 is allowed only with _FILE_OFFSET_BITS=64"
#if 0 /* disabled by -frewrite-includes */
#if 0
#  elif __TIMESIZE == 32
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 28 "/usr/include/features-time64.h" 3 4
#   define __USE_TIME_BITS64	1
#  endif
# 30 "/usr/include/features-time64.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if 0
# elif _TIME_BITS == 32
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 31 "/usr/include/features-time64.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if __TIMESIZE > 32
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 32 "/usr/include/features-time64.h" 3 4
#   error "_TIME_BITS=32 is not compatible with __TIMESIZE > 32"
#  endif
# 34 "/usr/include/features-time64.h" 3 4
# else
# 35 "/usr/include/features-time64.h" 3 4
#  error Invalid _TIME_BITS value (can only be 32 or 64-bit)
# endif
# 37 "/usr/include/features-time64.h" 3 4
#endif
# 38 "/usr/include/features-time64.h" 3 4
#endif /* features-time64.h expanded by -frewrite-includes */
# 393 "/usr/include/features.h" 2 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _DEFAULT_SOURCE
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 395 "/usr/include/features.h" 3 4
# define __USE_MISC	1
#endif
# 397 "/usr/include/features.h" 3 4

#ifdef	_ATFILE_SOURCE
# define __USE_ATFILE	1
#endif
# 401 "/usr/include/features.h" 3 4

#ifdef	_DYNAMIC_STACK_SIZE_SOURCE
# define __USE_DYNAMIC_STACK_SIZE	1
#endif
# 405 "/usr/include/features.h" 3 4

#ifdef	_GNU_SOURCE
# define __USE_GNU	1
#endif
# 409 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _FORTIFY_SOURCE && _FORTIFY_SOURCE > 0
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 411 "/usr/include/features.h" 3 4
#if 0 /* disabled by -frewrite-includes */
# if !defined __OPTIMIZE__ || __OPTIMIZE__ <= 0
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 412 "/usr/include/features.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if 0
# elif !__GNUC_PREREQ (4, 1)
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 413 "/usr/include/features.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if 0
# elif _FORTIFY_SOURCE > 2 && (__glibc_clang_prereq (9, 0)		      \
			       || __GNUC_PREREQ (12, 0))
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 415 "/usr/include/features.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if _FORTIFY_SOURCE > 3
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 417 "/usr/include/features.h" 3 4
#  endif
# 418 "/usr/include/features.h" 3 4
#  define __USE_FORTIFY_LEVEL 3
#if 0 /* disabled by -frewrite-includes */
#if 0
# elif _FORTIFY_SOURCE > 1
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 420 "/usr/include/features.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if _FORTIFY_SOURCE > 2
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 421 "/usr/include/features.h" 3 4
#  endif
# 422 "/usr/include/features.h" 3 4
#  define __USE_FORTIFY_LEVEL 2
# else
# 424 "/usr/include/features.h" 3 4
#  define __USE_FORTIFY_LEVEL 1
# endif
# 426 "/usr/include/features.h" 3 4
#endif
# 427 "/usr/include/features.h" 3 4
#ifndef __USE_FORTIFY_LEVEL
# define __USE_FORTIFY_LEVEL 0
#endif
# 430 "/usr/include/features.h" 3 4

/* The function 'gets' existed in C89, but is impossible to use
   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for
   compatibility with various implementations of <cstdio>, this test
   must consider only the value of __cplusplus when compiling C++.  */
#if 0 /* disabled by -frewrite-includes */
#if defined __cplusplus ? __cplusplus >= 201402L : defined __USE_ISOC11
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 436 "/usr/include/features.h" 3 4
# define __GLIBC_USE_DEPRECATED_GETS 0
#else
# 438 "/usr/include/features.h" 3 4
# define __GLIBC_USE_DEPRECATED_GETS 1
#endif
# 440 "/usr/include/features.h" 3 4

/* GNU formerly extended the scanf functions with modified format
   specifiers %as, %aS, and %a[...] that allocate a buffer for the
   input using malloc.  This extension conflicts with ISO C99, which
   defines %a as a standalone format specifier that reads a floating-
   point number; moreover, POSIX.1-2008 provides the same feature
   using the modifier letter 'm' instead (%ms, %mS, %m[...]).

   We now follow C99 unless GNU extensions are active and the compiler
   is specifically in C89 or C++98 mode (strict or not).  For
   instance, with GCC, -std=gnu11 will have C99-compliant scanf with
   or without -D_GNU_SOURCE, but -std=c89 -D_GNU_SOURCE will have the
   old extension.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined __USE_GNU							\
     && (defined __cplusplus						\
	 ? (__cplusplus < 201103L && !defined __GXX_EXPERIMENTAL_CXX0X__) \
	 : (!defined __STDC_VERSION__ || __STDC_VERSION__ < 199901L)))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 457 "/usr/include/features.h" 3 4
# define __GLIBC_USE_DEPRECATED_SCANF 1
#else
# 459 "/usr/include/features.h" 3 4
# define __GLIBC_USE_DEPRECATED_SCANF 0
#endif
# 461 "/usr/include/features.h" 3 4

/* Get definitions of __STDC_* predefined macros, if the compiler has
   not preincluded this header automatically.  */
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdc-predef.h expanded by -frewrite-includes */
#include <stdc-predef.h>
#else /* stdc-predef.h expanded by -frewrite-includes */
# 464 "/usr/include/features.h" 3 4
# 1 "/usr/include/stdc-predef.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef	_STDC_PREDEF_H
#define	_STDC_PREDEF_H	1

/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */

/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */

#ifdef __GCC_IEC_559
#if 0 /* disabled by -frewrite-includes */
# if __GCC_IEC_559 > 0
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 38 "/usr/include/stdc-predef.h" 3 4
#  define __STDC_IEC_559__		1
#  define __STDC_IEC_60559_BFP__ 	201404L
# endif
# 41 "/usr/include/stdc-predef.h" 3 4
#else
# 42 "/usr/include/stdc-predef.h" 3 4
# define __STDC_IEC_559__		1
# define __STDC_IEC_60559_BFP__ 	201404L
#endif
# 45 "/usr/include/stdc-predef.h" 3 4

#ifdef __GCC_IEC_559_COMPLEX
#if 0 /* disabled by -frewrite-includes */
# if __GCC_IEC_559_COMPLEX > 0
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 48 "/usr/include/stdc-predef.h" 3 4
#  define __STDC_IEC_559_COMPLEX__	1
#  define __STDC_IEC_60559_COMPLEX__	201404L
# endif
# 51 "/usr/include/stdc-predef.h" 3 4
#else
# 52 "/usr/include/stdc-predef.h" 3 4
# define __STDC_IEC_559_COMPLEX__	1
# define __STDC_IEC_60559_COMPLEX__	201404L
#endif
# 55 "/usr/include/stdc-predef.h" 3 4

/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
#define __STDC_ISO_10646__		201706L

#endif
# 65 "/usr/include/stdc-predef.h" 3 4
#endif /* stdc-predef.h expanded by -frewrite-includes */
# 465 "/usr/include/features.h" 2 3 4

/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */
#undef  __GNU_LIBRARY__
#define __GNU_LIBRARY__ 6

/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */
#define	__GLIBC__	2
#define	__GLIBC_MINOR__	35

#define __GLIBC_PREREQ(maj, min) \
	((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))

/* This is here only because every header file already includes this one.  */
#ifndef __ASSEMBLER__
# ifndef _SYS_CDEFS_H
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* cdefs.h expanded by -frewrite-includes */
#  include <sys/cdefs.h>
#else /* cdefs.h expanded by -frewrite-includes */
# 486 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
/* Copyright (C) 1992-2022 Free Software Foundation, Inc.
   Copyright The GNU Toolchain Authors.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef	_SYS_CDEFS_H
#define	_SYS_CDEFS_H	1

/* We are almost always included from features.h. */
#ifndef _FEATURES_H
#if 0 /* expanded by -frewrite-includes */
# include <features.h>
#endif /* expanded by -frewrite-includes */
# 24 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 25 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 26 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   supported anymore.  */
#if 0 /* disabled by -frewrite-includes */
#if defined __GNUC__ && !defined __STDC__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 31 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# error "You need a ISO C conforming compiler to use the glibc headers"
#endif
# 33 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Some user header file might have defined this before.  */
#undef	__P
#undef	__PMT

/* Compilers that lack __has_attribute may object to
       #if defined __has_attribute && __has_attribute (...)
   even though they do not need to evaluate the right-hand side of the &&.
   Similarly for __has_builtin, etc.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined __has_attribute \
     && (!defined __clang_minor__ \
         || 3 < __clang_major__ + (5 <= __clang_minor__)))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 45 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_has_attribute(attr) __has_attribute (attr)
#else
# 47 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_has_attribute(attr) 0
#endif
# 49 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#ifdef __has_builtin
# define __glibc_has_builtin(name) __has_builtin (name)
#else
# 52 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_has_builtin(name) 0
#endif
# 54 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#ifdef __has_extension
# define __glibc_has_extension(ext) __has_extension (ext)
#else
# 57 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_has_extension(ext) 0
#endif
# 59 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined __GNUC__ || defined __clang__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 61 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* All functions, except those with callbacks or those that
   synchronize memory, are leaf functions.  */
#if 0 /* disabled by -frewrite-includes */
# if __GNUC_PREREQ (4, 6) && !defined _LIBC
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 65 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __LEAF , __leaf__
#  define __LEAF_ATTR __attribute__ ((__leaf__))
# else
# 68 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __LEAF
#  define __LEAF_ATTR
# endif
# 71 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this only works with
   gcc 2.8.x and egcs.  For gcc 3.4 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well.  */
#if 0 /* disabled by -frewrite-includes */
# if !defined __cplusplus \
     && (__GNUC_PREREQ (3, 4) || __glibc_has_attribute (__nothrow__))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 79 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __THROW	__attribute__ ((__nothrow__ __LEAF))
#  define __THROWNL	__attribute__ ((__nothrow__))
#  define __NTH(fct)	__attribute__ ((__nothrow__ __LEAF)) fct
#  define __NTHNL(fct)  __attribute__ ((__nothrow__)) fct
# else
# 84 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if defined __cplusplus && (__GNUC_PREREQ (2,8) || __clang_major >= 4)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 85 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#   if __cplusplus >= 201103L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 86 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#    define __THROW	noexcept (true)
#   else
# 88 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#    define __THROW	throw ()
#   endif
# 90 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#   define __THROWNL	__THROW
#   define __NTH(fct)	__LEAF_ATTR fct __THROW
#   define __NTHNL(fct) fct __THROW
#  else
# 94 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#   define __THROW
#   define __THROWNL
#   define __NTH(fct)	fct
#   define __NTHNL(fct) fct
#  endif
# 99 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# endif
# 100 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#else	/* Not GCC or clang.  */
# 102 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if (defined __cplusplus						\
      || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 105 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __inline	inline
# else
# 107 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __inline		/* No inline functions.  */
# endif
# 109 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

# define __THROW
# define __THROWNL
# define __NTH(fct)	fct

#endif	/* GCC || clang.  */
# 115 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined.  */
#define __P(args)	args
#define __PMT(args)	args

/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */

#define __CONCAT(x,y)	x ## y
#define __STRING(x)	#x

/* This is not a typedef so `const __ptr_t' does the right thing.  */
#define __ptr_t void *


/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef	__cplusplus
# define __BEGIN_DECLS	extern "C" {
# define __END_DECLS	}
#else
# 136 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __BEGIN_DECLS
# define __END_DECLS
#endif
# 139 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4


/* Fortify support.  */
#define __bos(ptr) __builtin_object_size (ptr, __USE_FORTIFY_LEVEL > 1)
#define __bos0(ptr) __builtin_object_size (ptr, 0)

/* Use __builtin_dynamic_object_size at _FORTIFY_SOURCE=3 when available.  */
#if 0 /* disabled by -frewrite-includes */
#if __USE_FORTIFY_LEVEL == 3 && (__glibc_clang_prereq (9, 0)		      \
				 || __GNUC_PREREQ (12, 0))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 148 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_objsize0(__o) __builtin_dynamic_object_size (__o, 0)
# define __glibc_objsize(__o) __builtin_dynamic_object_size (__o, 1)
#else
# 151 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_objsize0(__o) __bos0 (__o)
# define __glibc_objsize(__o) __bos (__o)
#endif
# 154 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Compile time conditions to choose between the regular, _chk and _chk_warn
   variants.  These conditions should get evaluated to constant and optimized
   away.  */

#define __glibc_safe_len_cond(__l, __s, __osz) ((__l) <= (__osz) / (__s))
#define __glibc_unsigned_or_positive(__l) \
  ((__typeof (__l)) 0 < (__typeof (__l)) -1				      \
   || (__builtin_constant_p (__l) && (__l) > 0))

/* Length is known to be safe at compile time if the __L * __S <= __OBJSZ
   condition can be folded to a constant and if it is true.  The -1 check is
   redundant because since it implies that __glibc_safe_len_cond is true.  */
#define __glibc_safe_or_unknown_len(__l, __s, __osz) \
  (__glibc_unsigned_or_positive (__l)					      \
   && __builtin_constant_p (__glibc_safe_len_cond ((__SIZE_TYPE__) (__l),     \
						   __s, __osz))		      \
   && __glibc_safe_len_cond ((__SIZE_TYPE__) (__l), __s, __osz))

/* Conversely, we know at compile time that the length is unsafe if the
   __L * __S <= __OBJSZ condition can be folded to a constant and if it is
   false.  */
#define __glibc_unsafe_len(__l, __s, __osz) \
  (__glibc_unsigned_or_positive (__l)					      \
   && __builtin_constant_p (__glibc_safe_len_cond ((__SIZE_TYPE__) (__l),     \
						   __s, __osz))		      \
   && !__glibc_safe_len_cond ((__SIZE_TYPE__) (__l), __s, __osz))

/* Fortify function f.  __f_alias, __f_chk and __f_chk_warn must be
   declared.  */

#define __glibc_fortify(f, __l, __s, __osz, ...) \
  (__glibc_safe_or_unknown_len (__l, __s, __osz)			      \
   ? __ ## f ## _alias (__VA_ARGS__)					      \
   : (__glibc_unsafe_len (__l, __s, __osz)				      \
      ? __ ## f ## _chk_warn (__VA_ARGS__, __osz)			      \
      : __ ## f ## _chk (__VA_ARGS__, __osz)))			      \

/* Fortify function f, where object size argument passed to f is the number of
   elements and not total size.  */

#define __glibc_fortify_n(f, __l, __s, __osz, ...) \
  (__glibc_safe_or_unknown_len (__l, __s, __osz)			      \
   ? __ ## f ## _alias (__VA_ARGS__)					      \
   : (__glibc_unsafe_len (__l, __s, __osz)				      \
      ? __ ## f ## _chk_warn (__VA_ARGS__, (__osz) / (__s))		      \
      : __ ## f ## _chk (__VA_ARGS__, (__osz) / (__s))))		      \

#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (4,3)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 203 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __warnattr(msg) __attribute__((__warning__ (msg)))
# define __errordecl(name, msg) \
  extern void name (void) __attribute__((__error__ (msg)))
#else
# 207 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __warnattr(msg)
# define __errordecl(name, msg) extern void name (void)
#endif
# 210 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Support for flexible arrays.
   Headers that should use flexible arrays only if they're "real"
   (e.g. only if they won't affect sizeof()) should test
   #if __glibc_c99_flexarr_available.  */
#if 0 /* disabled by -frewrite-includes */
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L && !defined __HP_cc
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 216 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __flexarr	[]
# define __glibc_c99_flexarr_available 1
#if 0 /* disabled by -frewrite-includes */
#if 0
#elif __GNUC_PREREQ (2,97) || defined __clang__
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 219 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* GCC 2.97 and clang support C99 flexible array members as an extension,
   even when in C89 mode or compiling C++ (any version).  */
# define __flexarr	[]
# define __glibc_c99_flexarr_available 1
#if 0 /* disabled by -frewrite-includes */
#if 0
#elif defined __GNUC__
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 224 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Pre-2.97 GCC did not support C99 flexible arrays but did have
   an equivalent extension with slightly different notation.  */
# define __flexarr	[0]
# define __glibc_c99_flexarr_available 1
#else
# 229 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Some other non-C99 compiler.  Approximate with [1].  */
# define __flexarr	[1]
# define __glibc_c99_flexarr_available 0
#endif
# 233 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4


/* __asm__ ("xyz") is used throughout the headers to rename functions
   at the assembly language level.  This is wrapped by the __REDIRECT
   macro, in order to support compilers that can do this some other
   way.  When compilers don't support asm-names at all, we have to do
   preprocessor tricks instead (which don't have exactly the right
   semantics, but it's the best we can do).

   Example:
   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid); */

#if 0 /* disabled by -frewrite-includes */
#if (defined __GNUC__ && __GNUC__ >= 2) || (__clang_major__ >= 4)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 246 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

# define __REDIRECT(name, proto, alias) name proto __asm__ (__ASMNAME (#alias))
# ifdef __cplusplus
#  define __REDIRECT_NTH(name, proto, alias) \
     name proto __THROW __asm__ (__ASMNAME (#alias))
#  define __REDIRECT_NTHNL(name, proto, alias) \
     name proto __THROWNL __asm__ (__ASMNAME (#alias))
# else
# 254 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __REDIRECT_NTH(name, proto, alias) \
     name proto __asm__ (__ASMNAME (#alias)) __THROW
#  define __REDIRECT_NTHNL(name, proto, alias) \
     name proto __asm__ (__ASMNAME (#alias)) __THROWNL
# endif
# 259 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __ASMNAME(cname)  __ASMNAME2 (__USER_LABEL_PREFIX__, cname)
# define __ASMNAME2(prefix, cname) __STRING (prefix) cname

/*
#elif __SOME_OTHER_COMPILER__

# define __REDIRECT(name, proto, alias) name proto; \
	_Pragma("let " #name " = " #alias)
*/
#endif
# 269 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* GCC and clang have various useful declarations that can be made with
   the '__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it.  */
#if 0 /* disabled by -frewrite-includes */
#if !(defined __GNUC__ || defined __clang__)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 274 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute__(xyz)	/* Ignore */
#endif
# 276 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* At some point during the gcc 2.96 development the `malloc' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (2,96) || __glibc_has_attribute (__malloc__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 281 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_malloc__ __attribute__ ((__malloc__))
#else
# 283 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_malloc__ /* Ignore */
#endif
# 285 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Tell the compiler which arguments to an allocation function
   indicate the size of the allocation.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (4, 3)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 289 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_alloc_size__(params) \
  __attribute__ ((__alloc_size__ params))
#else
# 292 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_alloc_size__(params) /* Ignore.  */
#endif
# 294 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Tell the compiler which argument to an allocation function
   indicates the alignment of the allocation.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (4, 9) || __glibc_has_attribute (__alloc_align__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 298 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_alloc_align__(param) \
  __attribute__ ((__alloc_align__ param))
#else
# 301 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_alloc_align__(param) /* Ignore.  */
#endif
# 303 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* At some point during the gcc 2.96 development the `pure' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (2,96) || __glibc_has_attribute (__pure__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 308 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_pure__ __attribute__ ((__pure__))
#else
# 310 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_pure__ /* Ignore */
#endif
# 312 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* This declaration tells the compiler that the value is constant.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (2,5) || __glibc_has_attribute (__const__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 315 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_const__ __attribute__ ((__const__))
#else
# 317 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_const__ /* Ignore */
#endif
# 319 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (2,7) || __glibc_has_attribute (__unused__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 321 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_maybe_unused__ __attribute__ ((__unused__))
#else
# 323 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_maybe_unused__ /* Ignore */
#endif
# 325 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* At some point during the gcc 3.1 development the `used' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (3,1) || __glibc_has_attribute (__used__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 330 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_used__ __attribute__ ((__used__))
# define __attribute_noinline__ __attribute__ ((__noinline__))
#else
# 333 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_used__ __attribute__ ((__unused__))
# define __attribute_noinline__ /* Ignore */
#endif
# 336 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Since version 3.2, gcc allows marking deprecated functions.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (3,2) || __glibc_has_attribute (__deprecated__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 339 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_deprecated__ __attribute__ ((__deprecated__))
#else
# 341 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_deprecated__ /* Ignore */
#endif
# 343 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Since version 4.5, gcc also allows one to specify the message printed
   when a deprecated function is used.  clang claims to be gcc 4.2, but
   may also support this feature.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (4,5) \
    || __glibc_has_extension (__attribute_deprecated_with_message__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 349 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_deprecated_msg__(msg) \
	 __attribute__ ((__deprecated__ (msg)))
#else
# 352 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_deprecated_msg__(msg) __attribute_deprecated__
#endif
# 354 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* At some point during the gcc 2.8 development the `format_arg' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.
   If several `format_arg' attributes are given for the same function, in
   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
   all designated arguments are considered.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (2,8) || __glibc_has_attribute (__format_arg__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 362 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_format_arg__(x) __attribute__ ((__format_arg__ (x)))
#else
# 364 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_format_arg__(x) /* Ignore */
#endif
# 366 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* At some point during the gcc 2.97 development the `strfmon' format
   attribute for functions was introduced.  We don't want to use it
   unconditionally (although this would be possible) since it
   generates warnings.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (2,97) || __glibc_has_attribute (__format__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 372 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_format_strfmon__(a,b) \
  __attribute__ ((__format__ (__strfmon__, a, b)))
#else
# 375 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_format_strfmon__(a,b) /* Ignore */
#endif
# 377 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* The nonnull function attribute marks pointer parameters that
   must not be NULL.  This has the name __nonnull in glibc,
   and __attribute_nonnull__ in files shared with Gnulib to avoid
   collision with a different __nonnull in DragonFlyBSD 5.9.  */
#ifndef __attribute_nonnull__
#if 0 /* disabled by -frewrite-includes */
# if __GNUC_PREREQ (3,3) || __glibc_has_attribute (__nonnull__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 384 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __attribute_nonnull__(params) __attribute__ ((__nonnull__ params))
# else
# 386 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __attribute_nonnull__(params)
# endif
# 388 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 389 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#ifndef __nonnull
# define __nonnull(params) __attribute_nonnull__ (params)
#endif
# 392 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* The returns_nonnull function attribute marks the return type of the function
   as always being non-null.  */
#ifndef __returns_nonnull
#if 0 /* disabled by -frewrite-includes */
# if __GNUC_PREREQ (4, 9) || __glibc_has_attribute (__returns_nonnull__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 397 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __returns_nonnull __attribute__ ((__returns_nonnull__))
# else
# 399 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __returns_nonnull
# endif
# 401 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 402 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* If fortification mode, we warn about unused results of certain
   function calls which can lead to problems.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (3,4) || __glibc_has_attribute (__warn_unused_result__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 406 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_warn_unused_result__ \
   __attribute__ ((__warn_unused_result__))
#if 0 /* disabled by -frewrite-includes */
# if defined __USE_FORTIFY_LEVEL && __USE_FORTIFY_LEVEL > 0
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 409 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __wur __attribute_warn_unused_result__
# endif
# 411 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#else
# 412 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_warn_unused_result__ /* empty */
#endif
# 414 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#ifndef __wur
# define __wur /* Ignore */
#endif
# 417 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Forces a function to be always inlined.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (3,2) || __glibc_has_attribute (__always_inline__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 420 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* The Linux kernel defines __always_inline in stddef.h (283d7573), and
   it conflicts with this definition.  Therefore undefine it first to
   allow either header to be included first.  */
# undef __always_inline
# define __always_inline __inline __attribute__ ((__always_inline__))
#else
# 426 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# undef __always_inline
# define __always_inline __inline
#endif
# 429 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Associate error messages with the source location of the call site rather
   than with the source location inside the function.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (4,3) || __glibc_has_attribute (__artificial__)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 433 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_artificial__ __attribute__ ((__artificial__))
#else
# 435 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_artificial__ /* Ignore */
#endif
# 437 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  Using __GNUC_STDC_INLINE__
   or __GNUC_GNU_INLINE is not a good enough check for gcc because gcc versions
   older than 4.3 may define these macros and still not guarantee GNU inlining
   semantics.

   clang++ identifies itself as gcc-4.2, but has support for GNU inlining
   semantics, that can be checked for by using the __GNUC_STDC_INLINE_ and
   __GNUC_GNU_INLINE__ macro definitions.  */
#if 0 /* disabled by -frewrite-includes */
#if (!defined __cplusplus || __GNUC_PREREQ (4,3) \
     || (defined __clang__ && (defined __GNUC_STDC_INLINE__ \
			       || defined __GNUC_GNU_INLINE__)))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 450 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
# if defined __GNUC_STDC_INLINE__ || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 451 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __extern_inline extern __inline __attribute__ ((__gnu_inline__))
#  define __extern_always_inline \
  extern __always_inline __attribute__ ((__gnu_inline__))
# else
# 455 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __extern_inline extern __inline
#  define __extern_always_inline extern __always_inline
# endif
# 458 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 459 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#ifdef __extern_always_inline
# define __fortify_function __extern_always_inline __attribute_artificial__
#endif
# 463 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* GCC 4.3 and above allow passing all anonymous arguments of an
   __extern_always_inline function to some other vararg function.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (4,3)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 467 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __va_arg_pack() __builtin_va_arg_pack ()
# define __va_arg_pack_len() __builtin_va_arg_pack_len ()
#endif
# 470 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* It is possible to compile containing GCC extensions even if GCC is
   run in pedantic mode if the uses are carefully marked using the
   `__extension__' keyword.  But this is not generally available before
   version 2.8.  */
#if 0 /* disabled by -frewrite-includes */
#if !(__GNUC_PREREQ (2,8) || defined __clang__)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 476 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __extension__		/* Ignore */
#endif
# 478 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* __restrict is known in EGCS 1.2 and above, and in clang.
   It works also in C++ mode (outside of arrays), but only when spelled
   as '__restrict', not 'restrict'.  */
#if 0 /* disabled by -frewrite-includes */
#if !(__GNUC_PREREQ (2,92) || __clang_major__ >= 3)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 483 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
# if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 484 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __restrict	restrict
# else
# 486 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __restrict	/* Ignore */
# endif
# 488 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 489 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
     array_name[restrict]
   GCC 3.1 and clang support this.
   This syntax is not usable in C++ mode.  */
#if 0 /* disabled by -frewrite-includes */
#if (__GNUC_PREREQ (3,1) || __clang_major__ >= 3) && !defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 495 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __restrict_arr	__restrict
#else
# 497 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# ifdef __GNUC__
#  define __restrict_arr	/* Not supported in old GCC.  */
# else
# 500 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 501 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#   define __restrict_arr	restrict
#  else
# 503 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Some other non-C99 compiler.  */
#   define __restrict_arr	/* Not supported.  */
#  endif
# 506 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# endif
# 507 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 508 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if (__GNUC__ >= 3) || __glibc_has_builtin (__builtin_expect)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 510 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_unlikely(cond)	__builtin_expect ((cond), 0)
# define __glibc_likely(cond)	__builtin_expect ((cond), 1)
#else
# 513 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_unlikely(cond)	(cond)
# define __glibc_likely(cond)	(cond)
#endif
# 516 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if (!defined _Noreturn \
     && (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) < 201112 \
     &&  !(__GNUC_PREREQ (4,7) \
           || (3 < __clang_major__ + (5 <= __clang_minor__))))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 521 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
# if __GNUC_PREREQ (2,8)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 522 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define _Noreturn __attribute__ ((__noreturn__))
# else
# 524 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define _Noreturn
# endif
# 526 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 527 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (8, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 529 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Describes a char array whose address can safely be passed as the first
   argument to strncpy and strncat, as the char array is not necessarily
   a NUL-terminated string.  */
# define __attribute_nonstring__ __attribute__ ((__nonstring__))
#else
# 534 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_nonstring__
#endif
# 536 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Undefine (also defined in libc-symbols.h).  */
#undef __attribute_copy__
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (9, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 540 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Copies attributes from the declaration or type referenced by
   the argument.  */
# define __attribute_copy__(arg) __attribute__ ((__copy__ (arg)))
#else
# 544 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_copy__(arg)
#endif
# 546 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if (!defined _Static_assert && !defined __cplusplus \
     && (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) < 201112 \
     && (!(__GNUC_PREREQ (4, 6) || __clang_major__ >= 4) \
         || defined __STRICT_ANSI__))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 551 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define _Static_assert(expr, diagnostic) \
    extern int (*__Static_assert_function (void)) \
      [!!sizeof (struct { int __error_if_negative: (expr) ? 2 : -1; })]
#endif
# 555 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Gnulib avoids including these, as they don't work on non-glibc or
   older glibc platforms.  */
#ifndef __GNULIB_CDEFS
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* wordsize.h expanded by -frewrite-includes */
# include <bits/wordsize.h>
#else /* wordsize.h expanded by -frewrite-includes */
# 559 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */

#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && !defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 4 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	64
#else
# 6 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	32
#define __WORDSIZE32_SIZE_ULONG		0
#define __WORDSIZE32_PTRDIFF_LONG	0
#endif
# 10 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4

#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32	1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE		64
#else
# 16 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE_TIME64_COMPAT32	0
#endif
# 18 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
#endif /* wordsize.h expanded by -frewrite-includes */
# 560 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* long-double.h expanded by -frewrite-includes */
# include <bits/long-double.h>
#else /* long-double.h expanded by -frewrite-includes */
# 560 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
/* Properties of long double type.  ldbl-96 version.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License  published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* long double is distinct from double, so there is nothing to
   define here.  */
#define __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI 0
#endif /* long-double.h expanded by -frewrite-includes */
# 561 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
#endif
# 562 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI == 1
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 564 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# ifdef __REDIRECT

/* Alias name defined automatically.  */
#  define __LDBL_REDIR(name, proto) ... unused__ldbl_redir
#  define __LDBL_REDIR_DECL(name) \
  extern __typeof (name) name __asm (__ASMNAME ("__" #name "ieee128"));

/* Alias name defined automatically, with leading underscores.  */
#  define __LDBL_REDIR2_DECL(name) \
  extern __typeof (__##name) __##name \
    __asm (__ASMNAME ("__" #name "ieee128"));

/* Alias name defined manually.  */
#  define __LDBL_REDIR1(name, proto, alias) ... unused__ldbl_redir1
#  define __LDBL_REDIR1_DECL(name, alias) \
  extern __typeof (name) name __asm (__ASMNAME (#alias));

#  define __LDBL_REDIR1_NTH(name, proto, alias) \
  __REDIRECT_NTH (name, proto, alias)
#  define __REDIRECT_NTH_LDBL(name, proto, alias) \
  __LDBL_REDIR1_NTH (name, proto, __##alias##ieee128)

/* Unused.  */
#  define __REDIRECT_LDBL(name, proto, alias) ... unused__redirect_ldbl
#  define __LDBL_REDIR_NTH(name, proto) ... unused__ldbl_redir_nth

# else
# 591 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
_Static_assert (0, "IEEE 128-bits long double requires redirection on this platform");
# endif
# 593 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if 0
#elif defined __LONG_DOUBLE_MATH_OPTIONAL && defined __NO_LONG_DOUBLE_MATH
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 594 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __LDBL_COMPAT 1
# ifdef __REDIRECT
#  define __LDBL_REDIR1(name, proto, alias) __REDIRECT (name, proto, alias)
#  define __LDBL_REDIR(name, proto) \
  __LDBL_REDIR1 (name, proto, __nldbl_##name)
#  define __LDBL_REDIR1_NTH(name, proto, alias) __REDIRECT_NTH (name, proto, alias)
#  define __LDBL_REDIR_NTH(name, proto) \
  __LDBL_REDIR1_NTH (name, proto, __nldbl_##name)
#  define __LDBL_REDIR2_DECL(name) \
  extern __typeof (__##name) __##name __asm (__ASMNAME ("__nldbl___" #name));
#  define __LDBL_REDIR1_DECL(name, alias) \
  extern __typeof (name) name __asm (__ASMNAME (#alias));
#  define __LDBL_REDIR_DECL(name) \
  extern __typeof (name) name __asm (__ASMNAME ("__nldbl_" #name));
#  define __REDIRECT_LDBL(name, proto, alias) \
  __LDBL_REDIR1 (name, proto, __nldbl_##alias)
#  define __REDIRECT_NTH_LDBL(name, proto, alias) \
  __LDBL_REDIR1_NTH (name, proto, __nldbl_##alias)
# endif
# 613 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 614 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if (!defined __LDBL_COMPAT && __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI == 0) \
    || !defined __REDIRECT
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 616 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __LDBL_REDIR1(name, proto, alias) name proto
# define __LDBL_REDIR(name, proto) name proto
# define __LDBL_REDIR1_NTH(name, proto, alias) name proto __THROW
# define __LDBL_REDIR_NTH(name, proto) name proto __THROW
# define __LDBL_REDIR2_DECL(name)
# define __LDBL_REDIR_DECL(name)
# ifdef __REDIRECT
#  define __REDIRECT_LDBL(name, proto, alias) __REDIRECT (name, proto, alias)
#  define __REDIRECT_NTH_LDBL(name, proto, alias) \
  __REDIRECT_NTH (name, proto, alias)
# endif
# 627 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif
# 628 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* __glibc_macro_warning (MESSAGE) issues warning MESSAGE.  This is
   intended for use in preprocessor macros.

   Note: MESSAGE must be a _single_ string; concatenation of string
   literals is not supported.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (4,8) || __glibc_clang_prereq (3,5)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 635 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_macro_warning1(message) _Pragma (#message)
# define __glibc_macro_warning(message) \
  __glibc_macro_warning1 (GCC warning message)
#else
# 639 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __glibc_macro_warning(msg)
#endif
# 641 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Generic selection (ISO C11) is a C-only feature, available in GCC
   since version 4.9.  Previous versions do not provide generic
   selection, even though they might set __STDC_VERSION__ to 201112L,
   when in -std=c11 mode.  Thus, we must check for !defined __GNUC__
   when testing __STDC_VERSION__ for generic selection support.
   On the other hand, Clang also defines __GNUC__, so a clang-specific
   check is required to enable the use of generic selection.  */
#if 0 /* disabled by -frewrite-includes */
#if !defined __cplusplus \
    && (__GNUC_PREREQ (4, 9) \
	|| __glibc_has_extension (c_generic_selections) \
	|| (!defined __GNUC__ && defined __STDC_VERSION__ \
	    && __STDC_VERSION__ >= 201112L))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 654 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __HAVE_GENERIC_SELECTION 1
#else
# 656 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __HAVE_GENERIC_SELECTION 0
#endif
# 658 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (10, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 660 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Designates a 1-based positional argument ref-index of pointer type
   that can be used to access size-index elements of the pointed-to
   array according to access mode, or at least one element when
   size-index is not provided:
     access (access-mode, <ref-index> [, <size-index>])  */
#  define __attr_access(x) __attribute__ ((__access__ x))
/* For _FORTIFY_SOURCE == 3 we use __builtin_dynamic_object_size, which may
   use the access attribute to get object sizes from function definition
   arguments, so we can't use them on functions we fortify.  Drop the object
   size hints for such functions.  */
#if 0 /* disabled by -frewrite-includes */
#  if __USE_FORTIFY_LEVEL == 3
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 671 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#    define __fortified_attr_access(a, o, s) __attribute__ ((__access__ (a, o)))
#  else
# 673 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#    define __fortified_attr_access(a, o, s) __attr_access ((a, o, s))
#  endif
# 675 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if __GNUC_PREREQ (11, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 676 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#    define __attr_access_none(argno) __attribute__ ((__access__ (__none__, argno)))
#  else
# 678 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#    define __attr_access_none(argno)
#  endif
# 680 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#else
# 681 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#  define __fortified_attr_access(a, o, s)
#  define __attr_access(x)
#  define __attr_access_none(argno)
#endif
# 685 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (11, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 687 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Designates dealloc as a function to call to deallocate objects
   allocated by the declared function.  */
# define __attr_dealloc(dealloc, argno) \
    __attribute__ ((__malloc__ (dealloc, argno)))
# define __attr_dealloc_free __attr_dealloc (__builtin_free, 1)
#else
# 693 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attr_dealloc(dealloc, argno)
# define __attr_dealloc_free
#endif
# 696 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

/* Specify that a function such as setjmp or vfork may return
   twice.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (4, 1)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 700 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_returns_twice__ __attribute__ ((__returns_twice__))
#else
# 702 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# define __attribute_returns_twice__ /* Ignore.  */
#endif
# 704 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4

#endif	 /* sys/cdefs.h */
# 706 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#endif /* cdefs.h expanded by -frewrite-includes */
# 487 "/usr/include/features.h" 2 3 4
# endif
# 488 "/usr/include/features.h" 3 4

/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */
#if 0 /* disabled by -frewrite-includes */
# if defined __USE_FILE_OFFSET64 && !defined __REDIRECT
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 492 "/usr/include/features.h" 3 4
#  define __USE_LARGEFILE	1
#  define __USE_LARGEFILE64	1
# endif
# 495 "/usr/include/features.h" 3 4

#endif	/* !ASSEMBLER */
# 497 "/usr/include/features.h" 3 4

/* Decide whether we can define 'extern inline' functions in headers.  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \
    && !defined __OPTIMIZE_SIZE__ && !defined __NO_INLINE__ \
    && defined __extern_inline
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 502 "/usr/include/features.h" 3 4
# define __USE_EXTERN_INLINES	1
#endif
# 504 "/usr/include/features.h" 3 4


/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stubs.h expanded by -frewrite-includes */
#include <gnu/stubs.h>
#else /* stubs.h expanded by -frewrite-includes */
# 510 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
/* This file is automatically generated.
   This file selects the right generated file of `__stub_FUNCTION' macros
   based on the architecture being compiled for.  */


#if 0 /* disabled by -frewrite-includes */
#if !defined __x86_64__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 7 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
#if 0 /* expanded by -frewrite-includes */
# include <gnu/stubs-32.h>
#endif /* expanded by -frewrite-includes */
# 7 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 8 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
#endif
# 9 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && defined __LP64__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stubs-64.h expanded by -frewrite-includes */
# include <gnu/stubs-64.h>
#else /* stubs-64.h expanded by -frewrite-includes */
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
/* This file is automatically generated.
   It defines a symbol `__stub_FUNCTION' for each function
   in the C library which is a stub, meaning it will fail
   every time called, usually setting errno to ENOSYS.  */

#ifdef _LIBC
# error Applications may not define the macro _LIBC
#endif
# 9 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 3 4

#define __stub___compat_bdflush
#define __stub_chflags
#define __stub_fchflags
#define __stub_gtty
#define __stub_revoke
#define __stub_setlogin
#define __stub_sigreturn
#define __stub_stty
#endif /* stubs-64.h expanded by -frewrite-includes */
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
#endif
# 12 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 13 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
#if 0 /* expanded by -frewrite-includes */
# include <gnu/stubs-x32.h>
#endif /* expanded by -frewrite-includes */
# 13 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 14 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
#endif
# 15 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
#endif /* stubs.h expanded by -frewrite-includes */
# 511 "/usr/include/features.h" 2 3 4


#endif	/* features.h  */
# 514 "/usr/include/features.h" 3 4
#endif /* features.h expanded by -frewrite-includes */
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
#undef __GLIBC_USE_LIB_EXT2
#if 0 /* disabled by -frewrite-includes */
#if (defined __USE_GNU							\
     || (defined __STDC_WANT_LIB_EXT2__ && __STDC_WANT_LIB_EXT2__ > 0))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 40 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_LIB_EXT2 1
#else
# 42 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_LIB_EXT2 0
#endif
# 44 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.)  */
#undef __GLIBC_USE_IEC_60559_BFP_EXT
#if 0 /* disabled by -frewrite-includes */
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_BFP_EXT__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 69 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_BFP_EXT 1
#else
# 71 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_BFP_EXT 0
#endif
# 73 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
#undef __GLIBC_USE_IEC_60559_BFP_EXT_C2X
#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (IEC_60559_BFP_EXT) || __GLIBC_USE (ISOC2X)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 75 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_BFP_EXT_C2X 1
#else
# 77 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_BFP_EXT_C2X 0
#endif
# 79 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
#undef __GLIBC_USE_IEC_60559_EXT
#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (IEC_60559_BFP_EXT) || defined __STDC_WANT_IEC_60559_EXT__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 81 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_EXT 1
#else
# 83 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_EXT 0
#endif
# 85 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X.  */
#undef __GLIBC_USE_IEC_60559_FUNCS_EXT
#if 0 /* disabled by -frewrite-includes */
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_FUNCS_EXT__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 92 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_FUNCS_EXT 1
#else
# 94 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_FUNCS_EXT 0
#endif
# 96 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
#undef __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X
#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (IEC_60559_FUNCS_EXT) || __GLIBC_USE (ISOC2X)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 98 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X 1
#else
# 100 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X 0
#endif
# 102 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
#undef __GLIBC_USE_IEC_60559_TYPES_EXT
#if 0 /* disabled by -frewrite-includes */
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_TYPES_EXT__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 107 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_TYPES_EXT 1
#else
# 109 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_TYPES_EXT 0
#endif
# 111 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
#endif /* libc-header-start.h expanded by -frewrite-includes */
# 27 "/usr/include/stdint.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* types.h expanded by -frewrite-includes */
#include <bits/types.h>
#else /* types.h expanded by -frewrite-includes */
# 27 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */

#ifndef	_BITS_TYPES_H
#define	_BITS_TYPES_H	1

#if 0 /* expanded by -frewrite-includes */
#include <features.h>
#endif /* expanded by -frewrite-includes */
# 26 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* wordsize.h expanded by -frewrite-includes */
#include <bits/wordsize.h>
#else /* wordsize.h expanded by -frewrite-includes */
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */

#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && !defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 4 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	64
#else
# 6 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	32
#define __WORDSIZE32_SIZE_ULONG		0
#define __WORDSIZE32_PTRDIFF_LONG	0
#endif
# 10 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4

#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32	1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE		64
#else
# 16 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE_TIME64_COMPAT32	0
#endif
# 18 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
#endif /* wordsize.h expanded by -frewrite-includes */
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* timesize.h expanded by -frewrite-includes */
#include <bits/timesize.h>
#else /* timesize.h expanded by -frewrite-includes */
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
/* Bit size of the time_t type at glibc build time, x86-64 and x32 case.
   Copyright (C) 2018-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* wordsize.h expanded by -frewrite-includes */
#include <bits/wordsize.h>
#else /* wordsize.h expanded by -frewrite-includes */
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */

#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && !defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 4 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	64
#else
# 6 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	32
#define __WORDSIZE32_SIZE_ULONG		0
#define __WORDSIZE32_PTRDIFF_LONG	0
#endif
# 10 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4

#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32	1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE		64
#else
# 16 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE_TIME64_COMPAT32	0
#endif
# 18 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
#endif /* wordsize.h expanded by -frewrite-includes */
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 22 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
/* For x32, time is 64-bit even though word size is 32-bit.  */
# define __TIMESIZE	64
#else
# 25 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
/* For others, time size is word size.  */
# define __TIMESIZE	__WORDSIZE
#endif
# 28 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
#endif /* timesize.h expanded by -frewrite-includes */
# 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4

/* Convenience types.  */
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

/* Fixed-size types, underlying types depend on word size and compiler.  */
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
#if 0 /* disabled by -frewrite-includes */
#if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 44 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
#else
# 47 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;
#endif
# 50 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4

/* Smallest types with at least a given width.  */
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;

/* quad_t is also 64 bits.  */
#if 0 /* disabled by -frewrite-includes */
#if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 63 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
#else
# 66 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
#endif
# 69 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4

/* Largest integral types.  */
#if 0 /* disabled by -frewrite-includes */
#if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 72 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
#else
# 75 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
__extension__ typedef long long int __intmax_t;
__extension__ typedef unsigned long long int __uintmax_t;
#endif
# 78 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4


/* The machine-dependent file <bits/typesizes.h> defines __*_T_TYPE
   macros for each of the OS types we define below.  The definitions
   of those macros must use the following macros for underlying types.
   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
   variants of each of the following integer types on this machine.

	16		-- "natural" 16-bit type (always short)
	32		-- "natural" 32-bit type (always int)
	64		-- "natural" 64-bit type (long or long long)
	LONG32		-- 32-bit type, traditionally long
	QUAD		-- 64-bit type, traditionally long long
	WORD		-- natural type of __WORDSIZE bits (int or long)
	LONGWORD	-- type of __WORDSIZE bits, traditionally long

   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
   conventional uses of `long' or `long long' type modifiers match the
   types we define, even when a less-adorned type would be the same size.
   This matters for (somewhat) portably writing printf/scanf formats for
   these types, where using the appropriate l or ll format modifiers can
   make the typedefs and the formats match up across all GNU platforms.  If
   we used `long' when it's 64 bits where `long long' is expected, then the
   compiler would warn about the formats not matching the argument types,
   and the programmer changing them to shut up the compiler would break the
   program's portability.

   Here we assume what is presently the case in all the GCC configurations
   we support: long long is always 64 bits, long is always word/address size,
   and int is always 32 bits.  */

#define	__S16_TYPE		short int
#define __U16_TYPE		unsigned short int
#define	__S32_TYPE		int
#define __U32_TYPE		unsigned int
#define __SLONGWORD_TYPE	long int
#define __ULONGWORD_TYPE	unsigned long int
#if 0 /* disabled by -frewrite-includes */
#if __WORDSIZE == 32
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 116 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# define __SQUAD_TYPE		__int64_t
# define __UQUAD_TYPE		__uint64_t
# define __SWORD_TYPE		int
# define __UWORD_TYPE		unsigned int
# define __SLONG32_TYPE		long int
# define __ULONG32_TYPE		unsigned long int
# define __S64_TYPE		__int64_t
# define __U64_TYPE		__uint64_t
/* We want __extension__ before typedef's that use nonstandard base types
   such as `long long' in C89 mode.  */
# define __STD_TYPE		__extension__ typedef
#if 0 /* disabled by -frewrite-includes */
#if 0
#elif __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#elif 1 /* evaluated by -frewrite-includes */
# 128 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# define __SQUAD_TYPE		long int
# define __UQUAD_TYPE		unsigned long int
# define __SWORD_TYPE		long int
# define __UWORD_TYPE		unsigned long int
# define __SLONG32_TYPE		int
# define __ULONG32_TYPE		unsigned int
# define __S64_TYPE		long int
# define __U64_TYPE		unsigned long int
/* No need to mark the typedef with __extension__.   */
# define __STD_TYPE		typedef
#else
# 139 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# error
#endif
# 141 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* typesizes.h expanded by -frewrite-includes */
#include <bits/typesizes.h>	/* Defines __*_T_TYPE macros.  */
#else /* typesizes.h expanded by -frewrite-includes */
# 141 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
/* bits/typesizes.h -- underlying types for *_t.  Linux/x86-64 version.
   Copyright (C) 2012-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_TYPES_H
# error "Never include <bits/typesizes.h> directly; use <sys/types.h> instead."
#endif
# 22 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4

#ifndef	_BITS_TYPESIZES_H
#define	_BITS_TYPESIZES_H	1

/* See <bits/types.h> for the meaning of these macros.  This file exists so
   that <bits/types.h> need not vary across different GNU platforms.  */

/* X32 kernel interface is 64-bit.  */
#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 31 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
# define __SYSCALL_SLONG_TYPE	__SQUAD_TYPE
# define __SYSCALL_ULONG_TYPE	__UQUAD_TYPE
#else
# 34 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
# define __SYSCALL_SLONG_TYPE	__SLONGWORD_TYPE
# define __SYSCALL_ULONG_TYPE	__ULONGWORD_TYPE
#endif
# 37 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4

#define __DEV_T_TYPE		__UQUAD_TYPE
#define __UID_T_TYPE		__U32_TYPE
#define __GID_T_TYPE		__U32_TYPE
#define __INO_T_TYPE		__SYSCALL_ULONG_TYPE
#define __INO64_T_TYPE		__UQUAD_TYPE
#define __MODE_T_TYPE		__U32_TYPE
#ifdef __x86_64__
# define __NLINK_T_TYPE		__SYSCALL_ULONG_TYPE
# define __FSWORD_T_TYPE	__SYSCALL_SLONG_TYPE
#else
# 48 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
# define __NLINK_T_TYPE		__UWORD_TYPE
# define __FSWORD_T_TYPE	__SWORD_TYPE
#endif
# 51 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
#define __OFF_T_TYPE		__SYSCALL_SLONG_TYPE
#define __OFF64_T_TYPE		__SQUAD_TYPE
#define __PID_T_TYPE		__S32_TYPE
#define __RLIM_T_TYPE		__SYSCALL_ULONG_TYPE
#define __RLIM64_T_TYPE		__UQUAD_TYPE
#define __BLKCNT_T_TYPE		__SYSCALL_SLONG_TYPE
#define __BLKCNT64_T_TYPE	__SQUAD_TYPE
#define __FSBLKCNT_T_TYPE	__SYSCALL_ULONG_TYPE
#define __FSBLKCNT64_T_TYPE	__UQUAD_TYPE
#define __FSFILCNT_T_TYPE	__SYSCALL_ULONG_TYPE
#define __FSFILCNT64_T_TYPE	__UQUAD_TYPE
#define __ID_T_TYPE		__U32_TYPE
#define __CLOCK_T_TYPE		__SYSCALL_SLONG_TYPE
#define __TIME_T_TYPE		__SYSCALL_SLONG_TYPE
#define __USECONDS_T_TYPE	__U32_TYPE
#define __SUSECONDS_T_TYPE	__SYSCALL_SLONG_TYPE
#define __SUSECONDS64_T_TYPE	__SQUAD_TYPE
#define __DADDR_T_TYPE		__S32_TYPE
#define __KEY_T_TYPE		__S32_TYPE
#define __CLOCKID_T_TYPE	__S32_TYPE
#define __TIMER_T_TYPE		void *
#define __BLKSIZE_T_TYPE	__SYSCALL_SLONG_TYPE
#define __FSID_T_TYPE		struct { int __val[2]; }
#define __SSIZE_T_TYPE		__SWORD_TYPE
#define __CPU_MASK_TYPE 	__SYSCALL_ULONG_TYPE

#ifdef __x86_64__
/* Tell the libc code that off_t and off64_t are actually the same type
   for all ABI purposes, even if possibly expressed as different base types
   for C type-checking purposes.  */
# define __OFF_T_MATCHES_OFF64_T	1

/* Same for ino_t and ino64_t.  */
# define __INO_T_MATCHES_INO64_T	1

/* And for __rlim_t and __rlim64_t.  */
# define __RLIM_T_MATCHES_RLIM64_T	1

/* And for fsblkcnt_t, fsblkcnt64_t, fsfilcnt_t and fsfilcnt64_t.  */
# define __STATFS_MATCHES_STATFS64  1

/* And for getitimer, setitimer and rusage  */
# define __KERNEL_OLD_TIMEVAL_MATCHES_TIMEVAL64 1
#else
# 95 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
# define __RLIM_T_MATCHES_RLIM64_T	0

# define __STATFS_MATCHES_STATFS64  0

# define __KERNEL_OLD_TIMEVAL_MATCHES_TIMEVAL64 0
#endif
# 101 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4

/* Number of descriptors that can fit in an `fd_set'.  */
#define __FD_SETSIZE		1024


#endif /* bits/typesizes.h */
# 107 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
#endif /* typesizes.h expanded by -frewrite-includes */
# 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* time64.h expanded by -frewrite-includes */
#include <bits/time64.h>	/* Defines __TIME*_T_TYPE macros.  */
#else /* time64.h expanded by -frewrite-includes */
# 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time64.h" 1 3 4
/* bits/time64.h -- underlying types for __time64_t.  Generic version.
   Copyright (C) 2018-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_TYPES_H
# error "Never include <bits/time64.h> directly; use <sys/types.h> instead."
#endif
# 22 "/usr/include/x86_64-linux-gnu/bits/time64.h" 3 4

#ifndef	_BITS_TIME64_H
#define	_BITS_TIME64_H	1

/* Define __TIME64_T_TYPE so that it is always a 64-bit type.  */

#if 0 /* disabled by -frewrite-includes */
#if __TIMESIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 29 "/usr/include/x86_64-linux-gnu/bits/time64.h" 3 4
/* If we already have 64-bit time type then use it.  */
# define __TIME64_T_TYPE		__TIME_T_TYPE
#else
# 32 "/usr/include/x86_64-linux-gnu/bits/time64.h" 3 4
/* Define a 64-bit time type alongsize the 32-bit one.  */
# define __TIME64_T_TYPE		__SQUAD_TYPE
#endif
# 35 "/usr/include/x86_64-linux-gnu/bits/time64.h" 3 4

#endif /* bits/time64.h */
# 37 "/usr/include/x86_64-linux-gnu/bits/time64.h" 3 4
#endif /* time64.h expanded by -frewrite-includes */
# 143 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


__STD_TYPE __DEV_T_TYPE __dev_t;	/* Type of device numbers.  */
__STD_TYPE __UID_T_TYPE __uid_t;	/* Type of user identifications.  */
__STD_TYPE __GID_T_TYPE __gid_t;	/* Type of group identifications.  */
__STD_TYPE __INO_T_TYPE __ino_t;	/* Type of file serial numbers.  */
__STD_TYPE __INO64_T_TYPE __ino64_t;	/* Type of file serial numbers (LFS).*/
__STD_TYPE __MODE_T_TYPE __mode_t;	/* Type of file attribute bitmasks.  */
__STD_TYPE __NLINK_T_TYPE __nlink_t;	/* Type of file link counts.  */
__STD_TYPE __OFF_T_TYPE __off_t;	/* Type of file sizes and offsets.  */
__STD_TYPE __OFF64_T_TYPE __off64_t;	/* Type of file sizes and offsets (LFS).  */
__STD_TYPE __PID_T_TYPE __pid_t;	/* Type of process identifications.  */
__STD_TYPE __FSID_T_TYPE __fsid_t;	/* Type of file system IDs.  */
__STD_TYPE __CLOCK_T_TYPE __clock_t;	/* Type of CPU usage counts.  */
__STD_TYPE __RLIM_T_TYPE __rlim_t;	/* Type for resource measurement.  */
__STD_TYPE __RLIM64_T_TYPE __rlim64_t;	/* Type for resource measurement (LFS).  */
__STD_TYPE __ID_T_TYPE __id_t;		/* General type for IDs.  */
__STD_TYPE __TIME_T_TYPE __time_t;	/* Seconds since the Epoch.  */
__STD_TYPE __USECONDS_T_TYPE __useconds_t; /* Count of microseconds.  */
__STD_TYPE __SUSECONDS_T_TYPE __suseconds_t; /* Signed count of microseconds.  */
__STD_TYPE __SUSECONDS64_T_TYPE __suseconds64_t;

__STD_TYPE __DADDR_T_TYPE __daddr_t;	/* The type of a disk address.  */
__STD_TYPE __KEY_T_TYPE __key_t;	/* Type of an IPC key.  */

/* Clock ID used in clock and timer functions.  */
__STD_TYPE __CLOCKID_T_TYPE __clockid_t;

/* Timer ID returned by `timer_create'.  */
__STD_TYPE __TIMER_T_TYPE __timer_t;

/* Type to represent block size.  */
__STD_TYPE __BLKSIZE_T_TYPE __blksize_t;

/* Types from the Large File Support interface.  */

/* Type to count number of disk blocks.  */
__STD_TYPE __BLKCNT_T_TYPE __blkcnt_t;
__STD_TYPE __BLKCNT64_T_TYPE __blkcnt64_t;

/* Type to count file system blocks.  */
__STD_TYPE __FSBLKCNT_T_TYPE __fsblkcnt_t;
__STD_TYPE __FSBLKCNT64_T_TYPE __fsblkcnt64_t;

/* Type to count file system nodes.  */
__STD_TYPE __FSFILCNT_T_TYPE __fsfilcnt_t;
__STD_TYPE __FSFILCNT64_T_TYPE __fsfilcnt64_t;

/* Type of miscellaneous file system fields.  */
__STD_TYPE __FSWORD_T_TYPE __fsword_t;

__STD_TYPE __SSIZE_T_TYPE __ssize_t; /* Type of a byte count, or error.  */

/* Signed long type used in system calls.  */
__STD_TYPE __SYSCALL_SLONG_TYPE __syscall_slong_t;
/* Unsigned long type used in system calls.  */
__STD_TYPE __SYSCALL_ULONG_TYPE __syscall_ulong_t;

/* These few don't really vary by system, they always correspond
   to one of the other defined types.  */
typedef __off64_t __loff_t;	/* Type of file sizes and offsets (LFS).  */
typedef char *__caddr_t;

/* Duplicates info from stdint.h but this is used in unistd.h.  */
__STD_TYPE __SWORD_TYPE __intptr_t;

/* Duplicate info from sys/socket.h.  */
__STD_TYPE __U32_TYPE __socklen_t;

/* C99: An integer type that can be accessed as an atomic entity,
   even in the presence of asynchronous interrupts.
   It is not currently necessary for this to be machine-specific.  */
typedef int __sig_atomic_t;

/* Seconds since the Epoch, visible to user code when time_t is too
   narrow only for consistency with the old way of widening too-narrow
   types.  User code should never use __time64_t.  */
#if 0 /* disabled by -frewrite-includes */
#if __TIMESIZE == 64 && defined __LIBC
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 221 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# define __time64_t __time_t
#if 0 /* disabled by -frewrite-includes */
#if 0
#elif __TIMESIZE != 64
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 223 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
__STD_TYPE __TIME64_T_TYPE __time64_t;
#endif
# 225 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4

#undef __STD_TYPE

#endif /* bits/types.h */
# 229 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
#endif /* types.h expanded by -frewrite-includes */
# 28 "/usr/include/stdint.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* wchar.h expanded by -frewrite-includes */
#include <bits/wchar.h>
#else /* wchar.h expanded by -frewrite-includes */
# 28 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 1 3 4
/* wchar_t type related definitions.
   Copyright (C) 2000-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_WCHAR_H
#define _BITS_WCHAR_H	1

/* The fallback definitions, for when __WCHAR_MAX__ or __WCHAR_MIN__
   are not defined, give the right value and type as long as both int
   and wchar_t are 32-bit types.  Adding L'\0' to a constant value
   ensures that the type is correct; it is necessary to use (L'\0' +
   0) rather than just L'\0' so that the type in C++ is the promoted
   version of wchar_t rather than the distinct wchar_t type itself.
   Because wchar_t in preprocessor #if expressions is treated as
   intmax_t or uintmax_t, the expression (L'\0' - 1) would have the
   wrong value for WCHAR_MAX in such expressions and so cannot be used
   to define __WCHAR_MAX in the unsigned case.  */

#ifdef __WCHAR_MAX__
# define __WCHAR_MAX	__WCHAR_MAX__
#if 0 /* disabled by -frewrite-includes */
#if 0
#elif L'\0' - 1 > 0
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 36 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 3 4
# define __WCHAR_MAX	(0xffffffffu + L'\0')
#else
# 38 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 3 4
# define __WCHAR_MAX	(0x7fffffff + L'\0')
#endif
# 40 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 3 4

#ifdef __WCHAR_MIN__
# define __WCHAR_MIN	__WCHAR_MIN__
#if 0 /* disabled by -frewrite-includes */
#if 0
#elif L'\0' - 1 > 0
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 44 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 3 4
# define __WCHAR_MIN	(L'\0' + 0)
#else
# 46 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 3 4
# define __WCHAR_MIN	(-__WCHAR_MAX - 1)
#endif
# 48 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 3 4

#endif	/* bits/wchar.h */
# 50 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 3 4
#endif /* wchar.h expanded by -frewrite-includes */
# 29 "/usr/include/stdint.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* wordsize.h expanded by -frewrite-includes */
#include <bits/wordsize.h>
#else /* wordsize.h expanded by -frewrite-includes */
# 29 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */

#if 0 /* disabled by -frewrite-includes */
#if defined __x86_64__ && !defined __ILP32__
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 4 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	64
#else
# 6 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE	32
#define __WORDSIZE32_SIZE_ULONG		0
#define __WORDSIZE32_PTRDIFF_LONG	0
#endif
# 10 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4

#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32	1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE		64
#else
# 16 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
# define __WORDSIZE_TIME64_COMPAT32	0
#endif
# 18 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 3 4
#endif /* wordsize.h expanded by -frewrite-includes */
# 30 "/usr/include/stdint.h" 2 3 4

/* Exact integral types.  */

/* Signed.  */
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdint-intn.h expanded by -frewrite-includes */
#include <bits/stdint-intn.h>
#else /* stdint-intn.h expanded by -frewrite-includes */
# 34 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
/* Define intN_t types.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_STDINT_INTN_H
#define _BITS_STDINT_INTN_H	1

#if 0 /* expanded by -frewrite-includes */
#include <bits/types.h>
#endif /* expanded by -frewrite-includes */
# 22 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

#endif /* bits/stdint-intn.h */
# 30 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4
#endif /* stdint-intn.h expanded by -frewrite-includes */
# 35 "/usr/include/stdint.h" 2 3 4

/* Unsigned.  */
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdint-uintn.h expanded by -frewrite-includes */
#include <bits/stdint-uintn.h>
#else /* stdint-uintn.h expanded by -frewrite-includes */
# 37 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 1 3 4
/* Define uintN_t types.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_STDINT_UINTN_H
#define _BITS_STDINT_UINTN_H	1

#if 0 /* expanded by -frewrite-includes */
#include <bits/types.h>
#endif /* expanded by -frewrite-includes */
# 22 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 3 4

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

#endif /* bits/stdint-uintn.h */
# 30 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 3 4
#endif /* stdint-uintn.h expanded by -frewrite-includes */
# 38 "/usr/include/stdint.h" 2 3 4


/* Small types.  */

/* Signed.  */
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;

/* Unsigned.  */
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;


/* Fast types.  */

/* Signed.  */
typedef signed char		int_fast8_t;
#if 0 /* disabled by -frewrite-includes */
#if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 60 "/usr/include/stdint.h" 3 4
typedef long int		int_fast16_t;
typedef long int		int_fast32_t;
typedef long int		int_fast64_t;
#else
# 64 "/usr/include/stdint.h" 3 4
typedef int			int_fast16_t;
typedef int			int_fast32_t;
__extension__
typedef long long int		int_fast64_t;
#endif
# 69 "/usr/include/stdint.h" 3 4

/* Unsigned.  */
typedef unsigned char		uint_fast8_t;
#if 0 /* disabled by -frewrite-includes */
#if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 73 "/usr/include/stdint.h" 3 4
typedef unsigned long int	uint_fast16_t;
typedef unsigned long int	uint_fast32_t;
typedef unsigned long int	uint_fast64_t;
#else
# 77 "/usr/include/stdint.h" 3 4
typedef unsigned int		uint_fast16_t;
typedef unsigned int		uint_fast32_t;
__extension__
typedef unsigned long long int	uint_fast64_t;
#endif
# 82 "/usr/include/stdint.h" 3 4


/* Types for `void *' pointers.  */
#if 0 /* disabled by -frewrite-includes */
#if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 86 "/usr/include/stdint.h" 3 4
# ifndef __intptr_t_defined
typedef long int		intptr_t;
#  define __intptr_t_defined
# endif
# 90 "/usr/include/stdint.h" 3 4
typedef unsigned long int	uintptr_t;
#else
# 92 "/usr/include/stdint.h" 3 4
# ifndef __intptr_t_defined
typedef int			intptr_t;
#  define __intptr_t_defined
# endif
# 96 "/usr/include/stdint.h" 3 4
typedef unsigned int		uintptr_t;
#endif
# 98 "/usr/include/stdint.h" 3 4


/* Largest integral types.  */
typedef __intmax_t		intmax_t;
typedef __uintmax_t		uintmax_t;


#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 106 "/usr/include/stdint.h" 3 4
#  define __INT64_C(c)	c ## L
#  define __UINT64_C(c)	c ## UL
# else
# 109 "/usr/include/stdint.h" 3 4
#  define __INT64_C(c)	c ## LL
#  define __UINT64_C(c)	c ## ULL
# endif
# 112 "/usr/include/stdint.h" 3 4

/* Limits of integral types.  */

/* Minimum of signed integral types.  */
# define INT8_MIN		(-128)
# define INT16_MIN		(-32767-1)
# define INT32_MIN		(-2147483647-1)
# define INT64_MIN		(-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types.  */
# define INT8_MAX		(127)
# define INT16_MAX		(32767)
# define INT32_MAX		(2147483647)
# define INT64_MAX		(__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types.  */
# define UINT8_MAX		(255)
# define UINT16_MAX		(65535)
# define UINT32_MAX		(4294967295U)
# define UINT64_MAX		(__UINT64_C(18446744073709551615))


/* Minimum of signed integral types having a minimum size.  */
# define INT_LEAST8_MIN		(-128)
# define INT_LEAST16_MIN	(-32767-1)
# define INT_LEAST32_MIN	(-2147483647-1)
# define INT_LEAST64_MIN	(-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types having a minimum size.  */
# define INT_LEAST8_MAX		(127)
# define INT_LEAST16_MAX	(32767)
# define INT_LEAST32_MAX	(2147483647)
# define INT_LEAST64_MAX	(__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types having a minimum size.  */
# define UINT_LEAST8_MAX	(255)
# define UINT_LEAST16_MAX	(65535)
# define UINT_LEAST32_MAX	(4294967295U)
# define UINT_LEAST64_MAX	(__UINT64_C(18446744073709551615))


/* Minimum of fast signed integral types having a minimum size.  */
# define INT_FAST8_MIN		(-128)
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 154 "/usr/include/stdint.h" 3 4
#  define INT_FAST16_MIN	(-9223372036854775807L-1)
#  define INT_FAST32_MIN	(-9223372036854775807L-1)
# else
# 157 "/usr/include/stdint.h" 3 4
#  define INT_FAST16_MIN	(-2147483647-1)
#  define INT_FAST32_MIN	(-2147483647-1)
# endif
# 160 "/usr/include/stdint.h" 3 4
# define INT_FAST64_MIN		(-__INT64_C(9223372036854775807)-1)
/* Maximum of fast signed integral types having a minimum size.  */
# define INT_FAST8_MAX		(127)
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 164 "/usr/include/stdint.h" 3 4
#  define INT_FAST16_MAX	(9223372036854775807L)
#  define INT_FAST32_MAX	(9223372036854775807L)
# else
# 167 "/usr/include/stdint.h" 3 4
#  define INT_FAST16_MAX	(2147483647)
#  define INT_FAST32_MAX	(2147483647)
# endif
# 170 "/usr/include/stdint.h" 3 4
# define INT_FAST64_MAX		(__INT64_C(9223372036854775807))

/* Maximum of fast unsigned integral types having a minimum size.  */
# define UINT_FAST8_MAX		(255)
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 175 "/usr/include/stdint.h" 3 4
#  define UINT_FAST16_MAX	(18446744073709551615UL)
#  define UINT_FAST32_MAX	(18446744073709551615UL)
# else
# 178 "/usr/include/stdint.h" 3 4
#  define UINT_FAST16_MAX	(4294967295U)
#  define UINT_FAST32_MAX	(4294967295U)
# endif
# 181 "/usr/include/stdint.h" 3 4
# define UINT_FAST64_MAX	(__UINT64_C(18446744073709551615))


/* Values to test for integral types holding `void *' pointer.  */
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 186 "/usr/include/stdint.h" 3 4
#  define INTPTR_MIN		(-9223372036854775807L-1)
#  define INTPTR_MAX		(9223372036854775807L)
#  define UINTPTR_MAX		(18446744073709551615UL)
# else
# 190 "/usr/include/stdint.h" 3 4
#  define INTPTR_MIN		(-2147483647-1)
#  define INTPTR_MAX		(2147483647)
#  define UINTPTR_MAX		(4294967295U)
# endif
# 194 "/usr/include/stdint.h" 3 4


/* Minimum for largest signed integral type.  */
# define INTMAX_MIN		(-__INT64_C(9223372036854775807)-1)
/* Maximum for largest signed integral type.  */
# define INTMAX_MAX		(__INT64_C(9223372036854775807))

/* Maximum for largest unsigned integral type.  */
# define UINTMAX_MAX		(__UINT64_C(18446744073709551615))


/* Limits of other integer types.  */

/* Limits of `ptrdiff_t' type.  */
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 209 "/usr/include/stdint.h" 3 4
#  define PTRDIFF_MIN		(-9223372036854775807L-1)
#  define PTRDIFF_MAX		(9223372036854775807L)
# else
# 212 "/usr/include/stdint.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if __WORDSIZE32_PTRDIFF_LONG
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 213 "/usr/include/stdint.h" 3 4
#   define PTRDIFF_MIN		(-2147483647L-1)
#   define PTRDIFF_MAX		(2147483647L)
#  else
# 216 "/usr/include/stdint.h" 3 4
#   define PTRDIFF_MIN		(-2147483647-1)
#   define PTRDIFF_MAX		(2147483647)
#  endif
# 219 "/usr/include/stdint.h" 3 4
# endif
# 220 "/usr/include/stdint.h" 3 4

/* Limits of `sig_atomic_t'.  */
# define SIG_ATOMIC_MIN		(-2147483647-1)
# define SIG_ATOMIC_MAX		(2147483647)

/* Limit of `size_t' type.  */
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 227 "/usr/include/stdint.h" 3 4
#  define SIZE_MAX		(18446744073709551615UL)
# else
# 229 "/usr/include/stdint.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if __WORDSIZE32_SIZE_ULONG
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 230 "/usr/include/stdint.h" 3 4
#   define SIZE_MAX		(4294967295UL)
#  else
# 232 "/usr/include/stdint.h" 3 4
#   define SIZE_MAX		(4294967295U)
#  endif
# 234 "/usr/include/stdint.h" 3 4
# endif
# 235 "/usr/include/stdint.h" 3 4

/* Limits of `wchar_t'.  */
# ifndef WCHAR_MIN
/* These constants might also be defined in <wchar.h>.  */
#  define WCHAR_MIN		__WCHAR_MIN
#  define WCHAR_MAX		__WCHAR_MAX
# endif
# 242 "/usr/include/stdint.h" 3 4

/* Limits of `wint_t'.  */
# define WINT_MIN		(0u)
# define WINT_MAX		(4294967295u)

/* Signed.  */
# define INT8_C(c)	c
# define INT16_C(c)	c
# define INT32_C(c)	c
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 252 "/usr/include/stdint.h" 3 4
#  define INT64_C(c)	c ## L
# else
# 254 "/usr/include/stdint.h" 3 4
#  define INT64_C(c)	c ## LL
# endif
# 256 "/usr/include/stdint.h" 3 4

/* Unsigned.  */
# define UINT8_C(c)	c
# define UINT16_C(c)	c
# define UINT32_C(c)	c ## U
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 262 "/usr/include/stdint.h" 3 4
#  define UINT64_C(c)	c ## UL
# else
# 264 "/usr/include/stdint.h" 3 4
#  define UINT64_C(c)	c ## ULL
# endif
# 266 "/usr/include/stdint.h" 3 4

/* Maximal type.  */
#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 269 "/usr/include/stdint.h" 3 4
#  define INTMAX_C(c)	c ## L
#  define UINTMAX_C(c)	c ## UL
# else
# 272 "/usr/include/stdint.h" 3 4
#  define INTMAX_C(c)	c ## LL
#  define UINTMAX_C(c)	c ## ULL
# endif
# 275 "/usr/include/stdint.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (IEC_60559_BFP_EXT_C2X)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 277 "/usr/include/stdint.h" 3 4

# define INT8_WIDTH 8
# define UINT8_WIDTH 8
# define INT16_WIDTH 16
# define UINT16_WIDTH 16
# define INT32_WIDTH 32
# define UINT32_WIDTH 32
# define INT64_WIDTH 64
# define UINT64_WIDTH 64

# define INT_LEAST8_WIDTH 8
# define UINT_LEAST8_WIDTH 8
# define INT_LEAST16_WIDTH 16
# define UINT_LEAST16_WIDTH 16
# define INT_LEAST32_WIDTH 32
# define UINT_LEAST32_WIDTH 32
# define INT_LEAST64_WIDTH 64
# define UINT_LEAST64_WIDTH 64

# define INT_FAST8_WIDTH 8
# define UINT_FAST8_WIDTH 8
# define INT_FAST16_WIDTH __WORDSIZE
# define UINT_FAST16_WIDTH __WORDSIZE
# define INT_FAST32_WIDTH __WORDSIZE
# define UINT_FAST32_WIDTH __WORDSIZE
# define INT_FAST64_WIDTH 64
# define UINT_FAST64_WIDTH 64

# define INTPTR_WIDTH __WORDSIZE
# define UINTPTR_WIDTH __WORDSIZE

# define INTMAX_WIDTH 64
# define UINTMAX_WIDTH 64

# define PTRDIFF_WIDTH __WORDSIZE
# define SIG_ATOMIC_WIDTH 32
# define SIZE_WIDTH __WORDSIZE
# define WCHAR_WIDTH 32
# define WINT_WIDTH 32

#endif
# 318 "/usr/include/stdint.h" 3 4

#endif /* stdint.h */
# 320 "/usr/include/stdint.h" 3 4
#endif /* stdint.h expanded by -frewrite-includes */
# 57 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 2 3

# ifdef __STDC_LIMIT_MACROS_DEFINED_BY_CLANG
#  undef __STDC_LIMIT_MACROS
#  undef __STDC_LIMIT_MACROS_DEFINED_BY_CLANG
# endif
# 62 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# ifdef __STDC_CONSTANT_MACROS_DEFINED_BY_CLANG
#  undef __STDC_CONSTANT_MACROS
#  undef __STDC_CONSTANT_MACROS_DEFINED_BY_CLANG
# endif
# 66 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#else
# 68 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* C99 7.18.1.1 Exact-width integer types.
 * C99 7.18.1.2 Minimum-width integer types.
 * C99 7.18.1.3 Fastest minimum-width integer types.
 *
 * The standard requires that exact-width type be defined for 8-, 16-, 32-, and
 * 64-bit types if they are implemented. Other exact width types are optional.
 * This implementation defines an exact-width types for every integer width
 * that is represented in the standard integer types.
 *
 * The standard also requires minimum-width types be defined for 8-, 16-, 32-,
 * and 64-bit widths regardless of whether there are corresponding exact-width
 * types.
 *
 * To accommodate targets that are missing types that are exactly 8, 16, 32, or
 * 64 bits wide, this implementation takes an approach of cascading
 * redefinitions, redefining __int_leastN_t to successively smaller exact-width
 * types. It is therefore important that the types are defined in order of
 * descending widths.
 *
 * We currently assume that the minimum-width types and the fastest
 * minimum-width types are the same. This is allowed by the standard, but is
 * suboptimal.
 *
 * In violation of the standard, some targets do not implement a type that is
 * wide enough to represent all of the required widths (8-, 16-, 32-, 64-bit).
 * To accommodate these targets, a required minimum-width type is only
 * defined if there exists an exact-width type of equal or greater width.
 */

#ifdef __INT64_TYPE__
# ifndef __int8_t_defined /* glibc sys/types.h also defines int64_t*/
typedef __INT64_TYPE__ int64_t;
# endif /* __int8_t_defined */
# 102 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
typedef __UINT64_TYPE__ uint64_t;
# undef __int_least64_t
# define __int_least64_t int64_t
# undef __uint_least64_t
# define __uint_least64_t uint64_t
# undef __int_least32_t
# define __int_least32_t int64_t
# undef __uint_least32_t
# define __uint_least32_t uint64_t
# undef __int_least16_t
# define __int_least16_t int64_t
# undef __uint_least16_t
# define __uint_least16_t uint64_t
# undef __int_least8_t
# define __int_least8_t int64_t
# undef __uint_least8_t
# define __uint_least8_t uint64_t
#endif /* __INT64_TYPE__ */
# 120 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __int_least64_t
typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;
typedef __int_least64_t int_fast64_t;
typedef __uint_least64_t uint_fast64_t;
#endif /* __int_least64_t */
# 127 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __INT56_TYPE__
typedef __INT56_TYPE__ int56_t;
typedef __UINT56_TYPE__ uint56_t;
typedef int56_t int_least56_t;
typedef uint56_t uint_least56_t;
typedef int56_t int_fast56_t;
typedef uint56_t uint_fast56_t;
# undef __int_least32_t
# define __int_least32_t int56_t
# undef __uint_least32_t
# define __uint_least32_t uint56_t
# undef __int_least16_t
# define __int_least16_t int56_t
# undef __uint_least16_t
# define __uint_least16_t uint56_t
# undef __int_least8_t
# define __int_least8_t int56_t
# undef __uint_least8_t
# define __uint_least8_t uint56_t
#endif /* __INT56_TYPE__ */
# 148 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT48_TYPE__
typedef __INT48_TYPE__ int48_t;
typedef __UINT48_TYPE__ uint48_t;
typedef int48_t int_least48_t;
typedef uint48_t uint_least48_t;
typedef int48_t int_fast48_t;
typedef uint48_t uint_fast48_t;
# undef __int_least32_t
# define __int_least32_t int48_t
# undef __uint_least32_t
# define __uint_least32_t uint48_t
# undef __int_least16_t
# define __int_least16_t int48_t
# undef __uint_least16_t
# define __uint_least16_t uint48_t
# undef __int_least8_t
# define __int_least8_t int48_t
# undef __uint_least8_t
# define __uint_least8_t uint48_t
#endif /* __INT48_TYPE__ */
# 170 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT40_TYPE__
typedef __INT40_TYPE__ int40_t;
typedef __UINT40_TYPE__ uint40_t;
typedef int40_t int_least40_t;
typedef uint40_t uint_least40_t;
typedef int40_t int_fast40_t;
typedef uint40_t uint_fast40_t;
# undef __int_least32_t
# define __int_least32_t int40_t
# undef __uint_least32_t
# define __uint_least32_t uint40_t
# undef __int_least16_t
# define __int_least16_t int40_t
# undef __uint_least16_t
# define __uint_least16_t uint40_t
# undef __int_least8_t
# define __int_least8_t int40_t
# undef __uint_least8_t
# define __uint_least8_t uint40_t
#endif /* __INT40_TYPE__ */
# 192 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT32_TYPE__

# ifndef __int8_t_defined /* glibc sys/types.h also defines int32_t*/
typedef __INT32_TYPE__ int32_t;
# endif /* __int8_t_defined */
# 199 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

# ifndef __uint32_t_defined  /* more glibc compatibility */
# define __uint32_t_defined
typedef __UINT32_TYPE__ uint32_t;
# endif /* __uint32_t_defined */
# 204 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

# undef __int_least32_t
# define __int_least32_t int32_t
# undef __uint_least32_t
# define __uint_least32_t uint32_t
# undef __int_least16_t
# define __int_least16_t int32_t
# undef __uint_least16_t
# define __uint_least16_t uint32_t
# undef __int_least8_t
# define __int_least8_t int32_t
# undef __uint_least8_t
# define __uint_least8_t uint32_t
#endif /* __INT32_TYPE__ */
# 218 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __int_least32_t
typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;
typedef __int_least32_t int_fast32_t;
typedef __uint_least32_t uint_fast32_t;
#endif /* __int_least32_t */
# 225 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __INT24_TYPE__
typedef __INT24_TYPE__ int24_t;
typedef __UINT24_TYPE__ uint24_t;
typedef int24_t int_least24_t;
typedef uint24_t uint_least24_t;
typedef int24_t int_fast24_t;
typedef uint24_t uint_fast24_t;
# undef __int_least16_t
# define __int_least16_t int24_t
# undef __uint_least16_t
# define __uint_least16_t uint24_t
# undef __int_least8_t
# define __int_least8_t int24_t
# undef __uint_least8_t
# define __uint_least8_t uint24_t
#endif /* __INT24_TYPE__ */
# 242 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __INT16_TYPE__
#ifndef __int8_t_defined /* glibc sys/types.h also defines int16_t*/
typedef __INT16_TYPE__ int16_t;
#endif /* __int8_t_defined */
# 247 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
typedef __UINT16_TYPE__ uint16_t;
# undef __int_least16_t
# define __int_least16_t int16_t
# undef __uint_least16_t
# define __uint_least16_t uint16_t
# undef __int_least8_t
# define __int_least8_t int16_t
# undef __uint_least8_t
# define __uint_least8_t uint16_t
#endif /* __INT16_TYPE__ */
# 257 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __int_least16_t
typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;
typedef __int_least16_t int_fast16_t;
typedef __uint_least16_t uint_fast16_t;
#endif /* __int_least16_t */
# 264 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT8_TYPE__
#ifndef __int8_t_defined  /* glibc sys/types.h also defines int8_t*/
typedef __INT8_TYPE__ int8_t;
#endif /* __int8_t_defined */
# 270 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
typedef __UINT8_TYPE__ uint8_t;
# undef __int_least8_t
# define __int_least8_t int8_t
# undef __uint_least8_t
# define __uint_least8_t uint8_t
#endif /* __INT8_TYPE__ */
# 276 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __int_least8_t
typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;
typedef __int_least8_t int_fast8_t;
typedef __uint_least8_t uint_fast8_t;
#endif /* __int_least8_t */
# 283 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* prevent glibc sys/types.h from defining conflicting types */
#ifndef __int8_t_defined
# define __int8_t_defined
#endif /* __int8_t_defined */
# 288 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* C99 7.18.1.4 Integer types capable of holding object pointers.
 */
#define __stdint_join3(a,b,c) a ## b ## c

#ifndef _INTPTR_T
#ifndef __intptr_t_defined
typedef __INTPTR_TYPE__ intptr_t;
#define __intptr_t_defined
#define _INTPTR_T
#endif
# 299 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif
# 300 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifndef _UINTPTR_T
typedef __UINTPTR_TYPE__ uintptr_t;
#define _UINTPTR_T
#endif
# 305 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* C99 7.18.1.5 Greatest-width integer types.
 */
typedef __INTMAX_TYPE__  intmax_t;
typedef __UINTMAX_TYPE__ uintmax_t;

/* C99 7.18.4 Macros for minimum-width integer constants.
 *
 * The standard requires that integer constant macros be defined for all the
 * minimum-width types defined above. As 8-, 16-, 32-, and 64-bit minimum-width
 * types are required, the corresponding integer constant macros are defined
 * here. This implementation also defines minimum-width types for every other
 * integer width that the target implements, so corresponding macros are
 * defined below, too.
 *
 * Note that C++ should not check __STDC_CONSTANT_MACROS here, contrary to the
 * claims of the C standard (see C++ 18.3.1p2, [cstdint.syn]).
 */

#ifdef __int_least64_t
#define INT64_C(v) __INT64_C(v)
#define UINT64_C(v) __UINT64_C(v)
#endif /* __int_least64_t */
# 328 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT56_TYPE__
#define INT56_C(v) __INT56_C(v)
#define UINT56_C(v) __UINT56_C(v)
#endif /* __INT56_TYPE__ */
# 334 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT48_TYPE__
#define INT48_C(v) __INT48_C(v)
#define UINT48_C(v) __UINT48_C(v)
#endif /* __INT48_TYPE__ */
# 340 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT40_TYPE__
#define INT40_C(v) __INT40_C(v)
#define UINT40_C(v) __UINT40_C(v)
#endif /* __INT40_TYPE__ */
# 346 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __int_least32_t
#define INT32_C(v) __INT32_C(v)
#define UINT32_C(v) __UINT32_C(v)
#endif /* __int_least32_t */
# 352 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT24_TYPE__
#define INT24_C(v) __INT24_C(v)
#define UINT24_C(v) __UINT24_C(v)
#endif /* __INT24_TYPE__ */
# 358 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __int_least16_t
#define INT16_C(v) __INT16_C(v)
#define UINT16_C(v) __UINT16_C(v)
#endif /* __int_least16_t */
# 364 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __int_least8_t
#define INT8_C(v) __INT8_C(v)
#define UINT8_C(v) __UINT8_C(v)
#endif /* __int_least8_t */
# 370 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


/* C99 7.18.2.1 Limits of exact-width integer types.
 * C99 7.18.2.2 Limits of minimum-width integer types.
 * C99 7.18.2.3 Limits of fastest minimum-width integer types.
 *
 * The presence of limit macros are completely optional in C99.  This
 * implementation defines limits for all of the types (exact- and
 * minimum-width) that it defines above, using the limits of the minimum-width
 * type for any types that do not have exact-width representations.
 *
 * As in the type definitions, this section takes an approach of
 * successive-shrinking to determine which limits to use for the standard (8,
 * 16, 32, 64) bit widths when they don't have exact representations. It is
 * therefore important that the definitions be kept in order of decending
 * widths.
 *
 * Note that C++ should not check __STDC_LIMIT_MACROS here, contrary to the
 * claims of the C standard (see C++ 18.3.1p2, [cstdint.syn]).
 */

#ifdef __INT64_TYPE__
# define INT64_MAX           INT64_C( 9223372036854775807)
# define INT64_MIN         (-INT64_C( 9223372036854775807)-1)
# define UINT64_MAX         UINT64_C(18446744073709551615)

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 397 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT64_WIDTH         64
# define INT64_WIDTH          UINT64_WIDTH

# define __UINT_LEAST64_WIDTH UINT64_WIDTH
# undef __UINT_LEAST32_WIDTH
# define __UINT_LEAST32_WIDTH UINT64_WIDTH
# undef __UINT_LEAST16_WIDTH
# define __UINT_LEAST16_WIDTH UINT64_WIDTH
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX UINT64_MAX
#endif /* __STDC_VERSION__ */
# 408 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

# define __INT_LEAST64_MIN   INT64_MIN
# define __INT_LEAST64_MAX   INT64_MAX
# define __UINT_LEAST64_MAX UINT64_MAX
# undef __INT_LEAST32_MIN
# define __INT_LEAST32_MIN   INT64_MIN
# undef __INT_LEAST32_MAX
# define __INT_LEAST32_MAX   INT64_MAX
# undef __UINT_LEAST32_MAX
# define __UINT_LEAST32_MAX UINT64_MAX
# undef __INT_LEAST16_MIN
# define __INT_LEAST16_MIN   INT64_MIN
# undef __INT_LEAST16_MAX
# define __INT_LEAST16_MAX   INT64_MAX
# undef __UINT_LEAST16_MAX
# define __UINT_LEAST16_MAX UINT64_MAX
# undef __INT_LEAST8_MIN
# define __INT_LEAST8_MIN    INT64_MIN
# undef __INT_LEAST8_MAX
# define __INT_LEAST8_MAX    INT64_MAX
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX  UINT64_MAX
#endif /* __INT64_TYPE__ */
# 431 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __INT_LEAST64_MIN
# define INT_LEAST64_MIN   __INT_LEAST64_MIN
# define INT_LEAST64_MAX   __INT_LEAST64_MAX
# define UINT_LEAST64_MAX __UINT_LEAST64_MAX
# define INT_FAST64_MIN    __INT_LEAST64_MIN
# define INT_FAST64_MAX    __INT_LEAST64_MAX
# define UINT_FAST64_MAX  __UINT_LEAST64_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) &&  __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 441 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT_LEAST64_WIDTH __UINT_LEAST64_WIDTH
# define INT_LEAST64_WIDTH  UINT_LEAST64_WIDTH
# define UINT_FAST64_WIDTH  __UINT_LEAST64_WIDTH
# define INT_FAST64_WIDTH   UINT_FAST64_WIDTH
#endif /* __STDC_VERSION__ */
# 446 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT_LEAST64_MIN */
# 447 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT56_TYPE__
# define INT56_MAX           INT56_C(36028797018963967)
# define INT56_MIN         (-INT56_C(36028797018963967)-1)
# define UINT56_MAX         UINT56_C(72057594037927935)
# define INT_LEAST56_MIN     INT56_MIN
# define INT_LEAST56_MAX     INT56_MAX
# define UINT_LEAST56_MAX   UINT56_MAX
# define INT_FAST56_MIN      INT56_MIN
# define INT_FAST56_MAX      INT56_MAX
# define UINT_FAST56_MAX    UINT56_MAX

# undef __INT_LEAST32_MIN
# define __INT_LEAST32_MIN   INT56_MIN
# undef __INT_LEAST32_MAX
# define __INT_LEAST32_MAX   INT56_MAX
# undef __UINT_LEAST32_MAX
# define __UINT_LEAST32_MAX UINT56_MAX
# undef __INT_LEAST16_MIN
# define __INT_LEAST16_MIN   INT56_MIN
# undef __INT_LEAST16_MAX
# define __INT_LEAST16_MAX   INT56_MAX
# undef __UINT_LEAST16_MAX
# define __UINT_LEAST16_MAX UINT56_MAX
# undef __INT_LEAST8_MIN
# define __INT_LEAST8_MIN    INT56_MIN
# undef __INT_LEAST8_MAX
# define __INT_LEAST8_MAX    INT56_MAX
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX  UINT56_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 480 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT56_WIDTH         56
# define INT56_WIDTH          UINT56_WIDTH
# define UINT_LEAST56_WIDTH   UINT56_WIDTH
# define INT_LEAST56_WIDTH    UINT_LEAST56_WIDTH
# define UINT_FAST56_WIDTH    UINT56_WIDTH
# define INT_FAST56_WIDTH     UINT_FAST56_WIDTH
# undef __UINT_LEAST32_WIDTH
# define __UINT_LEAST32_WIDTH UINT56_WIDTH
# undef __UINT_LEAST16_WIDTH
# define __UINT_LEAST16_WIDTH UINT56_WIDTH
# undef __UINT_LEAST8_WIDTH
# define __UINT_LEAST8_WIDTH  UINT56_WIDTH
#endif /* __STDC_VERSION__ */
# 493 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT56_TYPE__ */
# 494 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT48_TYPE__
# define INT48_MAX           INT48_C(140737488355327)
# define INT48_MIN         (-INT48_C(140737488355327)-1)
# define UINT48_MAX         UINT48_C(281474976710655)
# define INT_LEAST48_MIN     INT48_MIN
# define INT_LEAST48_MAX     INT48_MAX
# define UINT_LEAST48_MAX   UINT48_MAX
# define INT_FAST48_MIN      INT48_MIN
# define INT_FAST48_MAX      INT48_MAX
# define UINT_FAST48_MAX    UINT48_MAX

# undef __INT_LEAST32_MIN
# define __INT_LEAST32_MIN   INT48_MIN
# undef __INT_LEAST32_MAX
# define __INT_LEAST32_MAX   INT48_MAX
# undef __UINT_LEAST32_MAX
# define __UINT_LEAST32_MAX UINT48_MAX
# undef __INT_LEAST16_MIN
# define __INT_LEAST16_MIN   INT48_MIN
# undef __INT_LEAST16_MAX
# define __INT_LEAST16_MAX   INT48_MAX
# undef __UINT_LEAST16_MAX
# define __UINT_LEAST16_MAX UINT48_MAX
# undef __INT_LEAST8_MIN
# define __INT_LEAST8_MIN    INT48_MIN
# undef __INT_LEAST8_MAX
# define __INT_LEAST8_MAX    INT48_MAX
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX  UINT48_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 527 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#define UINT48_WIDTH         48
#define INT48_WIDTH          UINT48_WIDTH
#define UINT_LEAST48_WIDTH   UINT48_WIDTH
#define INT_LEAST48_WIDTH    UINT_LEAST48_WIDTH
#define UINT_FAST48_WIDTH    UINT48_WIDTH
#define INT_FAST48_WIDTH     UINT_FAST48_WIDTH
#undef __UINT_LEAST32_WIDTH
#define __UINT_LEAST32_WIDTH UINT48_WIDTH
# undef __UINT_LEAST16_WIDTH
#define __UINT_LEAST16_WIDTH UINT48_WIDTH
# undef __UINT_LEAST8_WIDTH
#define __UINT_LEAST8_WIDTH  UINT48_WIDTH
#endif /* __STDC_VERSION__ */
# 540 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT48_TYPE__ */
# 541 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT40_TYPE__
# define INT40_MAX           INT40_C(549755813887)
# define INT40_MIN         (-INT40_C(549755813887)-1)
# define UINT40_MAX         UINT40_C(1099511627775)
# define INT_LEAST40_MIN     INT40_MIN
# define INT_LEAST40_MAX     INT40_MAX
# define UINT_LEAST40_MAX   UINT40_MAX
# define INT_FAST40_MIN      INT40_MIN
# define INT_FAST40_MAX      INT40_MAX
# define UINT_FAST40_MAX    UINT40_MAX

# undef __INT_LEAST32_MIN
# define __INT_LEAST32_MIN   INT40_MIN
# undef __INT_LEAST32_MAX
# define __INT_LEAST32_MAX   INT40_MAX
# undef __UINT_LEAST32_MAX
# define __UINT_LEAST32_MAX UINT40_MAX
# undef __INT_LEAST16_MIN
# define __INT_LEAST16_MIN   INT40_MIN
# undef __INT_LEAST16_MAX
# define __INT_LEAST16_MAX   INT40_MAX
# undef __UINT_LEAST16_MAX
# define __UINT_LEAST16_MAX UINT40_MAX
# undef __INT_LEAST8_MIN
# define __INT_LEAST8_MIN    INT40_MIN
# undef __INT_LEAST8_MAX
# define __INT_LEAST8_MAX    INT40_MAX
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX  UINT40_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 574 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT40_WIDTH         40
# define INT40_WIDTH          UINT40_WIDTH
# define UINT_LEAST40_WIDTH   UINT40_WIDTH
# define INT_LEAST40_WIDTH    UINT_LEAST40_WIDTH
# define UINT_FAST40_WIDTH    UINT40_WIDTH
# define INT_FAST40_WIDTH     UINT_FAST40_WIDTH
# undef __UINT_LEAST32_WIDTH
# define __UINT_LEAST32_WIDTH UINT40_WIDTH
# undef __UINT_LEAST16_WIDTH
# define __UINT_LEAST16_WIDTH UINT40_WIDTH
# undef __UINT_LEAST8_WIDTH
# define __UINT_LEAST8_WIDTH  UINT40_WIDTH
#endif /* __STDC_VERSION__ */
# 587 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT40_TYPE__ */
# 588 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT32_TYPE__
# define INT32_MAX           INT32_C(2147483647)
# define INT32_MIN         (-INT32_C(2147483647)-1)
# define UINT32_MAX         UINT32_C(4294967295)

# undef __INT_LEAST32_MIN
# define __INT_LEAST32_MIN   INT32_MIN
# undef __INT_LEAST32_MAX
# define __INT_LEAST32_MAX   INT32_MAX
# undef __UINT_LEAST32_MAX
# define __UINT_LEAST32_MAX UINT32_MAX
# undef __INT_LEAST16_MIN
# define __INT_LEAST16_MIN   INT32_MIN
# undef __INT_LEAST16_MAX
# define __INT_LEAST16_MAX   INT32_MAX
# undef __UINT_LEAST16_MAX
# define __UINT_LEAST16_MAX UINT32_MAX
# undef __INT_LEAST8_MIN
# define __INT_LEAST8_MIN    INT32_MIN
# undef __INT_LEAST8_MAX
# define __INT_LEAST8_MAX    INT32_MAX
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX  UINT32_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 615 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT32_WIDTH         32
# define INT32_WIDTH          UINT32_WIDTH
# undef __UINT_LEAST32_WIDTH
# define __UINT_LEAST32_WIDTH UINT32_WIDTH
# undef __UINT_LEAST16_WIDTH
# define __UINT_LEAST16_WIDTH UINT32_WIDTH
# undef __UINT_LEAST8_WIDTH
# define __UINT_LEAST8_WIDTH  UINT32_WIDTH
#endif /* __STDC_VERSION__ */
# 624 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT32_TYPE__ */
# 625 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __INT_LEAST32_MIN
# define INT_LEAST32_MIN   __INT_LEAST32_MIN
# define INT_LEAST32_MAX   __INT_LEAST32_MAX
# define UINT_LEAST32_MAX __UINT_LEAST32_MAX
# define INT_FAST32_MIN    __INT_LEAST32_MIN
# define INT_FAST32_MAX    __INT_LEAST32_MAX
# define UINT_FAST32_MAX  __UINT_LEAST32_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 635 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT_LEAST32_WIDTH __UINT_LEAST32_WIDTH
# define INT_LEAST32_WIDTH  UINT_LEAST32_WIDTH
# define UINT_FAST32_WIDTH  __UINT_LEAST32_WIDTH
# define INT_FAST32_WIDTH   UINT_FAST32_WIDTH
#endif /* __STDC_VERSION__ */
# 640 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT_LEAST32_MIN */
# 641 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT24_TYPE__
# define INT24_MAX           INT24_C(8388607)
# define INT24_MIN         (-INT24_C(8388607)-1)
# define UINT24_MAX         UINT24_C(16777215)
# define INT_LEAST24_MIN     INT24_MIN
# define INT_LEAST24_MAX     INT24_MAX
# define UINT_LEAST24_MAX   UINT24_MAX
# define INT_FAST24_MIN      INT24_MIN
# define INT_FAST24_MAX      INT24_MAX
# define UINT_FAST24_MAX    UINT24_MAX

# undef __INT_LEAST16_MIN
# define __INT_LEAST16_MIN   INT24_MIN
# undef __INT_LEAST16_MAX
# define __INT_LEAST16_MAX   INT24_MAX
# undef __UINT_LEAST16_MAX
# define __UINT_LEAST16_MAX UINT24_MAX
# undef __INT_LEAST8_MIN
# define __INT_LEAST8_MIN    INT24_MIN
# undef __INT_LEAST8_MAX
# define __INT_LEAST8_MAX    INT24_MAX
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX  UINT24_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 668 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT24_WIDTH         24
# define INT24_WIDTH          UINT24_WIDTH
# define UINT_LEAST24_WIDTH   UINT24_WIDTH
# define INT_LEAST24_WIDTH    UINT_LEAST24_WIDTH
# define UINT_FAST24_WIDTH    UINT24_WIDTH
# define INT_FAST24_WIDTH     UINT_FAST24_WIDTH
# undef __UINT_LEAST16_WIDTH
# define __UINT_LEAST16_WIDTH UINT24_WIDTH
# undef __UINT_LEAST8_WIDTH
# define __UINT_LEAST8_WIDTH  UINT24_WIDTH
#endif /* __STDC_VERSION__ */
# 679 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT24_TYPE__ */
# 680 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT16_TYPE__
#define INT16_MAX            INT16_C(32767)
#define INT16_MIN          (-INT16_C(32767)-1)
#define UINT16_MAX          UINT16_C(65535)

# undef __INT_LEAST16_MIN
# define __INT_LEAST16_MIN   INT16_MIN
# undef __INT_LEAST16_MAX
# define __INT_LEAST16_MAX   INT16_MAX
# undef __UINT_LEAST16_MAX
# define __UINT_LEAST16_MAX UINT16_MAX
# undef __INT_LEAST8_MIN
# define __INT_LEAST8_MIN    INT16_MIN
# undef __INT_LEAST8_MAX
# define __INT_LEAST8_MAX    INT16_MAX
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX  UINT16_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 701 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT16_WIDTH         16
# define INT16_WIDTH          UINT16_WIDTH
# undef __UINT_LEAST16_WIDTH
# define __UINT_LEAST16_WIDTH UINT16_WIDTH
# undef __UINT_LEAST8_WIDTH
# define __UINT_LEAST8_WIDTH  UINT16_WIDTH
#endif /* __STDC_VERSION__ */
# 708 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT16_TYPE__ */
# 709 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __INT_LEAST16_MIN
# define INT_LEAST16_MIN   __INT_LEAST16_MIN
# define INT_LEAST16_MAX   __INT_LEAST16_MAX
# define UINT_LEAST16_MAX __UINT_LEAST16_MAX
# define INT_FAST16_MIN    __INT_LEAST16_MIN
# define INT_FAST16_MAX    __INT_LEAST16_MAX
# define UINT_FAST16_MAX  __UINT_LEAST16_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 719 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT_LEAST16_WIDTH __UINT_LEAST16_WIDTH
# define INT_LEAST16_WIDTH  UINT_LEAST16_WIDTH
# define UINT_FAST16_WIDTH  __UINT_LEAST16_WIDTH
# define INT_FAST16_WIDTH   UINT_FAST16_WIDTH
#endif /* __STDC_VERSION__ */
# 724 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT_LEAST16_MIN */
# 725 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3


#ifdef __INT8_TYPE__
# define INT8_MAX            INT8_C(127)
# define INT8_MIN          (-INT8_C(127)-1)
# define UINT8_MAX          UINT8_C(255)

# undef __INT_LEAST8_MIN
# define __INT_LEAST8_MIN    INT8_MIN
# undef __INT_LEAST8_MAX
# define __INT_LEAST8_MAX    INT8_MAX
# undef __UINT_LEAST8_MAX
# define __UINT_LEAST8_MAX  UINT8_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 740 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT8_WIDTH         8
# define INT8_WIDTH          UINT8_WIDTH
# undef __UINT_LEAST8_WIDTH
# define __UINT_LEAST8_WIDTH UINT8_WIDTH
#endif /* __STDC_VERSION__ */
# 745 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT8_TYPE__ */
# 746 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifdef __INT_LEAST8_MIN
# define INT_LEAST8_MIN   __INT_LEAST8_MIN
# define INT_LEAST8_MAX   __INT_LEAST8_MAX
# define UINT_LEAST8_MAX __UINT_LEAST8_MAX
# define INT_FAST8_MIN    __INT_LEAST8_MIN
# define INT_FAST8_MAX    __INT_LEAST8_MAX
# define UINT_FAST8_MAX  __UINT_LEAST8_MAX

#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 756 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define UINT_LEAST8_WIDTH __UINT_LEAST8_WIDTH
# define INT_LEAST8_WIDTH  UINT_LEAST8_WIDTH
# define UINT_FAST8_WIDTH  __UINT_LEAST8_WIDTH
# define INT_FAST8_WIDTH   UINT_FAST8_WIDTH
#endif /* __STDC_VERSION__ */
# 761 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __INT_LEAST8_MIN */
# 762 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* Some utility macros */
#define  __INTN_MIN(n)  __stdint_join3( INT, n, _MIN)
#define  __INTN_MAX(n)  __stdint_join3( INT, n, _MAX)
#define __UINTN_MAX(n)  __stdint_join3(UINT, n, _MAX)
#define  __INTN_C(n, v) __stdint_join3( INT, n, _C(v))
#define __UINTN_C(n, v) __stdint_join3(UINT, n, _C(v))

/* C99 7.18.2.4 Limits of integer types capable of holding object pointers. */
/* C99 7.18.3 Limits of other integer types. */

#define  INTPTR_MIN  (-__INTPTR_MAX__-1)
#define  INTPTR_MAX    __INTPTR_MAX__
#define UINTPTR_MAX   __UINTPTR_MAX__
#define PTRDIFF_MIN (-__PTRDIFF_MAX__-1)
#define PTRDIFF_MAX   __PTRDIFF_MAX__
#define    SIZE_MAX      __SIZE_MAX__

/* C23 7.22.2.4 Width of integer types capable of holding object pointers. */
#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 782 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
/* NB: The C standard requires that these be the same value, but the compiler
   exposes separate internal width macros. */
#define INTPTR_WIDTH  __INTPTR_WIDTH__
#define UINTPTR_WIDTH __UINTPTR_WIDTH__
#endif
# 787 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* ISO9899:2011 7.20 (C11 Annex K): Define RSIZE_MAX if __STDC_WANT_LIB_EXT1__
 * is enabled. */
#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ >= 1
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 791 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#define   RSIZE_MAX            (SIZE_MAX >> 1)
#endif
# 793 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* C99 7.18.2.5 Limits of greatest-width integer types. */
#define  INTMAX_MIN (-__INTMAX_MAX__-1)
#define  INTMAX_MAX   __INTMAX_MAX__
#define UINTMAX_MAX  __UINTMAX_MAX__

/* C23 7.22.2.5 Width of greatest-width integer types. */
#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 801 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
/* NB: The C standard requires that these be the same value, but the compiler
   exposes separate internal width macros. */
#define INTMAX_WIDTH __INTMAX_WIDTH__
#define UINTMAX_WIDTH __UINTMAX_WIDTH__
#endif
# 806 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* C99 7.18.3 Limits of other integer types. */
#define SIG_ATOMIC_MIN __INTN_MIN(__SIG_ATOMIC_WIDTH__)
#define SIG_ATOMIC_MAX __INTN_MAX(__SIG_ATOMIC_WIDTH__)
#ifdef __WINT_UNSIGNED__
# define WINT_MIN       __UINTN_C(__WINT_WIDTH__, 0)
# define WINT_MAX       __UINTN_MAX(__WINT_WIDTH__)
#else
# 814 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
# define WINT_MIN       __INTN_MIN(__WINT_WIDTH__)
# define WINT_MAX       __INTN_MAX(__WINT_WIDTH__)
#endif
# 817 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#ifndef WCHAR_MAX
# define WCHAR_MAX __WCHAR_MAX__
#endif
# 821 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#ifndef WCHAR_MIN
#if 0 /* disabled by -frewrite-includes */
# if __WCHAR_MAX__ == __INTN_MAX(__WCHAR_WIDTH__)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 823 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#  define WCHAR_MIN __INTN_MIN(__WCHAR_WIDTH__)
# else
# 825 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#  define WCHAR_MIN __UINTN_C(__WCHAR_WIDTH__, 0)
# endif
# 827 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif
# 828 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

/* 7.18.4.2 Macros for greatest-width integer constants. */
#define  INTMAX_C(v) __INTMAX_C(v)
#define UINTMAX_C(v) __UINTMAX_C(v)

/* C23 7.22.3.x Width of other integer types. */
#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 835 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#define PTRDIFF_WIDTH    __PTRDIFF_WIDTH__
#define SIG_ATOMIC_WIDTH __SIG_ATOMIC_WIDTH__
#define SIZE_WIDTH       __SIZE_WIDTH__
#define WCHAR_WIDTH      __WCHAR_WIDTH__
#define WINT_WIDTH       __WINT_WIDTH__
#endif
# 841 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3

#endif /* __STDC_HOSTED__ */
# 843 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __MVS__ */
# 844 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* __CLANG_STDINT_H */
# 845 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdint.h" 3
#endif /* stdint.h expanded by -frewrite-includes */
# 2 "test_1609_e21a3547_3d9d921b_068b9d94_6d4734f3_4dd78440_b28bb6f7_221c4b02_d710a80e_8a962bd7_0a416e5d_6229703d.c" 2
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdio.h expanded by -frewrite-includes */
#include <stdio.h>
#else /* stdio.h expanded by -frewrite-includes */
# 2 "test_1609_e21a3547_3d9d921b_068b9d94_6d4734f3_4dd78440_b28bb6f7_221c4b02_d710a80e_8a962bd7_0a416e5d_6229703d.c"
# 1 "/usr/include/stdio.h" 1 3 4
/* Define ISO C stdio on top of C++ iostreams.
   Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.19 Input/output	<stdio.h>
 */

#ifndef _STDIO_H
#define _STDIO_H	1

#define __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* libc-header-start.h expanded by -frewrite-includes */
#include <bits/libc-header-start.h>
#else /* libc-header-start.h expanded by -frewrite-includes */
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
/* Handle feature test macros at the start of a header.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* This header is internal to glibc and should not be included outside
   of glibc headers.  Headers including it must define
   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
   cannot have multiple include guards because ISO C feature test
   macros depend on the definition of the macro when an affected
   header is included, not when the first system header is
   included.  */

#ifndef __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
# error "Never include <bits/libc-header-start.h> directly."
#endif
# 30 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

#undef __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION

#if 0 /* expanded by -frewrite-includes */
#include <features.h>
#endif /* expanded by -frewrite-includes */
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
#undef __GLIBC_USE_LIB_EXT2
#if 0 /* disabled by -frewrite-includes */
#if (defined __USE_GNU							\
     || (defined __STDC_WANT_LIB_EXT2__ && __STDC_WANT_LIB_EXT2__ > 0))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 40 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_LIB_EXT2 1
#else
# 42 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_LIB_EXT2 0
#endif
# 44 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  Most but not all symbols enabled by that macro in TS
   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in
   Annex F still require a new feature test macro
   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define
   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS
   18661-1 are not included in C2X (and thus should depend on
   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are
   enabled).

   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS
   18661-1 not included in C2X.

   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS
   18661-1 that are also included in C2X (with no feature test macro
   required in C2X).

   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1
   that are included in C2X but conditional on
   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features
   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS
   18661-1.)  */
#undef __GLIBC_USE_IEC_60559_BFP_EXT
#if 0 /* disabled by -frewrite-includes */
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_BFP_EXT__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 69 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_BFP_EXT 1
#else
# 71 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_BFP_EXT 0
#endif
# 73 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
#undef __GLIBC_USE_IEC_60559_BFP_EXT_C2X
#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (IEC_60559_BFP_EXT) || __GLIBC_USE (ISOC2X)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 75 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_BFP_EXT_C2X 1
#else
# 77 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_BFP_EXT_C2X 0
#endif
# 79 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
#undef __GLIBC_USE_IEC_60559_EXT
#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (IEC_60559_BFP_EXT) || defined __STDC_WANT_IEC_60559_EXT__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 81 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_EXT 1
#else
# 83 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_EXT 0
#endif
# 85 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction
   functions, the symbols from this TS are enabled unconditionally in
   C2X.  */
#undef __GLIBC_USE_IEC_60559_FUNCS_EXT
#if 0 /* disabled by -frewrite-includes */
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_FUNCS_EXT__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 92 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_FUNCS_EXT 1
#else
# 94 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_FUNCS_EXT 0
#endif
# 96 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
#undef __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X
#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (IEC_60559_FUNCS_EXT) || __GLIBC_USE (ISOC2X)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 98 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X 1
#else
# 100 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X 0
#endif
# 102 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4

/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
#undef __GLIBC_USE_IEC_60559_TYPES_EXT
#if 0 /* disabled by -frewrite-includes */
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_TYPES_EXT__
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 107 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_TYPES_EXT 1
#else
# 109 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# define __GLIBC_USE_IEC_60559_TYPES_EXT 0
#endif
# 111 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
#endif /* libc-header-start.h expanded by -frewrite-includes */
# 28 "/usr/include/stdio.h" 2 3 4

__BEGIN_DECLS

#define __need_size_t
#define __need_NULL
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stddef.h expanded by -frewrite-includes */
#include <stddef.h>
#else /* stddef.h expanded by -frewrite-includes */
# 33 "/usr/include/stdio.h" 3 4
# 1 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 1 3 4
/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

/*
 * This header is designed to be included multiple times. If any of the __need_
 * macros are defined, then only that subset of interfaces are provided. This
 * can be useful for POSIX headers that need to not expose all of stddef.h, but
 * need to use some of its interfaces. Otherwise this header provides all of
 * the expected interfaces.
 *
 * When clang modules are enabled, this header is a textual header to support
 * the multiple include behavior. As such, it doesn't directly declare anything
 * so that it doesn't add duplicate declarations to all of its includers'
 * modules.
 */
#if 0 /* disabled by -frewrite-includes */
#if defined(__MVS__) && __has_include_next(<stddef.h>)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 23 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_ptrdiff_t
#undef __need_size_t
#undef __need_rsize_t
#undef __need_wchar_t
#undef __need_NULL
#undef __need_nullptr_t
#undef __need_unreachable
#undef __need_max_align_t
#undef __need_offsetof
#undef __need_wint_t
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_header_macro.h>
#endif /* expanded by -frewrite-includes */
# 33 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 34 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include_next <stddef.h>
#endif /* expanded by -frewrite-includes */
# 34 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 35 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#else
# 37 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if !defined(__need_ptrdiff_t) && !defined(__need_size_t) &&                   \
    !defined(__need_rsize_t) && !defined(__need_wchar_t) &&                    \
    !defined(__need_NULL) && !defined(__need_nullptr_t) &&                     \
    !defined(__need_unreachable) && !defined(__need_max_align_t) &&            \
    !defined(__need_offsetof) && !defined(__need_wint_t)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 43 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#define __need_ptrdiff_t
#define __need_size_t
/* ISO9899:2011 7.20 (C11 Annex K): Define rsize_t if __STDC_WANT_LIB_EXT1__ is
 * enabled. */
#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ >= 1
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 48 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#define __need_rsize_t
#endif
# 50 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#define __need_wchar_t
#if 0 /* disabled by -frewrite-includes */
#if !defined(__STDDEF_H) || __has_feature(modules)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 52 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
/*
 * __stddef_null.h is special when building without modules: if __need_NULL is
 * set, then it will unconditionally redefine NULL. To avoid stepping on client
 * definitions of NULL, __need_NULL should only be set the first time this
 * header is included, that is when __STDDEF_H is not defined. However, when
 * building with modules, this header is a textual header and needs to
 * unconditionally include __stdef_null.h to support multiple submodules
 * exporting _Builtin_stddef.null. Take module SM with submodules A and B, whose
 * headers both include stddef.h When SM.A builds, __STDDEF_H will be defined.
 * When SM.B builds, the definition from SM.A will leak when building without
 * local submodule visibility. stddef.h wouldn't include __stddef_null.h, and
 * SM.B wouldn't import _Builtin_stddef.null, and SM.B's `export *` wouldn't
 * export NULL as expected. When building with modules, always include
 * __stddef_null.h so that everything works as expected.
 */
#define __need_NULL
#endif
# 69 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L) ||              \
    defined(__cplusplus)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 71 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#define __need_nullptr_t
#endif
# 73 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 74 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#define __need_unreachable
#endif
# 76 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) ||              \
    (defined(__cplusplus) && __cplusplus >= 201103L)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 78 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#define __need_max_align_t
#endif
# 80 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#define __need_offsetof
/* wint_t is provided by <wchar.h> and not <stddef.h>. It's here
 * for compatibility, but must be explicitly requested. Therefore
 * __need_wint_t is intentionally not defined here. */
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_header_macro.h>
#endif /* expanded by -frewrite-includes */
# 84 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 85 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#endif
# 86 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_ptrdiff_t)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 88 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_ptrdiff_t.h>
#endif /* expanded by -frewrite-includes */
# 88 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 89 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_ptrdiff_t
#endif /* defined(__need_ptrdiff_t) */
# 91 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_size_t)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 93 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* __stddef_size_t.h expanded by -frewrite-includes */
#include <__stddef_size_t.h>
#else /* __stddef_size_t.h expanded by -frewrite-includes */
# 93 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 1 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_size_t.h" 1 3 4
/*===---- __stddef_size_t.h - Definition of size_t -------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

/*
 * When -fbuiltin-headers-in-system-modules is set this is a non-modular header
 * and needs to behave as if it was textual.
 */
#if 0 /* disabled by -frewrite-includes */
#if !defined(_SIZE_T) ||                                                       \
    (__has_feature(modules) && !__building_module(_Builtin_stddef))
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 16 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_size_t.h" 3 4
#define _SIZE_T

typedef __SIZE_TYPE__ size_t;

#endif
# 21 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_size_t.h" 3 4
#endif /* __stddef_size_t.h expanded by -frewrite-includes */
# 94 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 2 3 4
#undef __need_size_t
#endif /*defined(__need_size_t) */
# 96 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_rsize_t)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 98 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_rsize_t.h>
#endif /* expanded by -frewrite-includes */
# 98 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 99 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_rsize_t
#endif /* defined(__need_rsize_t) */
# 101 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_wchar_t)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 103 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_wchar_t.h>
#endif /* expanded by -frewrite-includes */
# 103 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 104 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_wchar_t
#endif /* defined(__need_wchar_t) */
# 106 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_NULL)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 108 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* __stddef_null.h expanded by -frewrite-includes */
#include <__stddef_null.h>
#else /* __stddef_null.h expanded by -frewrite-includes */
# 108 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 1 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_null.h" 1 3 4
/*===---- __stddef_null.h - Definition of NULL -----------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#if 0 /* disabled by -frewrite-includes */
#if !defined(NULL) || !__building_module(_Builtin_stddef)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 11 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_null.h" 3 4

/* linux/stddef.h will define NULL to 0. glibc (and other) headers then define
 * __need_NULL and rely on stddef.h to redefine NULL to the correct value again.
 * Modules don't support redefining macros like that, but support that pattern
 * in the non-modules case.
 */
#undef NULL

#ifdef __cplusplus
#if 0 /* disabled by -frewrite-includes */
#if !defined(__MINGW32__) && !defined(_MSC_VER)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 21 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_null.h" 3 4
#define NULL __null
#else
# 23 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_null.h" 3 4
#define NULL 0
#endif
# 25 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_null.h" 3 4
#else
# 26 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_null.h" 3 4
#define NULL ((void*)0)
#endif
# 28 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_null.h" 3 4

#endif
# 30 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stddef_null.h" 3 4
#endif /* __stddef_null.h expanded by -frewrite-includes */
# 109 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 2 3 4
#undef __need_NULL
#endif /* defined(__need_NULL) */
# 111 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_nullptr_t)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 113 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_nullptr_t.h>
#endif /* expanded by -frewrite-includes */
# 113 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 114 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_nullptr_t
#endif /* defined(__need_nullptr_t) */
# 116 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_unreachable)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 118 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_unreachable.h>
#endif /* expanded by -frewrite-includes */
# 118 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 119 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_unreachable
#endif /* defined(__need_unreachable) */
# 121 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_max_align_t)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 123 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_max_align_t.h>
#endif /* expanded by -frewrite-includes */
# 123 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 124 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_max_align_t
#endif /* defined(__need_max_align_t) */
# 126 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined(__need_offsetof)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 128 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_offsetof.h>
#endif /* expanded by -frewrite-includes */
# 128 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 129 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_offsetof
#endif /* defined(__need_offsetof) */
# 131 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
__WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */
#if 0 /* disabled by -frewrite-includes */
#if defined(__need_wint_t)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 135 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stddef_wint_t.h>
#endif /* expanded by -frewrite-includes */
# 135 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
# 136 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#undef __need_wint_t
#endif /* __need_wint_t */
# 138 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4

#endif /* __MVS__ */
# 140 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stddef.h" 3 4
#endif /* stddef.h expanded by -frewrite-includes */
# 34 "/usr/include/stdio.h" 2 3 4

#define __need___va_list
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdarg.h expanded by -frewrite-includes */
#include <stdarg.h>
#else /* stdarg.h expanded by -frewrite-includes */
# 36 "/usr/include/stdio.h" 3 4
# 1 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 1 3 4
/*===---- stdarg.h - Variable argument handling ----------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

/*
 * This header is designed to be included multiple times. If any of the __need_
 * macros are defined, then only that subset of interfaces are provided. This
 * can be useful for POSIX headers that need to not expose all of stdarg.h, but
 * need to use some of its interfaces. Otherwise this header provides all of
 * the expected interfaces.
 *
 * When clang modules are enabled, this header is a textual header to support
 * the multiple include behavior. As such, it doesn't directly declare anything
 * so that it doesn't add duplicate declarations to all of its includers'
 * modules.
 */
#if 0 /* disabled by -frewrite-includes */
#if defined(__MVS__) && __has_include_next(<stdarg.h>)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 23 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#undef __need___va_list
#undef __need_va_list
#undef __need_va_arg
#undef __need___va_copy
#undef __need_va_copy
#if 0 /* expanded by -frewrite-includes */
#include <__stdarg_header_macro.h>
#endif /* expanded by -frewrite-includes */
# 28 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
# 29 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include_next <stdarg.h>
#endif /* expanded by -frewrite-includes */
# 29 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
# 30 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4

#else
# 32 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if !defined(__need___va_list) && !defined(__need_va_list) &&                  \
    !defined(__need_va_arg) && !defined(__need___va_copy) &&                   \
    !defined(__need_va_copy)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 35 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#define __need___va_list
#define __need_va_list
#define __need_va_arg
#define __need___va_copy
/* GCC always defines __va_copy, but does not define va_copy unless in c99 mode
 * or -ansi is not specified, since it was not part of C90.
 */
#if 0 /* disabled by -frewrite-includes */
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) ||              \
    (defined(__cplusplus) && __cplusplus >= 201103L) ||                        \
    !defined(__STRICT_ANSI__)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 45 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#define __need_va_copy
#endif
# 47 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <__stdarg_header_macro.h>
#endif /* expanded by -frewrite-includes */
# 47 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
# 48 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#endif
# 49 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4

#ifdef __need___va_list
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* __stdarg___gnuc_va_list.h expanded by -frewrite-includes */
#include <__stdarg___gnuc_va_list.h>
#else /* __stdarg___gnuc_va_list.h expanded by -frewrite-includes */
# 51 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
# 1 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stdarg___gnuc_va_list.h" 1 3 4
/*===---- __stdarg___gnuc_va_list.h - Definition of __gnuc_va_list ---------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif
# 14 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/__stdarg___gnuc_va_list.h" 3 4
#endif /* __stdarg___gnuc_va_list.h expanded by -frewrite-includes */
# 52 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 2 3 4
#undef __need___va_list
#endif /* defined(__need___va_list) */
# 54 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4

#ifdef __need_va_list
#if 0 /* expanded by -frewrite-includes */
#include <__stdarg_va_list.h>
#endif /* expanded by -frewrite-includes */
# 56 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
# 57 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#undef __need_va_list
#endif /* defined(__need_va_list) */
# 59 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4

#ifdef __need_va_arg
#if 0 /* expanded by -frewrite-includes */
#include <__stdarg_va_arg.h>
#endif /* expanded by -frewrite-includes */
# 61 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
# 62 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#undef __need_va_arg
#endif /* defined(__need_va_arg) */
# 64 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4

#ifdef __need___va_copy
#if 0 /* expanded by -frewrite-includes */
#include <__stdarg___va_copy.h>
#endif /* expanded by -frewrite-includes */
# 66 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
# 67 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#undef __need___va_copy
#endif /* defined(__need___va_copy) */
# 69 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4

#ifdef __need_va_copy
#if 0 /* expanded by -frewrite-includes */
#include <__stdarg_va_copy.h>
#endif /* expanded by -frewrite-includes */
# 71 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
# 72 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#undef __need_va_copy
#endif /* defined(__need_va_copy) */
# 74 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4

#endif /* __MVS__ */
# 76 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/stdarg.h" 3 4
#endif /* stdarg.h expanded by -frewrite-includes */
# 37 "/usr/include/stdio.h" 2 3 4

#if 0 /* expanded by -frewrite-includes */
#include <bits/types.h>
#endif /* expanded by -frewrite-includes */
# 38 "/usr/include/stdio.h" 3 4
# 39 "/usr/include/stdio.h" 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* __fpos_t.h expanded by -frewrite-includes */
#include <bits/types/__fpos_t.h>
#else /* __fpos_t.h expanded by -frewrite-includes */
# 39 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 1 3 4
#ifndef _____fpos_t_defined
#define _____fpos_t_defined 1

#if 0 /* expanded by -frewrite-includes */
#include <bits/types.h>
#endif /* expanded by -frewrite-includes */
# 4 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 3 4
# 5 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* __mbstate_t.h expanded by -frewrite-includes */
#include <bits/types/__mbstate_t.h>
#else /* __mbstate_t.h expanded by -frewrite-includes */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 1 3 4
#ifndef ____mbstate_t_defined
#define ____mbstate_t_defined 1

/* Integral type unchanged by default argument promotions that can
   hold any value corresponding to members of the extended character
   set, as well as at least one value that does not correspond to any
   member of the extended character set.  */
#ifndef __WINT_TYPE__
# define __WINT_TYPE__ unsigned int
#endif
# 11 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 3 4

/* Conversion state information.  */
typedef struct
{
  int __count;
  union
  {
    __WINT_TYPE__ __wch;
    char __wchb[4];
  } __value;		/* Value so far.  */
} __mbstate_t;

#endif
# 24 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 3 4
#endif /* __mbstate_t.h expanded by -frewrite-includes */
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 2 3 4

/* The tag name of this struct is _G_fpos_t to preserve historic
   C++ mangled names for functions taking fpos_t arguments.
   That name should not be used in new code.  */
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;

#endif
# 17 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 3 4
#endif /* __fpos_t.h expanded by -frewrite-includes */
# 40 "/usr/include/stdio.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* __fpos64_t.h expanded by -frewrite-includes */
#include <bits/types/__fpos64_t.h>
#else /* __fpos64_t.h expanded by -frewrite-includes */
# 40 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 1 3 4
#ifndef _____fpos64_t_defined
#define _____fpos64_t_defined 1

#if 0 /* expanded by -frewrite-includes */
#include <bits/types.h>
#endif /* expanded by -frewrite-includes */
# 4 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4
# 5 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#include <bits/types/__mbstate_t.h>
#endif /* expanded by -frewrite-includes */
# 5 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4

/* The tag name of this struct is _G_fpos64_t to preserve historic
   C++ mangled names for functions taking fpos_t and/or fpos64_t
   arguments.  That name should not be used in new code.  */
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;

#endif
# 17 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4
#endif /* __fpos64_t.h expanded by -frewrite-includes */
# 41 "/usr/include/stdio.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* __FILE.h expanded by -frewrite-includes */
#include <bits/types/__FILE.h>
#else /* __FILE.h expanded by -frewrite-includes */
# 41 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 1 3 4
#ifndef ____FILE_defined
#define ____FILE_defined 1

struct _IO_FILE;
typedef struct _IO_FILE __FILE;

#endif
# 8 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 3 4
#endif /* __FILE.h expanded by -frewrite-includes */
# 42 "/usr/include/stdio.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* FILE.h expanded by -frewrite-includes */
#include <bits/types/FILE.h>
#else /* FILE.h expanded by -frewrite-includes */
# 42 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 1 3 4
#ifndef __FILE_defined
#define __FILE_defined 1

struct _IO_FILE;

/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE FILE;

#endif
# 10 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3 4
#endif /* FILE.h expanded by -frewrite-includes */
# 43 "/usr/include/stdio.h" 2 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* struct_FILE.h expanded by -frewrite-includes */
#include <bits/types/struct_FILE.h>
#else /* struct_FILE.h expanded by -frewrite-includes */
# 43 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 1 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef __struct_FILE_defined
#define __struct_FILE_defined 1

/* Caution: The contents of this file are not part of the official
   stdio.h API.  However, much of it is part of the official *binary*
   interface, and therefore cannot be changed.  */

#if 0 /* disabled by -frewrite-includes */
#if defined _IO_USE_OLD_IO_FILE && !defined _LIBC
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 26 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
# error "_IO_USE_OLD_IO_FILE should only be defined when building libc itself"
#endif
# 28 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined _IO_lock_t_defined && !defined _LIBC
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 30 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
# error "_IO_lock_t_defined should only be defined when building libc itself"
#endif
# 32 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4

#if 0 /* expanded by -frewrite-includes */
#include <bits/types.h>
#endif /* expanded by -frewrite-includes */
# 33 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4

struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;

/* During the build of glibc itself, _IO_lock_t will already have been
   defined by internal headers.  */
#ifndef _IO_lock_t_defined
typedef void _IO_lock_t;
#endif
# 45 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4

/* The tag name of this struct is _IO_FILE to preserve historic
   C++ mangled names for functions taking FILE* arguments.
   That name should not be used in new code.  */
struct _IO_FILE
{
  int _flags;		/* High-order word is _IO_MAGIC; rest is flags. */

  /* The following pointers correspond to the C++ streambuf protocol. */
  char *_IO_read_ptr;	/* Current read pointer */
  char *_IO_read_end;	/* End of get area. */
  char *_IO_read_base;	/* Start of putback+get area. */
  char *_IO_write_base;	/* Start of put area. */
  char *_IO_write_ptr;	/* Current put pointer. */
  char *_IO_write_end;	/* End of put area. */
  char *_IO_buf_base;	/* Start of reserve area. */
  char *_IO_buf_end;	/* End of reserve area. */

  /* The following fields are used to support backing up and undo. */
  char *_IO_save_base; /* Pointer to start of non-current get area. */
  char *_IO_backup_base;  /* Pointer to first valid character of backup area */
  char *_IO_save_end; /* Pointer to end of non-current get area. */

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset; /* This used to be _offset but it's too small.  */

  /* 1+column number of pbase(); 0 is unknown. */
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;
#ifdef _IO_USE_OLD_IO_FILE
};

struct _IO_FILE_complete
{
  struct _IO_FILE _file;
#endif
# 89 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
  __off64_t _offset;
  /* Wide character stream stuff.  */
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  /* Make sure we don't get into trouble again.  */
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};

/* These macros are used by bits/stdio.h and internal headers.  */
#define __getc_unlocked_body(_fp)					\
  (__glibc_unlikely ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end)	\
   ? __uflow (_fp) : *(unsigned char *) (_fp)->_IO_read_ptr++)

#define __putc_unlocked_body(_ch, _fp)					\
  (__glibc_unlikely ((_fp)->_IO_write_ptr >= (_fp)->_IO_write_end)	\
   ? __overflow (_fp, (unsigned char) (_ch))				\
   : (unsigned char) (*(_fp)->_IO_write_ptr++ = (_ch)))

#define _IO_EOF_SEEN 0x0010
#define __feof_unlocked_body(_fp) (((_fp)->_flags & _IO_EOF_SEEN) != 0)

#define _IO_ERR_SEEN 0x0020
#define __ferror_unlocked_body(_fp) (((_fp)->_flags & _IO_ERR_SEEN) != 0)

#define _IO_USER_LOCK 0x8000
/* Many more flag bits are defined internally.  */

#endif
# 121 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
#endif /* struct_FILE.h expanded by -frewrite-includes */
# 44 "/usr/include/stdio.h" 2 3 4

#ifdef __USE_GNU
#if 0 /* expanded by -frewrite-includes */
# include <bits/types/cookie_io_functions_t.h>
#endif /* expanded by -frewrite-includes */
# 46 "/usr/include/stdio.h" 3 4
# 47 "/usr/include/stdio.h" 3 4
#endif
# 48 "/usr/include/stdio.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined __USE_XOPEN || defined __USE_XOPEN2K8
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 50 "/usr/include/stdio.h" 3 4
# ifdef __GNUC__
#  ifndef _VA_LIST_DEFINED
typedef __gnuc_va_list va_list;
#   define _VA_LIST_DEFINED
#  endif
# 55 "/usr/include/stdio.h" 3 4
# else
# 56 "/usr/include/stdio.h" 3 4
#if 0 /* expanded by -frewrite-includes */
#  include <stdarg.h>
#endif /* expanded by -frewrite-includes */
# 56 "/usr/include/stdio.h" 3 4
# 57 "/usr/include/stdio.h" 3 4
# endif
# 58 "/usr/include/stdio.h" 3 4
#endif
# 59 "/usr/include/stdio.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined __USE_UNIX98 || defined __USE_XOPEN2K
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 61 "/usr/include/stdio.h" 3 4
# ifndef __off_t_defined
# ifndef __USE_FILE_OFFSET64
typedef __off_t off_t;
# else
# 65 "/usr/include/stdio.h" 3 4
typedef __off64_t off_t;
# endif
# 67 "/usr/include/stdio.h" 3 4
# define __off_t_defined
# endif
# 69 "/usr/include/stdio.h" 3 4
#if 0 /* disabled by -frewrite-includes */
# if defined __USE_LARGEFILE64 && !defined __off64_t_defined
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 70 "/usr/include/stdio.h" 3 4
typedef __off64_t off64_t;
# define __off64_t_defined
# endif
# 73 "/usr/include/stdio.h" 3 4
#endif
# 74 "/usr/include/stdio.h" 3 4

#ifdef __USE_XOPEN2K8
# ifndef __ssize_t_defined
typedef __ssize_t ssize_t;
# define __ssize_t_defined
# endif
# 80 "/usr/include/stdio.h" 3 4
#endif
# 81 "/usr/include/stdio.h" 3 4

/* The type of the second argument to `fgetpos' and `fsetpos'.  */
#ifndef __USE_FILE_OFFSET64
typedef __fpos_t fpos_t;
#else
# 86 "/usr/include/stdio.h" 3 4
typedef __fpos64_t fpos_t;
#endif
# 88 "/usr/include/stdio.h" 3 4
#ifdef __USE_LARGEFILE64
typedef __fpos64_t fpos64_t;
#endif
# 91 "/usr/include/stdio.h" 3 4

/* The possibilities for the third argument to `setvbuf'.  */
#define _IOFBF 0		/* Fully buffered.  */
#define _IOLBF 1		/* Line buffered.  */
#define _IONBF 2		/* No buffering.  */


/* Default buffer size.  */
#define BUFSIZ 8192


/* The value returned by fgetc and similar functions to indicate the
   end of the file.  */
#define EOF (-1)


/* The possibilities for the third argument to `fseek'.
   These values should not be changed.  */
#define SEEK_SET	0	/* Seek from beginning of file.  */
#define SEEK_CUR	1	/* Seek from current position.  */
#define SEEK_END	2	/* Seek from end of file.  */
#ifdef __USE_GNU
# define SEEK_DATA	3	/* Seek to next data.  */
# define SEEK_HOLE	4	/* Seek to next hole.  */
#endif
# 116 "/usr/include/stdio.h" 3 4


#if 0 /* disabled by -frewrite-includes */
#if defined __USE_MISC || defined __USE_XOPEN
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 119 "/usr/include/stdio.h" 3 4
/* Default path prefix for `tempnam' and `tmpnam'.  */
# define P_tmpdir	"/tmp"
#endif
# 122 "/usr/include/stdio.h" 3 4


/* Get the values:
   L_tmpnam	How long an array of chars must be to be passed to `tmpnam'.
   TMP_MAX	The minimum number of unique filenames generated by tmpnam
		(and tempnam when it uses tmpnam's name space),
		or tempnam (the two are separate).
   L_ctermid	How long an array to pass to `ctermid'.
   L_cuserid	How long an array to pass to `cuserid'.
   FOPEN_MAX	Minimum number of files that can be open at once.
   FILENAME_MAX	Maximum length of a filename.  */
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdio_lim.h expanded by -frewrite-includes */
#include <bits/stdio_lim.h>
#else /* stdio_lim.h expanded by -frewrite-includes */
# 133 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
/* Copyright (C) 1994-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_STDIO_LIM_H
#define _BITS_STDIO_LIM_H 1

#ifndef _STDIO_H
# error "Never include <bits/stdio_lim.h> directly; use <stdio.h> instead."
#endif
# 24 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 3 4

#define L_tmpnam 20
#define TMP_MAX 238328
#define FILENAME_MAX 4096

#ifdef __USE_POSIX
# define L_ctermid 9
#if 0 /* disabled by -frewrite-includes */
# if !defined __USE_XOPEN2K || defined __USE_GNU
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 32 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 3 4
#  define L_cuserid 9
# endif
# 34 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 3 4
#endif
# 35 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 3 4

#undef  FOPEN_MAX
#define FOPEN_MAX 16

#endif /* bits/stdio_lim.h */
# 40 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 3 4
#endif /* stdio_lim.h expanded by -frewrite-includes */
# 134 "/usr/include/stdio.h" 2 3 4


#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (ISOC2X)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 137 "/usr/include/stdio.h" 3 4
/* Maximum length of printf output for a NaN.  */
# define _PRINTF_NAN_LEN_MAX 4
#endif
# 140 "/usr/include/stdio.h" 3 4


/* Standard streams.  */
extern FILE *stdin;		/* Standard input stream.  */
extern FILE *stdout;		/* Standard output stream.  */
extern FILE *stderr;		/* Standard error output stream.  */
/* C89/C99 say they're macros.  Make them happy.  */
#define stdin stdin
#define stdout stdout
#define stderr stderr

/* Remove file FILENAME.  */
extern int remove (const char *__filename) __THROW;
/* Rename file OLD to NEW.  */
extern int rename (const char *__old, const char *__new) __THROW;

#ifdef __USE_ATFILE
/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */
extern int renameat (int __oldfd, const char *__old, int __newfd,
		     const char *__new) __THROW;
#endif
# 161 "/usr/include/stdio.h" 3 4

#ifdef __USE_GNU
/* Flags for renameat2.  */
# define RENAME_NOREPLACE (1 << 0)
# define RENAME_EXCHANGE (1 << 1)
# define RENAME_WHITEOUT (1 << 2)

/* Rename file OLD relative to OLDFD to NEW relative to NEWFD, with
   additional flags.  */
extern int renameat2 (int __oldfd, const char *__old, int __newfd,
		      const char *__new, unsigned int __flags) __THROW;
#endif
# 173 "/usr/include/stdio.h" 3 4

/* Close STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fclose (FILE *__stream);

#undef __attr_dealloc_fclose
#define __attr_dealloc_fclose __attr_dealloc (fclose, 1)

/* Create a temporary file and open it read/write.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
#ifndef __USE_FILE_OFFSET64
extern FILE *tmpfile (void)
  __attribute_malloc__ __attr_dealloc_fclose __wur;
#else
# 191 "/usr/include/stdio.h" 3 4
# ifdef __REDIRECT
extern FILE *__REDIRECT (tmpfile, (void), tmpfile64)
  __attribute_malloc__ __attr_dealloc_fclose __wur;
# else
# 195 "/usr/include/stdio.h" 3 4
#  define tmpfile tmpfile64
# endif
# 197 "/usr/include/stdio.h" 3 4
#endif
# 198 "/usr/include/stdio.h" 3 4

#ifdef __USE_LARGEFILE64
extern FILE *tmpfile64 (void)
   __attribute_malloc__ __attr_dealloc_fclose __wur;
#endif
# 203 "/usr/include/stdio.h" 3 4

/* Generate a temporary filename.  */
extern char *tmpnam (char[L_tmpnam]) __THROW __wur;

#ifdef __USE_MISC
/* This is the reentrant variant of `tmpnam'.  The only difference is
   that it does not allow S to be NULL.  */
extern char *tmpnam_r (char __s[L_tmpnam]) __THROW __wur;
#endif
# 212 "/usr/include/stdio.h" 3 4


#if 0 /* disabled by -frewrite-includes */
#if defined __USE_MISC || defined __USE_XOPEN
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 215 "/usr/include/stdio.h" 3 4
/* Generate a unique temporary filename using up to five characters of PFX
   if it is not NULL.  The directory to put this file in is searched for
   as follows: First the environment variable "TMPDIR" is checked.
   If it contains the name of a writable directory, that directory is used.
   If not and if DIR is not NULL, that value is checked.  If that fails,
   P_tmpdir is tried and finally "/tmp".  The storage for the filename
   is allocated by `malloc'.  */
extern char *tempnam (const char *__dir, const char *__pfx)
   __THROW __attribute_malloc__ __wur __attr_dealloc_free;
#endif
# 225 "/usr/include/stdio.h" 3 4

/* Flush STREAM, or all streams if STREAM is NULL.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fflush (FILE *__stream);

#ifdef __USE_MISC
/* Faster versions when locking is not required.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fflush_unlocked (FILE *__stream);
#endif
# 241 "/usr/include/stdio.h" 3 4

#ifdef __USE_GNU
/* Close all streams.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fcloseall (void);
#endif
# 251 "/usr/include/stdio.h" 3 4


#ifndef __USE_FILE_OFFSET64
/* Open a file and create a new stream for it.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *fopen (const char *__restrict __filename,
		    const char *__restrict __modes)
  __attribute_malloc__ __attr_dealloc_fclose __wur;
/* Open a file, replacing an existing stream with it.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *freopen (const char *__restrict __filename,
		      const char *__restrict __modes,
		      FILE *__restrict __stream) __wur;
#else
# 269 "/usr/include/stdio.h" 3 4
# ifdef __REDIRECT
extern FILE *__REDIRECT (fopen, (const char *__restrict __filename,
				 const char *__restrict __modes), fopen64)
  __attribute_malloc__ __attr_dealloc_fclose __wur;
extern FILE *__REDIRECT (freopen, (const char *__restrict __filename,
				   const char *__restrict __modes,
				   FILE *__restrict __stream), freopen64)
  __wur;
# else
# 278 "/usr/include/stdio.h" 3 4
#  define fopen fopen64
#  define freopen freopen64
# endif
# 281 "/usr/include/stdio.h" 3 4
#endif
# 282 "/usr/include/stdio.h" 3 4
#ifdef __USE_LARGEFILE64
extern FILE *fopen64 (const char *__restrict __filename,
		      const char *__restrict __modes)
  __attribute_malloc__ __attr_dealloc_fclose __wur;
extern FILE *freopen64 (const char *__restrict __filename,
			const char *__restrict __modes,
			FILE *__restrict __stream) __wur;
#endif
# 290 "/usr/include/stdio.h" 3 4

#ifdef	__USE_POSIX
/* Create a new stream that refers to an existing system file descriptor.  */
extern FILE *fdopen (int __fd, const char *__modes) __THROW
  __attribute_malloc__ __attr_dealloc_fclose __wur;
#endif
# 296 "/usr/include/stdio.h" 3 4

#ifdef	__USE_GNU
/* Create a new stream that refers to the given magic cookie,
   and uses the given functions for input and output.  */
extern FILE *fopencookie (void *__restrict __magic_cookie,
			  const char *__restrict __modes,
			  cookie_io_functions_t __io_funcs) __THROW
  __attribute_malloc__ __attr_dealloc_fclose __wur;
#endif
# 305 "/usr/include/stdio.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined __USE_XOPEN2K8 || __GLIBC_USE (LIB_EXT2)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 307 "/usr/include/stdio.h" 3 4
/* Create a new stream that refers to a memory buffer.  */
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __THROW __attribute_malloc__ __attr_dealloc_fclose __wur;

/* Open a stream that writes into a malloc'd buffer that is expanded as
   necessary.  *BUFLOC and *SIZELOC are updated with the buffer's location
   and the number of characters written on fflush or fclose.  */
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __THROW
  __attribute_malloc__ __attr_dealloc_fclose __wur;

#ifdef _WCHAR_H
/* Like OPEN_MEMSTREAM, but the stream is wide oriented and produces
   a wide character string.  Declared here only to add attribute malloc
   and only if <wchar.h> has been previously #included.  */
extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) __THROW
  __attribute_malloc__ __attr_dealloc_fclose;
# endif
# 324 "/usr/include/stdio.h" 3 4
#endif
# 325 "/usr/include/stdio.h" 3 4

/* If BUF is NULL, make STREAM unbuffered.
   Else make it use buffer BUF, of size BUFSIZ.  */
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __THROW;
/* Make STREAM use buffering mode MODE.
   If BUF is not NULL, use N bytes of it for buffering;
   else allocate an internal buffer N bytes long.  */
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
		    int __modes, size_t __n) __THROW;

#ifdef	__USE_MISC
/* If BUF is NULL, make STREAM unbuffered.
   Else make it use SIZE bytes of BUF for buffering.  */
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
		       size_t __size) __THROW;

/* Make STREAM line-buffered.  */
extern void setlinebuf (FILE *__stream) __THROW;
#endif
# 344 "/usr/include/stdio.h" 3 4


/* Write formatted output to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fprintf (FILE *__restrict __stream,
		    const char *__restrict __format, ...);
/* Write formatted output to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int printf (const char *__restrict __format, ...);
/* Write formatted output to S.  */
extern int sprintf (char *__restrict __s,
		    const char *__restrict __format, ...) __THROWNL;

/* Write formatted output to S from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
		     __gnuc_va_list __arg);
/* Write formatted output to stdout from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
/* Write formatted output to S from argument list ARG.  */
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
		     __gnuc_va_list __arg) __THROWNL;

#if 0 /* disabled by -frewrite-includes */
#if defined __USE_ISOC99 || defined __USE_UNIX98
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 377 "/usr/include/stdio.h" 3 4
/* Maximum chars of output to write in MAXLEN.  */
extern int snprintf (char *__restrict __s, size_t __maxlen,
		     const char *__restrict __format, ...)
     __THROWNL __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
		      const char *__restrict __format, __gnuc_va_list __arg)
     __THROWNL __attribute__ ((__format__ (__printf__, 3, 0)));
#endif
# 386 "/usr/include/stdio.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (LIB_EXT2)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 388 "/usr/include/stdio.h" 3 4
/* Write formatted output to a string dynamically allocated with `malloc'.
   Store the address of the string in *PTR.  */
extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
		      __gnuc_va_list __arg)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 0))) __wur;
extern int __asprintf (char **__restrict __ptr,
		       const char *__restrict __fmt, ...)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3))) __wur;
extern int asprintf (char **__restrict __ptr,
		     const char *__restrict __fmt, ...)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3))) __wur;
#endif
# 400 "/usr/include/stdio.h" 3 4

#ifdef __USE_XOPEN2K8
/* Write formatted output to a file descriptor.  */
extern int vdprintf (int __fd, const char *__restrict __fmt,
		     __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
#endif
# 409 "/usr/include/stdio.h" 3 4


/* Read formatted input from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fscanf (FILE *__restrict __stream,
		   const char *__restrict __format, ...) __wur;
/* Read formatted input from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int scanf (const char *__restrict __format, ...) __wur;
/* Read formatted input from S.  */
extern int sscanf (const char *__restrict __s,
		   const char *__restrict __format, ...) __THROW;

/* For historical reasons, the C99-compliant versions of the scanf
   functions are at alternative names.  When __LDBL_COMPAT or
   __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI are in effect, this is handled in
   bits/stdio-ldbl.h.  */
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* floatn.h expanded by -frewrite-includes */
#include <bits/floatn.h>
#else /* floatn.h expanded by -frewrite-includes */
# 430 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
/* Macros to control TS 18661-3 glibc features on x86.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_FLOATN_H
#define _BITS_FLOATN_H

#if 0 /* expanded by -frewrite-includes */
#include <features.h>
#endif /* expanded by -frewrite-includes */
# 22 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* Defined to 1 if the current compiler invocation provides a
   floating-point type with the IEEE 754 binary128 format, and this
   glibc includes corresponding *f128 interfaces for it.  The required
   libgcc support was added some time after the basic compiler
   support, for x86_64 and x86.  */
#if 0 /* disabled by -frewrite-includes */
#if (defined __x86_64__							\
     ? __GNUC_PREREQ (4, 3)						\
     : (defined __GNU__ ? __GNUC_PREREQ (4, 5) : __GNUC_PREREQ (4, 4)))
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 32 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# define __HAVE_FLOAT128 1
#else
# 34 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# define __HAVE_FLOAT128 0
#endif
# 36 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* Defined to 1 if __HAVE_FLOAT128 is 1 and the type is ABI-distinct
   from the default float, double and long double types in this glibc.  */
#if 0 /* disabled by -frewrite-includes */
#if __HAVE_FLOAT128
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 40 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# define __HAVE_DISTINCT_FLOAT128 1
#else
# 42 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# define __HAVE_DISTINCT_FLOAT128 0
#endif
# 44 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* Defined to 1 if the current compiler invocation provides a
   floating-point type with the right format for _Float64x, and this
   glibc includes corresponding *f64x interfaces for it.  */
#define __HAVE_FLOAT64X 1

/* Defined to 1 if __HAVE_FLOAT64X is 1 and _Float64x has the format
   of long double.  Otherwise, if __HAVE_FLOAT64X is 1, _Float64x has
   the format of _Float128, which must be different from that of long
   double.  */
#define __HAVE_FLOAT64X_LONG_DOUBLE 1

#ifndef __ASSEMBLER__

/* Defined to concatenate the literal suffix to be used with _Float128
   types, if __HAVE_FLOAT128 is 1. */
#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT128
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 61 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 62 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
/* The literal suffix f128 exists only since GCC 7.0.  */
#   define __f128(x) x##q
#  else
# 65 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
#   define __f128(x) x##f128
#  endif
# 67 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# endif
# 68 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* Defined to a complex binary128 type if __HAVE_FLOAT128 is 1.  */
#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT128
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 71 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 72 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
/* Add a typedef for older GCC compilers which don't natively support
   _Complex _Float128.  */
typedef _Complex float __cfloat128 __attribute__ ((__mode__ (__TC__)));
#   define __CFLOAT128 __cfloat128
#  else
# 77 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
#   define __CFLOAT128 _Complex _Float128
#  endif
# 79 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# endif
# 80 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* The remaining of this file provides support for older compilers.  */
#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT128
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 83 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* The type _Float128 exists only since GCC 7.0.  */
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 86 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
typedef __float128 _Float128;
#  endif
# 88 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* __builtin_huge_valf128 doesn't exist before GCC 7.0.  */
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 91 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
#   define __builtin_huge_valf128() ((_Float128) __builtin_huge_val ())
#  endif
# 93 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* Older GCC has only a subset of built-in functions for _Float128 on
   x86, and __builtin_infq is not usable in static initializers.
   Converting a narrower sNaN to _Float128 produces a quiet NaN, so
   attempts to use _Float128 sNaNs will not work properly with older
   compilers.  */
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 100 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
#   define __builtin_copysignf128 __builtin_copysignq
#   define __builtin_fabsf128 __builtin_fabsq
#   define __builtin_inff128() ((_Float128) __builtin_inf ())
#   define __builtin_nanf128(x) ((_Float128) __builtin_nan (x))
#   define __builtin_nansf128(x) ((_Float128) __builtin_nans (x))
#  endif
# 106 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

/* In math/math.h, __MATH_TG will expand signbit to __builtin_signbit*,
   e.g.: __builtin_signbitf128, before GCC 6.  However, there has never
   been a __builtin_signbitf128 in GCC and the type-generic builtin is
   only available since GCC 6.  */
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (6, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 112 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
#   define __builtin_signbitf128 __signbitf128
#  endif
# 114 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

# endif
# 116 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

#endif /* !__ASSEMBLER__.  */
# 118 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4

#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* floatn-common.h expanded by -frewrite-includes */
#include <bits/floatn-common.h>
#else /* floatn-common.h expanded by -frewrite-includes */
# 119 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
/* Macros to control TS 18661-3 glibc features where the same
   definitions are appropriate for all platforms.
   Copyright (C) 2017-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_FLOATN_COMMON_H
#define _BITS_FLOATN_COMMON_H

#if 0 /* expanded by -frewrite-includes */
#include <features.h>
#endif /* expanded by -frewrite-includes */
# 23 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* long-double.h expanded by -frewrite-includes */
#include <bits/long-double.h>
#else /* long-double.h expanded by -frewrite-includes */
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
/* Properties of long double type.  ldbl-96 version.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License  published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* long double is distinct from double, so there is nothing to
   define here.  */
#define __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI 0
#endif /* long-double.h expanded by -frewrite-includes */
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4

/* This header should be included at the bottom of each bits/floatn.h.
   It defines the following macros for each _FloatN and _FloatNx type,
   where the same definitions, or definitions based only on the macros
   in bits/floatn.h, are appropriate for all glibc configurations.  */

/* Defined to 1 if the current compiler invocation provides a
   floating-point type with the right format for this type, and this
   glibc includes corresponding *fN or *fNx interfaces for it.  */
#define __HAVE_FLOAT16 0
#define __HAVE_FLOAT32 1
#define __HAVE_FLOAT64 1
#define __HAVE_FLOAT32X 1
#define __HAVE_FLOAT128X 0

/* Defined to 1 if the corresponding __HAVE_<type> macro is 1 and the
   type is the first with its format in the sequence of (the default
   choices for) float, double, long double, _Float16, _Float32,
   _Float64, _Float128, _Float32x, _Float64x, _Float128x for this
   glibc; that is, if functions present once per floating-point format
   rather than once per type are present for this type.

   All configurations supported by glibc have _Float32 the same format
   as float, _Float64 and _Float32x the same format as double, the
   _Float64x the same format as either long double or _Float128.  No
   configurations support _Float128x or, as of GCC 7, have compiler
   support for a type meeting the requirements for _Float128x.  */
#define __HAVE_DISTINCT_FLOAT16 __HAVE_FLOAT16
#define __HAVE_DISTINCT_FLOAT32 0
#define __HAVE_DISTINCT_FLOAT64 0
#define __HAVE_DISTINCT_FLOAT32X 0
#define __HAVE_DISTINCT_FLOAT64X 0
#define __HAVE_DISTINCT_FLOAT128X __HAVE_FLOAT128X

/* Defined to 1 if the corresponding _FloatN type is not binary compatible
   with the corresponding ISO C type in the current compilation unit as
   opposed to __HAVE_DISTINCT_FLOATN, which indicates the default types built
   in glibc.  */
#define __HAVE_FLOAT128_UNLIKE_LDBL (__HAVE_DISTINCT_FLOAT128	\
				     && __LDBL_MANT_DIG__ != 113)

/* Defined to 1 if any _FloatN or _FloatNx types that are not
   ABI-distinct are however distinct types at the C language level (so
   for the purposes of __builtin_types_compatible_p and _Generic).  */
#if 0 /* disabled by -frewrite-includes */
#if __GNUC_PREREQ (7, 0) && !defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 70 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# define __HAVE_FLOATN_NOT_TYPEDEF 1
#else
# 72 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# define __HAVE_FLOATN_NOT_TYPEDEF 0
#endif
# 74 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#ifndef __ASSEMBLER__

/* Defined to concatenate the literal suffix to be used with _FloatN
   or _FloatNx types, if __HAVE_<type> is 1.  The corresponding
   literal suffixes exist since GCC 7, for C only.  */
#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT16
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 81 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 82 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
/* No corresponding suffix available for this type.  */
#   define __f16(x) ((_Float16) x##f)
#  else
# 85 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __f16(x) x##f16
#  endif
# 87 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 88 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT32
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 90 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 91 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __f32(x) x##f
#  else
# 93 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __f32(x) x##f32
#  endif
# 95 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 96 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 98 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 99 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   ifdef __NO_LONG_DOUBLE_MATH
#    define __f64(x) x##l
#   else
# 102 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __f64(x) x
#   endif
# 104 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#  else
# 105 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __f64(x) x##f64
#  endif
# 107 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 108 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT32X
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 110 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 111 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __f32x(x) x
#  else
# 113 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __f32x(x) x##f32x
#  endif
# 115 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 116 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT64X
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 118 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 119 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#   if __HAVE_FLOAT64X_LONG_DOUBLE
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 120 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __f64x(x) x##l
#   else
# 122 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __f64x(x) __f128 (x)
#   endif
# 124 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#  else
# 125 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __f64x(x) x##f64x
#  endif
# 127 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 128 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT128X
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 130 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 131 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   error "_Float128X supported but no constant suffix"
#  else
# 133 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __f128x(x) x##f128x
#  endif
# 135 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 136 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

/* Defined to a complex type if __HAVE_<type> is 1.  */
#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT16
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 139 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 140 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef _Complex float __cfloat16 __attribute__ ((__mode__ (__HC__)));
#   define __CFLOAT16 __cfloat16
#  else
# 143 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __CFLOAT16 _Complex _Float16
#  endif
# 145 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 146 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT32
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 148 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 149 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __CFLOAT32 _Complex float
#  else
# 151 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __CFLOAT32 _Complex _Float32
#  endif
# 153 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 154 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 156 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 157 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   ifdef __NO_LONG_DOUBLE_MATH
#    define __CFLOAT64 _Complex long double
#   else
# 160 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __CFLOAT64 _Complex double
#   endif
# 162 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#  else
# 163 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __CFLOAT64 _Complex _Float64
#  endif
# 165 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 166 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT32X
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 168 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 169 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __CFLOAT32X _Complex double
#  else
# 171 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __CFLOAT32X _Complex _Float32x
#  endif
# 173 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 174 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT64X
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 176 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 177 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#   if __HAVE_FLOAT64X_LONG_DOUBLE
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 178 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __CFLOAT64X _Complex long double
#   else
# 180 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __CFLOAT64X __CFLOAT128
#   endif
# 182 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#  else
# 183 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __CFLOAT64X _Complex _Float64x
#  endif
# 185 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 186 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT128X
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 188 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 189 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   error "_Float128X supported but no complex type"
#  else
# 191 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __CFLOAT128X _Complex _Float128x
#  endif
# 193 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# endif
# 194 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

/* The remaining of this file provides support for older compilers.  */
#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT16
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 197 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 199 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef float _Float16 __attribute__ ((__mode__ (__HF__)));
#  endif
# 201 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 203 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __builtin_huge_valf16() ((_Float16) __builtin_huge_val ())
#   define __builtin_inff16() ((_Float16) __builtin_inf ())
#   define __builtin_nanf16(x) ((_Float16) __builtin_nan (x))
#   define __builtin_nansf16(x) ((_Float16) __builtin_nans (x))
#  endif
# 208 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

# endif
# 210 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT32
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 212 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 214 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef float _Float32;
#  endif
# 216 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 218 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __builtin_huge_valf32() (__builtin_huge_valf ())
#   define __builtin_inff32() (__builtin_inff ())
#   define __builtin_nanf32(x) (__builtin_nanf (x))
#   define __builtin_nansf32(x) (__builtin_nansf (x))
#  endif
# 223 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

# endif
# 225 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 227 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

/* If double, long double and _Float64 all have the same set of
   values, TS 18661-3 requires the usual arithmetic conversions on
   long double and _Float64 to produce _Float64.  For this to be the
   case when building with a compiler without a distinct _Float64
   type, _Float64 must be a typedef for long double, not for
   double.  */

#  ifdef __NO_LONG_DOUBLE_MATH

#if 0 /* disabled by -frewrite-includes */
#   if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 238 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef long double _Float64;
#   endif
# 240 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#   if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 242 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __builtin_huge_valf64() (__builtin_huge_vall ())
#    define __builtin_inff64() (__builtin_infl ())
#    define __builtin_nanf64(x) (__builtin_nanl (x))
#    define __builtin_nansf64(x) (__builtin_nansl (x))
#   endif
# 247 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#  else
# 249 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#   if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 251 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef double _Float64;
#   endif
# 253 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#   if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 255 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __builtin_huge_valf64() (__builtin_huge_val ())
#    define __builtin_inff64() (__builtin_inf ())
#    define __builtin_nanf64(x) (__builtin_nan (x))
#    define __builtin_nansf64(x) (__builtin_nans (x))
#   endif
# 260 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#  endif
# 262 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

# endif
# 264 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT32X
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 266 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 268 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef double _Float32x;
#  endif
# 270 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 272 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __builtin_huge_valf32x() (__builtin_huge_val ())
#   define __builtin_inff32x() (__builtin_inf ())
#   define __builtin_nanf32x(x) (__builtin_nan (x))
#   define __builtin_nansf32x(x) (__builtin_nans (x))
#  endif
# 277 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

# endif
# 279 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT64X
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 281 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if __HAVE_FLOAT64X_LONG_DOUBLE
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 283 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#   if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 285 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef long double _Float64x;
#   endif
# 287 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#   if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 289 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __builtin_huge_valf64x() (__builtin_huge_vall ())
#    define __builtin_inff64x() (__builtin_infl ())
#    define __builtin_nanf64x(x) (__builtin_nanl (x))
#    define __builtin_nansf64x(x) (__builtin_nansl (x))
#   endif
# 294 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#  else
# 296 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#   if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 298 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef _Float128 _Float64x;
#   endif
# 300 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#   if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 302 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#    define __builtin_huge_valf64x() (__builtin_huge_valf128 ())
#    define __builtin_inff64x() (__builtin_inff128 ())
#    define __builtin_nanf64x(x) (__builtin_nanf128 (x))
#    define __builtin_nansf64x(x) (__builtin_nansf128 (x))
#   endif
# 307 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#  endif
# 309 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

# endif
# 311 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __HAVE_FLOAT128X
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 313 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0) || defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 315 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   error "_Float128x supported but no type"
#  endif
# 317 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#  if !__GNUC_PREREQ (7, 0)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 319 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#   define __builtin_huge_valf128x() ((_Float128x) __builtin_huge_val ())
#   define __builtin_inff128x() ((_Float128x) __builtin_inf ())
#   define __builtin_nanf128x(x) ((_Float128x) __builtin_nan (x))
#   define __builtin_nansf128x(x) ((_Float128x) __builtin_nans (x))
#  endif
# 324 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

# endif
# 326 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#endif /* !__ASSEMBLER__.  */
# 328 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4

#endif /* _BITS_FLOATN_COMMON_H */
# 330 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
#endif /* floatn-common.h expanded by -frewrite-includes */
# 120 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4

#endif /* _BITS_FLOATN_H */
# 122 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
#endif /* floatn.h expanded by -frewrite-includes */
# 431 "/usr/include/stdio.h" 2 3 4
#if 0 /* disabled by -frewrite-includes */
#if !__GLIBC_USE (DEPRECATED_SCANF) && !defined __LDBL_COMPAT \
    && __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI == 0
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 433 "/usr/include/stdio.h" 3 4
# ifdef __REDIRECT
extern int __REDIRECT (fscanf, (FILE *__restrict __stream,
				const char *__restrict __format, ...),
		       __isoc99_fscanf) __wur;
extern int __REDIRECT (scanf, (const char *__restrict __format, ...),
		       __isoc99_scanf) __wur;
extern int __REDIRECT_NTH (sscanf, (const char *__restrict __s,
				    const char *__restrict __format, ...),
			   __isoc99_sscanf);
# else
# 443 "/usr/include/stdio.h" 3 4
extern int __isoc99_fscanf (FILE *__restrict __stream,
			    const char *__restrict __format, ...) __wur;
extern int __isoc99_scanf (const char *__restrict __format, ...) __wur;
extern int __isoc99_sscanf (const char *__restrict __s,
			    const char *__restrict __format, ...) __THROW;
#  define fscanf __isoc99_fscanf
#  define scanf __isoc99_scanf
#  define sscanf __isoc99_sscanf
# endif
# 452 "/usr/include/stdio.h" 3 4
#endif
# 453 "/usr/include/stdio.h" 3 4

#ifdef	__USE_ISOC99
/* Read formatted input from S into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
		    __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __wur;

/* Read formatted input from stdin into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) __wur;

/* Read formatted input from S into argument list ARG.  */
extern int vsscanf (const char *__restrict __s,
		    const char *__restrict __format, __gnuc_va_list __arg)
     __THROW __attribute__ ((__format__ (__scanf__, 2, 0)));

/* Same redirection as above for the v*scanf family.  */
#if 0 /* disabled by -frewrite-includes */
# if !__GLIBC_USE (DEPRECATED_SCANF)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 477 "/usr/include/stdio.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#  if defined __REDIRECT && !defined __LDBL_COMPAT \
      && __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI == 0
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 479 "/usr/include/stdio.h" 3 4
extern int __REDIRECT (vfscanf,
		       (FILE *__restrict __s,
			const char *__restrict __format, __gnuc_va_list __arg),
		       __isoc99_vfscanf)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __wur;
extern int __REDIRECT (vscanf, (const char *__restrict __format,
				__gnuc_va_list __arg), __isoc99_vscanf)
     __attribute__ ((__format__ (__scanf__, 1, 0))) __wur;
extern int __REDIRECT_NTH (vsscanf,
			   (const char *__restrict __s,
			    const char *__restrict __format,
			    __gnuc_va_list __arg), __isoc99_vsscanf)
     __attribute__ ((__format__ (__scanf__, 2, 0)));
#if 0 /* disabled by -frewrite-includes */
#if 0
#  elif !defined __REDIRECT
#endif
#endif /* disabled by -frewrite-includes */
#elif 0 /* evaluated by -frewrite-includes */
# 493 "/usr/include/stdio.h" 3 4
extern int __isoc99_vfscanf (FILE *__restrict __s,
			     const char *__restrict __format,
			     __gnuc_va_list __arg) __wur;
extern int __isoc99_vscanf (const char *__restrict __format,
			    __gnuc_va_list __arg) __wur;
extern int __isoc99_vsscanf (const char *__restrict __s,
			     const char *__restrict __format,
			     __gnuc_va_list __arg) __THROW;
#   define vfscanf __isoc99_vfscanf
#   define vscanf __isoc99_vscanf
#   define vsscanf __isoc99_vsscanf
#  endif
# 505 "/usr/include/stdio.h" 3 4
# endif
# 506 "/usr/include/stdio.h" 3 4
#endif /* Use ISO C9x.  */
# 507 "/usr/include/stdio.h" 3 4


/* Read a character from STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);

/* Read a character from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int getchar (void);

#ifdef __USE_POSIX199506
/* These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
#endif /* Use POSIX.  */
# 530 "/usr/include/stdio.h" 3 4

#ifdef __USE_MISC
/* Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fgetc_unlocked (FILE *__stream);
#endif /* Use MISC.  */
# 540 "/usr/include/stdio.h" 3 4


/* Write a character to STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.

   These functions is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);

/* Write a character to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int putchar (int __c);

#ifdef __USE_MISC
/* Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fputc_unlocked (int __c, FILE *__stream);
#endif /* Use MISC.  */
# 567 "/usr/include/stdio.h" 3 4

#ifdef __USE_POSIX199506
/* These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
#endif /* Use POSIX.  */
# 576 "/usr/include/stdio.h" 3 4


#if 0 /* disabled by -frewrite-includes */
#if defined __USE_MISC \
    || (defined __USE_XOPEN && !defined __USE_XOPEN2K)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 580 "/usr/include/stdio.h" 3 4
/* Get a word (int) from STREAM.  */
extern int getw (FILE *__stream);

/* Write a word (int) to STREAM.  */
extern int putw (int __w, FILE *__stream);
#endif
# 586 "/usr/include/stdio.h" 3 4


/* Get a newline-terminated string of finite length from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __wur __fortified_attr_access (__write_only__, 1, 2);

#if 0 /* disabled by -frewrite-includes */
#if __GLIBC_USE (DEPRECATED_GETS)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 596 "/usr/include/stdio.h" 3 4
/* Get a newline-terminated string from stdin, removing the newline.

   This function is impossible to use safely.  It has been officially
   removed from ISO C11 and ISO C++14, and we have also removed it
   from the _GNU_SOURCE feature list.  It remains available when
   explicitly using an old ISO C, Unix, or POSIX standard.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern char *gets (char *__s) __wur __attribute_deprecated__;
#endif
# 607 "/usr/include/stdio.h" 3 4

#ifdef __USE_GNU
/* This function does the same as `fgets' but does not lock the stream.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern char *fgets_unlocked (char *__restrict __s, int __n,
			     FILE *__restrict __stream) __wur
    __fortified_attr_access (__write_only__, 1, 2);
#endif
# 619 "/usr/include/stdio.h" 3 4


#if 0 /* disabled by -frewrite-includes */
#if defined __USE_XOPEN2K8 || __GLIBC_USE (LIB_EXT2)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 622 "/usr/include/stdio.h" 3 4
/* Read up to (and including) a DELIMITER from STREAM into *LINEPTR
   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
   NULL), pointing to *N characters of space.  It is realloc'd as
   necessary.  Returns the number of characters read (not including the
   null terminator), or -1 on error or EOF.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) __wur;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) __wur;

/* Like `getdelim', but reads up to a newline.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __wur;
#endif
# 649 "/usr/include/stdio.h" 3 4


/* Write a string to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);

/* Write a string, followed by a newline, to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int puts (const char *__s);


/* Push a character back onto the input buffer of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int ungetc (int __c, FILE *__stream);


/* Read chunks of generic data from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fread (void *__restrict __ptr, size_t __size,
		     size_t __n, FILE *__restrict __stream) __wur;
/* Write chunks of generic data to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
		      size_t __n, FILE *__restrict __s);

#ifdef __USE_GNU
/* This function does the same as `fputs' but does not lock the stream.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fputs_unlocked (const char *__restrict __s,
			   FILE *__restrict __stream);
#endif
# 694 "/usr/include/stdio.h" 3 4

#ifdef __USE_MISC
/* Faster versions when locking is not necessary.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
			      size_t __n, FILE *__restrict __stream) __wur;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
			       size_t __n, FILE *__restrict __stream);
#endif
# 707 "/usr/include/stdio.h" 3 4


/* Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseek (FILE *__stream, long int __off, int __whence);
/* Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern long int ftell (FILE *__stream) __wur;
/* Rewind to the beginning of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void rewind (FILE *__stream);

/* The Single Unix Specification, Version 2, specifies an alternative,
   more adequate interface for the two functions above which deal with
   file offset.  `long int' is not the right type.  These definitions
   are originally defined in the Large File Support API.  */

#if 0 /* disabled by -frewrite-includes */
#if defined __USE_LARGEFILE || defined __USE_XOPEN2K
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 731 "/usr/include/stdio.h" 3 4
# ifndef __USE_FILE_OFFSET64
/* Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
/* Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern __off_t ftello (FILE *__stream) __wur;
# else
# 743 "/usr/include/stdio.h" 3 4
#  ifdef __REDIRECT
extern int __REDIRECT (fseeko,
		       (FILE *__stream, __off64_t __off, int __whence),
		       fseeko64);
extern __off64_t __REDIRECT (ftello, (FILE *__stream), ftello64);
#  else
# 749 "/usr/include/stdio.h" 3 4
#   define fseeko fseeko64
#   define ftello ftello64
#  endif
# 752 "/usr/include/stdio.h" 3 4
# endif
# 753 "/usr/include/stdio.h" 3 4
#endif
# 754 "/usr/include/stdio.h" 3 4

#ifndef __USE_FILE_OFFSET64
/* Get STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
/* Set STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
#else
# 767 "/usr/include/stdio.h" 3 4
# ifdef __REDIRECT
extern int __REDIRECT (fgetpos, (FILE *__restrict __stream,
				 fpos_t *__restrict __pos), fgetpos64);
extern int __REDIRECT (fsetpos,
		       (FILE *__stream, const fpos_t *__pos), fsetpos64);
# else
# 773 "/usr/include/stdio.h" 3 4
#  define fgetpos fgetpos64
#  define fsetpos fsetpos64
# endif
# 776 "/usr/include/stdio.h" 3 4
#endif
# 777 "/usr/include/stdio.h" 3 4

#ifdef __USE_LARGEFILE64
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) __wur;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);
#endif
# 784 "/usr/include/stdio.h" 3 4

/* Clear the error and EOF indicators for STREAM.  */
extern void clearerr (FILE *__stream) __THROW;
/* Return the EOF indicator for STREAM.  */
extern int feof (FILE *__stream) __THROW __wur;
/* Return the error indicator for STREAM.  */
extern int ferror (FILE *__stream) __THROW __wur;

#ifdef __USE_MISC
/* Faster versions when locking is not required.  */
extern void clearerr_unlocked (FILE *__stream) __THROW;
extern int feof_unlocked (FILE *__stream) __THROW __wur;
extern int ferror_unlocked (FILE *__stream) __THROW __wur;
#endif
# 798 "/usr/include/stdio.h" 3 4


/* Print a message describing the meaning of the value of errno.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void perror (const char *__s);


#ifdef	__USE_POSIX
/* Return the system file descriptor for STREAM.  */
extern int fileno (FILE *__stream) __THROW __wur;
#endif /* Use POSIX.  */
# 811 "/usr/include/stdio.h" 3 4

#ifdef __USE_MISC
/* Faster version when locking is not required.  */
extern int fileno_unlocked (FILE *__stream) __THROW __wur;
#endif
# 816 "/usr/include/stdio.h" 3 4


#ifdef __USE_POSIX2
/* Close a stream opened by popen and return the status of its child.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int pclose (FILE *__stream);

/* Create a new stream connected to a pipe running the given command.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *popen (const char *__command, const char *__modes)
  __attribute_malloc__ __attr_dealloc (pclose, 1) __wur;

#endif
# 833 "/usr/include/stdio.h" 3 4


#ifdef	__USE_POSIX
/* Return the name of the controlling terminal.  */
extern char *ctermid (char *__s) __THROW
  __attr_access ((__write_only__, 1));
#endif /* Use POSIX.  */
# 840 "/usr/include/stdio.h" 3 4


#if 0 /* disabled by -frewrite-includes */
#if (defined __USE_XOPEN && !defined __USE_XOPEN2K) || defined __USE_GNU
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 843 "/usr/include/stdio.h" 3 4
/* Return the name of the current user.  */
extern char *cuserid (char *__s)
  __attr_access ((__write_only__, 1));
#endif /* Use X/Open, but not issue 6.  */
# 847 "/usr/include/stdio.h" 3 4


#ifdef	__USE_GNU
struct obstack;			/* See <obstack.h>.  */

/* Write formatted output to an obstack.  */
extern int obstack_printf (struct obstack *__restrict __obstack,
			   const char *__restrict __format, ...)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
			    const char *__restrict __format,
			    __gnuc_va_list __args)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 0)));
#endif /* Use GNU.  */
# 861 "/usr/include/stdio.h" 3 4


#ifdef __USE_POSIX199506
/* These are defined in POSIX.1:1996.  */

/* Acquire ownership of STREAM.  */
extern void flockfile (FILE *__stream) __THROW;

/* Try to acquire ownership of STREAM but do not block if it is not
   possible.  */
extern int ftrylockfile (FILE *__stream) __THROW __wur;

/* Relinquish the ownership granted for STREAM.  */
extern void funlockfile (FILE *__stream) __THROW;
#endif /* POSIX */
# 876 "/usr/include/stdio.h" 3 4

#if 0 /* disabled by -frewrite-includes */
#if defined __USE_XOPEN && !defined __USE_XOPEN2K && !defined __USE_GNU
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 878 "/usr/include/stdio.h" 3 4
/*  X/Open Issues 1-5 required getopt to be declared in this
   header.  It was removed in Issue 6.  GNU follows Issue 6.  */
#if 0 /* expanded by -frewrite-includes */
# include <bits/getopt_posix.h>
#endif /* expanded by -frewrite-includes */
# 880 "/usr/include/stdio.h" 3 4
# 881 "/usr/include/stdio.h" 3 4
#endif
# 882 "/usr/include/stdio.h" 3 4

/* Slow-path routines used by the optimized inline functions in
   bits/stdio.h.  */
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);

/* If we are compiling with optimizing read this file.  It contains
   several optimizing inline functions and macros.  */
#ifdef __USE_EXTERN_INLINES
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* stdio.h expanded by -frewrite-includes */
# include <bits/stdio.h>
#else /* stdio.h expanded by -frewrite-includes */
# 891 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 1 3 4
/* Optimizing macros and inline functions for stdio functions.
   Copyright (C) 1998-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_STDIO_H
#define _BITS_STDIO_H 1

#ifndef _STDIO_H
# error "Never include <bits/stdio.h> directly; use <stdio.h> instead."
#endif
# 25 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4

#ifndef __extern_inline
# define __STDIO_INLINE inline
#else
# 29 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4
# define __STDIO_INLINE __extern_inline
#endif
# 31 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4


#ifdef __USE_EXTERN_INLINES
/* For -D_FORTIFY_SOURCE{,=2,=3} bits/stdio2.h will define a different
   inline.  */
#if 0 /* disabled by -frewrite-includes */
# if !(__USE_FORTIFY_LEVEL > 0 && defined __fortify_function)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 37 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4
/* Write formatted output to stdout from argument list ARG.  */
__STDIO_INLINE int
vprintf (const char *__restrict __fmt, __gnuc_va_list __arg)
{
  return vfprintf (stdout, __fmt, __arg);
}
# endif
# 44 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4

/* Read a character from stdin.  */
__STDIO_INLINE int
getchar (void)
{
  return getc (stdin);
}


# ifdef __USE_MISC
/* Faster version when locking is not necessary.  */
__STDIO_INLINE int
fgetc_unlocked (FILE *__fp)
{
  return __getc_unlocked_body (__fp);
}
# endif /* misc */
# 61 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4


# ifdef __USE_POSIX199506
/* This is defined in POSIX.1:1996.  */
__STDIO_INLINE int
getc_unlocked (FILE *__fp)
{
  return __getc_unlocked_body (__fp);
}

/* This is defined in POSIX.1:1996.  */
__STDIO_INLINE int
getchar_unlocked (void)
{
  return __getc_unlocked_body (stdin);
}
# endif	/* POSIX */
# 78 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4


/* Write a character to stdout.  */
__STDIO_INLINE int
putchar (int __c)
{
  return putc (__c, stdout);
}


# ifdef __USE_MISC
/* Faster version when locking is not necessary.  */
__STDIO_INLINE int
fputc_unlocked (int __c, FILE *__stream)
{
  return __putc_unlocked_body (__c, __stream);
}
# endif /* misc */
# 96 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4


# ifdef __USE_POSIX199506
/* This is defined in POSIX.1:1996.  */
__STDIO_INLINE int
putc_unlocked (int __c, FILE *__stream)
{
  return __putc_unlocked_body (__c, __stream);
}

/* This is defined in POSIX.1:1996.  */
__STDIO_INLINE int
putchar_unlocked (int __c)
{
  return __putc_unlocked_body (__c, stdout);
}
# endif	/* POSIX */
# 113 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4


# ifdef	__USE_GNU
/* Like `getdelim', but reads up to a newline.  */
__STDIO_INLINE __ssize_t
getline (char **__lineptr, size_t *__n, FILE *__stream)
{
  return __getdelim (__lineptr, __n, '\n', __stream);
}
# endif /* GNU */
# 123 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4


# ifdef __USE_MISC
/* Faster versions when locking is not required.  */
__STDIO_INLINE int
__NTH (feof_unlocked (FILE *__stream))
{
  return __feof_unlocked_body (__stream);
}

/* Faster versions when locking is not required.  */
__STDIO_INLINE int
__NTH (ferror_unlocked (FILE *__stream))
{
  return __ferror_unlocked_body (__stream);
}
# endif /* misc */
# 140 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4

#endif /* Use extern inlines.  */
# 142 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4


#if 0 /* disabled by -frewrite-includes */
#if defined __USE_MISC && defined __GNUC__ && defined __OPTIMIZE__ \
    && !defined __cplusplus
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 146 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4
/* Perform some simple optimizations.  */
# define fread_unlocked(ptr, size, n, stream) \
  (__extension__ ((__builtin_constant_p (size) && __builtin_constant_p (n)    \
		   && (size_t) (size) * (size_t) (n) <= 8		      \
		   && (size_t) (size) != 0)				      \
		  ? ({ char *__ptr = (char *) (ptr);			      \
		       FILE *__stream = (stream);			      \
		       size_t __cnt;					      \
		       for (__cnt = (size_t) (size) * (size_t) (n);	      \
			    __cnt > 0; --__cnt)				      \
			 {						      \
			   int __c = getc_unlocked (__stream);		      \
			   if (__c == EOF)				      \
			     break;					      \
			   *__ptr++ = __c;				      \
			 }						      \
		       ((size_t) (size) * (size_t) (n) - __cnt)		      \
			/ (size_t) (size); })				      \
		  : (((__builtin_constant_p (size) && (size_t) (size) == 0)   \
		      || (__builtin_constant_p (n) && (size_t) (n) == 0))     \
			/* Evaluate all parameters once.  */		      \
		     ? ((void) (ptr), (void) (stream), (void) (size),	      \
			(void) (n), (size_t) 0)				      \
		     : fread_unlocked (ptr, size, n, stream))))

# define fwrite_unlocked(ptr, size, n, stream) \
  (__extension__ ((__builtin_constant_p (size) && __builtin_constant_p (n)    \
		   && (size_t) (size) * (size_t) (n) <= 8		      \
		   && (size_t) (size) != 0)				      \
		  ? ({ const char *__ptr = (const char *) (ptr);	      \
		       FILE *__stream = (stream);			      \
		       size_t __cnt;					      \
		       for (__cnt = (size_t) (size) * (size_t) (n);	      \
			    __cnt > 0; --__cnt)				      \
			 if (putc_unlocked (*__ptr++, __stream) == EOF)	      \
			   break;					      \
		       ((size_t) (size) * (size_t) (n) - __cnt)		      \
			/ (size_t) (size); })				      \
		  : (((__builtin_constant_p (size) && (size_t) (size) == 0)   \
		      || (__builtin_constant_p (n) && (size_t) (n) == 0))     \
			/* Evaluate all parameters once.  */		      \
		     ? ((void) (ptr), (void) (stream), (void) (size),	      \
			(void) (n), (size_t) 0)				      \
		     : fwrite_unlocked (ptr, size, n, stream))))
#endif
# 191 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4

/* Define helper macro.  */
#undef __STDIO_INLINE

#endif /* bits/stdio.h.  */
# 196 "/usr/include/x86_64-linux-gnu/bits/stdio.h" 3 4
#endif /* stdio.h expanded by -frewrite-includes */
# 892 "/usr/include/stdio.h" 2 3 4
#endif
# 893 "/usr/include/stdio.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if __USE_FORTIFY_LEVEL > 0 && defined __fortify_function
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 894 "/usr/include/stdio.h" 3 4
#if 0 /* expanded by -frewrite-includes */
# include <bits/stdio2.h>
#endif /* expanded by -frewrite-includes */
# 894 "/usr/include/stdio.h" 3 4
# 895 "/usr/include/stdio.h" 3 4
#endif
# 896 "/usr/include/stdio.h" 3 4

#if 0 /* expanded by -frewrite-includes */
#include <bits/floatn.h>
#endif /* expanded by -frewrite-includes */
# 897 "/usr/include/stdio.h" 3 4
# 898 "/usr/include/stdio.h" 3 4
#if 0 /* disabled by -frewrite-includes */
#if defined __LDBL_COMPAT || __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI == 1
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 899 "/usr/include/stdio.h" 3 4
#if 0 /* expanded by -frewrite-includes */
# include <bits/stdio-ldbl.h>
#endif /* expanded by -frewrite-includes */
# 899 "/usr/include/stdio.h" 3 4
# 900 "/usr/include/stdio.h" 3 4
#endif
# 901 "/usr/include/stdio.h" 3 4

__END_DECLS

#endif /* <stdio.h> included.  */
# 905 "/usr/include/stdio.h" 3 4
#endif /* stdio.h expanded by -frewrite-includes */
# 3 "test_1609_e21a3547_3d9d921b_068b9d94_6d4734f3_4dd78440_b28bb6f7_221c4b02_d710a80e_8a962bd7_0a416e5d_6229703d.c" 2
#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* inttypes.h expanded by -frewrite-includes */
#include <inttypes.h>
#else /* inttypes.h expanded by -frewrite-includes */
# 3 "test_1609_e21a3547_3d9d921b_068b9d94_6d4734f3_4dd78440_b28bb6f7_221c4b02_d710a80e_8a962bd7_0a416e5d_6229703d.c"
# 1 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 1 3
/*===---- inttypes.h - Standard header for integer printf macros ----------===*\
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
\*===----------------------------------------------------------------------===*/

#ifndef __CLANG_INTTYPES_H
// AIX system headers need inttypes.h to be re-enterable while _STD_TYPES_T
// is defined until an inclusion of it without _STD_TYPES_T occurs, in which
// case the header guard macro is defined.
#if 0 /* disabled by -frewrite-includes */
#if !defined(_AIX) || !defined(_STD_TYPES_T)
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 14 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
#define __CLANG_INTTYPES_H
#endif
# 16 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
#if 0 /* disabled by -frewrite-includes */
#if defined(__MVS__) && __has_include_next(<inttypes.h>)
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 17 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
#if 0 /* expanded by -frewrite-includes */
#include_next <inttypes.h>
#endif /* expanded by -frewrite-includes */
# 17 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
# 18 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
#else
# 19 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3

#if 0 /* disabled by -frewrite-includes */
#if defined(_MSC_VER) && _MSC_VER < 1800
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 21 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
#error MSVC does not have inttypes.h prior to Visual Studio 2013
#endif
# 23 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3

#if defined(__CLANG_REWRITTEN_INCLUDES) || defined(__CLANG_REWRITTEN_SYSTEM_INCLUDES) /* inttypes.h expanded by -frewrite-includes */
#include_next <inttypes.h>
#else /* inttypes.h expanded by -frewrite-includes */
# 24 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
# 1 "/usr/include/inttypes.h" 1 3 4
/* Copyright (C) 1997-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	ISO C99: 7.8 Format conversion of integer types	<inttypes.h>
 */

#ifndef _INTTYPES_H
#define _INTTYPES_H	1

#if 0 /* expanded by -frewrite-includes */
#include <features.h>
#endif /* expanded by -frewrite-includes */
# 25 "/usr/include/inttypes.h" 3 4
# 26 "/usr/include/inttypes.h" 3 4
/* Get the type definitions.  */
#if 0 /* expanded by -frewrite-includes */
#include <stdint.h>
#endif /* expanded by -frewrite-includes */
# 27 "/usr/include/inttypes.h" 3 4
# 28 "/usr/include/inttypes.h" 3 4

/* Get a definition for wchar_t.  But we must not define wchar_t itself.  */
#ifndef ____gwchar_t_defined
# ifdef __cplusplus
#  define __gwchar_t wchar_t
#if 0 /* disabled by -frewrite-includes */
#if 0
# elif defined __WCHAR_TYPE__
#endif
#endif /* disabled by -frewrite-includes */
#elif 1 /* evaluated by -frewrite-includes */
# 34 "/usr/include/inttypes.h" 3 4
typedef __WCHAR_TYPE__ __gwchar_t;
# else
# 36 "/usr/include/inttypes.h" 3 4
#  define __need_wchar_t
#if 0 /* expanded by -frewrite-includes */
#  include <stddef.h>
#endif /* expanded by -frewrite-includes */
# 37 "/usr/include/inttypes.h" 3 4
# 38 "/usr/include/inttypes.h" 3 4
typedef wchar_t __gwchar_t;
# endif
# 40 "/usr/include/inttypes.h" 3 4
# define ____gwchar_t_defined	1
#endif
# 42 "/usr/include/inttypes.h" 3 4

#if 0 /* disabled by -frewrite-includes */
# if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 44 "/usr/include/inttypes.h" 3 4
#  define __PRI64_PREFIX	"l"
#  define __PRIPTR_PREFIX	"l"
# else
# 47 "/usr/include/inttypes.h" 3 4
#  define __PRI64_PREFIX	"ll"
#  define __PRIPTR_PREFIX
# endif
# 50 "/usr/include/inttypes.h" 3 4

/* Macros for printing format specifiers.  */

/* Decimal notation.  */
# define PRId8		"d"
# define PRId16		"d"
# define PRId32		"d"
# define PRId64		__PRI64_PREFIX "d"

# define PRIdLEAST8	"d"
# define PRIdLEAST16	"d"
# define PRIdLEAST32	"d"
# define PRIdLEAST64	__PRI64_PREFIX "d"

# define PRIdFAST8	"d"
# define PRIdFAST16	__PRIPTR_PREFIX "d"
# define PRIdFAST32	__PRIPTR_PREFIX "d"
# define PRIdFAST64	__PRI64_PREFIX "d"


# define PRIi8		"i"
# define PRIi16		"i"
# define PRIi32		"i"
# define PRIi64		__PRI64_PREFIX "i"

# define PRIiLEAST8	"i"
# define PRIiLEAST16	"i"
# define PRIiLEAST32	"i"
# define PRIiLEAST64	__PRI64_PREFIX "i"

# define PRIiFAST8	"i"
# define PRIiFAST16	__PRIPTR_PREFIX "i"
# define PRIiFAST32	__PRIPTR_PREFIX "i"
# define PRIiFAST64	__PRI64_PREFIX "i"

/* Octal notation.  */
# define PRIo8		"o"
# define PRIo16		"o"
# define PRIo32		"o"
# define PRIo64		__PRI64_PREFIX "o"

# define PRIoLEAST8	"o"
# define PRIoLEAST16	"o"
# define PRIoLEAST32	"o"
# define PRIoLEAST64	__PRI64_PREFIX "o"

# define PRIoFAST8	"o"
# define PRIoFAST16	__PRIPTR_PREFIX "o"
# define PRIoFAST32	__PRIPTR_PREFIX "o"
# define PRIoFAST64	__PRI64_PREFIX "o"

/* Unsigned integers.  */
# define PRIu8		"u"
# define PRIu16		"u"
# define PRIu32		"u"
# define PRIu64		__PRI64_PREFIX "u"

# define PRIuLEAST8	"u"
# define PRIuLEAST16	"u"
# define PRIuLEAST32	"u"
# define PRIuLEAST64	__PRI64_PREFIX "u"

# define PRIuFAST8	"u"
# define PRIuFAST16	__PRIPTR_PREFIX "u"
# define PRIuFAST32	__PRIPTR_PREFIX "u"
# define PRIuFAST64	__PRI64_PREFIX "u"

/* lowercase hexadecimal notation.  */
# define PRIx8		"x"
# define PRIx16		"x"
# define PRIx32		"x"
# define PRIx64		__PRI64_PREFIX "x"

# define PRIxLEAST8	"x"
# define PRIxLEAST16	"x"
# define PRIxLEAST32	"x"
# define PRIxLEAST64	__PRI64_PREFIX "x"

# define PRIxFAST8	"x"
# define PRIxFAST16	__PRIPTR_PREFIX "x"
# define PRIxFAST32	__PRIPTR_PREFIX "x"
# define PRIxFAST64	__PRI64_PREFIX "x"

/* UPPERCASE hexadecimal notation.  */
# define PRIX8		"X"
# define PRIX16		"X"
# define PRIX32		"X"
# define PRIX64		__PRI64_PREFIX "X"

# define PRIXLEAST8	"X"
# define PRIXLEAST16	"X"
# define PRIXLEAST32	"X"
# define PRIXLEAST64	__PRI64_PREFIX "X"

# define PRIXFAST8	"X"
# define PRIXFAST16	__PRIPTR_PREFIX "X"
# define PRIXFAST32	__PRIPTR_PREFIX "X"
# define PRIXFAST64	__PRI64_PREFIX "X"


/* Macros for printing `intmax_t' and `uintmax_t'.  */
# define PRIdMAX	__PRI64_PREFIX "d"
# define PRIiMAX	__PRI64_PREFIX "i"
# define PRIoMAX	__PRI64_PREFIX "o"
# define PRIuMAX	__PRI64_PREFIX "u"
# define PRIxMAX	__PRI64_PREFIX "x"
# define PRIXMAX	__PRI64_PREFIX "X"


/* Macros for printing `intptr_t' and `uintptr_t'.  */
# define PRIdPTR	__PRIPTR_PREFIX "d"
# define PRIiPTR	__PRIPTR_PREFIX "i"
# define PRIoPTR	__PRIPTR_PREFIX "o"
# define PRIuPTR	__PRIPTR_PREFIX "u"
# define PRIxPTR	__PRIPTR_PREFIX "x"
# define PRIXPTR	__PRIPTR_PREFIX "X"


/* Macros for scanning format specifiers.  */

/* Signed decimal notation.  */
# define SCNd8		"hhd"
# define SCNd16		"hd"
# define SCNd32		"d"
# define SCNd64		__PRI64_PREFIX "d"

# define SCNdLEAST8	"hhd"
# define SCNdLEAST16	"hd"
# define SCNdLEAST32	"d"
# define SCNdLEAST64	__PRI64_PREFIX "d"

# define SCNdFAST8	"hhd"
# define SCNdFAST16	__PRIPTR_PREFIX "d"
# define SCNdFAST32	__PRIPTR_PREFIX "d"
# define SCNdFAST64	__PRI64_PREFIX "d"

/* Signed decimal notation.  */
# define SCNi8		"hhi"
# define SCNi16		"hi"
# define SCNi32		"i"
# define SCNi64		__PRI64_PREFIX "i"

# define SCNiLEAST8	"hhi"
# define SCNiLEAST16	"hi"
# define SCNiLEAST32	"i"
# define SCNiLEAST64	__PRI64_PREFIX "i"

# define SCNiFAST8	"hhi"
# define SCNiFAST16	__PRIPTR_PREFIX "i"
# define SCNiFAST32	__PRIPTR_PREFIX "i"
# define SCNiFAST64	__PRI64_PREFIX "i"

/* Unsigned decimal notation.  */
# define SCNu8		"hhu"
# define SCNu16		"hu"
# define SCNu32		"u"
# define SCNu64		__PRI64_PREFIX "u"

# define SCNuLEAST8	"hhu"
# define SCNuLEAST16	"hu"
# define SCNuLEAST32	"u"
# define SCNuLEAST64	__PRI64_PREFIX "u"

# define SCNuFAST8	"hhu"
# define SCNuFAST16	__PRIPTR_PREFIX "u"
# define SCNuFAST32	__PRIPTR_PREFIX "u"
# define SCNuFAST64	__PRI64_PREFIX "u"

/* Octal notation.  */
# define SCNo8		"hho"
# define SCNo16		"ho"
# define SCNo32		"o"
# define SCNo64		__PRI64_PREFIX "o"

# define SCNoLEAST8	"hho"
# define SCNoLEAST16	"ho"
# define SCNoLEAST32	"o"
# define SCNoLEAST64	__PRI64_PREFIX "o"

# define SCNoFAST8	"hho"
# define SCNoFAST16	__PRIPTR_PREFIX "o"
# define SCNoFAST32	__PRIPTR_PREFIX "o"
# define SCNoFAST64	__PRI64_PREFIX "o"

/* Hexadecimal notation.  */
# define SCNx8		"hhx"
# define SCNx16		"hx"
# define SCNx32		"x"
# define SCNx64		__PRI64_PREFIX "x"

# define SCNxLEAST8	"hhx"
# define SCNxLEAST16	"hx"
# define SCNxLEAST32	"x"
# define SCNxLEAST64	__PRI64_PREFIX "x"

# define SCNxFAST8	"hhx"
# define SCNxFAST16	__PRIPTR_PREFIX "x"
# define SCNxFAST32	__PRIPTR_PREFIX "x"
# define SCNxFAST64	__PRI64_PREFIX "x"


/* Macros for scanning `intmax_t' and `uintmax_t'.  */
# define SCNdMAX	__PRI64_PREFIX "d"
# define SCNiMAX	__PRI64_PREFIX "i"
# define SCNoMAX	__PRI64_PREFIX "o"
# define SCNuMAX	__PRI64_PREFIX "u"
# define SCNxMAX	__PRI64_PREFIX "x"

/* Macros for scaning `intptr_t' and `uintptr_t'.  */
# define SCNdPTR	__PRIPTR_PREFIX "d"
# define SCNiPTR	__PRIPTR_PREFIX "i"
# define SCNoPTR	__PRIPTR_PREFIX "o"
# define SCNuPTR	__PRIPTR_PREFIX "u"
# define SCNxPTR	__PRIPTR_PREFIX "x"


__BEGIN_DECLS

#if 0 /* disabled by -frewrite-includes */
#if __WORDSIZE == 64
#endif
#endif /* disabled by -frewrite-includes */
#if 1 /* evaluated by -frewrite-includes */
# 269 "/usr/include/inttypes.h" 3 4

/* We have to define the `uintmax_t' type using `ldiv_t'.  */
typedef struct
  {
    long int quot;		/* Quotient.  */
    long int rem;		/* Remainder.  */
  } imaxdiv_t;

#else
# 278 "/usr/include/inttypes.h" 3 4

/* We have to define the `uintmax_t' type using `lldiv_t'.  */
typedef struct
  {
    __extension__ long long int quot;	/* Quotient.  */
    __extension__ long long int rem;	/* Remainder.  */
  } imaxdiv_t;

#endif
# 287 "/usr/include/inttypes.h" 3 4


/* Compute absolute value of N.  */
extern intmax_t imaxabs (intmax_t __n) __THROW __attribute__ ((__const__));

/* Return the `imaxdiv_t' representation of the value of NUMER over DENOM. */
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __THROW __attribute__ ((__const__));

/* Like `strtol' but convert to `intmax_t'.  */
extern intmax_t strtoimax (const char *__restrict __nptr,
			   char **__restrict __endptr, int __base) __THROW;

/* Like `strtoul' but convert to `uintmax_t'.  */
extern uintmax_t strtoumax (const char *__restrict __nptr,
			    char ** __restrict __endptr, int __base) __THROW;

/* Like `wcstol' but convert to `intmax_t'.  */
extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
			   __gwchar_t **__restrict __endptr, int __base)
     __THROW;

/* Like `wcstoul' but convert to `uintmax_t'.  */
extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
			    __gwchar_t ** __restrict __endptr, int __base)
     __THROW;

__END_DECLS

#endif /* inttypes.h */
# 317 "/usr/include/inttypes.h" 3 4
#endif /* inttypes.h expanded by -frewrite-includes */
# 25 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 2 3

#if 0 /* disabled by -frewrite-includes */
#if defined(_MSC_VER) && _MSC_VER < 1900
#endif
#endif /* disabled by -frewrite-includes */
#if 0 /* evaluated by -frewrite-includes */
# 27 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
/* MSVC headers define int32_t as int, but PRIx32 as "lx" instead of "x".
 * This triggers format warnings, so fix it up here. */
#undef PRId32
#undef PRIdLEAST32
#undef PRIdFAST32
#undef PRIi32
#undef PRIiLEAST32
#undef PRIiFAST32
#undef PRIo32
#undef PRIoLEAST32
#undef PRIoFAST32
#undef PRIu32
#undef PRIuLEAST32
#undef PRIuFAST32
#undef PRIx32
#undef PRIxLEAST32
#undef PRIxFAST32
#undef PRIX32
#undef PRIXLEAST32
#undef PRIXFAST32

#undef SCNd32
#undef SCNdLEAST32
#undef SCNdFAST32
#undef SCNi32
#undef SCNiLEAST32
#undef SCNiFAST32
#undef SCNo32
#undef SCNoLEAST32
#undef SCNoFAST32
#undef SCNu32
#undef SCNuLEAST32
#undef SCNuFAST32
#undef SCNx32
#undef SCNxLEAST32
#undef SCNxFAST32

#define PRId32 "d"
#define PRIdLEAST32 "d"
#define PRIdFAST32 "d"
#define PRIi32 "i"
#define PRIiLEAST32 "i"
#define PRIiFAST32 "i"
#define PRIo32 "o"
#define PRIoLEAST32 "o"
#define PRIoFAST32 "o"
#define PRIu32 "u"
#define PRIuLEAST32 "u"
#define PRIuFAST32 "u"
#define PRIx32 "x"
#define PRIxLEAST32 "x"
#define PRIxFAST32 "x"
#define PRIX32 "X"
#define PRIXLEAST32 "X"
#define PRIXFAST32 "X"

#define SCNd32 "d"
#define SCNdLEAST32 "d"
#define SCNdFAST32 "d"
#define SCNi32 "i"
#define SCNiLEAST32 "i"
#define SCNiFAST32 "i"
#define SCNo32 "o"
#define SCNoLEAST32 "o"
#define SCNoFAST32 "o"
#define SCNu32 "u"
#define SCNuLEAST32 "u"
#define SCNuFAST32 "u"
#define SCNx32 "x"
#define SCNxLEAST32 "x"
#define SCNxFAST32 "x"
#endif
# 99 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3

#endif /* __MVS__ */
# 101 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
#endif /* __CLANG_INTTYPES_H */
# 102 "/users/a_irmak/llvm-latest-build/lib/clang/22/include/inttypes.h" 3
#endif /* inttypes.h expanded by -frewrite-includes */
# 4 "test_1609_e21a3547_3d9d921b_068b9d94_6d4734f3_4dd78440_b28bb6f7_221c4b02_d710a80e_8a962bd7_0a416e5d_6229703d.c" 2

int32_t a, c, e;
int8_t b;
int16_t d;
int32_t x;
int64_t y;

int64_t f() {
  int32_t g = 0;
  x = g + 42 + ((long)((((double)(x)) * ((double)(g))))) + 42 * ((long)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))))) & ((int)(x))))) + 42 + ((short)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))) + 42 * ((long)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))))) & ((int)(x))))))) >> ((int)(x))))) * ((short)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))) + 42 * ((long)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))))) & ((int)(x))))))) ^ ((int)(x))))) - ((long)((((int)(x)) >> ((int)(x))))) - ((short)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))) + 42 * ((long)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))))) & ((int)(x))))))) << ((int)(x))))) * ((short)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))) + 42 * ((long)((((int)(g + 42 + ((long)((((double)(x)) * ((double)(g))))))) & ((int)(x))))))) << ((int)(x)))));
  
int loop_break_15434 = 0;

int loop_break_15651 = 0;

int loop_break_15674 = 0;

int loop_break_17325 = 0;

int loop_break_17348 = 0;
for (; g < 5; g++)
    ;
  
int loop_break_15506 = 0;

int loop_break_15746 = 0;

int loop_break_15792 = 0;

int loop_break_17469 = 0;

int loop_break_17516 = 0;
for (; g < 3; (void)g)
  h:
    for (;; (void)a)
      ;
  
int loop_break_15613 = 0;

int loop_break_15893 = 0;

int loop_break_15994 = 0;

int loop_break_18369 = 0;

int loop_break_18470 = 0;
for (;; (void)b) {
    




loop_break_18470++;
if(loop_break_18470<=14){
continue;
}

loop_break_18369++;
if(loop_break_18369<=45){
continue;
}

loop_break_15994++;
if(((int)loop_break_15994<=6 + 41 + ((short)((((double)(6)) + ((double)(loop_break_15994))))))){
break;
}

loop_break_15893++;
if(((int)loop_break_15893<=42 + 41 - ((long)((((double)(loop_break_15893)) * ((double)(loop_break_15893))))) * ((int)((((double)(loop_break_15893)) + ((double)(42))))) * ((int)((((int)(42)) % ((int)(42))))) * ((int)((((double)(loop_break_15893)) * ((double)(42))))) - ((long)((((double)(42)) + ((double)(loop_break_15893))))) + ((int)((((double)(loop_break_15893)) + ((double)(42))))))){
continue;
}

loop_break_15613++;
if(0){
continue;
}

int32_t i;
    if (0)
      goto h;
    if (d) {
      if (e)
        return 0;
      break;
    }
    if (0)
      continue;
  }
  {
    0 + 42 - ((short)((((double)(0)) + ((double)(y))))) + ((long)((((int)(0)) | ((int)(y))))) * ((short)((((int)(0)) >> ((int)(y))))) - ((int)((((double)(y)) * ((double)(y)))));
    return y;
  };
}

int64_t z;

int32_t main() {
  int64_t val_8;
  int64_t val_7;
  int32_t val_6;
  int16_t val_5;
  int8_t val_4;
  int32_t val_3;
  int32_t val_2;
  int32_t val_1;

  
;val_2 = -2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))) + 42 * ((int)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))) << ((int)(val_2))))) + ((short)((((double)(val_2)) - ((double)(val_2))))) * ((short)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))) ^ ((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2)))))))))) + 42 + ((short)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))) + 42 * ((int)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))) << ((int)(val_2))))) + ((short)((((double)(val_2)) - ((double)(val_2))))) * ((short)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))) ^ ((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2)))))))))))) ^ ((int)(val_2))))) * ((int)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))) + 42 * ((int)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))) << ((int)(val_2))))) + ((short)((((double)(val_2)) - ((double)(val_2))))) * ((short)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))) ^ ((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2)))))))))))) | ((int)(val_2))))) + ((short)((((int)(val_2)) ^ ((int)(val_2)))));
0 + 42 + ((short)((((double)(val_1)) * ((double)(val_1))))) + 42 - ((int)((((int)(val_1)) >> ((int)(val_1))))) + ((int)((((int)(0)) % ((int)(0 + 42))))) - ((int)((((int)(((short)((((double)(val_1)) * ((double)(val_1))))))) << ((int)(0 + 42)))));
  
;val_3 = 0 + 42 * ((int)((((double)(0)) + ((double)(0))))) - ((short)((((double)(val_3)) + ((double)(val_3))))) + ((long)((((double)(0)) * ((double)(0))))) - ((long)((((int)(0)) & ((int)(0))))) + 42 + ((short)((((int)(0 + 42 * ((int)((((double)(0)) + ((double)(0))))) - ((short)((((double)(val_3)) + ((double)(val_3))))) + ((long)((((double)(0)) * ((double)(0))))) - ((long)((((int)(0)) & ((int)(0))))))) << ((int)(0 + 42 * ((int)((((double)(0)) + ((double)(0))))) - ((short)((((double)(val_3)) + ((double)(val_3))))) + ((long)((((double)(0)) * ((double)(0))))) - ((long)((((int)(0)) & ((int)(0))))))))));
val_2 = -2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))) + 42 * ((int)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))) << ((int)(val_2))))) + ((short)((((double)(val_2)) - ((double)(val_2))))) * ((short)((((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))) ^ ((int)(-2 + 42 + ((long)((((double)(val_2)) * ((double)(val_2))))) * ((long)((((double)(val_2)) + ((double)(-2))))) - ((short)((((double)(val_2)) + ((double)(-2))))) + ((long)((((double)(-2)) + ((double)(val_2))))) - ((short)((((double)(-2)) + ((double)(val_2))))))))));
  
;val_4 = 0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))) + 42 + ((long)((((int)(val_4)) % ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) - ((short)((((int)(val_4)) | ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) * ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) % ((int)(val_4))))) - ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) >> ((int)(val_4))))) + ((long)((((int)(val_4)) << ((int)(val_4)))));
val_3 = 0 + 42 * ((int)((((double)(0)) + ((double)(0))))) - ((short)((((double)(val_3)) + ((double)(val_3))))) + ((long)((((double)(0)) * ((double)(0))))) - ((long)((((int)(0)) & ((int)(0))))) + 42 + ((short)((((int)(0 + 42 * ((int)((((double)(0)) + ((double)(0))))) - ((short)((((double)(val_3)) + ((double)(val_3))))) + ((long)((((double)(0)) * ((double)(0))))) - ((long)((((int)(0)) & ((int)(0))))))) << ((int)(0 + 42 * ((int)((((double)(0)) + ((double)(0))))) - ((short)((((double)(val_3)) + ((double)(val_3))))) + ((long)((((double)(0)) * ((double)(0))))) - ((long)((((int)(0)) & ((int)(0))))))))));
  val_4 = 0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))) + 42 + ((long)((((int)(val_4)) % ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) - ((short)((((int)(val_4)) | ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) * ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) % ((int)(val_4))))) - ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) >> ((int)(val_4))))) + ((long)((((int)(val_4)) << ((int)(val_4))))) + 42 + ((short)((((int)(val_4)) << ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))) + 42 + ((long)((((int)(val_4)) % ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) - ((short)((((int)(val_4)) | ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) * ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) % ((int)(val_4))))) - ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) >> ((int)(val_4))))) + ((long)((((int)(val_4)) << ((int)(val_4)))))))))) + ((short)((((double)(val_4)) * ((double)(val_4))))) * ((int)((((int)(val_4)) % ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))) + 42 + ((long)((((int)(val_4)) % ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) - ((short)((((int)(val_4)) | ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) * ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) % ((int)(val_4))))) - ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) >> ((int)(val_4))))) + ((long)((((int)(val_4)) << ((int)(val_4)))))))))) - ((short)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))) + 42 + ((long)((((int)(val_4)) % ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) - ((short)((((int)(val_4)) | ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) * ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) % ((int)(val_4))))) - ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) >> ((int)(val_4))))) + ((long)((((int)(val_4)) << ((int)(val_4))))))) ^ ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))) + 42 + ((long)((((int)(val_4)) % ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) - ((short)((((int)(val_4)) | ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) * ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) % ((int)(val_4))))) - ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) >> ((int)(val_4))))) + ((long)((((int)(val_4)) << ((int)(val_4)))))))))) + ((long)((((int)(val_4)) ^ ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))) + 42 + ((long)((((int)(val_4)) % ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) - ((short)((((int)(val_4)) | ((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0)))))))))) * ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) % ((int)(val_4))))) - ((long)((((int)(0 + 42 + ((long)((((int)(val_4)) % ((int)(val_4))))) * ((long)((((double)(val_4)) - ((double)(0))))) + ((short)((((int)(0)) % ((int)(0))))))) >> ((int)(val_4))))) + ((long)((((int)(val_4)) << ((int)(val_4))))))))));
  val_5;
  
;val_7 = 0 + 42 + ((int)((((double)(0)) * ((double)(0))))) - ((int)((((double)(val_7)) + ((double)(val_7))))) + ((int)((((double)(val_7)) * ((double)(0)))));
4 + 42 - ((long)((((int)(4)) ^ ((int)(val_6))))) - ((short)((((int)(4)) ^ ((int)(4))))) - ((short)((((double)(val_6)) * ((double)(val_6))))) * ((short)((((double)(4)) + ((double)(4)))));
  
;val_8 = 0 + 42 - ((short)((((double)(val_8)) - ((double)(0))))) + ((short)((((int)(val_8)) ^ ((int)(0))))) + 42 * ((short)((((double)(0 + 42 - ((short)((((double)(val_8)) - ((double)(0))))) + ((short)((((int)(val_8)) ^ ((int)(0))))))) - ((double)(0 + 42 - ((short)((((double)(val_8)) - ((double)(0))))) + ((short)((((int)(val_8)) ^ ((int)(0)))))))))) + ((int)((((double)(val_8)) - ((double)(0 + 42 - ((short)((((double)(val_8)) - ((double)(0))))) + ((short)((((int)(val_8)) ^ ((int)(0)))))))))) - ((int)((((int)(val_8)) % ((int)(val_8))))) + ((long)((((double)(val_8)) * ((double)(val_8))))) + ((short)((((double)(val_8)) - ((double)(val_8))))) + 42 - ((short)((((int)(((long)((((double)(val_8)) * ((double)(val_8))))))) % ((int)(((short)((((double)(val_8)) - ((double)(val_8))))))))));
val_7 = 0 + 42 + ((int)((((double)(0)) * ((double)(0))))) - ((int)((((double)(val_7)) + ((double)(val_7))))) + ((int)((((double)(val_7)) * ((double)(0)))));
  val_8 = 0 + 42 - ((short)((((double)(val_8)) - ((double)(0))))) + ((short)((((int)(val_8)) ^ ((int)(0))))) + 42 * ((short)((((double)(0 + 42 - ((short)((((double)(val_8)) - ((double)(0))))) + ((short)((((int)(val_8)) ^ ((int)(0))))))) - ((double)(0 + 42 - ((short)((((double)(val_8)) - ((double)(0))))) + ((short)((((int)(val_8)) ^ ((int)(0)))))))))) + ((int)((((double)(val_8)) - ((double)(0 + 42 - ((short)((((double)(val_8)) - ((double)(0))))) + ((short)((((int)(val_8)) ^ ((int)(0)))))))))) - ((int)((((int)(val_8)) % ((int)(val_8))))) + ((long)((((double)(val_8)) * ((double)(val_8))))) + ((short)((((double)(val_8)) - ((double)(val_8)))));

  val_8 + 42 * ((long)((((int)(z)) % ((int)(val_8))))) - ((short)((((double)(val_8)) * ((double)(val_8))))) * ((int)((((int)(z)) & ((int)(z))))) + 42 * ((long)((((int)(val_8 + 42 * ((long)((((int)(z)) % ((int)(val_8))))) - ((short)((((double)(val_8)) * ((double)(val_8))))) * ((int)((((int)(z)) & ((int)(z))))))) << ((int)(((long)((((int)(z)) % ((int)(val_8)))))))))) * ((short)((((double)(42)) - ((double)(((long)((((int)(z)) % ((int)(val_8)))))))))) * ((short)((((int)(val_8 + 42 * ((long)((((int)(z)) % ((int)(val_8))))))) << ((int)(((long)((((int)(z)) % ((int)(val_8)))))))))) - ((short)((((int)(((short)((((double)(val_8)) * ((double)(val_8))))) * ((int)((((int)(z)) & ((int)(z))))))) << ((int)(((short)((((double)(val_8)) * ((double)(val_8))))) * ((int)((((int)(z)) & ((int)(z)))))))))) + ((long)((((int)(val_8)) << ((int)(val_8)))));
  
;x = val_6 + 42 + ((short)((((double)(x)) - ((double)(val_6))))) + 42 - ((short)((((int)(val_6)) >> ((int)(42))))) * ((short)((((int)(((short)((((double)(x)) - ((double)(val_6))))))) ^ ((int)(x))))) * ((int)((((int)(val_6)) >> ((int)(val_6))))) * ((long)((((int)(val_6 + 42)) << ((int)(val_6))))) + 42 - ((short)((((int)(val_6 + 42 + ((short)((((double)(x)) - ((double)(val_6))))) + 42 - ((short)((((int)(val_6)) >> ((int)(42))))) * ((short)((((int)(((short)((((double)(x)) - ((double)(val_6))))))) ^ ((int)(x))))) * ((int)((((int)(val_6)) >> ((int)(val_6))))) * ((long)((((int)(val_6 + 42)) << ((int)(val_6))))))) ^ ((int)(val_6 + 42 + ((short)((((double)(x)) - ((double)(val_6))))) + 42 - ((short)((((int)(val_6)) >> ((int)(42))))) * ((short)((((int)(((short)((((double)(x)) - ((double)(val_6))))))) ^ ((int)(x))))) * ((int)((((int)(val_6)) >> ((int)(val_6))))) * ((long)((((int)(val_6 + 42)) << ((int)(val_6)))))))))) * ((int)((((int)(val_6 + 42 + ((short)((((double)(x)) - ((double)(val_6))))) + 42 - ((short)((((int)(val_6)) >> ((int)(42))))) * ((short)((((int)(((short)((((double)(x)) - ((double)(val_6))))))) ^ ((int)(x))))) * ((int)((((int)(val_6)) >> ((int)(val_6))))) * ((long)((((int)(val_6 + 42)) << ((int)(val_6))))))) % ((int)(x)))));
val_7 + 42 + ((long)((((double)(val_7)) * ((double)(val_7))))) * ((short)((((double)(val_7)) + ((double)(y))))) + 42 - ((int)((((int)(((long)((((double)(val_7)) * ((double)(val_7))))))) % ((int)(val_7)))));
  
;d = val_5 + 42 - ((short)((((double)(d)) + ((double)(val_5))))) + ((short)((((double)(d)) + ((double)(val_5))))) * ((int)((((double)(val_5)) + ((double)(d))))) * ((long)((((int)(d)) & ((int)(d))))) + 42 - ((int)((((int)(val_5 + 42 - ((short)((((double)(d)) + ((double)(val_5))))) + ((short)((((double)(d)) + ((double)(val_5))))) * ((int)((((double)(val_5)) + ((double)(d))))) * ((long)((((int)(d)) & ((int)(d))))))) ^ ((int)(d))))) - ((short)((((int)(val_5 + 42 - ((short)((((double)(d)) + ((double)(val_5))))) + ((short)((((double)(d)) + ((double)(val_5))))) * ((int)((((double)(val_5)) + ((double)(d))))) * ((long)((((int)(d)) & ((int)(d))))))) & ((int)(d))))) * ((long)((((int)(d)) << ((int)(val_5 + 42 - ((short)((((double)(d)) + ((double)(val_5))))) + ((short)((((double)(d)) + ((double)(val_5))))) * ((int)((((double)(val_5)) + ((double)(d))))) * ((long)((((int)(d)) & ((int)(d)))))))))) * ((int)((((int)(d)) % ((int)(d))))) + ((long)((((int)(val_5 + 42 - ((short)((((double)(d)) + ((double)(val_5))))) + ((short)((((double)(d)) + ((double)(val_5))))) * ((int)((((double)(val_5)) + ((double)(d))))) * ((long)((((int)(d)) & ((int)(d))))))) ^ ((int)(val_5 + 42 - ((short)((((double)(d)) + ((double)(val_5))))) + ((short)((((double)(d)) + ((double)(val_5))))) * ((int)((((double)(val_5)) + ((double)(d))))) * ((long)((((int)(d)) & ((int)(d))))))))));
x = val_6 + 42 + ((short)((((double)(x)) - ((double)(val_6))))) + 42 - ((short)((((int)(val_6)) >> ((int)(42))))) * ((short)((((int)(((short)((((double)(x)) - ((double)(val_6))))))) ^ ((int)(x))))) * ((int)((((int)(val_6)) >> ((int)(val_6))))) * ((long)((((int)(val_6 + 42)) << ((int)(val_6))))) + 42 - ((short)((((int)(val_6 + 42 + ((short)((((double)(x)) - ((double)(val_6))))) + 42 - ((short)((((int)(val_6)) >> ((int)(42))))) * ((short)((((int)(((short)((((double)(x)) - ((double)(val_6))))))) ^ ((int)(x))))) * ((int)((((int)(val_6)) >> ((int)(val_6))))) * ((long)((((int)(val_6 + 42)) << ((int)(val_6))))))) ^ ((int)(val_6 + 42 + ((short)((((double)(x)) - ((double)(val_6))))) + 42 - ((short)((((int)(val_6)) >> ((int)(42))))) * ((short)((((int)(((short)((((double)(x)) - ((double)(val_6))))))) ^ ((int)(x))))) * ((int)((((int)(val_6)) >> ((int)(val_6))))) * ((long)((((int)(val_6 + 42)) << ((int)(val_6)))))))))) * ((int)((((int)(val_6 + 42 + ((short)((((double)(x)) - ((double)(val_6))))) + 42 - ((short)((((int)(val_6)) >> ((int)(42))))) * ((short)((((int)(((short)((((double)(x)) - ((double)(val_6))))))) ^ ((int)(x))))) * ((int)((((int)(val_6)) >> ((int)(val_6))))) * ((long)((((int)(val_6 + 42)) << ((int)(val_6))))))) % ((int)(x)))));
  
;b = val_4 + 42 - ((short)((((double)(val_4)) * ((double)(b))))) * ((long)((((int)(b)) ^ ((int)(val_4)))));
d = val_5 + 42 - ((short)((((double)(d)) + ((double)(val_5))))) + ((short)((((double)(d)) + ((double)(val_5))))) * ((int)((((double)(val_5)) + ((double)(d))))) * ((long)((((int)(d)) & ((int)(d)))));
  
;e = val_3 + 42 - ((int)((((double)(e)) + ((double)(e))))) - ((int)((((double)(e)) + ((double)(e))))) * ((short)((((int)(val_3)) << ((int)(val_3)))));
b = val_4 + 42 - ((short)((((double)(val_4)) * ((double)(b))))) * ((long)((((int)(b)) ^ ((int)(val_4)))));
  e = val_3 + 42 - ((int)((((double)(e)) + ((double)(e))))) - ((int)((((double)(e)) + ((double)(e))))) * ((short)((((int)(val_3)) << ((int)(val_3)))));
  val_2 + 42 * ((short)((((int)(c)) & ((int)(c))))) - ((long)((((double)(c)) - ((double)(c))))) * ((int)((((double)(val_2)) - ((double)(val_2))))) * ((int)((((int)(c)) << ((int)(c))))) + 42 + ((long)((((int)(val_2 + 42 * ((short)((((int)(c)) & ((int)(c))))) - ((long)((((double)(c)) - ((double)(c))))) * ((int)((((double)(val_2)) - ((double)(val_2))))) * ((int)((((int)(c)) << ((int)(c))))))) ^ ((int)(c))))) - ((int)((((int)(c)) & ((int)(c))))) + ((short)((((int)(c)) << ((int)(val_2 + 42 * ((short)((((int)(c)) & ((int)(c))))) - ((long)((((double)(c)) - ((double)(c))))) * ((int)((((double)(val_2)) - ((double)(val_2))))) * ((int)((((int)(c)) << ((int)(c)))))))))) - ((int)((((int)(c)) % ((int)(c)))));
  val_1 + 42 - ((int)((((double)(val_1)) * ((double)(a)))));
  f() + 42 - ((long)((((double)(f())) * ((double)(z))))) + ((long)((((double)(z)) + ((double)(f()))))) - ((int)((((double)(z)) - ((double)(f())))));

  printf("a = %" PRIi32 "\n", a);
  printf("b = %" PRIi8 "\n", b);
  printf("c = %" PRIi32 "\n", c);
  printf("d = %" PRIi16 "\n", d);
  printf("x = %" PRIi32 "\n", x);
  printf("e = %" PRIi32 "\n", e);
  printf("z = %" PRIi64 "\n", z);
  printf("y = %" PRIi64 "\n", y);

  return 0;
}
