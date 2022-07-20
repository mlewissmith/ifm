/* Plot output format header */

#ifndef IFM_PLOT_H
#define IFM_PLOT_H

#include "ifm-format.h"

extern mapfuncs plot_mapfuncs;

extern void plot_map_start(void);
extern void plot_map_section(vhash *sect);
extern void plot_map_room(vhash *room);
extern void plot_map_link(vhash *link);
extern void plot_map_endsection(void);
extern void plot_map_finish(void);

#endif
