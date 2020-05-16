// Testbench
#include "systemc.h"
#include <stdio.h>

SC_MODULE(testbench){

	// Setting up I/O
	sc_out<sc_logic> x; // x and y needs to be generated -> output
	sc_out<sc_logic> y;
	sc_in<sc_logic> carry;
	sc_in<sc_logic> sum;
	sc_in<bool> clk;

	void stim_gen(){
	
		// Going through the different cases of the truth table
		// x = 0, y = 0
		x.write(SC_LOGIC_0);
		y.write(SC_LOGIC_0);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_0);
		sc_assert(carry == SC_LOGIC_0);
		wait();
		cout << "" << endl;
		cout << "" << endl;
		cout << "Halfadder" << endl;	
		cout << "---------" << endl;
		//Setting up the truth table
		cout << "|x|y|c|s|" << endl;		

		print_result();
		
		// x = 0, y = 1
		x.write(SC_LOGIC_0);
		y.write(SC_LOGIC_1);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_1);
		sc_assert(carry == SC_LOGIC_0);
		wait();
		print_result();
		
		// x = 1, y = 0
		x.write(SC_LOGIC_1);
		y.write(SC_LOGIC_0);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_1);
		sc_assert(carry == SC_LOGIC_0);
		wait();
		print_result();

		// x = 1, y = 1
		x.write(SC_LOGIC_1);
		y.write(SC_LOGIC_1);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_0);
		sc_assert(carry == SC_LOGIC_1);
		wait();
		print_result();
		cout << "---------" << endl;
		sc_stop();
	}

	void print_result(){

		cout << "|" << x.read() << "|" << y.read() << "|" << carry.read() << "|" << sum.read() << "|" << endl;
	}

	SC_CTOR(testbench){
		
		SC_THREAD(stim_gen);
		sensitive << clk.pos();
	}
};
