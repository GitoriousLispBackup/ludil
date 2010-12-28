#include <ludilBitmask.h>
#include <ludilTest.h>

DEFTEST(bitMask8, "testing if 8 bitmask works")
BEGIN
  ludilUInt8_t v_mask = 0;
  int           v_i;

  for (v_i = 0; v_i < 8; v_i++)
  {
    v_mask = ludilBitmask8Set (v_mask, v_i);
    ASSERTM ("testing bit", (ludilBitmask8Get (v_mask, v_i)));
  }
  SUCCESS;
END

DEFTEST(bitMask16, "testing if 16 bitmask works")
BEGIN
  ludilUInt16_t v_mask = 0;
  int           v_i;

  for (v_i = 0; v_i < 16; v_i++)
  {
    v_mask = ludilBitmask16Set (v_mask, v_i);
    ASSERTM ("testing bit", (ludilBitmask16Get (v_mask, v_i)));
  }
  SUCCESS;
END

DEFTEST(bitMask32, "testing if 32 bitmask works")
BEGIN
  ludilUInt32_t v_mask = 0;
  int           v_i;

  for (v_i = 0; v_i < 32; v_i++)
  {
    v_mask = ludilBitmask32Set (v_mask, v_i);
    ASSERTM ("testing bit", (ludilBitmask32Get (v_mask, v_i)));
  }
  SUCCESS;
END

DEFTEST(bitMask64, "testing if 64 bitmask works")
BEGIN
  ludilUInt64_t v_mask = 0;
  int           v_i;

  for (v_i = 0; v_i < 64; v_i++)
  {
    v_mask = ludilBitmask64Set (v_mask, v_i);
    ASSERTM ("testing bit", (ludilBitmask64Get (v_mask, v_i)));
  }
  SUCCESS;
END


/* test order */
BEGIN_TESTS
  TESTM(bitMask8);
  TESTM(bitMask16);
  TESTM(bitMask32);
  TESTM(bitMask64);
END_TESTS
