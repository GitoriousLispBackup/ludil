#include <ludilTypes.h>


/* ------------------------------------------------------------ */
/** @file ludilType.h
 *  @author Josef P. Bernhart
 *  @date 27-12-2010
 *
 *  This file contains all the operations which can be operated
 *  on a ludilType, which is a meta type. It describes what 
 *  a specific piece of data is for a data. 
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
  ludilTypeExtendRange      = 8000,
  ludilTypeFileRange        = 9000
} ludilType_t;

