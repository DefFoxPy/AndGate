#ifndef ANDGATE_H
#define ANDGATE_H

#include <systemc.h>

class AndGate : public sc_module {
	public:
		sc_in<bool> a_in, b_in; // puertos de entrada
		sc_out<bool> c_out;     // puerto de salida

		SC_CTOR(AndGate);       // constructor

	private:
		void process();

};

#endif // ANDGATE_H