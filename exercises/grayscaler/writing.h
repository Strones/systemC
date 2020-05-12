// writing.h
#include "systemc.h"
#include "bitmap_image.hpp"
#include <stdio.h>


SC_MODULE(bmp_writer){
	sc_in<sc_uint<8>> gray_red, gray_green, gray_blue;
	sc_out<sc_uint<8>> red, green, blue;
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
				red.write(color.red);
				green.write(color.green);
				blue.write(color.blue);

				// Wait for the grayscaler to do the work
				wait(1,SC_NS);

				// Save the grayscaled pixels, pixel by pixel and save it in color_new
				rgb_t color_new;
				color_new.red = gray_red.read();
				color_new.green = gray_green.read();
				color_new.blue = gray_blue.read();
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
