/* Lepton EDA library - Scheme API
 * Copyright (C) 2010-2013 Peter Brett <peter@peter-b.co.uk>
 * Copyright (C) 2010-2016 gEDA Contributors
 * Copyright (C) 2017-2021 Lepton EDA Contributors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/*!
 * \file scheme_init.c
 * \brief Scheme API initialisation
 */
#include <config.h>

#include "liblepton_priv.h"
#include "libleptonguile_priv.h"

/*! Non-zero if the Scheme API has been initialised. */
static gsize init_called = 0;

SCM_GLOBAL_SYMBOL (edascm_object_state_sym, "object-state");

/*! \brief Scheme API initialisation worker function.
 * \par Function Description
 * Called by edascm_init() with current thread in Guile mode.
 */
static void *
edascm_init_impl (void *data)
{
  #include "scheme_init.x"

  scm_setlocale (scm_variable_ref (scm_c_lookup ("LC_ALL")),
                 SCM_UNDEFINED);
  edascm_init_smob ();
  edascm_init_toplevel ();
  edascm_init_component ();
  edascm_init_page ();
  edascm_init_attrib ();
  edascm_init_config ();
  edascm_init_closure ();
  edascm_init_rc ();
  return NULL;
}

/*! \brief Initialise the Scheme API.
 * \ingroup guile_c_iface
 * \par Function Description
 * Registers all modules, procedures and variables exported by the
 * libgeda Scheme API.
 */
void
edascm_init ()
{
  if (g_once_init_enter (&init_called)) {
    scm_with_guile (edascm_init_impl, NULL);
    g_once_init_leave (&init_called, 1);
  }
}
