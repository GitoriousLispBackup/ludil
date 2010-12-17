#ifndef LUDIL_MEMORY_H
#define LUDIL_MEMORY_H

#include <stdlib.h>
#include <ludilTypes.h>

/* macros */
#define LUDIL_FREE(ptr_ptr) if (*ptr_ptr) { free((void *)*ptr_ptr); *ptr_ptr = NULL; }
#define LUDIL_ALLOC(var,size) var = (typeof (var))malloc(size);

/* functions */
ludilPtr_t ludilAlloc (ludilSize_t p_size); 
void ludilFree (ludilPtr_t *p_dataPtr);
#endif
