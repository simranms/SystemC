#include <systemc.h>

SC_MODULE(testbench){
    sc_out<bool> reset;
    sc_vector<sc_out<int>> inputs;
    sc_in<int> output;

    void test(){
        reset.write(true);
        for (int i = 0; i < inputs.size(); i++){
            inputs[i].write(i + 1);
        }
      
        wait(5, SC_NS);
        reset.write(false);
        wait(5, SC_NS);
        int expected_output = inputs.size() * (inputs.size() + 1) / 2;
        if (output.read() == expected_output){
            cout << "Test PASSED" << endl;
        } 
        else{
            cout << "Test FAILED" << endl;
        }
        sc_stop();
    }

    SC_CTOR(testbench){
        SC_THREAD(test);
        sensitive << output;
    }
};
