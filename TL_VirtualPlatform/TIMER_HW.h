#pragma once
#include <systemc>
#include "bus_if.h"
using namespace sc_dt;
using namespace sc_core;

SC_MODULE(TIMER), public bus_if
{
	sc_in<bool> clk;
	sc_uint<32> max,counter,control;

	bool continueRun,runIf;

	void write(sc_uint<32> addr, sc_uint<32> data);
	sc_uint<32> read(sc_uint<32> addr);

	SC_CTOR(TIMER)
	{
		max = 0;
		counter = 0;
		control = 0;
		continueRun = false;
		runIf = false;
		SC_METHOD(run);
		sensitive << clk.pos();
	}

	void run();
};