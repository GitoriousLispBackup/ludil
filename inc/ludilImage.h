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

#ifndef LUDIL_IMAGE_H
#define LUDIL_IMAGE_H

#include <ludilTypes.h>

/* is a ludil object */
typedef struct
{
  ludilSize_t   width;
  ludilSize_t   height;
  ludilSize_t   pixelSize;  

  ludilData_t   data;
} ludilImage_t;

/* function */
ludilImage_t * ludilImageFromFile (ludilPath_t p_path);


#endif
