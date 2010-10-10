#ifndef RAMBO_TYPES_H
#define RAMBO_TYPES_H

#include <stddef.h>
#include <stdint.h>

/* signed integer types */
typedef int8_t  ramboInt8_t;
typedef int16_t ramboInt16_t;
typedef int32_t ramboInt32_t;
typedef int64_t ramboInt64_t;

/* unsigned integer types */
typedef uint8_t  ramboUInt8_t;
typedef uint16_t ramboUInt16_t;
typedef uint32_t ramboUInt32_t;
typedef uint64_t ramboUInt64_t;

typedef ramboUInt8_t ramboByte_t;

/* abstract integer types */
typedef size_t ramboSize_t;

/* internal string type */
typedef char * ramboInternalString_t;     /* a internal string is a string which is only used by rambo */

/* filepath string */
typedef const char * ramboPath_t;

/* array types */
typedef ramboByte_t ramboData_t[1];

/* pointer types */
typedef void * ramboPtr_t;

typedef ramboUInt8_t *ramboPtrUInt8_t;
typedef ramboUInt16_t *ramboPtrUInt16_t;
typedef ramboUInt32_t *ramboPtrUInt32_t;
typedef ramboUInt64_t *ramboPtrUInt64_t;

typedef ramboInt8_t *ramboPtrInt8_t;
typedef ramboInt16_t *ramboPtrInt16_t;
typedef ramboInt32_t *ramboPtrInt32_t;
typedef ramboInt64_t *ramboPtrInt64_t;

typedef ramboSize_t *ramboPtrSize_t;
typedef ramboInternalString_t *ramboPtrInternalString_t;


/* reference types */
typedef unsigned int ramboId_t;     /* an id, can be used as a reference  */

/* boolean type */
typedef unsigned int ramboBool_t;

#define TRUE  1
#define FALSE 0 

/* enumeration integer types */
typedef enum 
{
  ramboTypeBasicRange       = 0,
  ramboTypeNone,
  ramboTypeInt8,
  ramboTypeInt16,
  ramboTypeInt32,
  ramboTypeInt64,

  ramboTypeUInt8,
  ramboTypeUInt16,
  ramboTypeUInt32,
  ramboTypeUInt64,
  
  ramboTypeByte,

  ramboTypeSize,

  ramboTypeString,
  ramboTypeInternalString,
  ramboTypePath,

  ramboTypeData,
  ramboTypeBlob,

  ramboTypeBool,
  ramboTypeObject, 
  ramboTypeId,
  ramboTypePtr,
  ramboType,

  ramboTypeSoundRange       = 100,
  ramboTypeNetRange         = 200,
  ramboTypeVideoRange       = 300,
  ramboTypeInputRange       = 400,
  ramboTypeOutputRange      = 500,
  ramboTypeImageRange       = 600,
  ramboTypeSignalRange      = 700,
  ramboTypeExtendRange      = 800,
  ramboTypeFileRange        = 900
} ramboType_t;

/* structure types */

/* general object */
typedef struct
{
  ramboId_t     id;         /* id of data */
  ramboType_t   type;       /* type of data */
  ramboPtr_t    pointer;    /* pointer to contained data */
} ramboObject_t;

typedef ramboObject_t *ramboRef_t;  

/* array types */
typedef struct 
{
  ramboSize_t     size;
  ramboData_t     data;
} ramboBlob_t;

typedef ramboBlob_t ramboString_t;


/* type macros */
#define RAMBO_PTR_NULL  NULL

#endif
