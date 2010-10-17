#include <ramboTypes.h>
#include <ramboImage.h>
#include <ramboMemory.h>
#include <stdio.h>

int 
main (int argc, char **argv) 
{
  ramboImage_t *v_imagePtr = NULL;
  ramboPath_t v_path = NULL;

  if (argc > 1)
  {
    printf ("file: %s\n", argv[1]);
    v_imagePtr = ramboImageFromFile (argv[1]);

    if (v_imagePtr)
    {
      printf ("(rambo:image width: %u heigth: %u pixel-size: %u)\n",
              v_imagePtr->width, v_imagePtr->height, v_imagePtr->pixelSize);
      RAMBO_FREE (&v_imagePtr);
    }
  }

  return 0;
}
