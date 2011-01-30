#include <ludilBlob.h>
#include <stdlib.h>
#include <string.h>


/* ------------------------------------------------------------ */
void 
ludilBlobInit (ludilBlob_t    **p_blobPtr, 
               ludilSize_t      p_dataSize)
/* ------------------------------------------------------------ */
{
  if (p_blobPtr && ((*p_blobPtr) == NULL) && (p_dataSize > 0))
  {
      (*p_blobPtr) = malloc (sizeof (ludilBlob_t) + p_dataSize);
      (*p_blobPtr)->size = sizeof (ludilBlob_t) + p_dataSize;
      (*p_blobPtr)->length = 0;
  }
}

/* ------------------------------------------------------------ */
void 
ludilBlobFree (ludilBlob_t    **p_blobPtr)
/* ------------------------------------------------------------ */
{
  if (p_blobPtr && (*p_blobPtr))
  {
     free ((void *) (*p_blobPtr));
     (*p_blobPtr) = NULL;
  }
}

/* ------------------------------------------------------------ */
ludilPtr_t
ludilBlobHere (ludilBlob_t    *p_blob)
/* ------------------------------------------------------------ */
{
    return &(p_blob->data [p_blob->length]);
}

/* ------------------------------------------------------------ */
ludilBlob_t *
ludilBlobAlloc (ludilBlob_t    *p_blob, 
                ludilSize_t     p_size)
/* ------------------------------------------------------------ */
{
  ludilSize_t       v_newSize = 0;
  ludilBlob_t      *v_blob = NULL;

  if (p_blob && p_size)
  {
    v_newSize = (p_blob->length + p_size + sizeof (ludilBlob_t));

    /* when we add the object, then it should be in the bounds */
    if (v_newSize > p_blob->size)
    {
      /* resize blob, if we are bigger */
      v_blob = (ludilBlob_t *)realloc (p_blob, v_newSize);

      if (!v_blob)
        return NULL;

      v_blob->size = v_newSize;
    }
    else
      v_blob = p_blob;

    v_blob->length = v_newSize - sizeof (ludilBlob_t);
  
  }
  return v_blob;
}

/* ------------------------------------------------------------ */
ludilBlob_t *
ludilBlobAdd (ludilBlob_t    *p_blob, 
              ludilPtr_t      p_pointer,
              ludilSize_t     p_size)
/* ------------------------------------------------------------ */
{
  ludilBlob_t      *v_blob = NULL;
  ludilSize_t       v_size;

  if (p_blob && p_pointer && (p_size > 0))
  {
    v_size = p_blob->length;
    v_blob = ludilBlobAlloc (p_blob, p_size);

    /* copy the data and set it right */
    memcpy (&(v_blob->data [v_size]), p_pointer, p_size);
  }
  return v_blob;
}

