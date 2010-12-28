#include <ludilBitmask.h>


/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask8Get (ludilUInt8_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  if ((sizeof (p_bitmask)*8) > p_offset)
  {
    if ((1 << (p_offset)) & p_bitmask)
      return TRUE;
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask16Get (ludilUInt16_t  p_bitmask,
                   ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  if ((sizeof (p_bitmask)*8) > p_offset)
  {
    if ((1 << (p_offset)) & p_bitmask)
      return TRUE;
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask32Get (ludilUInt32_t  p_bitmask,
                   ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  if ((sizeof (p_bitmask)*8) > p_offset)
  {
    if ((1 << (p_offset)) & p_bitmask)
      return TRUE;
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask64Get (ludilUInt64_t  p_bitmask,
                   ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{

  if ((sizeof (p_bitmask)*8) > p_offset)
  {
    if ((1 << (p_offset)) & p_bitmask)
      return TRUE;
  }
  return FALSE;
}

/* ------------------------------------------------------------ */
ludilUInt8_t
ludilBitmask8Set (ludilUInt8_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  ludilUInt8_t  v_mask = p_bitmask;

  if ((sizeof (p_bitmask)*8) > p_offset)
    v_mask = ((1 << p_offset) | p_bitmask);

  return v_mask;
}

/* ------------------------------------------------------------ */
ludilUInt16_t
ludilBitmask16Set (ludilUInt16_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  ludilUInt16_t  v_mask = p_bitmask;

  if ((sizeof (p_bitmask)*8) > p_offset)
    v_mask = ((1 << p_offset) | p_bitmask);

  return v_mask;
}

/* ------------------------------------------------------------ */
ludilUInt32_t
ludilBitmask32Set (ludilUInt32_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  ludilUInt32_t  v_mask = p_bitmask;

  if ((sizeof (p_bitmask)*8) > p_offset)
    v_mask = ((1 << p_offset) | p_bitmask);

  return v_mask;
}

/* ------------------------------------------------------------ */
ludilUInt64_t
ludilBitmask64Set (ludilUInt64_t  p_bitmask,
                  ludilOffset_t p_offset)
/* ------------------------------------------------------------ */
{
  ludilUInt64_t  v_mask = p_bitmask;

  if ((sizeof (p_bitmask)*8) > p_offset)
    v_mask = ((1 << p_offset) | p_bitmask);

  return v_mask;
}
