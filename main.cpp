#include <systemc.h>
#include "andgate.h" // incluyendo la compuerta al main
#include "testbench.h"

int sc_main(int argc, char *argv[]) {
	sc_signal<bool> a, b, c;  			// creación de los cables de los puertos 

	// creación del reloj con su periodo
	sc_time period(10, SC_NS);          // 10 Nano segundos
	sc_clock clock("clock", period);
	
	
	AndGate and_gate("andgate");       // agregando la compuerta con un nombre representativo			
	TestBench test_bench("testbench");

	// conectando los puertos
	and_gate.a_in(a);
	test_bench.a_out(a);
	and_gate.b_in(b);
	test_bench.b_out(b);
	and_gate.c_out(c);
	test_bench.c_in(c);
	test_bench.clk(clock);

	sc_start(); // toda función main tiene esta función

	return 0;
}