#pragma once
#include <systemc>
#include "bus_if.h"
using namespace sc_dt;
using namespace sc_core;

SC_MODULE(TIMER), public bus_if
{
	sc_signal<sc_uint<32> > max,counter,control;

	void write(sc_uint<32> addr, sc_uint<32> data);
	sc_uint<32> read(sc_uint<32> addr);

	SC_CTOR(TIMER)
	{
		SC_METHOD(run);
		sensitive << control;
	}

	void run();
};