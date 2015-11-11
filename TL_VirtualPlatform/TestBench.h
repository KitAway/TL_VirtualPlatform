#pragma once
#include <systemc>
#include "car_if.h"

SC_MODULE(testbench)
{
	sc_port<car_if> carIf;

	SC_CTOR(testbench)
	{
		SC_THREAD(run);
	}
	void run();
};