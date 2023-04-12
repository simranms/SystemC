#include "systemc.h"

SC_MODULE(divider) {
  sc_in<sc_uint<8>> a; // input a, n-bit wide
  sc_in<sc_uint<8>> b; // input b, n-bit wide
  sc_out<sc_uint<16>> c; // output c, 2n-bit wide
  
  void divide() {
    c.write(a.read() / b.read()); // divide a and b, and write result to c
  }
  
  SC_CTOR(divider) {
    SC_METHOD(divide);
    sensitive << a << b;
  }
};
