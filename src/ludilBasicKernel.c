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

#include <ludilKernel.h>
#include <ludilTypes.h>
#include <ludilBlob.h>

#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>

#define LUDIL_KERNEL_PLUGINS 10
#define LUDIL_KERNEL_HEAP_SIZE 1024
#define LUDIL_KERNEL_EVENTS 256

#define LUDIL_PLUGIN_PREFIX LUDIL_PROJECT_NAME"Plugin"
#define LUDIL_PLUGIN_SUFFIX ""
#define LUDIL_PLUGIN_FILE_PREFIX "lib"LUDIL_PLUGIN_PREFIX
#define LUDIL_PLUGIN_FILE_SUFFIX LUDIL_PLUGIN_SUFFIX".so" 

/* ------------------------------------------------------------ */
typedef enum
{
  INFO
} ludilKernelEvent_t;
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
static ludilBool_t
ludilKernelEvent (ludilKernelEvent_t p_event, const char *p_fmt, ...)
/* ------------------------------------------------------------ */
{
  char          v_buffer [256];
  va_list       v_ap;
  char          v_infoStr [] = "\e[32m[INFO]\e[0m ";

  /* initializing */
  v_buffer [0] = '\0';

  va_start (v_ap, p_fmt);

  if (p_event == INFO)
  {
    vsnprintf (v_buffer, sizeof (v_buffer), p_fmt, v_ap);
    printf ("%s%s\n", v_infoStr, v_buffer);
  }

  va_end (v_ap);

  return TRUE;
}

