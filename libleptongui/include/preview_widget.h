/* Lepton EDA Schematic Capture
 * Copyright (C) 1998-2010 Ales Hvezda
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
/*!
 *  \file preview_widget.h
 *
 *  \brief A widget for viewing a symbol or schematic
 */

#define SCHEMATIC_TYPE_PREVIEW           (schematic_preview_get_type())
#define SCHEMATIC_PREVIEW(obj)           (G_TYPE_CHECK_INSTANCE_CAST ((obj), SCHEMATIC_TYPE_PREVIEW, SchematicPreview))
#define SCHEMATIC_PREVIEW_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST ((klass),  SCHEMATIC_TYPE_PREVIEW, SchematicPreviewClass))
#define SCHEMATIC_IS_PREVIEW(obj)        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SCHEMATIC_TYPE_PREVIEW))
#define SCHEMATIC_PREVIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SCHEMATIC_TYPE_PREVIEW, SchematicPreviewClass))

typedef struct _SchematicPreviewClass SchematicPreviewClass;
typedef struct _SchematicPreview      SchematicPreview;

struct _SchematicPreviewClass
{
  GschemPageViewClass parent_class;
};

struct _SchematicPreview
{
  GschemPageView parent_instance;

  GschemToplevel *window;

  gchar *filename;
  gchar *buffer;

  gboolean active;
};

GType
schematic_preview_get_type (void);

GtkWidget*
schematic_preview_new ();

G_BEGIN_DECLS

gboolean
preview_callback_button_press (GtkWidget *widget,
                               GdkEventButton *event,
                               gpointer user_data);
void
schematic_preview_callback_realize (GtkWidget *widget,
                                    gpointer user_data);
gboolean
preview_event_scroll (GtkWidget *widget,
                      GdkEventScroll *event,
                      GschemToplevel *w_current);
GschemToplevel*
schematic_preview_get_preview_w_current (GtkWidget *preview);

G_END_DECLS