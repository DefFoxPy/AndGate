#ifndef TEST_BENCH_H
#define TEST_BENCH_H

#include <systemc.h>

class TestBench : public sc_module {
	public:
		sc_out<bool> a_out, b_out;
		sc_in<bool> c_in;
		sc_in_clk clk;  // creación del reloj

		SC_CTOR(TestBench);

	private:
		void test();
		void print();
};

#endif // TEST_BENCH_H