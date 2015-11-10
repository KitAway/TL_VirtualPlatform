#pragma once
#include <systemc>
#include "bus_if.h"

SC_MODULE(Bus),public bus_if
{
	sc_port<bus_if> PIO, TIMER;

	void write(sc_uint<32> addr, sc_uint<32> data);
	sc_uint<32> read(sc_uint<32> addr);
};