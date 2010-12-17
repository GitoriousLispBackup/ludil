#include <SDL/SDL.h>
#include <ludilImage.h>
#include <ludilMemory.h>


int
main (int argc, char **argv)
{
  SDL_Surface *v_screenPtr = NULL;
  int          v_state = 0;

  ludilImage_t *v_imagePtr = NULL;
  ludilPath_t   v_path     = NULL;
  int           v_i   = 0;

  if (argc > 1)
  {
    printf ("opening file: %s\n", argv[1]);
    v_imagePtr = ludilImageFromFile (argv[1]);
  }

  if ((v_state = SDL_Init (SDL_INIT_VIDEO)) != 0)
  {
    printf ("couldn't init surface\n");
    goto EXCEPTION;
  }

  v_screenPtr = SDL_SetVideoMode (640, 480, 32, SDL_SWSURFACE|SDL_DOUBLEBUF);
  if (!v_screenPtr)
  {
    printf ("screen couldn't be allocated\n");
    goto EXCEPTION;
  }

  if (v_imagePtr)
  {
    SDL_LockSurface (v_screenPtr);
    for (v_i = 0; v_i < v_imagePtr->height; v_i++) 
    {
      memcpy (&(((char *)v_screenPtr->pixels)[v_screenPtr->format->BytesPerPixel*v_i*v_screenPtr->w]),
              &(v_imagePtr->data[v_i*v_imagePtr->pixelSize*v_imagePtr->width]), 
              v_imagePtr->pixelSize*v_imagePtr->width);
    }
    SDL_UnlockSurface (v_screenPtr);
  }

  if (SDL_Flip (v_screenPtr) == -1)
  {
    printf ("screen couldn't be flipped\n");
    goto EXCEPTION;
  }

  printf ("Press any key to end\n");
  getc (stdin);

DONE:
  if (v_imagePtr)
  {
    LUDIL_FREE (&v_imagePtr);
  }
  SDL_Quit ();

  return 0;

EXCEPTION:
  if (v_imagePtr)
  {
    LUDIL_FREE (&v_imagePtr);
  }
  if (v_screenPtr)
  {
    SDL_Quit ();
  }
  return 1;
}
