//half adder

#include "systemc.h"

SC_MODULE(half_adder){

	sc_in<bool> x, y; // Inputs of HA 
	sc_out<bool> c,s; // Ouputs of HA Carry, Sum

	void half_adder_process(); // process

	SC_CTOR (half_adder) // Constructor method
	{
		SC_METHOD (half_adder_process); // Is activated by event, then executed in delta-time, and terminate
		sensitive << x << y; // Registration at sensitivity list
	}
};

// Module half-adder
void half_adder::half_adder_process() {
	
	s.write (x.read() ^ y.read()); // Half-adder a,b inputs, sum output
	c.write (x.read() & y.read()); // Half-adder carry output
}


/*
    Half-adder
  |a|b|sum|carry|
  |0|0| 0 |  0  |
  |0|1| 1 |  0  |
  |1|0| 1 |  0  |
  |1|1| 0 |  1  |
 
*/

