#pragma once

#include <systemc>
#include "bus_if.h"
#include "hardwareAddr.h"
#include "lightColor.h"
using namespace sc_dt;
using namespace sc_core;

SC_MODULE(PIO),public bus_if
{
	sc_uint<32> data;
	SC_CTOR(PIO)
	{
		data.range(6, 4) = Green;
		data.range(3, 1) = Red;
	}
	void write(sc_uint<32> addr, sc_uint<32> data);
	sc_uint<32> read(sc_uint<32> addr);
	void run();
};