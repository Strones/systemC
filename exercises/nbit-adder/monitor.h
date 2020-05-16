// Monitor for nbit_adder

#define NUMBER_OF_ADDERS 8

SC_MODULE(monitor){
	sc_vector<sc_in<bool>> x, y;
	sc_in<bool> clk;

	void start_monitoring(){
	

		int a = 1;
		while(a < 5){
			wait(20,SC_NS);
			cout << "Generated random values" <<  endl;

			for(int i = 0; i < NUMBER_OF_ADDERS; i++){
			cout << "x[" << i << "] = " << x[i] << " | " << "y[" << i << "] = " << y[i] << endl;  
			}
			cout << "" << endl;
			wait(100,SC_NS);
			a++;
		}
		sc_stop();
	}

	SC_CTOR(monitor) : x("x_monitor_values", NUMBER_OF_ADDERS), y("y_monitor_values", NUMBER_OF_ADDERS){
		SC_THREAD(start_monitoring);
		sensitive << clk.pos();
	}
};
