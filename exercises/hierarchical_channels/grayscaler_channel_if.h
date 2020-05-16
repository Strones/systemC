// further details at doulos.com/knowhow/systemc/tutorial/hierarchical_channels
#pragma once // fixed redefiniton error
#include "systemc.h"

class            grayscaler_channel_write_if: virtual public sc_interface{
	public:
		virtual bool ch_write(sc_uint<8> red, sc_uint<8> green, sc_uint<8> blue) = 0;
};


class grayscaler_channel_read_if: virtual public sc_interface{
	public: 
		virtual bool ch_read(sc_uint<8>& red, sc_uint<8>& green, sc_uint<8>& blue) = 0;
};

