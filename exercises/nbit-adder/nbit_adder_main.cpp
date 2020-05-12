#include "systemc.h"
#include "nbit_adder.h"
#include "generate.h"
#include <stdio.h>
#include "assertions.h"
#include "monitor.h"


int sc_main (int argc, char* argv[]){


	cout<<""<<endl;
	cout<<""<<endl;
	cout << "--------------------------------------------------------------" << endl;

	sc_vector<sc_signal<bool>> x("x_signals", 8), y("y_signals", 8), sum("sum_signals", 8);
	sc_signal<bool> co;
	sc_clock tb_clk("tb_clk", 10, SC_NS, 0.5);

	// Assertion
	assertions assertion("Assertion");
	for(int i = 0; i < 8; i++){
		assertion.x[i]   (x[i]);
		assertion.y[i]   (y[i]);
		assertion.sum[i] (sum[i]);	
	}
	assertion.clk (tb_clk);
	assertion.carry (co);
	
	// Generate inputs
	generate gen1("gen1_inputs");
	for(int i = 0; i < 8; i++){
			gen1.x[i] (x[i]);
			gen1.y[i] (y[i]);
	}

	gen1.clk (tb_clk);
	
	// Monitor generated values
	monitor monitor1("monitor_1");
	monitor1.clk (tb_clk);
	for(int i = 0; i < 8; i++){
		monitor1.x[i] (x[i]);
		monitor1.y[i] (y[i]);
	}
	

	// Creating Nbit_Adder module
	nbit_adder nbitadder ("8bitadder", 8);
	nbitadder.clk (tb_clk);
	for (int i = 0; i < 8; i++){
		nbitadder.x[i]       (x[i]);
		nbitadder.y[i]       (y[i]);
		nbitadder.sum_out[i] (sum[i]);
	}

	nbitadder.co (co);

	//Creating trace file
	sc_trace_file *trace = sc_create_vcd_trace_file ("NBIT_ADDER");
	trace->set_time_unit(1,SC_NS);

	sc_trace (trace, x[0], "x_0");
	sc_trace (trace, x[1], "x_1");
	sc_trace (trace, x[2], "x_2");
	sc_trace (trace, x[3], "x_3");
	sc_trace (trace, x[4], "x_4");
	sc_trace (trace, x[5], "x_5");
	sc_trace (trace, x[6], "x_6");
	sc_trace (trace, x[7], "x_7");

	sc_trace (trace, y[0], "y_0");
	sc_trace (trace, y[1], "y_1");
	sc_trace (trace, y[2], "y_2");
	sc_trace (trace, y[3], "y_3");
	sc_trace (trace, y[4], "y_4");
	sc_trace (trace, y[5], "y_5");
	sc_trace (trace, y[6], "y_6");
	sc_trace (trace, y[7], "y_7");

	sc_trace (trace, sum[0], "sum_0");
	sc_trace (trace, sum[1], "sum_1");
	sc_trace (trace, sum[2], "sum_2");
	sc_trace (trace, sum[3], "sum_3");
	sc_trace (trace, sum[4], "sum_4");
	sc_trace (trace, sum[5], "sum_5");
	sc_trace (trace, sum[6], "sum_6");
	sc_trace (trace, sum[7], "sum_7");

	sc_trace (trace, co, "cout");
	sc_trace (trace, tb_clk, "clk");

	sc_start();
	
	sc_close_vcd_trace_file(trace);

	cout << "--------------------------------------------------------------" << endl;
	return 0;

}
