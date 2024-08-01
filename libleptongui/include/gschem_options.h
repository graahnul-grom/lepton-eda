/* Lepton EDA Schematic Capture
 * Copyright (C) 2013 Ales Hvezda
 * Copyright (C) 2013-2014 gEDA Contributors
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
 * \file gschem_options.h
 *
 * \brief
 */

/*! \brief The initial mode for magnetic nets
 *
 *  TRUE = enabled
 *  FALSE = disabled
 *
 *  Loading a configuration will overwrite this value
 */
#define DEFAULT_MAGNETIC_NET_MODE (TRUE)


/*! \brief The initial mode for rubber band nets
 *
 *  TRUE = enabled
 *  FALSE = disabled
 *
 *  Loading a configuration will overwrite this value
 */
#define DEFAULT_NET_RUBBER_BAND_MODE (TRUE)


/*! \brief The initial grid mode
 *
 *  This value will get replaced by user settings.
 */
#define DEFAULT_GRID_MODE (GRID_MODE_MESH)


/*! \brief The initial snap size
 *
 *  This value will get replaced by user settings.
 */
#define DEFAULT_SNAP_SIZE (100)


/*! \brief The maximum snap size, inclusive
 *
 *  An even power of two multiplied by 100 ensures the snap size does not get
 *  off track when the user scales to the limit.
 */
#define MAXIMUM_SNAP_SIZE (102400)


/*! \brief The minimum snap size, inclusive
 *
 *  A value of 5 might be better for the minimum. Using the spin widget can
 *  allow the snap size to get off track.
 */
#define MINIMUM_SNAP_SIZE (1)


#define SCHEMATIC_TYPE_OPTIONS           (schematic_options_get_type ())
#define SCHEMATIC_OPTIONS(obj)           (G_TYPE_CHECK_INSTANCE_CAST ((obj), SCHEMATIC_TYPE_OPTIONS, SchematicOptions))
#define SCHEMATIC_OPTIONS_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST ((klass),  SCHEMATIC_TYPE_OPTIONS, SchematicOptionsClass))
#define IS_SCHEMATIC_OPTIONS(obj)        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SCHEMATIC_TYPE_OPTIONS))
#define SCHEMATIC_OPTIONS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj),  SCHEMATIC_TYPE_OPTIONS, SchematicOptionsClass))

typedef struct _SchematicOptionsClass SchematicOptionsClass;
typedef struct _SchematicOptions SchematicOptions;

struct _SchematicOptionsClass {
  GObjectClass parent_class;
};

struct _SchematicOptions {
  GObject parent;

  int        grid_mode;
  gboolean   magnetic_net_mode;
  gboolean   net_rubber_band_mode;
  SchematicSnapMode snap_mode;
  int        snap_size;
};

G_BEGIN_DECLS

void
schematic_options_cycle_grid_mode (SchematicOptions *options);

void
schematic_options_cycle_magnetic_net_mode (SchematicOptions *options);

void
schematic_options_cycle_net_rubber_band_mode (SchematicOptions *options);

void
schematic_options_cycle_snap_mode (SchematicOptions *options);

SchematicGridMode
schematic_options_get_grid_mode (SchematicOptions *options);

gboolean
schematic_options_get_magnetic_net_mode (SchematicOptions *options);

gboolean
schematic_options_get_net_rubber_band_mode (SchematicOptions *options);

SchematicSnapMode
schematic_options_get_snap_mode (SchematicOptions *options);

int
schematic_options_get_snap_size (SchematicOptions *options);

GType
schematic_options_get_type ();

SchematicOptions*
schematic_options_new ();

void
schematic_options_set_grid_mode (SchematicOptions *options,
                                 SchematicGridMode grid_mode);
void
schematic_options_set_magnetic_net_mode (SchematicOptions *options,
                                         gboolean enabled);
void
schematic_options_set_net_rubber_band_mode (SchematicOptions *options,
                                            gboolean enabled);
void
gschem_options_set_snap_mode (SchematicOptions *options, SchematicSnapMode snap_mode);

void
gschem_options_set_snap_size (SchematicOptions *options, int snap_size);

G_END_DECLS
