#include <ludilTest.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static void 
ludilTestPrintHelp (ludilTestEnv_t *p_env)
{
  printf ("-h\tprints this help\n");
  printf ("-q\tturns on quiet mode, no output\n");
}

void 
ludilTestStart (ludilTestEnv_t *p_env)
{
  while ((v_ludilTest_option = getopt (argc, argv, "qh")) != -1)
  {
    switch (v_ludilTest_option)
    {
      case 'h': 
      ludilTestPrintHelp (p_env);
      break;

      case 'q':\
      p_env->print = 0;
      break; 
    }
  }
}
