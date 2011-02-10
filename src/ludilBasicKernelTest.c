#include <ludilKernel.h>
#include <stdio.h>

int 
main ()
{
  ludilEnv_t     *v_env    = NULL;
  ludilPlugin_t  *v_plugin = NULL;

  ludilKernelInit (&v_env);

  v_plugin = ludilKernelPluginLoad (v_env, "Test");
  printf ("v_plugin : %d\n", v_plugin);

  ludilKernelStart (v_env);
  ludilKernelStop (v_env);

  ludilKernelFree (&v_env);

  return 0;
}
