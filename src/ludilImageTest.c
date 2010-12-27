#include <ludilTypes.h>
#include <ludilImage.h>
#include <ludilMemory.h>
#include <ludilTest.h>
#include <stdio.h>

/* ------------------------------------------------------------ */
/** @file ludilImageTest.c
 *  @author Josef P. Bernhart
 *  @date 27-10-2010
 *  @ingroup tests
 *
 *  @brief ludil image test 
 *
 *  This testprogram tests the ludilImage_t type
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
int 
main (int argc, char **argv) 
/* ------------------------------------------------------------ */
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
      ludilFree ((ludilPtr_t *)&v_imagePtr);
    }
  }

  return 0;
}
