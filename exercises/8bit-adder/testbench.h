// Testbench
#include "systemc.h"
#include <stdio.h>

SC_MODULE(testbench){

	// Setting up I/O
	sc_out<sc_logic> x,y,ci;
	sc_in<sc_logic> co;
	sc_in<sc_logic> sum;
	sc_in<bool> clk;

	void stim_gen(){
	
		// Going through the different cases of the truth table
		// x = 0, y = 0, ci = 0 
		x.write(SC_LOGIC_0);
		y.write(SC_LOGIC_0);
		ci.write(SC_LOGIC_0);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_0);
		sc_assert(co == SC_LOGIC_0);
		wait();
		
		cout << "------------------" << endl;
		//Setting up the truth table
		cout << "    Full-Adder    " << endl;
		cout << "|x|y|cin|cout|sum|" << endl;		
		print_result();
		
		// x = 0, y = 0, ci = 1 
		x.write(SC_LOGIC_0);
		y.write(SC_LOGIC_0);
		ci.write(SC_LOGIC_1);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_1);
		sc_assert(co == SC_LOGIC_0);
		wait();	
		print_result();
		
		// x = 0, y = 1, ci = 0 
		x.write(SC_LOGIC_0);
		y.write(SC_LOGIC_1);
		ci.write(SC_LOGIC_0);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_1);
		sc_assert(co == SC_LOGIC_0);
		wait();	
		print_result();
	
		// x = 0, y = 1, ci = 1 
		x.write(SC_LOGIC_0);
		y.write(SC_LOGIC_1);
		ci.write(SC_LOGIC_1);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_0);
		sc_assert(co == SC_LOGIC_1);
		wait();	
		print_result();

		// x = 1, y = 0, ci = 0 
		x.write(SC_LOGIC_1);
		y.write(SC_LOGIC_0);
		ci.write(SC_LOGIC_0);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_1);
		sc_assert(co == SC_LOGIC_0);
		wait();	
		print_result();

		// x = 1, y = 0, ci = 1 
		x.write(SC_LOGIC_1);
		y.write(SC_LOGIC_0);
		ci.write(SC_LOGIC_1);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_0);
		sc_assert(co == SC_LOGIC_1);
		wait();	
		print_result();

		// x = 1, y = 1, ci = 0 
		x.write(SC_LOGIC_1);
		y.write(SC_LOGIC_1);
		ci.write(SC_LOGIC_0);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_0);
		sc_assert(co == SC_LOGIC_1);
		wait();	
		print_result();

		// x = 1, y = 1, ci = 1 
		x.write(SC_LOGIC_1);
		y.write(SC_LOGIC_1);
		ci.write(SC_LOGIC_1);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_1);
		sc_assert(co == SC_LOGIC_1);
		wait();	
		print_result();

		// x = 1, y = 1, ci = 1 
		x.write(SC_LOGIC_1);
		y.write(SC_LOGIC_1);
		ci.write(SC_LOGIC_1);
		wait(1,SC_NS); 			// wait 1 NS
		sc_assert(sum == SC_LOGIC_1);
		sc_assert(co == SC_LOGIC_1);
		wait();	
		print_result();

		cout << "------------------" << endl;
		sc_stop();
	}

	void print_result(){

		cout << "|" << x.read() << "|" << y.read() << "| " << ci.read() << " |  " << co.read() << " | " << sum.read() << " |" << endl;
	}

	SC_CTOR(testbench){
		
		SC_THREAD(stim_gen);
		sensitive << clk.pos();
	}
};
