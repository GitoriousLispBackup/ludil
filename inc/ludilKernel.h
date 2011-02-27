/* ------------------------------------------------------------ */
/*
 *   Ludil - Scheme/C game programming framework
 *   Copyright (C) 2010,2011 Josef P. Bernhart <bernhartjp@yahoo.de>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/* ------------------------------------------------------------ */

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

typedef void (*ludilPluginHandlerCB_t)(ludilPtr_t);
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

  ludilPluginHandlerCB_t  initCB;
  ludilPluginHandlerCB_t  startCB;
  ludilPluginHandlerCB_t  stopCB;
  ludilPluginHandlerCB_t  stepCB;
  ludilPluginHandlerCB_t  freeCB;
  
} ludilPlugin_t;

typedef enum 
{
  PLUGIN,
  MAIN,
  MESSAGE
} ludilKernelThreadType_t;

typedef struct 
{
  pthread_t                     thread;      /**< internal thread */
  ludilId_t                     id;          /**< id of thread */
  char                          name [256];  /**< name of thread */
  ludilKernelThreadType_t       type;        /**< type of thread */
  ludilBlob_t                  *input;       /**< input buffer of thread */
  ludilBlob_t                  *output;      /**< output buffer of thread */
  ludilBlob_t                  *heap;        /**< thread heap */

} ludilKernelThread_t;

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

  pthread_t          mainThread;     /**< the kernel main loop */

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
 *  @param    p_evn          [In] environment 
 *  @param    p_pluginName   [In] name of plugin to load, without
 *                                the library prefixes and suffixes
 *                                eg. just 'Lisp' and not libludilPluginLisp.so
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
 *   @param   p_env      [In] environment
 *   @param   p_string   [In] C null terminated string, which should be saved in system 
 */
/* ------------------------------------------------------------ */
ludilString_t *
ludilKernelAddCString (ludilEnv_t      *p_env,
                       const char      *p_string);
/* ------------------------------------------------------------ */


#endif
