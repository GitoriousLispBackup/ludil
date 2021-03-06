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

#include <ludilMemory.h>
#include <ludilTypes.h>
#include <stdlib.h>
#include <string.h>

/* macros */
#define LUDIL_FREE(ptr_ptr) if (*ptr_ptr) { free((void *)*ptr_ptr); *ptr_ptr = NULL; }
#define LUDIL_ALLOC(var,size) var = (typeof (var))malloc(size);

/* ------------------------------------------------------------ */
ludilPtr_t 
ludilAlloc (ludilSize_t p_size)
/* ------------------------------------------------------------ */
{
  ludilPtr_t v_dataPtr = NULL;

  LUDIL_ALLOC (v_dataPtr, p_size);

  if (v_dataPtr)
  {
    memset (v_dataPtr, 0, p_size);
    return v_dataPtr;
  }
  return LUDIL_PTR_NULL;
}

/* ------------------------------------------------------------ */
void 
ludilFree (ludilPtr_t *p_dataPtr)
/* ------------------------------------------------------------ */
{
  if (p_dataPtr)
  {
    LUDIL_FREE (p_dataPtr);
  }
}
