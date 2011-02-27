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

#ifndef LUDIL_MEMORY_H
#define LUDIL_MEMORY_H

#include <stdlib.h>
#include <ludilTypes.h>


/* ------------------------------------------------------------ */
/** ludilAlloc
 * 
 * Allocates an amount of bytes and returns the pointer to it
 *
 * @param p_size      @b [In] size of data, which should be allocated
 *
 * @return
 *  pointer to allocated data structure
 */
/* ------------------------------------------------------------ */
ludilPtr_t 
ludilAlloc (ludilSize_t p_size); 
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilFree
 *
 * Frees a given data structure
 * 
 * @param p_dataPtr       @b [In] pointer to a pointer to the
 *                                allocated data structure
 * @return
 * nothing
 */
/* ------------------------------------------------------------ */
void 
ludilFree (ludilPtr_t *p_dataPtr);
/* ------------------------------------------------------------ */
#endif
