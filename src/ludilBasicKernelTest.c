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

#include <ludilKernel.h>
#include <stdio.h>

int 
main ()
{
  ludilEnv_t     *v_env    = NULL;
  ludilPlugin_t  *v_plugin = NULL;

  ludilKernelInit (&v_env);

  v_plugin = ludilKernelPluginLoad (v_env, "Test");
  printf ("v_plugin : %d\n", v_plugin);

  ludilKernelStart (v_env);
  ludilKernelStop (v_env);

  ludilKernelFree (&v_env);

  return 0;
}
