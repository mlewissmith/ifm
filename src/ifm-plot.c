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

/* Current plotter */
static plPlotter *plotter;

/* Internal functions */
static void draw_plot(void);

/* Map functions */
void
plot_map_start(void)
{
    /* Set plot parameters */
    plPlotterParams *params = pl_newplparams();
    pl_setplparam(params, "PAGESIZE", "a4");

    /* Create a plotter */
    if ((plotter = pl_newpl_r("ps", stdin, stdout, stderr, params)) == NULL)
        v_die("can't create plotter");

    if (pl_openpl_r(plotter) < 0)
        v_die("can't open plotter");

    draw_plot();
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
    /* Finalize plot */
    if (pl_closepl_r(plotter) < 0)
        v_die("can't close plotter");

    if (pl_deletepl_r(plotter) < 0)
        v_die("can't delete plotter");
}

/* Demo plot */

#define SIZE 100.0   /* nominal size of user coordinate frame */
#define EXPAND 2.2   /* expansion factor for elliptical box */

static void
draw_boxed_string(char *s, double size, double angle)
{
    double true_size, width;

    pl_ftextangle_r(plotter, angle);      /* set text angle (degrees) */
    true_size = pl_ffontsize_r(plotter, size);  /* set font size */
    width = pl_flabelwidth_r(plotter, s); /* compute width of string */
    pl_fellipserel_r(plotter, 0.0, 0.0,
                     EXPAND * 0.5 * width, EXPAND * 0.5 * true_size,
                     angle);              /* draw surrounding ellipse */
    pl_alabel_r(plotter, 'c', 'c', s);    /* draw centered text string */
}

static void
draw_plot(void)
{
    /* Specify user coor system */
    pl_fspace_r(plotter, -(SIZE), -(SIZE), SIZE, SIZE);
    pl_pencolorname_r(plotter, "blue");     /* use blue pen */
    pl_fillcolorname_r(plotter, "yellow");   /* set white fill color */
    pl_filltype_r(plotter, 1);   /* fill ellipses with fill color */

    /* Choose a Postscript font */
    pl_fontname_r(plotter, "NewCenturySchlbk-Roman");

    for (int i = 80; i > 1; i--) {
        double theta, radius;

        theta = 0.5 *(double)i;  /* theta is in radians */
        radius = SIZE / pow(theta, 0.35);  /* this yields a spiral */
        pl_fmove_r(plotter, radius * cos(theta), radius * sin(theta));
        draw_boxed_string("GNU libplot!", 0.04 * radius,
                          (180.0 * theta / M_PI) - 90.0);
    }
}
