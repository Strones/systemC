#include "half_adder.h"
#include "testbench.h"

int sc_main (int argc, char *argj[]){
	
	// Setting up new signals
	sc_signal <sc_logic> m_x, m_y;
	sc_signal <sc_logic> m_c, m_s;

	sc_clock m_clk("tb_clock", 10, SC_NS, 0.5);
	
	// Creating half-adder
	half_adder HA ("half-adder");

	// Adding signals to HA
	HA.x (m_x);
	HA.y (m_y);
	HA.c (m_c);
	HA.s (m_s);


	// Verification
	// Setting up TB
	testbench tb ("tb");
	tb.x      (m_x);
	tb.y      (m_y);
	tb.carry   (m_c);
	tb.sum    (m_s);
	tb.clk    (m_clk);

	
	//Creating .vcd file and adding data to it
	sc_trace_file *trace = sc_create_vcd_trace_file ("HALFADDER");

	sc_trace (trace, m_x, "x");
	sc_trace (trace, m_y, "y");
	sc_trace (trace, m_s, "sum");
	sc_trace (trace, m_c, "carry");
	sc_trace (trace, m_clk, "clk");

	sc_start(); // Start the simulation

	sc_close_vcd_trace_file(trace);


	return 0;

}
