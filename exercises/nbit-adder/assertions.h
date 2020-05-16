// assertions.h

#include "systemc.h"
#define NUMBER_OF_ADDERS 8
#define SUM 9  // Must be one more than NUMBER_OF_ADDERS

SC_MODULE(assertions){

	sc_vector<sc_in<bool>> x,y,sum;
	sc_in<bool> carry;
	sc_in<bool> clk;

	void start_assertion(){
		sc_uint<NUMBER_OF_ADDERS> int_x, int_y;
		sc_uint<SUM> int_sum;
		

		cout << "Asserting..."<< endl;

		while(1){
			int_x   = 0;
			int_y   = 0;
			int_sum = 0;

			wait(100,SC_NS);

			for(int i = 0; i < NUMBER_OF_ADDERS; i++){
				int_x   = int_x + (x[i] << i);
				int_y   = int_y + (y[i] << i);
				int_sum = int_sum + (sum[i] << i);
			}

			int_sum = int_sum + (carry << NUMBER_OF_ADDERS);
			
			if ((int_x + int_y) != int_sum){
				cout << "Assertion Result: FAIL"<< endl;
			}
			sc_assert((int_x + int_y) == int_sum);
		}
	}

	SC_CTOR(assertions) : x("x_input", NUMBER_OF_ADDERS), y("y_input", NUMBER_OF_ADDERS), sum("sum_input", NUMBER_OF_ADDERS){
		SC_THREAD(start_assertion);
		sensitive << clk.pos();
	}
};
