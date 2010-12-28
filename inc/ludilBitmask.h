#include <ludilTypes.h>

/* ------------------------------------------------------------ */
/** @file ludilTypes.h 
 *  @author Josef P. Bernhart
 *  @date 28-12-2010
 *  @ingroup base
 *
 *  Bitmask handling library, bitmasks are all unsigned integers
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief gets bit from an uint8 bitmask
 *
 *  @param p_bitmask        @b [In] bitmask
 *  @param p_offset         @b [In] offset into bitmask
 *  
 *  @return
 *  TRUE if bit was set
 *  FALSE if wasn't set
 */
/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask8Get (ludilUInt8_t  p_bitmask,
                  ludilOffset_t p_offset);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief gets bit from an uint16 bitmask
 *
 *  @param p_bitmask        @b [In] bitmask
 *  @param p_offset         @b [In] offset into bitmask
 *
 *  @return
 *  TRUE if bit was set
 *  FALSE if wasn't set
 */
/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask16Get (ludilUInt16_t  p_bitmask,
                   ludilOffset_t p_offset);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief gets bit from an uint32 bitmask
 *
 *  @param p_bitmask        @b [In] bitmask
 *  @param p_offset         @b [In] offset into bitmask
 *
 *  @return
 *  TRUE if bit was set
 *  FALSE if wasn't set
 */
/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask32Get (ludilUInt32_t  p_bitmask,
                   ludilOffset_t p_offset);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief gets bit from an uint64 bitmask
 *
 *  @param p_bitmask        @b [In] bitmask
 *  @param p_offset         @b [In] offset into bitmask
 *
 *  @return
 *  TRUE if bit was set
 *  FALSE if wasn't set
 */
/* ------------------------------------------------------------ */
ludilBool_t
ludilBitmask64Get (ludilUInt64_t  p_bitmask,
                   ludilOffset_t p_offset);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief sets bit of an uint8 bitmask
 *
 *  @param p_bitmask        @b [In] bitmask
 *  @param p_offset         @b [In] offset into bitmask
 *
 *  @return
 *  TRUE if bit was set
 *  FALSE if wasn't set
 */
/* ------------------------------------------------------------ */
ludilUInt8_t
ludilBitmask8Set (ludilUInt8_t  p_bitmask,
                  ludilOffset_t p_offset);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief sets bit of an uint16 bitmask
 *
 *  @param p_bitmask        @b [In] bitmask
 *  @param p_offset         @b [In] offset into bitmask
 *
 *  @return
 *  TRUE if bit was set
 *  FALSE if wasn't set
 */
/* ------------------------------------------------------------ */
ludilUInt16_t
ludilBitmask16Set (ludilUInt16_t  p_bitmask,
                   ludilOffset_t p_offset);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief sets bit of an uint32 bitmask
 *
 *  @param p_bitmask        @b [In] bitmask
 *  @param p_offset         @b [In] offset into bitmask
 *
 *  @return
 *  TRUE if bit was set
 *  FALSE if wasn't set
 */
/* ------------------------------------------------------------ */
ludilUInt32_t
ludilBitmask32Set (ludilUInt32_t  p_bitmask,
                   ludilOffset_t p_offset);
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/** @brief sets bit of an uint64 bitmask
 *
 *  @param p_bitmask        @b [In] bitmask
 *  @param p_offset         @b [In] offset into bitmask
 *
 *  @return
 *  TRUE if bit was set
 *  FALSE if wasn't set
 */
/* ------------------------------------------------------------ */
ludilUInt64_t
ludilBitmask64Set (ludilUInt64_t  p_bitmask,
                   ludilOffset_t p_offset);
/* ------------------------------------------------------------ */
