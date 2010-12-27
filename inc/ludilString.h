#ifndef LUDIL_STRING_H
#define LUDIL_STRING_H

#include <ludilTypes.h>

/* ------------------------------------------------------------ */
/** @file ludilTypes.h
 *  @author Josef P. Bernhart 
 *
 *  Is a the main types definitions file, will be modularized
 *  in later releases
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilStringAlloc
 *
 * Allocates a string of the given length in characters
 *
 * @param p_length           @b [In] length of allocated string
 *
 * @return
 * allocated string
 */
/* ------------------------------------------------------------ */
ludilString_t *
ludilStringAlloc (ludilSize_t p_length);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** ludilStringNew
 *
 * Creates a new ludil string from a given constant c string
 *
 * @param p_string           @b [In] c string, from which 
 *                                   a ludil version is generated
 *
 * @return
 * pointer to allocated string
 */
/* ------------------------------------------------------------ */
ludilString_t *
ludilStringNew (const char *p_string);
/* ------------------------------------------------------------ */


#endif
