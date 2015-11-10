#pragma once

#include <systemc>
//using sc_core::sc_interface;
using namespace sc_dt;
using namespace sc_core;

class bus_if: virtual public sc_interface
{
public:
	virtual void write(sc_uint<32> addr, sc_uint<32> data) = 0;
	virtual sc_uint<32> read(sc_uint<32> addr) = 0;
};