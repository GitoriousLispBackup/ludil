#include <ludilKernel.h>
#include <ludilTypes.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <ludilBlob.h>
#include <string.h>
#include <stdio.h>

#define LUDIL_KERNEL_PLUGINS 10
#define LUDIL_KERNEL_HEAP_SIZE 1024
#define LUDIL_KERNEL_EVENTS 256

#define LUDIL_PLUGIN_PREFIX (LUDIL_PROJECT_NAME"Plugin")
#define LUDIL_PLUGIN_SUFFIX (".so")

/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelInit (ludilEnv_t      **p_env)
/* ------------------------------------------------------------ */
{
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
  }
DONE:
  return TRUE;
EXIT:
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelFree (ludilEnv_t      **p_env)
/* ------------------------------------------------------------ */
{
  if (p_env && (*p_env))
  {
    ludilKernelPluginsClose (*p_env);

    ludilBlobFree (&(*p_env)->heap);
    ludilBlobFree (&(*p_env)->pluginList);
  }
DONE:
  return TRUE;
EXIT:
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t 
ludilKernelStart (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  if (p_env && (p_env->started == FALSE))
  {
    p_env->started = TRUE;

    return TRUE; 
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
    p_env->started = FALSE;

    return TRUE; 
  }
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
ludilPlugin_t *
ludilKernelPluginLoad (ludilEnv_t       *p_env,
                       const char       *p_pluginName)
/* ------------------------------------------------------------ */
{
  ludilPlugin_t     *v_plugin = NULL;
  ludilSize_t        v_size = 0, v_i;
  void              *v_handler = NULL;
  ludilPlugin_t      v_buf;
  void             (*v_cb)(void) = NULL;

  char               v_initStr [] = "Init";   
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
    v_handler = dlopen (p_pluginName, RTLD_NOW);

    /* make an entry, but only if we have a valid handler */
    if (v_handler)
    {
      v_plugin = (ludilPlugin_t *)ludilBlobHere (p_env->pluginList);

      p_env->pluginList = ludilBlobAlloc (p_env->pluginList, sizeof (ludilPlugin_t)+sizeof(void *));

      v_plugin->name = ludilBlobHere (p_env->heap);
      v_plugin->externCtx.length = sizeof (void *);
      v_plugin->externCtx.size = (sizeof (void *) + sizeof (ludilBlob_t)); 
      memcpy (&v_plugin->externCtx.data, &v_handler, sizeof (v_handler));

      p_env->heap = ludilBlobAdd (p_env->heap, (ludilPtr_t)p_pluginName, strlen (p_pluginName)+1); 

      /* we got a handler ... init the plugin */
      snprintf (v_symbolStr,
                sizeof (v_symbolStr),
                "%s%s%s%s",
                LUDIL_PLUGIN_PREFIX,
                p_pluginName,
                v_initStr,
                LUDIL_PLUGIN_SUFFIX);

      v_cb = dlsym (v_handler,  v_symbolStr);
      if (v_cb)
        v_cb ();
      else
        puts ("no symbol found");
    }
  }
  return v_plugin; 
}

/* ------------------------------------------------------------ */
ludilBool_t
ludilKernelPluginsClose (ludilEnv_t       *p_env)
/* ------------------------------------------------------------ */
{
  if (p_env)
  {
     
  }
  return FALSE;
}
