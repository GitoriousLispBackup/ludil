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

#ifndef LUDIL_TYPES_H
#define LUDIL_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <ludilProjectConfig.h>

/* ------------------------------------------------------------ */
/** @defgroup base
 *  @brief ludil base 
 *  Contains the basic functionality for other ludil extensions
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief ludil meta type 
 *
 * Which holds the information, what a specific thing is.
 * Normally this is attached to ludil objects.
 */
/* ------------------------------------------------------------ */
typedef enum 
{
  ludilTypeBasicRange       = 0,
  ludilTypeNone,
  ludilTypeInt8,
  ludilTypeInt16,
  ludilTypeInt32,
  ludilTypeInt64,

  ludilTypeUInt8,
  ludilTypeUInt16,
  ludilTypeUInt32,
  ludilTypeUInt64,
  
  ludilTypeByte,

  ludilTypeSize,

  ludilTypeString,
  ludilTypeInternalString,
  ludilTypePath,

  ludilTypeData,
  ludilTypeBlob,

  ludilTypeBool,
  ludilTypeObject, 
  ludilTypeId,
  ludilTypePtr,
  ludilType,

  ludilTypeSoundRange       = 1000,
  ludilTypeNetRange         = 2000,
  ludilTypeVideoRange       = 3000,
  ludilTypeInputRange       = 4000,
  ludilTypeOutputRange      = 5000,
  ludilTypeImageRange       = 6000,
  ludilTypeSignalRange      = 7000,
  ludilTypeFileRange        = 8000,
  ludilTypeExtendRange      = 9000
} ludilType_t;

/* ------------------------------------------------------------ */
/** @file ludilTypes.h
 *  @author Josef P. Bernhart 
 *  @date 12-27-2010
 *  @ingroup base
 *
 *  Is a the main types definitions file, will be modularized
 *  in later releases
 */
/* ------------------------------------------------------------ */

/** @addtogroup ludil_sit signed integer types */
/*@{*/
/** signed int 1 byte ( 8 bit ) */
typedef int8_t  ludilInt8_t; 
/** signed int 2 bytes ( 16 bit ) */
typedef int16_t ludilInt16_t;
/** signed int 4 bytes ( 32 bit ) */
typedef int32_t ludilInt32_t;
/** signed int 8 bytes ( 64 bit ) */
typedef int64_t ludilInt64_t;
/*@}*/

/** @addtogroup ludil_uit unsigned integer types */
/*@{*/
/** unsigned int 1 byte ( 8 bit ) */
typedef uint8_t  ludilUInt8_t;
/** unsigned int 2 byte ( 16 bit ) */
typedef uint16_t ludilUInt16_t;
/** unsigned int 4 byte ( 32 bit ) */
typedef uint32_t ludilUInt32_t;
/** unsigned int 8 byte ( 64 bit ) */
typedef uint64_t ludilUInt64_t;

/** unsigned int 1 byte ( 8 bit ) an alias for ludiUInt8_t */
typedef char ludilByte_t;
/*@}*/

/** @addtogroup ludil_at abstract integer types */
/*@{*/
/** The size of some data in bytes */
typedef size_t      ludilSize_t;
/** The length of some data in units */
typedef size_t      ludilLength_t;
/** An offset into an array in units, not bytes */
typedef ludilSize_t ludilOffset_t;
/*@}*/

/** @addtogroup ludil_trt time related types */
/*@{*/ 
/** type for saving the time since 
 *  the start of a ludil session in miliseconds */
typedef uint32_t    ludilTicks_t;
/*@}*/

/** @addtogroup ludil_at array types */
/*@{*/
/** a variable sized piece of data */
typedef ludilByte_t ludilData_t [1];
/*@}*/

/** @addtogroup ludil_ptrt pointer types */
/*@{*/
/** general pointer */
typedef char *ludilPtr_t;

