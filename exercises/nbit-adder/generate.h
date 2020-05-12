// generate random values for testing

#include "systemc.h"
#include <cstdlib>
#include <stdio.h>
#include <ctime>

SC_MODULE(generate){

	sc_vector<sc_out<bool>> x,y;
	sc_in<bool> clk;
	int r1,r2;
	void signal_generate(){

		srand((unsigned) time(0));
		wait(10,SC_NS);

		// Generates random values
		for(int i = 0; i < 8; i++){
			x[i] =  rand() % 2;
			y[i] =  rand() % 2;
		}
	}

	SC_CTOR(generate) : x("x_value", 8), y("y_value", 8){
		
		SC_THREAD(signal_generate);
		sensitive << clk.pos();
	}
};
