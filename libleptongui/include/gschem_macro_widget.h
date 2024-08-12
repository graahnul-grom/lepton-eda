/* Lepton EDA Schematic Capture
 * Copyright (C) 1998-2010 Ales Hvezda
 * Copyright (C) 1998-2013 gEDA Contributors
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
/*!
 * \file gschem_macro_widget.h
 *
 * \brief A widget for entering macros
 */

#ifndef LEPTON_MACRO_WIDGET_H_
#define LEPTON_MACRO_WIDGET_H_

/* Maximum number of items to keep in the
 * macro widget command history by default:
 */
#define MACRO_WIDGET_HISTORY_MAX 10



#define SCHEMATIC_TYPE_MACRO_WIDGET           (schematic_macro_widget_get_type())
#define SCHEMATIC_MACRO_WIDGET(obj)           (G_TYPE_CHECK_INSTANCE_CAST ((obj), SCHEMATIC_TYPE_MACRO_WIDGET, SchematicMacroWidget))
#define SCHEMATIC_MACRO_WIDGET_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST ((klass),  SCHEMATIC_TYPE_MACRO_WIDGET, SchematicMacroWidgetClass))
#define SCHEMATIC_IS_MACRO_WIDGET(obj)        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SCHEMATIC_TYPE_MACRO_WIDGET))
#define SCHEMATIC_MACRO_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SCHEMATIC_TYPE_MACRO_WIDGET, SchematicMacroWidgetClass))

typedef struct _SchematicMacroWidgetClass SchematicMacroWidgetClass;
typedef struct _SchematicMacroWidget SchematicMacroWidget;

struct _SchematicMacroWidgetClass
{
  GtkInfoBarClass parent_class;
};

struct _SchematicMacroWidget
{
  GtkInfoBar parent;

  /* command history: */
  GtkListStore* store;

  SchematicWindow* toplevel;

  GtkWidget *combo;
  GtkWidget *entry;
  GtkWidget *evaluate_button;
};



GtkWidget*
macro_widget_new (SchematicWindow* toplevel);

G_BEGIN_DECLS

void
macro_widget_show (GtkWidget* widget);

G_END_DECLS

GType
schematic_macro_widget_get_type();


#endif /* LEPTON_MACRO_WIDGET_H_ */
