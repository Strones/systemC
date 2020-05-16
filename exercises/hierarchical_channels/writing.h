// writing.h
#pragma once // fixed redefiniton error
#include "systemc.h"
#include "bitmap_image.hpp"
#include <stdio.h>
#include "grayscaler_channel_if.h"


SC_MODULE(bmp_writer){
	
	sc_port<grayscaler_channel_read_if> grayInput;
	sc_port<grayscaler_channel_write_if> colorOutput;
	bitmap_image img;

	void writing(){
		const unsigned int height = img.height();
		const unsigned int width = img.width();

		for(int i=0; i<height; i++){
			for(int j=0; j < width; j++){
				// Create rgb_t structure to save the pixel
				rgb_t color;
				// Get the pixel form the imge and Save pixel by pixel in struct color
				img.get_pixel(j,i,color);
				colorOutput->ch_write((sc_uint<8>)color.red, (sc_uint<8>)color.green, (sc_uint<8>)color.blue);

				// Wait for the grayscaler to do the work
				wait(1,SC_NS);

				// Save the grayscaled pixels, pixel by pixel and save it in color_new
				rgb_t color_new;
				sc_uint<8> red   = 0;
				sc_uint<8> green = 0;
				sc_uint<8> blue  = 0;

				grayInput->ch_read(red,green,blue);
				color_new.red   = (unsigned char) red;
				color_new.green = (unsigned char) green;
				color_new.blue  = (unsigned char) blue;
				img.set_pixel(j,i,color_new);
			}
		}

		// save the new image
		img.save_image("bmp_gray.bmp");
		cout << "Grayscale completed!" << endl;
		sc_stop();

	}

	// register process because SCTOR is not used
	SC_HAS_PROCESS(bmp_writer);

	bmp_writer(sc_module_name name, bitmap_image image){
		this->img = image;
		SC_THREAD(writing);
	}

};
