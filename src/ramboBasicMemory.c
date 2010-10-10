#include <ramboMemory.h>
#include <ramboTypes.h>
#include <stdlib.h>
#include <string.h>

ramboPtr_t 
ramboAlloc (ramboSize_t p_size)
{
  ramboPtr_t v_dataPtr = NULL;

  RAMBO_ALLOC (v_dataPtr, p_size);

  if (v_dataPtr)
  {
    memset (v_dataPtr, 0, p_size);
    return v_dataPtr;
  }
  return RAMBO_PTR_NULL;
}

void 
ramboFree (ramboPtr_t *p_dataPtr)
{
  RAMBO_FREE (p_dataPtr);
}
