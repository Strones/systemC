// main.cpp
/*
 *****************************************************************************
 *                                                                           *
 *                          Platform Independent                             *
 *                    Bitmap Image Reader Writer Library                     *
 *                                                                           *
 * Author: Arash Partow - 2002                                               *
 * URL: http://partow.net/programming/bitmap/index.html                      *
 *                                                                           *
 * Note: This library only supports 24-bits per pixel bitmap format files.   *
 *                                                                           *
 * Copyright notice:                                                         *
 * Free use of the Platform Independent Bitmap Image Reader Writer Library   *
 * is permitted under the guidelines and in accordance with the most current *
 * version of the MIT License.                                               *
 * http://www.opensource.org/licenses/MIT                                    *
 *                                                                           *
 *****************************************************************************
*/

#include "systemc.h"
#include "bitmap_image.hpp"
#include "grayscaler.h"
#include "writing.h"


int sc_main(int argc, char* argv[]){
	sc_clock clk("CLK",1, SC_NS, 0.5);
	sc_signal<sc_uint<8>> red, green, blue, gray_red, gray_green, gray_blue;
	bitmap_image image("test.bmp");

	if(!image){
		return -1;
	}

	grayscaler grayscaler_1 ("Grayscaler_1");
	bmp_writer  writer ("Writer_1", image);

	grayscaler_1.clk          (clk);

	// Connect writer with grayscale input, to get pixels from bitmap
	writer.red                (red);
	writer.green              (green);
	writer.blue               (blue);

	grayscaler_1.red          (red);
	grayscaler_1.green        (green);
	grayscaler_1.blue         (blue);

	grayscaler_1.gray_red     (gray_red);
	grayscaler_1.gray_green   (gray_green);
	grayscaler_1.gray_blue    (gray_blue);

	// Connect grayscale output with writer input to save pixels
	writer.gray_red           (gray_red);
	writer.gray_green         (gray_green);
	writer.gray_blue          (gray_blue);

	sc_start();

	return 0;
}

