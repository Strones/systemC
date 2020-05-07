// assertions.h

#include "systemc.h"

SC_MODULE(assertions){

	sc_vector<sc_in<bool>> x,y,sum;
	sc_in<bool> carry;

	void start_assertion(){
		sc_uint<8> int_x, int_y;
		sc_uint<9> int_sum;

		cout << "Asserting..."<< endl;

		while(1){
			int_x   = 0;
			int_y   = 0;
			int_sum = 0;

			wait(100,SC_NS);

			for(int i = 0; i < 8; i++){
				int_x   = int_x + (x[i] << i);
				int_y   = int_y + (y[i] << i);
				int_sum = int_sum + (sum[i] << i);
			}

			int_sum = int_sum + (carry << 8);
			
			if ((int_x + int_y) != int_sum){
				cout << "Assertion Result: FAIL"<< endl;
			}
			sc_assert((int_x + int_y) == int_sum);
			cout << "Assertion Result: PASS" << endl;
		}
	}

	SC_CTOR(assertions) : x("x_input", 8), y("y_input", 8), sum("sum_input", 8){
		SC_THREAD(start_assertion);
		for(int i = 0; i < 8; i++){
			sensitive << x[i] << y[i];
		}
	}
};
