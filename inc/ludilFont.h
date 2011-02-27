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

#ifndef LUDIL_FONT_H
#define LUDIL_FONT_H

#include <ludilTypes.h>
#include <ludilString.h>

/* ------------------------------------------------------------ */
/**
 *
 */
/* ------------------------------------------------------------ */
typedef enum
{
  BOLD,
  ITALIC,
  UNDERLINE,
  STRIKETHROUGH
} ludilFontStyle_t;


/* ------------------------------------------------------------ */
/**
 *
 */
/* ------------------------------------------------------------ */
typedef struct 
{
  ludilFontStyle_t  style; /**< the style of the font */

} ludilFont_t;

/* ------------------------------------------------------------ */
/**
 *  Opens a font
 *
 *  @param p_fontPtr        @b [In] pointer to font structure
 *  @param p_path           @b [In] path to a font file
 */
/* ------------------------------------------------------------ */
ludilFont_t *
ludilFontOpen (ludilFont_t *p_fontPtr, 
               ludilPath_t  p_path);
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/**
 *  Closes a font
 *
 *  @param p_fontPtr        @b [In] pointer to font structure
 */
/* ------------------------------------------------------------ */
void
ludilFontClose (ludilFont_t *p_fontPtr);
/* ------------------------------------------------------------ */

#endif
