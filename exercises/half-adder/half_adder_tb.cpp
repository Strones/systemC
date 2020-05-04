#include "half_adder.h"

SC_MODULE (driver)
{
	sc_out <bool> d_a, d_b;

	void my_process() // Behavior of modules specified by processes
	{
		sc_uint<2> combo; // 2 bit length
		combo = 0; // combinations for half adder (4)

		while(1)
		{
			d_a = combo[0]; // Set the first bits
			d_b = combo[1];

			wait(1, SC_NS);  // loop must contain callof wait, otherwise -> endless loop

			combo++; // Set the next bits

			if(combo == 0){  // After all combinations -> stop
				sc_stop();
			} 
		}
	}

	SC_CTOR(driver) // Constructor
	{
		SC_THREAD (my_process); // Call of above process
	}
};

int sc_main (int argc, char *argj[]){
	
	// Setting up new signals
	sc_signal <bool> m_x, m_y;
	sc_signal <bool> m_c, m_s;
	
	// Creating a driver
	driver DRIVER ("driver_half_adder");
	
	// Adding signals to the driver
	DRIVER.d_a (m_x);
	DRIVER.d_b (m_y);

	// Creating half-adder
	half_adder HA ("half-adder");
	
	// Adding signals to HA
	HA.x (m_x);
	HA.y (m_y);
	HA.c (m_c);
	HA.s (m_s);
	
	//Creating .vcd file and adding data to it
	sc_trace_file *trace = sc_create_vcd_trace_file ("HALFADDER");


	sc_trace (trace, m_x, "x");
	sc_trace (trace, m_y, "y");
	sc_trace (trace, m_s, "sum");
	sc_trace (trace, m_c, "carry");

	sc_start(); // Start the simulation

	sc_close_vcd_trace_file(trace);

	return 0;

}
