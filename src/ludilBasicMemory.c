#include <ludilMemory.h>
#include <ludilTypes.h>
#include <stdlib.h>
#include <string.h>

/* macros */
#define LUDIL_FREE(ptr_ptr) if (*ptr_ptr) { free((void *)*ptr_ptr); *ptr_ptr = NULL; }
#define LUDIL_ALLOC(var,size) var = (typeof (var))malloc(size);

/* ------------------------------------------------------------ */
ludilPtr_t 
ludilAlloc (ludilSize_t p_size)
/* ------------------------------------------------------------ */
{
  ludilPtr_t v_dataPtr = NULL;

  LUDIL_ALLOC (v_dataPtr, p_size);

  if (v_dataPtr)
  {
    memset (v_dataPtr, 0, p_size);
    return v_dataPtr;
  }
  return LUDIL_PTR_NULL;
}

/* ------------------------------------------------------------ */
void 
ludilFree (ludilPtr_t *p_dataPtr)
/* ------------------------------------------------------------ */
{
  if (p_dataPtr)
  {
    LUDIL_FREE (p_dataPtr);
  }
}
