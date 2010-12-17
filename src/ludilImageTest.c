#include <ludilTypes.h>
#include <ludilImage.h>
#include <ludilMemory.h>
#include <stdio.h>

int 
main (int argc, char **argv) 
{
  ludilImage_t *v_imagePtr = NULL;
  ludilPath_t v_path = NULL;

  if (argc > 1)
  {
    printf ("file: %s\n", argv[1]);
    v_imagePtr = ludilImageFromFile (argv[1]);

    if (v_imagePtr)
    {
      printf ("(ludil:image width: %u heigth: %u pixel-size: %u)\n",
              v_imagePtr->width, v_imagePtr->height, v_imagePtr->pixelSize);
      LUDIL_FREE (&v_imagePtr);
    }
  }

  return 0;
}
