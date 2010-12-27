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
