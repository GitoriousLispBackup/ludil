#ifndef LUDIL_IMAGE_H
#define LUDIL_IMAGE_H

#include <ludilTypes.h>

/* is a ludil object */
typedef struct
{
  ludilSize_t   width;
  ludilSize_t   height;
  ludilSize_t   pixelSize;  

  ludilData_t   data;
} ludilImage_t;

/* function */
ludilImage_t * ludilImageFromFile (ludilPath_t p_path);


#endif
