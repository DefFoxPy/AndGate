#include <andgate.h>

AndGate::AndGate(sc_module_name moduleName) : sc_module(moduleName),
	a_in("a_in"), b_in("b_in"), c_out("c_out") {
	
	SC_METHOD(process);        // registramos el proceso para que se ejecute cuando se detecten cambios en a_in y b_in
	dont_initialize();         // evitamos que ese ejecute al inicio, sino que se ejecute cuando de verdad ocurra un evento
	sensitive << a_in << b_in; // se active cuando detecte  cambios en a_in y b_in

}

void AndGate::process() {
	//cout << "proceso and" << endl; // debug
	c_out.write(a_in.read() and b_in.read());
}