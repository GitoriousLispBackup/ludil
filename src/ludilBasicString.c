#include <ludilString.h>
#include <ludilMemory.h>
#include <string.h>

/* ------------------------------------------------------------ */
ludilString_t *
ludilStringAlloc (ludilSize_t p_length)
/* ------------------------------------------------------------ */
{
  ludilString_t  *v_stringPtr = NULL;
  ludilSize_t     v_size = sizeof (ludilString_t) + p_length;

  if (p_length > 0)
  {
    v_stringPtr = (ludilString_t *)ludilAlloc (v_size);
    
    if (v_stringPtr)
    {
      v_stringPtr->size = v_size;
      v_stringPtr->length = p_length;
    }
  }
  return v_stringPtr;
}

/* ------------------------------------------------------------ */
ludilString_t *
ludilStringNew (const char *p_string)
/* ------------------------------------------------------------ */
{
  ludilSize_t     v_length;
  ludilString_t  *v_stringPtr = NULL;

  if (p_string)
  {
    v_length = strlen (p_string);
    v_stringPtr = ludilStringAlloc (v_length);

    memcpy (&v_stringPtr->data, p_string, v_length);

  }
  return v_stringPtr;
}
