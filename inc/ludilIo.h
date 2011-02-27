/* ------------------------------------------------------------ */
/*
 *   Ludil - Scheme/C game programming framework
 *   Copyright (C) 2010,2011 Josef P. Bernhart <bernhartjp@yahoo.de>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/* ------------------------------------------------------------ */

#ifndef LUDIL_IO_H
#define LUDIL_IO_H

#include <stdio.h>
#include <ludilTypes.h>

/* ------------------------------------------------------------ */
/** @file ludilIo.h
 *  @author Josef P. Bernhart 
 *  @date 27-12-2010
 *  @ingroup base 
 *
 *  Contains all the definitions related to Io operations
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief io port 
 *
 *  Is an abstract file descriptor, which means, that
 *  the end point of a reading or writing operation can be a 
 *  file, a buffer in memory, a stream or a pipe
 */
/* ------------------------------------------------------------ */
typedef FILE ludilPort_t;

/* ------------------------------------------------------------ */
/** @brief prints string to port 
 *
 * Prints the given string to the given port
 *
 * @param p_portPtr        @b [In] The port to which the string 
 *                                 should be printed. A value of
 *                                 NULL means the default 
 *                                 output port
 * @param p_string         @b [In] String, which should be printed
 */
/* ------------------------------------------------------------ */
void
ludilIoPrintString (ludilPort_t     *p_portPtr,
                    ludilString_t   *p_string);
/* ------------------------------------------------------------ */

#endif
