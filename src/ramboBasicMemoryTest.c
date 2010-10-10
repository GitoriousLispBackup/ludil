#include <ramboTypes.h>
#include <ramboMemory.h>
#include <ramboTest.h>

/* variables */
static ramboPtrSize_t v_dataPtr = NULL;
static ramboSize_t v_i = 0;
static ramboSize_t v_dataSize = 100;

DEFTEST(initTest, "inittest")
BEGIN
  for (v_i = 0; v_i < v_dataSize; v_i++)
  {
    if (v_dataPtr [v_i] != 0)
    { 
      ramboFree ((ramboPtr_t *)&v_dataPtr);
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
    ramboFree ((ramboPtr_t *)&v_dataPtr);
    FAIL;
   }
  }
  SUCCESS;
END

DEFTEST(freeTest, "testing if ramboFree works")
BEGIN
  /* test free */
  ramboFree ((ramboPtr_t *)&v_dataPtr);
  if (v_dataPtr != NULL)
    FAIL;
  SUCCESS;
END

DEFTEST(allocTest, "testing if ramboAlloc returns")
BEGIN
  v_dataPtr = ramboAlloc (v_dataSize*sizeof(ramboSize_t));
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
