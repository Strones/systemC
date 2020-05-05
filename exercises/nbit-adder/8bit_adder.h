// n bit adder

#include "system.c"
#include "full_adder.h"

SC_MODULE(nbit_adder){
	sc_in<sc_logic> ci,x_1 ,x_2 ,x_3 ,x_4 ,x_5 ,x_6 ,x_7 ,x_8;
	sc_in<sc_logic> y_1 ,y_2 ,y_3 ,y_4 ,y_5 ,y_6 ,y_7 ,y_8;
	sc_out<sc_logic> co,sum_1 ,sum_2 ,sum_3 ,sum_4 ,sum_5 ,sum_6 ,sum_7 ,sum_8;

	full_adder fa1, fa2, fa3, fa4, fa5, fa6, fa7, fa8;

	sc_signal<sc_logic> S1 ,S2 ,S3 ,S4 ,S5 ,S6 ,S7;

	SC_CTOR(nbit_adder): fa1("FA1"), fa2("FA2"), fa3("FA3"), fa4("FA4"), fa5("FA5"), fa6("FA6"), fa7("FA7"), fa8("FA8"){

		//Connect everything like in the block diagram ofthe Carry-Ripple-Adder
		fa1.x(x_1);
		fa1.y(y_2);
		fa1.cin(ci);
		fa1.cout(S1);
		fa1.sum(sum_1);

		fa2.x(x_2);
		fa2.y(y_2);
		fa2.cin(S1);
		fa2.cout(S2);
		fa2.sum(sum_2);

		fa3.x(x_3);
		fa3.y(y_3);
		fa3.cin(S2);
		fa3.cout(S3);
		fa3.sum(sum_3);

		fa4.x(x_4);
		fa4.y(y_4);
		fa4.cin(S3);
		fa4.cout(S4);
		fa4.sum(sum_4);

		fa5.x(x_4);
		fa5.y(y_4);
		fa5.cin(S4);
		fa5.cout(S5);
		fa5.sum(sum_5);

		fa6.x(x_6);
		fa6.y(y_6);
		fa6.cin(S5);
		fa6.cout(S6);
		fa6.sum(sum_6);

		fa7.x(x_7);
		fa7.y(y_7);
		fa7.cin(S6);
		fa7.cout(S7);
		fa7.sum(sum_6);

		fa8.x(x_8);
		fa8.y(y_8);
		fa8.cin(S7);
		f8.cout(co);
		f8.sum(sum_8);

	}
};
