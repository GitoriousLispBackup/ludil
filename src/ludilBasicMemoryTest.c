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
  v_dataPtr = ludilAlloc (v_dataSize*sizeof(ludilSize_t));
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
