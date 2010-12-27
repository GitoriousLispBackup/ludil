#ifndef LUDIL_MEMORY_H
#define LUDIL_MEMORY_H

#include <stdlib.h>
#include <ludilTypes.h>


/* ------------------------------------------------------------ */
/** ludilAlloc
 * 
 * Allocates an amount of bytes and returns the pointer to it
 *
 * @param p_size      @b [In] size of data, which should be allocated
 *
 * @return
 *  pointer to allocated data structure
 */
/* ------------------------------------------------------------ */
ludilPtr_t 
ludilAlloc (ludilSize_t p_size); 
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilFree
 *
 * Frees a given data structure
 * 
 * @param p_dataPtr       @b [In] pointer to a pointer to the
 *                                allocated data structure
 * @return
 * nothing
 */
/* ------------------------------------------------------------ */
void 
ludilFree (ludilPtr_t *p_dataPtr);
/* ------------------------------------------------------------ */
#endif
