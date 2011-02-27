/* ------------------------------------------------------------ */
/*
 *   Ludil - Scheme/C game programming framework
 *   Copyright (C) 2010,2011 Josef P. Bernhart <bernhartjp@yahoo.de>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/* ------------------------------------------------------------ */


#ifndef LUDIL_BLOB_H
#define LUDIL_BLOB_H

#include <ludilTypes.h>

/* ------------------------------------------------------------ */
/** @file ludilBlob.h
 *  @author Josef P. Bernhart 
 *  @date 31-01-2011
 *  @ingroup base
 *
 *  Defines operations on blobs
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @page blobs Blobs
 * Blobs are in ludil some sort of general storage data structure,
 * as they are in Databases (blob = binary large object).
 *
 * They can contain files, images, etc.
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief inits a blob
 *
 *  Initializes a blob structure in memory
 *
 *  @param p_blobPtr        @b [Out] Pointer to blob pointer
 *  @param p_dataSize       @b [In] Size of blob in bytes
 */
/* ------------------------------------------------------------ */
void 
ludilBlobInit (ludilBlob_t    **p_blobPtr, 
               ludilSize_t      p_dataSize);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief frees a blob 
 * 
 *  Frees a blob 
 * 
 *  @param p_blobPtr        @b [In/Out] Pointer to blob, which
 *                                      should be freed
 */
/* ------------------------------------------------------------ */
void 
ludilBlobFree (ludilBlob_t    **p_blobPtr);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief retrive next free place in a blob
 *
 *  Returns a pointer of the end of the blob, which isn't used
 *  ( free )
 *
 * @param p_blob          @b [In] Pointer to blob
 *
 * @returns   pointer to end of blob
 */
/* ------------------------------------------------------------ */
ludilPtr_t
ludilBlobHere (ludilBlob_t    *p_blob);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief allocates space in a blob 
 *
 * Allocates the given amount of space (in bytes) at the 
 * end of the given blob, if the blob is smaller than this size,
 * the the blob is made bigger. For that case, the new 
 * blob pointer is returned, then the old blob pointer isn't
 * useable anymore.
 *
 * @param p_blob        @b [In] Pointer to blob
 * @param p_size        @b [In] Size of block, which should be 
 *                              allocated in bytes
 *
 * @returns old / new blob pointer, if something was re-allocated
 *
 */
/* ------------------------------------------------------------ */
ludilBlob_t *
ludilBlobAlloc (ludilBlob_t    *p_blob, 
                ludilSize_t     p_size);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief adds structure to blob
 *
 * Copies the given data structure at the end of the blob, 
 * if the blob is too small for the data structure, then 
 * the blob is resized (= a new blob is created and the old
 * blob is deleted and the new blob is returned )
 *
 * @param p_blob        @b [In] Pointer to blob
 * @param p_pointer     @b [In] Pointer to structure, which should
 *                              be copied
 * @param p_size        @b [In] Size in bytes
 *
 * @return old / new blob
 */
/* ------------------------------------------------------------ */
ludilBlob_t *
ludilBlobAdd (ludilBlob_t    *p_blob, 
              ludilPtr_t      p_pointer,
              ludilSize_t     p_size);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief returns free space in bytes
 *
 * Returns the free space in a given blob
 *
 * @param p_blob      @b [In] blob structure
 *
 * @return free size of blob in bytes
 *
 */
/* ------------------------------------------------------------ */
ludilSize_t
ludilBlobFreeSpace (ludilBlob_t *p_blob);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief returns true if a size fits into a blob
 *
 * Tests if a specific size fits into the given blob 
 * 
 * @param p_blob      @b [In] pointer to blob
 * @param p_size      @b [In] size in bytes
 *
 * @returns TRUE if size fits into blob, else FALSE
 *
 */
/* ------------------------------------------------------------ */
ludilBool_t
ludilBlobFits (ludilBlob_t *p_blob,
               ludilSize_t  p_size);
/* ------------------------------------------------------------ */


#endif
