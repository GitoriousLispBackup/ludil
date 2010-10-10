#include <ramboImage.h>
#include <ramboTypes.h>
#include <ramboMemory.h>
#include <png.h>
#include <stdio.h>

static const ramboSize_t ramboPNGSigCmpSize_C = 8;

ramboImage_t *
ramboImageFromFile (ramboPath_t p_path)
{
  FILE                    *v_filePtr  = NULL;
  ramboImage_t            *v_imagePtr = NULL;  
  ramboSize_t              v_readBytes = 0;
  ramboByte_t              v_sig [ramboPNGSigCmpSize_C];

  png_structp              v_pngReadPtr    = NULL;
  png_infop                v_pngInfoPtr    = NULL;
  png_infop                v_pngEndInfoPtr = NULL;
  png_uint_32              v_width         = 0;
  png_uint_32              v_height        = 0;
  png_bytepp               v_rowPtr        = NULL;
  ramboSize_t              v_i             = 0;
  ramboSize_t              v_ii            = 0;

  v_filePtr = fopen (p_path, "rb");
  if (!v_filePtr)
    goto EXCEPTION;

  v_readBytes = fread (v_sig, 
                       sizeof(ramboByte_t), 
                       ramboPNGSigCmpSize_C, 
                       v_filePtr);
  if (!v_readBytes)
    goto EXCEPTION;

  /* compare signature */
  if (png_check_sig (v_sig, v_readBytes))
  {
     v_pngReadPtr = png_create_read_struct (PNG_LIBPNG_VER_STRING,
                                            NULL,
                                            NULL,
                                            NULL);
     if (!v_pngReadPtr)
      goto EXCEPTION;

     v_pngInfoPtr = png_create_info_struct (v_pngReadPtr);
     if (!v_pngInfoPtr)
     {
      png_destroy_read_struct (&v_pngReadPtr, NULL, NULL);
      goto EXCEPTION;
     }

     v_pngEndInfoPtr = png_create_info_struct (v_pngReadPtr); 
     if (!v_pngEndInfoPtr)
     {
      png_destroy_read_struct (&v_pngReadPtr, 
                               &v_pngInfoPtr,
                               NULL);
      goto EXCEPTION;
     }
    
     /* telling libpng, that we already read the signature */
     png_set_sig_bytes (v_pngReadPtr, v_readBytes);

     /* init io */
     png_init_io (v_pngReadPtr, v_filePtr);

     /* read image into memory */
     png_read_png (v_pngReadPtr, 
                   v_pngInfoPtr, 
                   PNG_TRANSFORM_IDENTITY,
                   NULL);

     /* get dimensions */
     v_width = png_get_image_width (v_pngReadPtr, v_pngInfoPtr);
     v_height = png_get_image_height (v_pngReadPtr, v_pngInfoPtr);

    /* get rows */ 
    v_rowPtr = png_get_rows (v_pngReadPtr, v_pngInfoPtr); 
    if (!v_rowPtr)
      goto EXCEPTION;

    v_imagePtr = (ramboImage_t *)ramboAlloc ( sizeof(ramboImage_t)+(v_width*v_height));

    if (!v_imagePtr)
      goto EXCEPTION;

    v_imagePtr->width = (ramboSize_t)v_width;
    v_imagePtr->height = (ramboSize_t)v_height;

    /* copying data into an image */
    for (v_i = 0; v_i < v_height; v_i++)
    {
      for (v_ii = 0; v_ii < v_width; v_ii++)
      {
        v_imagePtr->data [v_i+v_ii] = v_rowPtr [v_i][v_ii]; 
      }
    }
  }

  if (v_filePtr)
  {
    png_destroy_read_struct (&v_pngReadPtr, 
                             &v_pngInfoPtr,
                             &v_pngEndInfoPtr);
    fclose (v_filePtr);
  }
DONE:
  return v_imagePtr;

EXCEPTION:
  if (v_filePtr)
  {
    fclose (v_filePtr);
    v_filePtr = NULL;
  }
  if (v_pngReadPtr && v_pngInfoPtr && v_pngEndInfoPtr) 
  {
    png_destroy_read_struct (&v_pngReadPtr,
                             &v_pngInfoPtr,
                             &v_pngEndInfoPtr);
    v_pngReadPtr = NULL;
    v_pngInfoPtr = NULL;
    v_pngEndInfoPtr = NULL;
  }  
  return RAMBO_PTR_NULL;
}