#ifndef LUDIL_TEST_H
#define LUDIL_TEST_H

#include <stdio.h>
#include <unistd.h>
#include <ludilTypes.h>

/* types */
typedef struct 
{
  char name [128]; /**< name of test environment ( tool, program, library, etc.  ) */
  int  print;      /**< print mode */
}
ludilTestEnv_t;


/* ------------------------------------------------------------ */
/** @brief creates a test environment
 *
 */
/* ------------------------------------------------------------ */
ludilTestEnv_t *
ludilTestInit (ludilTestEnv_t *p_envPtr, 
               int p_argc, 
               char **p_argv);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief prints assert line
 *
 *  Prints the line of an assertion
 *  This is an internal function
 */
/* ------------------------------------------------------------ */
ludilBool_t
ludilTestPrintAssert (ludilTestEnv_t *p_envPtr,
                      const char     *p_text, 
                      const char     *p_assert,
                      ludilBool_t     p_result);
/* ------------------------------------------------------------ */


/* macros */

#ifdef ASSERT
 #undef ASSERT
#endif

#ifdef DEFTEST
 #undef DEFTEST
#endif

#ifdef BEGIN
 #undef BEGIN
#endif

#ifdef END
 #undef END
#endif

#ifdef BEGIN_TESTS
 #undef BEGIN_TESTS
#endif

#ifdef END_TESTS
 #undef END_TESTS
#endif

#ifdef TESTC
 #undef TESTC
#endif 

#ifdef TESTM
 #undef TESTM
#endif 

#ifdef FAIL
 #undef FAIL
#endif 

#ifdef SUCCESS
 #undef SUCCESS
#endif 

/* ------------------------------------------------------------ */
/** @brief defines a test 
 *
 *  'DEFTEST' defines a test, which can later be runned by
 *  using TESTM or TESTC
 *  
 *  @param name       @b [In] name of the test ( a symbol )
 *  @param what       @b [In] what a text, which describes 
 *                            what the test does
 *  This runs a test which can fail
 */ 
/* ------------------------------------------------------------ */
#define DEFTEST(name, what) \
  static const char g_ludilTest_ ## name[] = #name ; \
  static const char g_ludilTest_ ## name ## _what [] = #what ; \
  static int name (void) 

/* ------------------------------------------------------------ */
/** @brief start of body of test definition 
 *
 *  Starts the body of a test definition
 */
/* ------------------------------------------------------------ */
#define BEGIN {

/* ------------------------------------------------------------ */
/** @brief end of body of test definition 
 *
 *  Ends the body of a test definition
 */
/* ------------------------------------------------------------ */
#define END }


/* ------------------------------------------------------------ */
/** @brief ends a test, with result failure 
 *  
 *  This ends a test with a failure
 */ 
/* ------------------------------------------------------------ */
#define FAIL return 0

/* ------------------------------------------------------------ */
/** @brief ends a test, with result success
 *  
 *  This ends a test with success
 */ 
/* ------------------------------------------------------------ */
#define SUCCESS return 1

/* ------------------------------------------------------------ */
/** @brief runs a test, can fail 
 *  
 *  This runs a test which can fail
 */ 
/* ------------------------------------------------------------ */
#define TESTC(name) \
  printf ("[TEST] %s START\n",  g_ludilTest_ ## name ## _what); \
  if (name()) { \
  if (v_ludilTest_print) \
  printf("[TEST] %s END ...............SUCCESS\n", g_ludilTest_ ## name ## _what); \
  v_ludilTest_result = 0; } else { \
  if (v_ludilTest_print) \
  printf("[TEST] %s END ...............FAILED\n", g_ludilTest_ ## name ## _what); \
  v_ludilTest_result = 1; }

/* ------------------------------------------------------------ */
/** @brief runs test, must not fail
 *
 *  This runs a test, which must not fail, if it does
 *  the whole unit test was a failure
 */
/* ------------------------------------------------------------ */
#define TESTM(name) \
  printf ("[TEST] %s START\n",  g_ludilTest_ ## name ## _what); \
  if (name()) { \
  if (v_ludilTest_print) \
  printf("[TEST] %s END ...............SUCCESS\n", g_ludilTest_ ## name ## _what); \
  v_ludilTest_result = 0; } else { \
  if (v_ludilTest_print) \
  printf("[TEST] %s END ...............FAILED\n", g_ludilTest_ ## name ## _what); \
  return 1; }

/* ------------------------------------------------------------ */
/** @brief assert, can fail 
 *
 *  This assertion only checks something and shows what failed
 *  or succeeded, but it doesn't cause the surrounding test to 
 *  fail.
 */
/* ------------------------------------------------------------ */
#define ASSERTC(name, assert) \
  ludilTestPrintAssert (NULL, \
                        name,  \
                        #assert, \
                        (assert) ? TRUE : FALSE)

/* ------------------------------------------------------------ */
/** @brief assert, must not fail 
 *  
 *  This assert guarentees, that an assertion was successful, if
 *  not the surrounding test fails. The 'M' in its name 
 *  means 'must not fail'
 */
/* ------------------------------------------------------------ */
#define ASSERTM(name, assert) \
  if (IS_FALSE(ASSERTC(name, assert))) \
    FAIL;

/* ------------------------------------------------------------ */
/** @brief begins a tests block
 *  
 *  A test block is a block of tests, it shows in which order
 *  tests should be evaluated, as for example a dynamic 
 *  allocated data structure can't be tested, before it wasn't
 *  ensured that the allocation worked.
 *
 *  Only one such block can be defined within one source file
 */
/* ------------------------------------------------------------ */
#define BEGIN_TESTS int main(int argc, char **argv) { \
  int       v_ludilTest_result = 0; \
  int       v_ludilTest_print = 1;  \
  int       v_ludilTest_option = 0;  \
    while ((v_ludilTest_option = getopt (argc, argv, "qh")) != -1) \
    { \
      switch (v_ludilTest_option) \
      {  \
        case 'h': \
          printf ("help of unit test %s:\n", argv[0]); \
          puts ("-h\tprints this help"); \
          puts ("-q\tdisables output, useful for batch processing"); \
        return 0; \
\
        case 'q': \
          v_ludilTest_print = 0; \
        break; \
      } \
    } \

/* ------------------------------------------------------------ */
/** @brief ends a tests block
 */
/* ------------------------------------------------------------ */
#define END_TESTS return v_ludilTest_result; }

#endif
