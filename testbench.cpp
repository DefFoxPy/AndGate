#include "testbench.h"

TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName),
	a_out("a_out"), b_out("b_out"), c_in("c_in"), clk("clk") {

	SC_THREAD(test);
	dont_initialize();
	sensitive << clk.pos(); // se ejecutará por cada flanco de subiba 
}

void TestBench::test() {

	cout << "Inicio de la simulación" << endl;
	cout << "a\tb\tc" << endl; // tabla 

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			a_out.write(i);
			b_out.write(j);
			wait();
			print();
		}
	}

	sc_stop();
}

void TestBench::print() {
	cout << a_out.read() << "\t" << b_out.read() << "\t" << c_in.read() << endl;
}