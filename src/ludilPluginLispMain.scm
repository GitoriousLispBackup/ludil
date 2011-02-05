#>
#include "chicken.h"


/* ------------------------------------------------------------ */
static C_word g_word = C_SCHEME_UNDEFINED;
static int    g_run = 1;
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
void 
ludilPluginLispInit ()
/* ------------------------------------------------------------ */
{
  CHICKEN_initialize (0,0,0, C_toplevel);
  g_word = CHICKEN_run (C_toplevel);
}

/* ------------------------------------------------------------ */
void 
ludilPluginLispStart ()
/* ------------------------------------------------------------ */
{
  g_run = 1;

  while (g_run)
    g_word = CHICKEN_continue (g_word);
}

/* ------------------------------------------------------------ */
void 
ludilPluginLispStop ()
/* ------------------------------------------------------------ */
{
  g_run = 0;
}

/* ------------------------------------------------------------ */
void 
ludilPluginLispFree ()
/* ------------------------------------------------------------ */
{

}

<#

(require-extension srfi-18)
(define m (make-mutex))

(define (t)
  (mutex-lock! m)
  (thread-sleep! 1)
  (print (thread-name (current-thread)))
  (mutex-unlock! m)
  (t))

(thread-start! (make-thread t 'PING))
(thread-start! (make-thread t 'PONG))

(let loop ()
 (return-to-host)
 (thread-yield!)
 (loop))
