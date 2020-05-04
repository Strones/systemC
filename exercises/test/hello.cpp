#include <systemc.h>

SC_MODULE (mymodule) {
	SC_CTOR (mymodule) {

	}
	
 void myfunction();
};

void mymodule::myfunction() {
	cout << "Hello World!\n";
}

int sc_main(int argc, char* argv[]){

	mymodule myinstance("abc");
	myinstance.myfunction();

 	return 0;
}
