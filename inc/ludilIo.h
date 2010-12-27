#ifndef LUDIL_IO_H
#define LUDIL_IO_H

#include <stdio.h>
#include <ludilTypes.h>

/* ------------------------------------------------------------ */
/** @file ludilIo.h
 *  @author Josef P. Bernhart 
 *  @date 27-12-2010
 *  @ingroup base 
 *
 *  Contains all the definitions related to Io operations
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief io port 
 *
 *  Is an abstract file descriptor, which means, that
 *  the end point of a reading or writing operation can be a 
 *  file, a buffer in memory, a stream or a pipe
 */
/* ------------------------------------------------------------ */
typedef FILE ludilPort_t;

/* ------------------------------------------------------------ */
/** @brief prints string to port 
 *
 * Prints the given string to the given port
 *
 * @param p_portPtr        @b [In] The port to which the string 
 *                                 should be printed. A value of
 *                                 NULL means the default 
 *                                 output port
 * @param p_string         @b [In] String, which should be printed
 */
/* ------------------------------------------------------------ */
void
ludilIoPrintString (ludilPort_t     *p_portPtr,
                    ludilString_t   *p_string);
/* ------------------------------------------------------------ */

#endif
