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

#include <ludilTypes.h>
#include <ludilMemory.h>
#include <ludilIo.h>
#include <ludilString.h>
#include <ludilTest.h>
#include <string.h>

/* variables */
static const char v_string [] = "This is a string";
static ludilSize_t v_length = 0; 
static ludilSize_t v_size = 0;
static ludilString_t *v_stringPtr = NULL;

DEFTEST(newString, "testing if new string works")
BEGIN
  v_stringPtr = ludilStringNew (v_string);
  v_length = strlen (v_string);
  v_size = v_length + sizeof (ludilString_t);

  ASSERTM ("allocation valid", (v_stringPtr))
  ASSERTM( "length valid", (v_stringPtr->length == v_length))
  ASSERTM ("size valid", (v_stringPtr->size == v_size))

  ludilFree ((ludilPtr_t *)&v_stringPtr);
  ASSERTM ("string free", (v_stringPtr == NULL))
  SUCCESS;
END

DEFTEST(printString, "testing if print string works")
BEGIN
  ludilString_t *v_stringPtr = ludilStringNew ("A string");
  ludilIoPrintString (NULL, v_stringPtr);
  ludilFree ((ludilPtr_t *)&v_stringPtr);
  SUCCESS;
END

/* test order */
BEGIN_TESTS
  TESTM(newString);
  TESTC(printString);
END_TESTS
