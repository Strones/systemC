// Author: Fabian Garber
#include "systemc.h"
#include "grayscaler_channel.h"
#include "grayscaler.h"
#include "bitmap_image.hpp"
#include "writing.h"

int sc_main(int agrc, char* argv[]){
	bitmap_image image("test.bmp");


	grayscaler grayscaler1            ("GREY1");
	bmp_writer  writer1               ("WRITER1", image);
  
	grayscaler_channel channel1       ("CH1");
	grayscaler_channel channel2       ("CH2");
	
	sc_clock clk("CLK", 1, SC_NS, 0.5);

	grayscaler1.clk (clk);

	writer1.colorOutput     (channel1);
	grayscaler1.colorInput  (channel1);

	grayscaler1.grayOutput  (channel2);
	writer1.grayInput       (channel2);
	
	sc_start();

	return 0;

}
