#include <ludilIo.h>


/* ------------------------------------------------------------ */
void
ludilIoPrintString (ludilPort_t     *p_portPtr, 
                    ludilString_t   *p_string)
/* ------------------------------------------------------------ */
{
  ludilSize_t v_i;

  if (p_portPtr == NULL)
  {
    if (p_string)
    {
      if (p_string->length > (p_string->size-sizeof (ludilString_t)))
        return ;

      for (v_i = 0; v_i < p_string->length; v_i++)
        putchar ((int)p_string->data [v_i]);
    }
  }

  return ;
}
