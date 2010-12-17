#ifndef LUDIL_TYPES_H
#define LUDIL_TYPES_H

#include <stddef.h>
#include <stdint.h>

/* signed integer types */
typedef int8_t  ludilInt8_t;
typedef int16_t ludilInt16_t;
typedef int32_t ludilInt32_t;
typedef int64_t ludilInt64_t;

/* unsigned integer types */
typedef uint8_t  ludilUInt8_t;
typedef uint16_t ludilUInt16_t;
typedef uint32_t ludilUInt32_t;
typedef uint64_t ludilUInt64_t;

typedef ludilUInt8_t ludilByte_t;

/* abstract integer types */
typedef size_t ludilSize_t;

/* internal string type */
typedef char * ludilInternalString_t;     /* a internal string is a string which is only used by ludil */

/* filepath string */
typedef const char * ludilPath_t;

/* array types */
typedef ludilByte_t ludilData_t[1];

/* pointer types */
typedef void * ludilPtr_t;

typedef ludilUInt8_t *ludilPtrUInt8_t;
typedef ludilUInt16_t *ludilPtrUInt16_t;
typedef ludilUInt32_t *ludilPtrUInt32_t;
typedef ludilUInt64_t *ludilPtrUInt64_t;

typedef ludilInt8_t *ludilPtrInt8_t;
typedef ludilInt16_t *ludilPtrInt16_t;
typedef ludilInt32_t *ludilPtrInt32_t;
typedef ludilInt64_t *ludilPtrInt64_t;

typedef ludilSize_t *ludilPtrSize_t;
typedef ludilInternalString_t *ludilPtrInternalString_t;


/* reference types */
typedef unsigned int ludilId_t;     /* an id, can be used as a reference  */

/* boolean type */
typedef unsigned int ludilBool_t;

#define TRUE  1
#define FALSE 0 

/* enumeration integer types */
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

  ludilTypeSoundRange       = 100,
  ludilTypeNetRange         = 200,
  ludilTypeVideoRange       = 300,
  ludilTypeInputRange       = 400,
  ludilTypeOutputRange      = 500,
  ludilTypeImageRange       = 600,
  ludilTypeSignalRange      = 700,
  ludilTypeExtendRange      = 800,
  ludilTypeFileRange        = 900
} ludilType_t;

/* structure types */

/* general object */
typedef struct
{
  ludilId_t     id;         /* id of data */
  ludilType_t   type;       /* type of data */
  ludilPtr_t    pointer;    /* pointer to contained data */
} ludilObject_t;

typedef ludilObject_t *ludilRef_t;  

/* array types */
typedef struct 
{
  ludilSize_t     size;
  ludilData_t     data;
} ludilBlob_t;

typedef ludilBlob_t ludilString_t;


/* type macros */
#define LUDIL_PTR_NULL  NULL

#endif
