// more info at doulos.com/knowhow/systemc/tutorial/hierarchical_channels
#pragma once // fixed redefiniton error
#include "systemc.h"
#include "grayscaler_channel_if.h"

// this class implements the virtual functions in the interface
class grayscaler_channel
: public sc_module, public grayscaler_channel_write_if, public grayscaler_channel_read_if {

private:
	sc_uint<8> redData;
	sc_uint<8> greenData;
	sc_uint<8> blueData;

public:
  // constructor
	grayscaler_channel(sc_module_name nm): sc_module(nm), redData(0), greenData(0), blueData(0){

	}

	bool ch_write(sc_uint<8> red, sc_uint<8> green, sc_uint<8> blue){
		redData   = red;
		greenData = green;
		blueData  = blue;
		// after successfull writing return true
		return true;
	}


	bool ch_read(sc_uint<8>& red, sc_uint<8>& green, sc_uint<8>& blue){
		red   = redData;
		green = greenData;
		blue  = blueData;
		// after successfull reading return true
		return true;
	}
			
};
