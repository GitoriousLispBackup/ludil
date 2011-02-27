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

#include <ludilTypes.h>
#include <SDL/SDL.h>

typedef enum 
{
    CommandLineInterface,
    GraphicalUserInterface,
    GraphicalHUDInterface
} ludilShellInterface_t;

typedef enum
{
    None,
    Started,
    Stopped
} ludilShellState_t;

typedef struct
{
    ludilShellInterface_t      interface;
    ludilShellState_t          state;

} ludilShell_s;

typedef ludilShell_s *ludilShell_t;

/* ------------------------------------------------------------ */
/** 
 * 
 * Starts a shell
 *
 */
/* ------------------------------------------------------------ */
ludilBool_t ludilShellStart (ludilShell_t p_shell);

/* ------------------------------------------------------------ */
/** 
 * 
 * Stops a shell 
 *
 */
/* ------------------------------------------------------------ */
ludilBool_t ludilShellStop (ludilShell_t  p_shell);

/* ------------------------------------------------------------ */
/** 
 * 
 * Changes the interface of a shell, works also while the shell
 * is running. Then the shell is updated in realtime.
 *
 */
/* ------------------------------------------------------------ */
ludilBool_t ludilShellSetInterface (ludilShell_t          p_shell, 
                                    ludilShellInterface_t p_interface);
