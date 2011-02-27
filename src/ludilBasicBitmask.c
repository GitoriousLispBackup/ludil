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


#include <ludilBitmask.h>


/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask8Get (ludilUInt8_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  if ((sizeof (p_bitmask)*8) > p_offset)
  {
    if ((1 << (p_offset)) & p_bitmask)
      return TRUE;
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask16Get (ludilUInt16_t  p_bitmask,
                   ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  if ((sizeof (p_bitmask)*8) > p_offset)
  {
    if ((1 << (p_offset)) & p_bitmask)
      return TRUE;
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask32Get (ludilUInt32_t  p_bitmask,
                   ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  if ((sizeof (p_bitmask)*8) > p_offset)
  {
    if ((1 << (p_offset)) & p_bitmask)
      return TRUE;
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask64Get (ludilUInt64_t  p_bitmask,
                   ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{

  if ((sizeof (p_bitmask)*8) > p_offset)
  {
    if ((1 << (p_offset)) & p_bitmask)
      return TRUE;
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilUInt8_t
ludilBitmask8Set (ludilUInt8_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  ludilUInt8_t  v_mask = p_bitmask;

  if ((sizeof (p_bitmask)*8) > p_offset)
    v_mask = ((1 << p_offset) | p_bitmask);

  return v_mask;
}

/* ------------------------------------------------------------ */
ludilUInt16_t
ludilBitmask16Set (ludilUInt16_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  ludilUInt16_t  v_mask = p_bitmask;

  if ((sizeof (p_bitmask)*8) > p_offset)
    v_mask = ((1 << p_offset) | p_bitmask);

  return v_mask;
}

/* ------------------------------------------------------------ */
ludilUInt32_t
ludilBitmask32Set (ludilUInt32_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  ludilUInt32_t  v_mask = p_bitmask;

  if ((sizeof (p_bitmask)*8) > p_offset)
    v_mask = ((1 << p_offset) | p_bitmask);

  return v_mask;
}

/* ------------------------------------------------------------ */
ludilUInt64_t
ludilBitmask64Set (ludilUInt64_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  ludilUInt64_t  v_mask = p_bitmask;

  if ((sizeof (p_bitmask)*8) > p_offset)
    v_mask = ((1 << p_offset) | p_bitmask);

  return v_mask;
}
