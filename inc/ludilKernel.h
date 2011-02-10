#ifndef LUDIL_KERNEL_H
#define LUDIL_KERNEL_H

#include <ludilTypes.h>
#include <pthread.h>

/* ------------------------------------------------------------ */
/** @file ludilKernel.h
 *  @author Josef P. Bernhart 
 *  @date 30-01-2011
 *  @ingroup base
 *
 *  Contains the kernel of ludil, which holds the basic functionality
 *  of the system and is considered as a management unit.
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief plugin handle
 * 
 *  This type represents a loaded plugin, it can be later used
 *  to call procedures
 */
/* ------------------------------------------------------------ */
typedef struct 
{
  char            *name;      /**< name of the plugin */
  ludilBlob_t      externCtx; /**< extern context, for the loaded plugin */
  ludilBool_t      started;   /**< is true, if plugin was started */
} ludilPlugin_t;

/* ------------------------------------------------------------ */
/** @brief ludil toplevel environment
 * 
 *  This structure is used to handle all of ludil's associated data,
 *  processes libraries, plugins, ressources and so on. 
 */
/* ------------------------------------------------------------ */
typedef struct
{
  ludilBlob_t       *pluginList;     /**< list of associated plugins */
  ludilBool_t        started;        /**< true if env was started */
  ludilBlob_t       *heap;           /**< heap, where data objects are stored */
  ludilString_t     *infoString;     /**< returns the info string */
  pthread_t          kernelThread;   /**< kernel thread of main loop */

} ludilEnv_t;

/* ------------------------------------------------------------ */
/** @brief initializes a kernel environment
 *  
 *  This procedure initializes, allocates and sets the correct
 *  behaviour associated with a kernel environment.
 *  It doesn't start the kernel environment.
 */
/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelInit (ludilEnv_t      **p_env);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief frees the kernel environment
 * 
 *  This procedure frees all the ressources associated 
 *  with a kernel environment. If the env was 'running', then
 *  it will be stopped.
 */
/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelFree (ludilEnv_t      **p_env);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief starts a kernel environment
 *  
 *  This procedure starts a kernel environment.
 */
/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelStart (ludilEnv_t       *p_env);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief stops a kernel environment
 *   
 *  Stops a kernel environment, but doesn't free its state and
 *  resources
 */
/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelStop (ludilEnv_t       *p_env);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief loads a plugin
 * 
 *  This procedure loads a ludil plugin
 */
/* ------------------------------------------------------------ */
ludilPlugin_t *
ludilKernelPluginLoad (ludilEnv_t       *p_env,
                       char             *p_pluginName);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/**
 *  Adds a string to the kernel 
 *
 *   @param         [In] environment
 *   @param         [In] C null terminated string, which should be saved in system 
 */
/* ------------------------------------------------------------ */
ludilString_t *
ludilKernelAddCString (ludilEnv_t      *p_env,
                       const char      *p_string);
/* ------------------------------------------------------------ */

#endif
