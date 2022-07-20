/* Plot output format */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <vars.h>
#include <plot.h>

#include "ifm-format.h"
#include "ifm-main.h"
#include "ifm-map.h"
#include "ifm-plot.h"
#include "ifm-util.h"
#include "ifm-vars.h"

/* Map function list */
mapfuncs plot_mapfuncs = {
    plot_map_start,
    plot_map_section,
    plot_map_room,
    plot_map_link,
    NULL,
    NULL,
    plot_map_finish
};

/* Internal functions */

/* Map functions */
void
plot_map_start(void)
{
    /* TODO: write me */
}

void
plot_map_section(vhash *sect)
{
    /* TODO: write me */
}

void
plot_map_room(vhash *room)
{
    /* TODO: write me */
}

void
plot_map_link(vhash *link)
{
    /* TODO: write me */
}

void
plot_map_finish(void)
{
    /* TODO: write me */
}
