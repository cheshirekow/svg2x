/* svg2eps  convert an svg image to an eps image
 *
 * Copyright (c) 2005 Red Hat, Inc.
 * Copyright (c) 2006 Red Hat, Inc.
 * Copyright (c) 2007 Red Hat, Inc.
 * Copyright (c) 2012 Josh Bialkowski
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors: Kristian Høgsberg <krh@redhat.com>
 *	        Carl Worth <cworth@redhat.com>
 *	        Behdad Esfahbod <besfahbo@redhat.com>
 *	        Josh Biakowski <jbialk@mit.edu>
 *
 *  gcc `pkg-config --cflags --libs librsvg-2.0 cairo-pdf` -o svg2eps svg2eps.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <librsvg/rsvg.h>
#include <librsvg/rsvg-cairo.h>

#include <cairo-ps.h>

#define FAIL(msg)							\
    do { fprintf (stderr, "FAIL: %s\n", msg); exit (-1); } while (0)

#define PIXELS_PER_POINT 1


/**
 *  \brief  a simple program to convert svg files to eps files
 */
int main (int argc, char *argv[])
{
    GError *error = NULL;           //< result of rsvg operations
    RsvgHandle          *handle;    //< handle to rsvg document
    RsvgDimensionData   dim;        //< dimension of the svg document

    double      width, height;      //< dimensions of the output document

    const char *filename        = argv[1];  //< input filename
    const char *output_filename = argv[2];  //< output filename

    cairo_surface_t *surface;   //< the cairo surface we draw to
    cairo_t         *cr;        //< the cairo context
    cairo_status_t status;      //< sotres the result of cairo operations

    // if the user called the program with other than 2 arguments, we don't
    // know what to do, so just pring usage
    if (argc != 3)
	FAIL ("usage: svg2eps input_file.svg output_file.eps");

    // initialize the glib object library
    g_type_init ();

    // set the svg  defaultresolution
    rsvg_set_default_dpi (72.0);

    // open the svg file and get an rsvg handle to the opened file
    handle = rsvg_handle_new_from_file (filename, &error);

    // if we failed to open the file then print the error ad exit
    if (error != NULL)
        FAIL (error->message);

    // get the dimensions of the opened svg document
    rsvg_handle_get_dimensions (handle, &dim);

    // copy out the dimensions
    width   = dim.width;
    height  = dim.height;

    // create a post-script cairo surface to draw on
    surface = cairo_ps_surface_create (output_filename, width, height);

    // create a cairo context with that surface
    cr = cairo_create (surface);

    // tell rsvg to render the document into the cairo context
    rsvg_handle_render_cairo (handle, cr);

    // check the status of the context, i.e. see if there were errors
    status = cairo_status (cr);

    // if there were errors then print them to the console and quit
    if (status)
        FAIL (cairo_status_to_string (status));

    // clean up nicely
    cairo_destroy (cr);
    cairo_surface_destroy (surface);

    return 0;
}
