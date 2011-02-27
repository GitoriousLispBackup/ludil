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

#include <ludilString.h>
#include <ludilMemory.h>
#include <string.h>

/* ------------------------------------------------------------ */
ludilString_t *
ludilStringAlloc (ludilSize_t p_length)
/* ------------------------------------------------------------ */
{
  ludilString_t  *v_stringPtr = NULL;
  ludilSize_t     v_size = sizeof (ludilString_t) + p_length;

  if (p_length > 0)
  {
    v_stringPtr = (ludilString_t *)ludilAlloc (v_size);
    
    if (v_stringPtr)
    {
      v_stringPtr->size = v_size;
      v_stringPtr->length = p_length;
    }
  }
  return v_stringPtr;
}

/* ------------------------------------------------------------ */
ludilString_t *
ludilStringNew (const char *p_string)
/* ------------------------------------------------------------ */
{
  ludilSize_t     v_length;
  ludilString_t  *v_stringPtr = NULL;

  if (p_string)
  {
    v_length = strlen (p_string);
    v_stringPtr = ludilStringAlloc (v_length);

    memcpy (&v_stringPtr->data, p_string, v_length);

  }
  return v_stringPtr;
}
