// Grayscaler.h
// Author: Fabian Garber		


SC_MODULE(grayscaler){
	
	sc_in<bool> clk;
	sc_in<sc_uint<8>> red, green, blue;
	sc_out<sc_uint<8>> gray_red, gray_green, gray_blue;

	// calculate the grayscale value and save it to grayValue
	void color_to_gray(){
		sc_uint<8> grayValue = (sc_uint<8>) ((red.read()>>2)+(red.read()>>5)+(green.read()>>1)+(green.read()>>4)+(blue.read()>>4)+(blue.read()>>5));


		gray_red.write(grayValue);
		gray_green.write(grayValue);
		gray_blue.write(grayValue);
	}

	SC_CTOR(grayscaler){
		SC_METHOD(color_to_gray);
		sensitive << clk.pos();
	}
};
