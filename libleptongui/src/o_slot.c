/* Lepton EDA Schematic Capture
 * Copyright (C) 1998-2010 Ales Hvezda
 * Copyright (C) 1998-2016 gEDA Contributors
 * Copyright (C) 2017-2024 Lepton EDA Contributors
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#include <config.h>

#include <stdio.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include "schematic.h"

#define MAX_SLOT_SIZE 10


/*! \todo Finish function documentation!!!
 *  \brief
 *  \par Function Description
 *
 */
void
o_slot_end (SchematicWindow *w_current,
            LeptonObject *object,
            const char *string)
{
  LeptonObject *new_obj;
  char *slot_value;
  char *numslots_value;
  LeptonObject *o_slot;
  char *value = NULL;
  int numslots;
  int new_slot_number;
  int status;

  g_return_if_fail (object != NULL);

  LeptonPage *active_page = schematic_window_get_active_page (w_current);

  status = o_attrib_string_get_name_value (string, NULL, &value);
  if (!status) {
    g_message (_("Slot attribute malformed"));
    return;
  }

  numslots_value =
    o_attrib_search_object_attribs_by_name (object, "numslots", 0);

  if (!numslots_value) {
    g_message (_("numslots attribute missing"));
    g_message (_("Slotting not allowed for this component"));
    g_free (value);
    return;
  }

  numslots = atoi (numslots_value);
  g_free (numslots_value);

  new_slot_number = atoi (value);

#if DEBUG
  printf ("numslots = %d\n", numslots);
#endif

  if (new_slot_number > numslots || new_slot_number <=0 ) {
    g_message (_("New slot number out of range"));
    g_free (value);
    return;
  }

  /* first see if slot attribute already exists outside
   * component */
  slot_value = lepton_slot_search (object, &o_slot);
  g_free (slot_value);

  if (o_slot != NULL && !o_attrib_is_inherited (o_slot)) {
    lepton_text_object_set_string (o_slot, string);
  } else {
    /* here you need to do the add the slot
       attribute since it doesn't exist */
    new_obj = lepton_text_object_new (ATTRIBUTE_COLOR,
                                      lepton_component_object_get_x (object),
                                      lepton_component_object_get_y (object),
                                      LOWER_LEFT,
                                      0, /* zero is angle */
                                      string,
                                      10,
                                      INVISIBLE,
                                      SHOW_NAME_VALUE);
    lepton_page_append (active_page, new_obj);

    /* manually attach attribute */
    o_attrib_attach (new_obj, object, FALSE);

    /* Call add-objects-hook */
    g_run_hook_object (w_current, "add-objects-hook", new_obj);
  }

  lepton_slot_update_object (object);

  schematic_window_active_page_changed (w_current);
  g_free (value);
}
