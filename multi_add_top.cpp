#include <systemc.h>
#include <multi_add.cpp>
SC_MODULE(top) {
    sc_clock clock;
    sc_signal<bool> reset;
    sc_vector<sc_signal<int>> inputs;
    sc_signal<int> output;
    multi_addition adder;

    SC_CTOR(top) : 
        clock("clock", 10, SC_NS), 
        adder("adder", 3)
    {
        reset.write(false);
        adder.clock(clock);
        adder.reset(reset);
        for (int i = 0; i < 3; i++) {
            inputs[i].write(i);
            adder.inputs[i](inputs[i]);
        }
        adder.output(output);
    }
};

int sc_main(int argc, char* argv[]) {
    top my_top("my_top");
    sc_start(100, SC_NS);
    return 0;
}
