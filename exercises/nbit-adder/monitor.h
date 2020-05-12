// Monitor for nbit_adder

SC_MODULE(monitor){
	sc_vector<sc_in<bool>> x, y;
	sc_in<bool> clk;

	void start_monitoring(){
	

		int a = 1;
		while(a < 5){

			cout << "Generated random values" <<  endl;

			for(int i = 0; i < 8; i++){
			cout << "x[" << i << "] = " << x[i] << " | " << "y[" << i << "] = " << y[i] << endl;  
			}
			cout << "" << endl;
			wait(100,SC_NS);
			a++;
		}
		sc_stop();
	}

	SC_CTOR(monitor) : x("x_monitor_values", 8), y("y_monitor_values", 8){
		SC_THREAD(start_monitoring);
		sensitive << clk.pos();
	}
};
