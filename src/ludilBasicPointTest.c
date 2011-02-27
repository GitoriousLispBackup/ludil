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
#include <ludilPoint.h>
#include <ludilTest.h>

/* variables */

DEFTEST(printTest, "testing if ludilPointString works")
BEGIN
  ludilPoint_t  v_point;
  ludilString_t *v_stringPtr = ludilPointString (&v_point, NULL);

  ASSERTM ("null test", v_stringPtr);
  ludilIoPrintString (NULL, v_stringPtr);

  ludilFree ((ludilPtr_t *)&v_stringPtr);
END

/* test order */
BEGIN_TESTS
  TESTC(printTest);
END_TESTS
