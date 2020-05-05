//half adder

#include <stdio.h>
#include "systemc.h"

SC_MODULE(half_adder){

	sc_in<sc_logic> x, y; // Inputs of HA 
	sc_out<sc_logic> c,s; // Ouputs of HA Carry, Sum

	void half_adder_process(); // process

	SC_CTOR (half_adder) // Constructor method
	{
		SC_METHOD (half_adder_process); // Is activated by event, then executed in delta-time, and terminate
		sensitive << x << y; // Registration at sensitivity list
	}
};

// Module half-adder
void half_adder::half_adder_process() {
	
	s.write (x.read() ^ y.read()); // Half-adder x,y inputs, sum output
	c.write (x.read() & y.read()); // Half-adder carry output
}


/*
    Half-adder
  |x|y|sum|carry|
  |0|0| 0 |  0  |
  |0|1| 1 |  0  |
  |1|0| 1 |  0  |
  |1|1| 0 |  1  |
 
*/

