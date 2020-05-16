// Grayscaler.h
// Author: Fabian Garber	
#pragma once // fixed redefiniton error
#include "systemc.h"
#include "grayscaler_channel_if.h"

SC_MODULE(grayscaler){
	
	sc_in<bool> clk;
	sc_port<grayscaler_channel_read_if> colorInput;
	sc_port<grayscaler_channel_write_if> grayOutput;

	// calculate the grayscale value and save it to grayValue
	void color_to_gray(){


		sc_uint<8> red   = 0;
		sc_uint<8> green = 0;
		sc_uint<8> blue  = 0;
		colorInput->ch_read(red,green,blue);
		
		sc_uint<8> grayValue = (sc_uint<8>) ((red>>2)+(red>>5)+(green>>1)+(green>>4)+(blue>>4)+(blue>>5));

		grayOutput->ch_write(grayValue, grayValue, grayValue);

	}

	SC_CTOR(grayscaler){
		SC_METHOD(color_to_gray);
		sensitive << clk.pos();
	}
};
