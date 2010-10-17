#ifndef RAMBO_IMAGE_H
#define RAMBO_IMAGE_H

#include <ramboTypes.h>

/* is a rambo object */
typedef struct
{
  ramboSize_t   width;
  ramboSize_t   height;
  ramboSize_t   pixelSize;  

  ramboData_t   data;
} ramboImage_t;

/* function */
ramboImage_t * ramboImageFromFile (ramboPath_t p_path);


#endif
