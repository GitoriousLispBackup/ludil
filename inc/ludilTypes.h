#ifndef LUDIL_TYPES_H
#define LUDIL_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <ludilType.h>

/* ------------------------------------------------------------ */
/** @defgroup base
 *  @brief ludil base 
 *  Contains the basic functionality for other ludil extensions
 */
/* ------------------------------------------------------------ */

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
typedef uint8_t  ludilUInt8_t;
typedef uint16_t ludilUInt16_t;
typedef uint32_t ludilUInt32_t;
typedef uint64_t ludilUInt64_t;

typedef ludilUInt8_t ludilByte_t;
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
typedef ludilByte_t ludilData_t [1];
/*@}*/

/** @addtogroup ludil_ptrt pointer types */
/*@{*/
typedef char *ludilPtr_t;

typedef ludilUInt8_t *ludilPtrUInt8_t;
typedef ludilUInt16_t *ludilPtrUInt16_t;
typedef ludilUInt32_t *ludilPtrUInt32_t;
typedef ludilUInt64_t *ludilPtrUInt64_t;

typedef ludilInt8_t *ludilPtrInt8_t;
typedef ludilInt16_t *ludilPtrInt16_t;
typedef ludilInt32_t *ludilPtrInt32_t;
typedef ludilInt64_t *ludilPtrInt64_t;

typedef ludilSize_t *ludilPtrSize_t;
/*@}*/

/** @addtogroup ludil_reft reference types */
/*@{*/
typedef unsigned int ludilId_t;     
/*@}*/

/** ludil boolean type */
typedef enum 
{ 
  FALSE = 0, 
  UNSURE, 
  TRUE
} ludilBool_t;

#define SUCCESS TRUE
#define FAILURE FALSE
#define IS_TRUE(x) (x == TRUE)


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
  ludilSize_t     length;   /**< size of contained data */
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
