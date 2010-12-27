#include <ludilPoint.h>
#include <ludilTypes.h>
#include <stdio.h>
#include <string.h>


/* ------------------------------------------------------------ */
ludilPoint_t *
ludilPointSet (ludilPoint_t *p_pointPtr,
               ludilOffset_t p_x, 
               ludilOffset_t p_y)
/* ------------------------------------------------------------ */
{
  if (p_pointPtr)
  {
    p_pointPtr->x = p_x;
    p_pointPtr->y = p_y;
  }
  return p_pointPtr;
}

/* ------------------------------------------------------------ */
ludilOffset_t 
ludilPointGetX (ludilPoint_t *p_pointPtr)
/* ------------------------------------------------------------ */
{
  if (p_pointPtr)
    return p_pointPtr->x;

  return 0;
}

/* ------------------------------------------------------------ */
ludilOffset_t 
ludilPointGetY (ludilPoint_t *p_pointPtr)
/* ------------------------------------------------------------ */
{
  if (p_pointPtr)
    return p_pointPtr->y;

  return 0;
}

/* ------------------------------------------------------------ */
ludilPoint_t * 
ludilPointAdd (ludilPoint_t *p_destPtr, 
               ludilPoint_t *p_srcPtr)
/* ------------------------------------------------------------ */
{
  if (p_destPtr && p_srcPtr)
  {
    p_destPtr->x += p_srcPtr->x;
    p_destPtr->y += p_srcPtr->y;
  }
  return p_destPtr;
}

/* ------------------------------------------------------------ */
ludilPoint_t * 
ludilPointSub (ludilPoint_t *p_destPtr, 
               ludilPoint_t *p_srcPtr)
/* ------------------------------------------------------------ */
{
  if (p_destPtr && p_srcPtr)
  {
    p_destPtr->x -= p_srcPtr->x;
    p_destPtr->y -= p_srcPtr->y;
  }
  return p_destPtr;
}

/* ------------------------------------------------------------ */
ludilString_t * 
ludilPointString (ludilPoint_t  *p_pointPtr, 
                  ludilString_t *p_stringPtr)
/* ------------------------------------------------------------ */
{
  ludilString_t *v_stringPtr = NULL;

  if (p_pointPtr)
  {
    if (p_stringPtr)
      v_stringPtr = p_stringPtr;
    else
      v_stringPtr = ((ludilString_t *)ludilStringAlloc (40));

    if (!v_stringPtr)
      return NULL;

    snprintf (v_stringPtr->data, v_stringPtr->size, 
              "(ludilPoint x: %"PRI_L_OFFSET
              " y: %"PRI_L_OFFSET")", 
              p_pointPtr->x,
              p_pointPtr->y);

    v_stringPtr->length = strlen (v_stringPtr->data);
  }

  return v_stringPtr;
}