/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelInit (ludilEnv_t      **p_env)
/* ------------------------------------------------------------ */
{
  ludilPlugin_t     *v_pluginPtr = NULL;

  if (p_env && (*p_env == NULL)) 
  {
    *p_env = (ludilEnv_t *)malloc (sizeof (ludilEnv_t));

    if (*p_env == NULL)
      goto EXIT;

    (*p_env)->started = FALSE;

    /* init the heap */
    ludilBlobInit (&(*p_env)->heap, LUDIL_KERNEL_HEAP_SIZE*sizeof (ludilUInt8_t));

    /* init the plugin list */
    ludilBlobInit (&(*p_env)->pluginList, (sizeof (ludilPlugin_t *)+sizeof (void *))*LUDIL_KERNEL_PLUGINS);

    /* load the lisp plugin */
    v_pluginPtr = ludilKernelPluginLoad ((*p_env), "Lisp");

    ludilKernelEvent (INFO, "Initialized kernel");
  }
DONE:
  return TRUE;
EXIT:
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilString_t *
ludilKernelAddCString (ludilEnv_t      *p_env,
                       const char      *p_string)
/* ------------------------------------------------------------ */
{
  ludilString_t     *v_string = NULL;
  ludilSize_t        v_length = strlen (p_string);

  v_string = (ludilString_t *)ludilBlobHere (p_env->heap);

  if (v_string)
  {
    p_env->heap = ludilBlobAlloc (p_env->heap, 
                                  sizeof (ludilString_t)+v_length);
    if (p_env->heap)
    {
      v_string->length = v_length;
      v_string->size = v_length+sizeof (ludilString_t);
      memcpy (v_string->data, p_string, v_length+1);
    }
  }

  return v_string;
}

/* ------------------------------------------------------------ */
ludilPluginHandlerCB_t
findSymbol (void        *p_handler,
            char        *p_pluginName,
            const char  *p_routine)
/* ------------------------------------------------------------ */
{
  char                        v_symbolStr [256];
  ludilPluginHandlerCB_t      v_cb = NULL;

  /* we got a handler ... init the plugin */
  snprintf (v_symbolStr,
            sizeof (v_symbolStr),
            "%s%s%s",
            LUDIL_PLUGIN_PREFIX,
            p_pluginName,
            p_routine);

  v_cb = dlsym (p_handler,  v_symbolStr);

  return v_cb;
}

/* ------------------------------------------------------------ */
ludilPlugin_t *
ludilKernelPluginLoad (ludilEnv_t       *p_env,
                       char             *p_pluginName)
/* ------------------------------------------------------------ */
{
  ludilPlugin_t     *v_plugin = NULL;
  ludilSize_t        v_size = 0, v_i;
  void              *v_handler = NULL;
  ludilPlugin_t      v_buf;

  char               v_initStr [] = "Init";   
  char               v_startStr [] = "Start";
  char               v_stepStr [] = "NextStep";
  char               v_freeStr [] = "Free";
  char               v_stopStr [] = "Stop";

  char               v_symbolStr [256];

  v_symbolStr [0] = '\0';

  if (p_env && p_pluginName)
  {
    v_plugin = (ludilPlugin_t *)p_env->pluginList->data;
    v_size = (p_env->pluginList->length)/(sizeof (ludilPlugin_t));

    /* search for plugin */
    for (v_i = 0; v_i < v_size; v_i++)
    {
      if (strcmp (p_pluginName, v_plugin [v_i].name) == 0)
        return &(v_plugin [v_i]); 
    }

    /* ok, no plugin found, so open it */
    v_plugin = NULL;

    snprintf (v_symbolStr,
              sizeof (v_symbolStr),
              "%s%s%s",
              LUDIL_PLUGIN_FILE_PREFIX,
              p_pluginName,
              LUDIL_PLUGIN_FILE_SUFFIX);
    v_handler = dlopen (v_symbolStr, RTLD_NOW);

    /* make an entry, but only if we have a valid handler */
    if (v_handler)
    {
      v_symbolStr [0] = '\0';
      v_plugin = (ludilPlugin_t *)ludilBlobHere (p_env->pluginList);

      p_env->pluginList = ludilBlobAlloc (p_env->pluginList, sizeof (ludilPlugin_t)+sizeof(void *));

      v_plugin->name = ludilBlobHere (p_env->heap);
      v_plugin->externCtx.length = sizeof (v_handler);
      v_plugin->externCtx.size = (sizeof (v_handler) + sizeof (ludilBlob_t)); 
      memcpy (&v_plugin->externCtx.data, &v_handler, sizeof (v_handler));

      p_env->heap = ludilBlobAdd (p_env->heap, (ludilPtr_t)p_pluginName, strlen (p_pluginName)+1); 

      /* we got a handler ... init the plugin */
      if ((v_plugin->initCB = findSymbol (v_handler, 
                                          p_pluginName,
                                          v_initStr)) == NULL)
      {
        p_env->pluginList->length -= sizeof (ludilPlugin_t);
        v_plugin = NULL;
      }
      else
      {
        v_plugin->initCB (NULL);
        v_plugin->startCB = NULL;
        v_plugin->stopCB = NULL;
        v_plugin->stepCB = NULL;
        v_plugin->freeCB = NULL;

        v_plugin->startCB = findSymbol (v_handler, 
                                        p_pluginName,
                                        v_startStr);
        v_plugin->stopCB = findSymbol (v_handler, 
                                       p_pluginName,
                                       v_stopStr);
        v_plugin->stepCB = findSymbol (v_handler, 
                                       p_pluginName,
                                       v_stepStr);
        v_plugin->freeCB = findSymbol (v_handler, 
                                       p_pluginName,
                                       v_freeStr);
      }

    }
  }
  return v_plugin; 
}

/* ------------------------------------------------------------ */
static ludilBool_t
ludilKernelPluginsCallStart (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  ludilPlugin_t     *v_plugin  = NULL;
  ludilSize_t        v_size    = 0, v_i;

  if (p_env)
  {
     v_size = (p_env->pluginList->length)/(sizeof (ludilPlugin_t));
     v_plugin = (ludilPlugin_t *)(p_env->pluginList->data); 

     for (v_i = 0; v_i < v_size; v_i++)
     {
       if (v_plugin[v_i].name && (strlen (v_plugin[v_i].name) > 0))
       {
         if (v_plugin [v_i].startCB) 
         {
          v_plugin [v_i].startCB (NULL);
          ludilKernelEvent (INFO, "Called routine Start of plugin '%s'", 
                                   v_plugin[v_i].name);
         }
         else
         {
          ludilKernelEvent (INFO, "Couldn't call Start routine of plugin '%s'", 
                                  v_plugin[v_i].name);
         }
       }
     }
  }
  return TRUE;
}
/* ------------------------------------------------------------ */
static ludilBool_t
ludilKernelPluginsCallStop (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  ludilPlugin_t     *v_plugin  = NULL;
  ludilSize_t        v_size    = 0, v_i;

  if (p_env)
  {
     v_size = (p_env->pluginList->length)/(sizeof (ludilPlugin_t));
     v_plugin = (ludilPlugin_t *)(p_env->pluginList->data); 

     for (v_i = 0; v_i < v_size; v_i++)
     {
       if (v_plugin[v_i].name && (strlen (v_plugin[v_i].name) > 0))
       {
         if (v_plugin [v_i].stopCB) 
         {
          v_plugin [v_i].stopCB (NULL);
          ludilKernelEvent (INFO, "Called routine Stop of plugin '%s'", 
                                   v_plugin[v_i].name);
         }
         else
         {
          ludilKernelEvent (INFO, "Couldn't call Stop routine of plugin '%s'", 
                                  v_plugin[v_i].name);
         }
       }
     }
  }
  return TRUE;
}
/* ------------------------------------------------------------ */
static ludilBool_t
ludilKernelPluginsCallStep (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  ludilPlugin_t     *v_plugin  = NULL;
  ludilSize_t        v_size    = 0, v_i;

  if (p_env)
  {
     v_size = (p_env->pluginList->length)/(sizeof (ludilPlugin_t));
     v_plugin = (ludilPlugin_t *)(p_env->pluginList->data); 

     for (v_i = 0; v_i < v_size; v_i++)
     {
       if (v_plugin[v_i].name && (strlen (v_plugin[v_i].name) > 0))
       {
         if (v_plugin [v_i].stepCB) 
         {
          v_plugin [v_i].stepCB (NULL);
          ludilKernelEvent (INFO, "Called routine NextStep of plugin '%s'", 
                                   v_plugin[v_i].name);
         }
         else
         {
          ludilKernelEvent (INFO, "Couldn't call NextStep routine of plugin '%s'", 
                                  v_plugin[v_i].name);
         }
       }
     }
  }
  return TRUE;
}
/* ------------------------------------------------------------ */
static ludilBool_t
ludilKernelPluginsCallFree (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  ludilPlugin_t     *v_plugin  = NULL;
  ludilSize_t        v_size    = 0, v_i;

  if (p_env)
  {
     v_size = (p_env->pluginList->length)/(sizeof (ludilPlugin_t));
     v_plugin = (ludilPlugin_t *)(p_env->pluginList->data); 

     for (v_i = 0; v_i < v_size; v_i++)
     {
       if (v_plugin[v_i].name && (strlen (v_plugin[v_i].name) > 0))
       {
         if (v_plugin [v_i].freeCB) 
         {
          v_plugin [v_i].freeCB (NULL);
          ludilKernelEvent (INFO, "Called routine Free of plugin '%s'", 
                                   v_plugin[v_i].name);
         }
         else
         {
          ludilKernelEvent (INFO, "Couldn't call Free routine of plugin '%s'", 
                                  v_plugin[v_i].name);
         }
       }
     }
  }
  return TRUE;
}

/* ------------------------------------------------------------ */
static ludilBool_t 
ludilKernelMainLoop (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  if (p_env && (p_env->started == TRUE))
  {
    /* calling the NextStep routine of each plugin */
    if (TRUE == ludilKernelPluginsCallStep (p_env))
      return TRUE; 
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
static void *
ludilKernelMainLoopThread (void *p_dataPtr)
/* ------------------------------------------------------------ */
{
  ludilBool_t       v_run = TRUE;
  ludilEnv_t       *v_env = (ludilEnv_t *)p_dataPtr; 

  while (v_run == TRUE)
  {
    v_run = ludilKernelMainLoop (v_env);
  }
  return NULL;
}

/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelStart (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  ludilEnv_t      *v_env = NULL;

  if (p_env && (p_env->started == FALSE))
  {
    if (TRUE == ludilKernelPluginsCallStart (p_env))
    {
      p_env->started = TRUE;
      ludilKernelEvent (INFO, "Kernel started");

      /* actually it should get it's own copy */
      v_env = p_env;
      
      if (pthread_create (&(p_env->mainThread),
                          NULL,
                          &ludilKernelMainLoopThread,
                          v_env) == 0)
        return TRUE; 
    }
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelStop (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  if (p_env && (p_env->started == TRUE))
  {
    /* stop main loop thread */
    pthread_cancel (p_env->mainThread);

    /* sync with KernelThread */
    if (pthread_join (p_env->mainThread, NULL) == 0)
    {
      if (TRUE == ludilKernelPluginsCallStop (p_env))
      {
        ludilKernelEvent (INFO, "Kernel stopped");
        p_env->started = FALSE;
        return TRUE; 
      }
    }
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelFree (ludilEnv_t      **p_env)
/* ------------------------------------------------------------ */
{
  ludilPlugin_t     *v_plugin  = NULL;
  ludilSize_t        v_size    = 0, v_i;
  void              *v_handler = NULL;

  if (p_env && (*p_env))
  {
    if ((*p_env)->started == TRUE)
    {
      ludilKernelStop (*p_env);
    }

    /* free resources of each plugin, then close the plugin itself */
    ludilKernelPluginsCallFree (*p_env);

    /* close the plugins */
    v_size = ((*p_env)->pluginList->length)/(sizeof (ludilPlugin_t));
    v_plugin = (ludilPlugin_t *)&((*p_env)->pluginList->data); 

    for (v_i = 0; v_i < v_size; v_i++)
    {
      if (sizeof (v_handler) == v_plugin[v_i].externCtx.length)
        memcpy (&v_handler, &(v_plugin[v_i].externCtx.data), v_plugin[v_i].externCtx.length);

      if (v_handler && (v_plugin[v_i].name) && (strlen (v_plugin[v_i].name) > 0))
      {
        ludilKernelEvent (INFO, "Freeing plugin '%s'\n", v_plugin[v_i].name); 
        dlclose (v_handler);
      }
    }

    ludilBlobFree (&(*p_env)->heap);
    ludilBlobFree (&(*p_env)->pluginList);
  }
DONE:
  return TRUE;
EXIT:
  return FALSE;
}
