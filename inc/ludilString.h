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

#ifndef LUDIL_STRING_H
#define LUDIL_STRING_H

#include <ludilTypes.h>

/* ------------------------------------------------------------ */
/** @file ludilTypes.h
 *  @author Josef P. Bernhart 
 *
 *  Is a the main types definitions file, will be modularized
 *  in later releases
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilStringAlloc
 *
 * Allocates a string of the given length in characters
 *
 * @param p_length           @b [In] length of allocated string
 *
 * @return
 * allocated string
 */
/* ------------------------------------------------------------ */
ludilString_t *
ludilStringAlloc (ludilSize_t p_length);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilStringNew
 *
 * Creates a new ludil string from a given constant c string
 *
 * @param p_string           @b [In] c string, from which 
 *                                   a ludil version is generated
 *
 * @return
 * pointer to allocated string
 */
/* ------------------------------------------------------------ */
ludilString_t *
ludilStringNew (const char *p_string);
/* ------------------------------------------------------------ */


#endif
