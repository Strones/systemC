#include "full_adder.h"
#include "testbench.h"

/*
     Full-Adder
 |x|y|cin|cout|sum|
 |0|0| 0 |  0 | 0 |
 |0|0| 1 |  0 | 1 |
 |0|1| 0 |  0 | 1 |
 |0|1| 1 |  1 | 0 |
 |1|0| 0 |  0 | 1 |
 |1|0| 1 |  1 | 0 |
 |1|1| 0 |  1 | 0 |
 |1|1| 1 |  1 | 1 |

*/

int sc_main (int argc, char* argv[]){

	//Define the N in nbit
	int nbit = 0;

	cout<<""<<endl;
	cout<<""<<endl;
	cout << "--------------------------------------------------------" << endl;
	while((nbit > 8) | (nbit == 0)){

		cout << "Enter the number of bit for the Nbit-Adder (range 1 to 8):" << endl;
		cin >> nbit;
			}

	sc_signal <sc_logic> x, y, cin, cout, sum;
	sc_clock tb_clk("tb_clk", 10, SC_NS, 0.5);

	// Creating FULLADDER module
	full_adder FA ("full-adder");

	// Adding signals to module FA
	FA.x     (x);
	FA.y     (y);
	FA.cin   (cin);
	FA.cout  (cout);
	FA.sum  (sum);
	
	// Create tb
	testbench tb("tb_1");

	tb.co    (cout);
	tb.ci    (cin);
	tb.x     (x);
	tb.y     (y);
	tb.sum   (sum);
	tb.clk   (tb_clk);

	
	//Creating trace file
	sc_trace_file *trace = sc_create_vcd_trace_file ("FULLADDER");

	sc_trace (trace, x, "x");
	sc_trace (trace, y, "y");
	sc_trace (trace, cin, "cin");
	sc_trace (trace, cout, "cout");
	sc_trace (trace, sum, "sum");
	sc_trace (trace, tb_clk, "clk");

	sc_start();
	
	sc_close_vcd_trace_file(trace);

	return 0;

}
