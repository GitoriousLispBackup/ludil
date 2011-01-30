#ifndef LUDIL_KERNEL_H
#define LUDIL_KERNEL_H

#include <ludilTypes.h>

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
  ludilBlob_t       *pluginList; /**< list of associated plugins */
  ludilBool_t        started;    /**< true if env was started */
  ludilBlob_t       *heap;       /**< heap, where data objects are stored */
  ludilString_t     *infoString; /**< returns the info string */
} ludilEnv_t;

/* ------------------------------------------------------------ */
/**
 * 
 */
/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelInit (ludilEnv_t      **p_env);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/**
 * 
 */
/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelFree (ludilEnv_t      **p_env);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/**
 * 
 */
/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelStart (ludilEnv_t       *p_env);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/**
 *   
 */
/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelStop (ludilEnv_t       *p_env);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/**
 * 
 */
/* ------------------------------------------------------------ */
ludilPlugin_t *
ludilKernelPluginLoad (ludilEnv_t       *p_env,
                       const char       *p_pluginName);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/**
 * 
 */
/* ------------------------------------------------------------ */
ludilBool_t
ludilKernelPluginsClose (ludilEnv_t       *p_env);
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
