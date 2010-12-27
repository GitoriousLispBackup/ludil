#ifndef LUDIL_POINT_H
#define LUDIL_POINT_H

#include <ludilTypes.h>

/* ------------------------------------------------------------ */
/** @file ludilPoint.h
 *  @author Josef P. Bernhart 
 *
 *  Contains the definitions related to 2d points for ludil
 */
/* ------------------------------------------------------------ */



typedef struct 
{
  ludilOffset_t x;
  ludilOffset_t y;
} ludilPoint_t;

/* ------------------------------------------------------------ */
/** ludilPointSet
 *
 * Sets the given point to the given values 
 *
 * @param p_x           @b [In] x position of point
 * @param p_y           @b [In] y position of point
 *
 * @return
 * original pointer on success or NULL
 */
/* ------------------------------------------------------------ */
ludilPoint_t *
ludilPointSet (ludilPoint_t *p_pointPtr,
               ludilOffset_t p_x, 
               ludilOffset_t p_y);
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/** ludilPointGetX 
 *
 * Gets the x position of the given point
 *
 * @param p_pointPtr        @b [In] pointer to point data structure
 * 
 * @return
 * x position of point
 */
/* ------------------------------------------------------------ */
ludilOffset_t 
ludilPointGetX (ludilPoint_t *p_pointPtr);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilPointGetY 
 *
 * Gets the y position of the given point
 *
 * @param p_pointPtr        @b [In] pointer to point data structure
 * 
 * @return
 * y position of point
 */
/* ------------------------------------------------------------ */
ludilOffset_t 
ludilPointGetY (ludilPoint_t *p_pointPtr);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilPointAdd
 *
 * Adds the given points together ( A = A + B)
 *
 * @param p_destPtr        @b [In/Out] pointer to A pointer
 * @param p_srcPtr         @b [In] source point pointer
 * 
 * @return
 * pointer of the result
 */
/* ------------------------------------------------------------ */
ludilPoint_t * 
ludilPointAdd (ludilPoint_t *p_destPtr, 
               ludilPoint_t *p_srcPtr);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilPointSub
 *
 * Subtracts the given points  ( A = A - B)
 *
 * @param p_destPtr        @b [In/Out] pointer to destination pointer
 * @param p_srcPtr         @b [In] source point pointer
 * 
 * @return
 * pointer of the result
 */
/* ------------------------------------------------------------ */
ludilPoint_t * 
ludilPointSub (ludilPoint_t *p_destPtr, 
               ludilPoint_t *p_srcPtr);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilPointString
 *
 * Converts the given point into a ludil string
 *
 * @param p_pointPtr       @b [In] pointer to point
 * @param p_stringPtr      @b [Out] output string
 * 
 * @return
 * pointer of the result
 */
/* ------------------------------------------------------------ */
ludilString_t * 
ludilPointString (ludilPoint_t  *p_pointPtr, 
                  ludilString_t *p_stringPtr);
/* ------------------------------------------------------------ */

#endif
