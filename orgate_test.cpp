#include"systemc.h"
#include"orgate.cpp"

int sc_main(int agrc, char* agrv[])
{
	sc_signal<bool> a;
	sc_signal<bool> b;
	sc_signal<bool> y;
	sc_trace_file *tf;  
  
  // trace file command to store waveform in vcd
	orgate or1("or gate");
	or1.a(a);
	or1.b(b);
	or1.y(y);
  tf=sc_create_vcd_trace_file("or gate");
  
	//tracefile_signal
	sc_trace(tf,a,"a");
	sc_trace(tf,b,"b");
	sc_trace(tf,y,"y");
  
  //start
	a=0;
	b=0;
	sc_start(1,SC_NS);
	cout<<"a= " <<a<<"b= "<<b<<"y"<<y<<endl;

	a=0;
	b=1;
	sc_start(1,SC_NS);
	cout<<"a= " <<a<<"b= "<<b<<"y"<<y<<endl;

	a=1;
	b=0;
	sc_start(1,SC_NS);
	cout<<"a= " <<a<<"b= "<<b<<"y"<<y<<endl;

	a=1;
	b=1;
	sc_start(1,SC_NS);
	cout<<"a= " <<a<<"b= "<<b<<"y"<<y<<endl;

	a=0;
	b=0;
	sc_start(1,SC_NS);
	cout<<"a= " <<a<<"b= "<<b<<"y"<<y<<endl;
	
	sc_stop();  //stop
	sc_close_vcd_trace_file(tf);
	cout<<"finished at time" <<sc_time_stamp<<endl;
	return 0;
}
