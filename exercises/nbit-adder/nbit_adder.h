// Nbit_adder

#include "systemc.h"
#include "full_adder.h"

SC_MODULE(nbit_adder){
	
	// Define all necessary vectors for the FAs
	// Inputs
	sc_vector<sc_in<bool>> x, y;

	// Outputs
	sc_vector<sc_out<bool>> sum_out;	

	// Carry
	sc_vector<sc_signal<bool>> carry, sum;
	sc_signal<bool> ci;
	
	// Fulladder
	sc_vector<full_adder> FA;

	// Clock
	sc_in<bool> clk;

	// Output carry
	sc_out<bool> co;

	// Number of FAs
	int n;

	void adder(){
		co.write(carry[n-1]); // last carry is output carry
		for(int i=0; i < n; i++){
			sum_out[i].write(sum[i]); // output sum vector consists of all the signal sum bits
		}
	}

	// Register adder process to module
	SC_HAS_PROCESS(nbit_adder);

	// Constructor
	nbit_adder(sc_module_name name, int n) : x("X_inputs", n), y("Y_inputs", n), sum_out("total_sum", n), carry("Carries", n), sum("sums", n), ci("carry_in", n), FA("full_adders", n){

		this->n = n; // Constructor n to local n

		// Adding ports of the first adder
		ci.write(false);

		FA[0].x(x[0]);
		FA[0].y(y[0]);
		FA[0].cin(ci);
		FA[0].sum(sum[0]);
		FA[0].co(carry[0]);
		FA[0].clk(clk);

		// Adding ports of additional FAs
		for(int i = 1; i < n; i++){
			FA[i].x(x[i]);
			FA[i].y(y[i]);
			FA[i].cin(carry[i-1]);
			FA[i].sum(sum[i]);
			FA[i].co(carry[i]);
			FA[i].clk(clk);
		}

		SC_METHOD(adder); 
		sensitive << clk.pos();
		
	} 


};
