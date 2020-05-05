// OR module

SC_MODULE(or_module){

	sc_in<sc_logic> x, y; // Inputs of OR 
	sc_out<sc_logic> z; // Ouputs of OR

	void or_module_process(); // process

	SC_CTOR (or_module) // Constructor method
	{
		SC_METHOD (or_module_process); // Is activated by event, then executed in delta-time, and terminate
		sensitive << x << y; // Registration at sensitivity list
	}
};

// Module or
void or_module::or_module_process() {
	
	z.write (x.read() | y.read()); 
}
