#include <systemc.h>

SC_MODULE(multi_addition) {
    sc_in_clk clock;
    sc_in<bool> reset;
    sc_vector<sc_in<int>> inputs;
    sc_out<int> output;

    void add() {
        int sum = 0;
        for (int i = 0; i < inputs.size(); i++) {
            sum += inputs[i].read();
        }
        output.write(sum);
    }

    SC_HAS_PROCESS(multi_addition);

    multi_addition(sc_module_name name, int num_inputs) : 
        sc_module(name),
        inputs("inputs", num_inputs)
    {
        SC_METHOD(add);
        sensitive << clock.pos();
        for (int i = 0; i < num_inputs; i++) {
            sensitive << inputs[i];
        }
    }
};
