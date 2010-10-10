#include <ramboTest.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static void 
ramboTestPrintHelp (ramboTestEnv_t *p_env)
{
  printf ("-h\tprints this help\n");
  printf ("-q\tturns on quiet mode, no output\n");
}

void 
ramboTestStart (ramboTestEnv_t *p_env)
{
  while ((v_ramboTest_option = getopt (argc, argv, "qh")) != -1)
  {
    switch (v_ramboTest_option)
    {
      case 'h': 
      ramboTestPrintHelp (p_env);
      break;

      case 'q':\
      p_env->print = 0;
      break; 
    }
  }
}
