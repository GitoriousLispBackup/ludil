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
#include <ludilTest.h>

/* variables */
static ludilPtrSize_t v_dataPtr = NULL;
static ludilSize_t v_i = 0;
static ludilSize_t v_dataSize = 100;

DEFTEST(initTest, "inittest")
BEGIN
  for (v_i = 0; v_i < v_dataSize; v_i++)
  {
    if (v_dataPtr [v_i] != 0)
    { 
      ludilFree ((ludilPtr_t *)&v_dataPtr);
      FAIL;
    }
  }
  SUCCESS;
END

DEFTEST(fillTest, "testing the array")
BEGIN
  /* fill array */
  for (v_i = 0; v_i < v_dataSize; v_i++)
    v_dataPtr [v_i] = v_i;

  /* test the written data */
  for (v_i = 0; v_i < v_dataSize; v_i++)
  {
   if (v_dataPtr [v_i] != v_i)
   {
    ludilFree ((ludilPtr_t *)&v_dataPtr);
    FAIL;
   }
  }
  SUCCESS;
END

DEFTEST(freeTest, "testing if ludilFree works")
BEGIN
  /* test free */
  ludilFree ((ludilPtr_t *)&v_dataPtr);
  if (v_dataPtr != NULL)
    FAIL;
  SUCCESS;
END

DEFTEST(allocTest, "testing if ludilAlloc returns")
BEGIN
  v_dataPtr = (ludilPtrSize_t)ludilAlloc (v_dataSize*sizeof(ludilSize_t));
  if (!v_dataPtr)
    FAIL;
  SUCCESS;
END

/* test order */
BEGIN_TESTS
  TESTM(allocTest);
  TESTC(initTest);
  TESTC(fillTest);
END_TESTS
