#ifndef RAMBO_TEST_H
#define RAMBO_TEST_H

#include <stdio.h>
#include <unistd.h>

/* types */
typedef struct 
{
  char name [128]; /* name of test environment ( tool, program, library, etc.  ) */
  int  print;      /* print mode */
}
ramboTestEnv_t;

/* prototypes */
void ramboTestStart (ramboTestEnv_t *p_env);

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
  static const char g_ramboTest_ ## name[] = #name ; \
  static const char g_ramboTest_ ## name ## _what [] = #what ; \
  static int name (void) 
#define BEGIN {
#define END }

#define FAIL return 0
#define SUCCESS return 1

/* this test can fail, it means, that the other tests after this one are executed, even when this one fails */ 
#define TESTC(name) \
  if (v_ramboTest_print) \
  printf("[TEST] %s ...............", g_ramboTest_ ## name ## _what); \
  if (name()) { \
  if (v_ramboTest_print) \
  puts ("SUCCESS"); v_ramboTest_result = 0; } else { \
  if (v_ramboTest_print) \
  puts("FAILED");  v_ramboTest_result = 1; }

/* this test must no fail, it means that the other tests after this one aren't executed when this test fails */
#define TESTM(name) \
  if (v_ramboTest_print) \
  printf("[TEST] %s ...............", g_ramboTest_ ## name ## _what); \
  if (name()) { \
  if (v_ramboTest_print) \
  puts ("SUCCESS"); \
  v_ramboTest_result = 0; } else { \
  if (v_ramboTest_print) \
  puts("FAILED"); return 1; }

/* asserts are small one line tests */
#define ASSERT(name, assert) \
  if (assert) { if() \
                  puts ("[ASSERT] " name "(" #assert ") ............... SUCCESS"); } \
  else {  if () \
          puts ("[ASSERT] " name "(" #assert ") ............... FAILED"); return 1; }

#define BEGIN_TESTS int main(int argc, char **argv) { \
  int v_ramboTest_result = 0; \
  int v_ramboTest_print = 1; \
  int v_ramboTest_option = 0; \
  while ((v_ramboTest_option = getopt (argc, argv, "qh")) != -1) {\
  switch (v_ramboTest_option) {\
    case 'h': \
    printf ("help of unit test %s:\n", argv[0]); \
    puts ("-h\tprints this help"); \
    puts ("-q\tdisables output, useful for batch processing"); \
    return 0; \
    case 'q': \
    v_ramboTest_print = 0;\
    break; \
    } \
  }

#define END_TESTS return v_ramboTest_result; }

#endif