/** pointer to unsigned int 1 byte ( 8 bit )  */
typedef ludilUInt8_t *ludilPtrUInt8_t;
/** pointer to unsigned int 2 byte ( 16 bit )  */
typedef ludilUInt16_t *ludilPtrUInt16_t;
/** pointer to unsigned int 4 byte ( 32 bit )  */
typedef ludilUInt32_t *ludilPtrUInt32_t;
/** pointer to unsigned int 8 byte ( 64 bit )  */
typedef ludilUInt64_t *ludilPtrUInt64_t;

/** pointer to signed int 1 byte ( 8 bit )  */
typedef ludilInt8_t *ludilPtrInt8_t;
/** pointer to signed int 2 byte ( 16 bit )  */
typedef ludilInt16_t *ludilPtrInt16_t;
/** pointer to signed int 4 byte ( 32 bit )  */
typedef ludilInt32_t *ludilPtrInt32_t;
/** pointer to signed int 8 byte ( 64 bit )  */
typedef ludilInt64_t *ludilPtrInt64_t;

/** pointer to size value  */
typedef ludilSize_t *ludilPtrSize_t;
/*@}*/

/** @addtogroup ludil_reft reference types */
/*@{*/

/* ------------------------------------------------------------ */
/** Identifying numeric value for a specific piece of data, 
 *  in contrast to a pointer its value doesn't represent
 *  an address in memory. It can be an offset into an 
 *  array, but it doesn't need to be. 
 */
/* ------------------------------------------------------------ */
typedef unsigned int ludilId_t;     
/*@}*/

/** ludil boolean type */
typedef enum 
{ 
  FALSE = 0, 
  UNSURE, 
  TRUE
} ludilBool_t;

#define IS_TRUE(x) (x == TRUE)
#define IS_FALSE(x) (x == FALSE)

/** @addtogroup ludil_structt structure types */
/*@{*/

/* ------------------------------------------------------------ */
/** @brief ludil general object 
 *
 *  A structure which describes a specific piece of data, to
 *  which to which a pointer points to. So the object attaches
 *  a type to some piece of data in the memory.
 * */
/* ------------------------------------------------------------ */
typedef struct
{
  ludilId_t     id;         /**< id of data */
  ludilType_t   type;       /**< type of data */
  ludilPtr_t    pointer;    /**< pointer to contained data */
} ludilObject_t;

typedef ludilObject_t *ludilRef_t;  


/* ------------------------------------------------------------ */
/** @brief ludil binary large object 
 *
 *  A structure for holding variable length data of any kind, 
 *  in an unoptimized way.
 *  
 *  Examples would be:
 *  - an image 
 *  - a soundfile 
 *  - a save game 
 *  - etc.
 */
/* ------------------------------------------------------------ */
typedef struct 
{
  ludilSize_t     size;     /**< size of blob structure in memory, 
                                 as a blob is of variable size */
  ludilSize_t     length;   /**< size of contained data, so how much of the data is actually used */
  ludilData_t     data;    /**< data contained within the blob */
} ludilBlob_t;

/** @addtogroup ludil_strt string related types */
/*@{*/

/* ------------------------------------------------------------ */
/** @brief ludil string 
 *
 *  Is the string type for storing ludil strings
 *  This string type handles UTF-8 encoded counted strings
 */
/* ------------------------------------------------------------ */
typedef ludilBlob_t ludilString_t;

/* ------------------------------------------------------------ */
/** @brief ludil filepath string
 *
 *  Holds a filepath for accessing files on the operating system
 */
/* ------------------------------------------------------------ */
typedef const char *ludilPath_t;
/*@}*/

/*@}*/

/* type macros */
#define LUDIL_PTR_NULL  NULL

/* print macros */
# if __WORDSIZE == 64
#   define PRI_L_SIZE "lu"
# else 
#   define PRI_L_SIZE "llu"
# endif

#define PRI_L_OFFSET PRI_L_SIZE

#endif
