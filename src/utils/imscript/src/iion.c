#include <stdio.h> // only for "fprintf"
#include <stdlib.h> // only for "free"
#include <stdint.h>
#include "iio.h"

// read an image in any format from STDIN and write a ppm to STDOUT
int main_iion(int c, char *v[])
{
	if (c != 3)
		return fprintf(stderr, "usage:\n\t%s infile outfile\n", *v);
	//                                         0 1      2
	char *filename_in = v[1];
	char *filename_out = v[2];
	int w, h, pd;
	float *x = iio_read_image_float_vec(filename_in, &w, &h, &pd);
	if (!x)
		return fprintf(stderr, "cannot image \"%s\"\n", filename_in);
	iio_write_image_float_vec(filename_out, x, w, h, pd);
	free(x);
	return 0;
}
#ifndef HIDE_ALL_MAINS
int main(int c, char **v) { return main_iion(c, v); }
#endif
