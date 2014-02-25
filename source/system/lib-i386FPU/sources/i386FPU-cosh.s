/*!
 *  \file    i386FPU-cosh.s
 *  \brief   cosh assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: cosh assembler function.
#
#   AUTHOR:    J.T. Conklin (jtc@wimsey.com)
#   GROUP:     Winning Strategies, Inc.
#   PROJECT:   The Depth
#   PART:      i386 FPU math library
#   VERSION:   1.0
#   CREATED:   03.01.2006 01:14:28
#
#   EMAIL:     chronoxor@gmail.com
#   WWW:       http://code.google.com/p/depth
#
#   COPYRIGHT: (C) 2006 The NULL workgroup. All Rights Reserved.
#-----------------------------------------------------------------------------
#   Copyright (C) 2006 The NULL workgroup
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#-----------------------------------------------------------------------------
#   FILE ID: $Id$
#
#   CHANGE LOG:
#
#   $Log$
#=============================================================================
# DESCRIPTION:
#   double cosh(double x)
#   These function return the hyperbolic cosine of x, defined mathematically
#   as (exp (x) + exp (-x)) / 2. They may signal overflow if x is too large.
#=============================================================================
.text
.global _i386FPU_cosh
_i386FPU_cosh:
	pushl	%ebp
	movl	%esp,		%ebp
	subl	$16,		%esp

	fldl	8(%ebp)
	fldl2e
	fmulp	%st,		%st(1)
	fst	%st(1)
	fstcw	-4(%ebp)
	fstcw	-8(%ebp)
	fwait
	andw	$0xf3ff,	-4(%ebp)
	fldcw	-4(%ebp)
	frndint
	fldcw	-8(%ebp)
	fst	%st(2)
	fsubrp	%st,		%st(1)
	f2xm1
	fld1
	faddp	%st,		%st(1)
	fscale
	fst	%st(1)

	fld1
	fdivp	%st,		%st(1)
	faddp	%st,		%st(1)

	fldl	LC0

	fmulp	%st,		%st(1)

	# Start of overflow checking: if result is INF or -INF
	fstl	-16(%ebp)
	movl	-16(%ebp),	%eax
	testl	%eax,		%eax
	jnz	L9
	movl	-12(%ebp),	%eax
	andl	$0x7FFFFFFF,	%eax
	cmpl	$0x7FF00000,	%eax
	jne	L9
L9:
	# End of overflow checking
	movl	%ebp,		%esp
	popl	%ebp
	ret

.align	4, 0x90
LC0:
	.double 0.5
#=============================================================================
