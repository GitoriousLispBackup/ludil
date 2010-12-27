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
