/*! \brief different kind of snapping mechanisms used in LeptonToplevel */
typedef enum {SNAP_OFF, SNAP_GRID, SNAP_RESNAP, SNAP_STATE_COUNT} SNAP_STATE;

typedef struct st_stretch STRETCH;

struct st_stretch
{
  LeptonObject *object;
  int whichone;
};
