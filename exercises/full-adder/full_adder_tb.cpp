#include "full_adder.h"

/*
     Full-Adder
 |a|b|cin|sum|cout|
 |0|0| 0 | 0 |  0 |
 |0|0| 1 | 1 |  0 |
 |0|1| 0 | 1 |  0 |
 |0|1| 1 | 0 |  1 |
 |1|0| 0 | 1 |  0 |
 |1|0| 1 | 0 |  1 |
 |1|1| 0 | 0 |  1 |
 |1|1| 1 | 1 |  1 |

*/

SC_MODULE (driver)
{
	sc_out <bool> d_a, d_b, d_cin;

	void my_process()
	{
		sc_uint<3> combinations; // 3 bit lengths
		combinations = 0; // combinations for full-adder (8)

		while(1)
		{
			d_a   = combinations[2];
			d_b   = combinations[1];
			d_cin = combinations[0];

			wait(1,SC_NS);

			combinations++;

			if(combinations == 0){
				sc_stop();
			}
		}
	}

	SC_CTOR(driver)
	{
		SC_THREAD(my_process);
	}
};

int sc_main (int argc, char *argv[]){

	// Setting up signals
	sc_signal <bool> x, y, cin, cout, sum;


	// Creating a driver
	driver DRIVER ("driver_full_adder");

	// Adding signals to the driver
	DRIVER.d_a   (x);
	DRIVER.d_b   (y);
	DRIVER.d_cin (cin);

	// Creating FULLADDER module
	full_adder FA ("full-adder");

	// Adding signals to module FA
	FA.x     (x);
	FA.y     (y);
	FA.cin   (cin);
	FA.cout  (cout);
	FA.sum  (sum);
/*
	// Creating modules
	half_adder HA1 ("half-adder1");
	half_adder HA2 ("half-adder2");
	or_module OR ("or-1");

	// Adding signals to modules for full-adder
	HA1.x (x);
	HA1.y (y);
	HA1.c (or_1);
	HA1.s (z);
	
	HA2.x (z);
	HA2.y (cin);
	HA2.c (or_2);
	HA2.s (sum);

	OR.x (or_1);
	OR.y (or_2);
	OR.z (cout);
*/	
	//Creating trace file
	sc_trace_file *trace = sc_create_vcd_trace_file ("FULLADDER");

	sc_trace (trace, x, "x");
	sc_trace (trace, y, "y");
	sc_trace (trace, cin, "cin");
	sc_trace (trace, cout, "cout");
	sc_trace (trace, sum, "sum");

	sc_start();
	
	sc_close_vcd_trace_file(trace);

	return 0;

}
