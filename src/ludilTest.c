#include <ludilTest.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ludilTypes.h>

/* ------------------------------------------------------------ */
static const char g_failure [] = "\x1b[31mFAILURE\x1b[m";
static const char g_success [] = "\x1b[32mSUCCESS\x1b[m";
static const char g_assert [] = "[ASSERT]";
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
ludilBool_t
ludilTestPrintAssert (ludilTestEnv_t *p_envPtr,
                      const char     *p_text, 
                      const char     *p_assertStr,
                      ludilBool_t     p_result)
/* ------------------------------------------------------------ */
{
  printf ("%s %s (%s) ............... %s\n", 
          g_assert,
          p_text, 
          p_assertStr,
          (IS_TRUE(p_result)) ? (g_success) : (g_failure));

  return p_result;
}

