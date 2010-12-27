#ifndef LUDIL_TEST_H
#define LUDIL_TEST_H

#include <stdio.h>
#include <unistd.h>

/* types */
typedef struct 
{
  char name [128]; /* name of test environment ( tool, program, library, etc.  ) */
  int  print;      /* print mode */
}
ludilTestEnv_t;

/* prototypes */
void ludilTestStart (ludilTestEnv_t *p_env);

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

#define DEFTEST(name, what) \
  static const char g_ludilTest_ ## name[] = #name ; \
  static const char g_ludilTest_ ## name ## _what [] = #what ; \
  static int name (void) 
#define BEGIN {
#define END }

#define FAIL return 0
#define SUCCESS return 1

/* this test can fail, it means, that the other tests after this one are executed, even when this one fails */ 
#define TESTC(name) \
  printf ("[TEST] %s\n",  g_ludilTest_ ## name ## _what); \
  if (name()) { \
  if (v_ludilTest_print) \
  printf("[TEST] %s ...............SUCCESS\n", g_ludilTest_ ## name ## _what); \
  v_ludilTest_result = 0; } else { \
  if (v_ludilTest_print) \
  printf("[TEST] %s ...............FAILED\n", g_ludilTest_ ## name ## _what); \
  v_ludilTest_result = 1; }

/* this test must no fail, it means that the other tests after this one aren't executed when this test fails */
#define TESTM(name) \
  printf ("[TEST] %s\n",  g_ludilTest_ ## name ## _what); \
  if (name()) { \
  if (v_ludilTest_print) \
  printf("[TEST] %s ...............SUCCESS\n", g_ludilTest_ ## name ## _what); \
  v_ludilTest_result = 0; } else { \
  if (v_ludilTest_print) \
  printf("[TEST] %s ...............FAILED\n", g_ludilTest_ ## name ## _what); \
  return 1; }

/* asserts are small one line tests */
#define ASSERTM(name, assert) \
  if (assert) { \
    puts ("[ASSERT] " name "(" #assert ") ............... SUCCESS"); } \
  else { \
    puts ("[ASSERT] " name "(" #assert ") ............... FAILED"); FAIL; }

#define ASSERTC(name, assert) \
  if (assert) { \
    puts ("[ASSERT] " name "(" #assert ") ............... SUCCESS"); } \
  else { \
    puts ("[ASSERT] " name "(" #assert ") ............... FAILED"); }

#define BEGIN_TESTS int main(int argc, char **argv) { \
  int v_ludilTest_result = 0; \
  int v_ludilTest_print = 1; \
  int v_ludilTest_option = 0; \
  while ((v_ludilTest_option = getopt (argc, argv, "qh")) != -1) {\
  switch (v_ludilTest_option) {\
    case 'h': \
    printf ("help of unit test %s:\n", argv[0]); \
    puts ("-h\tprints this help"); \
    puts ("-q\tdisables output, useful for batch processing"); \
    return 0; \
    case 'q': \
    v_ludilTest_print = 0;\
    break; \
    } \
  }

#define END_TESTS return v_ludilTest_result; }

#endif
