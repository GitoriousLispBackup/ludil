#ifndef RAMBO_MEMORY_H
#define RAMBO_MEMORY_H

#include <stdlib.h>
#include <ramboTypes.h>

/* macros */
#define RAMBO_FREE(ptr_ptr) if (*ptr_ptr) { free((void *)*ptr_ptr); *ptr_ptr = NULL; }
#define RAMBO_ALLOC(var,size) var = (typeof (var))malloc(size);

/* functions */
ramboPtr_t ramboAlloc (ramboSize_t p_size); 
void ramboFree (ramboPtr_t *p_dataPtr);
#endif
