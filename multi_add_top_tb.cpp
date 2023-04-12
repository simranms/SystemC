#include <systemc.h>

SC_MODULE(top){
    sc_clock clock;
    sc_signal<bool> reset;
    sc_signal<int> output;
    sc_vector<sc_signal<int>> inputs;
    multi_addition adder;
    testbench tb;

    SC_CTOR(top) : 
        clock("clock", 10, SC_NS), 
        adder("adder", 3),
        tb("tb")
    {
        reset.write(false);
        adder.clock(clock);
        adder.reset(reset);
        for (int i = 0; i < 3; i++){
            inputs[i].write(0);
            adder.inputs[i](inputs[i]);
            tb.inputs[i](inputs[i]);
        }
        adder.output(output);
        tb.reset(reset);
        tb.output(output);
    }
};

int sc_main(int argc, char* argv[]){
    top my_top("my_top");
    sc_start();
    return 0;
}
