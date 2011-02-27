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

#ifndef LUDIL_EVENT_H
#define LUDIL_EVENT_H

#include <ludilTypes.h>

/* ------------------------------------------------------------ */
/** @file ludilEvent.h 
 *  @author Josef P. Bernhart
 *  @date 31-01-2011
 *  @ingroup base
 *
 *  Event procedures
 */
/* ------------------------------------------------------------ */
typedef enum
{
  EXCEPTION,      /**< is a special signal for unexpected situations, which need to be fixed by the system  */
  ERROR,          /**< is a special signal, which causes the exiting of the application,
                       to handle a situation, which couldn't be handled by the exception handler */
  SIGNAL          /**< is used for signals, which were raised,
                       signals are special events, for triggering some kind of action */
} ludilEventGroup_t;

/* ------------------------------------------------------------ */
/** @brief event type
 *
 */
/* ------------------------------------------------------------ */
typedef struct
{
  ludilEventGroup_t     group;      /**< event group of event */
  ludilId_t             eventId;    /**< id of event, an 'unique' identifier for each event */
  ludilRef_t            ref;        /**< reference to additional data */
} ludilEvent_t;

/* ------------------------------------------------------------ */
/** @brief event queue type
 * 
 */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */

#endif
