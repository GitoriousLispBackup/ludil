#include <ludilTypes.h>
#include <SDL/SDL.h>

typedef enum 
{
    CommandLineInterface,
    GraphicalUserInterface,
    GraphicalHUDInterface
} ludilShellInterface_t;

typedef enum
{
    None,
    Started,
    Stopped
} ludilShellState_t;

typedef struct
{
    ludilShellInterface_t      interface;
    ludilShellState_t          state;

} ludilShell_s;

typedef ludilShell_s *ludilShell_t;

/* ------------------------------------------------------------ */
/** 
 * 
 * Starts a shell
 *
 */
/* ------------------------------------------------------------ */
ludilBool_t ludilShellStart (ludilShell_t p_shell);

/* ------------------------------------------------------------ */
/** 
 * 
 * Stops a shell 
 *
 */
/* ------------------------------------------------------------ */
ludilBool_t ludilShellStop (ludilShell_t  p_shell);

/* ------------------------------------------------------------ */
/** 
 * 
 * Changes the interface of a shell, works also while the shell
 * is running. Then the shell is updated in realtime.
 *
 */
/* ------------------------------------------------------------ */
ludilBool_t ludilShellSetInterface (ludilShell_t          p_shell, 
                                    ludilShellInterface_t p_interface);
