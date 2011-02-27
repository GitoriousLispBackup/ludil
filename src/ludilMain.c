#include <ludilTypes.h>
#include <ludilKernel.h>

/* ------------------------------------------------------------ */
int 
main (int p_argc, char **p_argv)
/* ------------------------------------------------------------ */
{
  ludilEnv_t  *v_env;

  ludilKernelInit (&v_env);
  ludilKernelFree (&v_env);

  return 0;
}
