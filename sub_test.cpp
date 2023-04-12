#include"systemc.h"
#include"sub.cpp"

SC_MODULE(testbench){
    sc_out< sc_uint<32> > a;
    sc_out< sc_uint<32> > b;
    sc_in< sc_uint<32> > out;

    void test(){                                  //start
        // Test case 1: a = 10, b = 5
        a.write(10);
        b.write(5);
        wait(1, SC_NS);
        assert(out.read() == 5);

        // Test case 2: a = 0, b = 0
        a.write(0);
        b.write(0);
        wait(1, SC_NS);
        assert(out.read() == 0);
      sc_stop();                                 //stop
    }

    SC_CTOR(testbench) {
        SC_THREAD(test);
        sensitive << out;
    }
};
int sc_main(int argc, char *argv[]){
    sc_signal< sc_uint<32> > a;
    sc_signal< sc_uint<32> > b;
    sc_signal< sc_uint<32> > out;
    n_bit_subtractor subtractor("subtractor");
  
  //instantiation
    subtractor.a(a);
    subtractor.b(b);
    subtractor.out(out);
 //testbench instatiation
    testbench tb("tb");
    tb.a(a);
    tb.b(b);
    tb.out(out);
  
    sc_start();
    return 0;
}
