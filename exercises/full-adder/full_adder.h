// Full-adder

#include "systemc.h"
#include "half_adder.h"
#include "or.h"

SC_MODULE(full_adder){
	
	sc_in<bool> x,y,cin;
	sc_out<bool> sum,cout;

	half_adder ha1, ha2;
	or_module or1;

	sc_signal<bool> S1, S2, S3;

	SC_CTOR(full_adder) : ha1("HA1"), ha2("HA2"), or1("OR1"){
	// Connect everything like in the block diagram	
		ha1.x(x); 
		ha1.y(y); 
		ha1.c(S1);
		ha1.s(S2);
		ha2.x(S2); 
		ha2.y(cin); 
		ha2.c(S3);
		ha2.s(sum);
		or1.x(S1); 
		or1.y(S3); 
		or1.z(cout);
		
	}
};
