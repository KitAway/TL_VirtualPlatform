#pragma once
#include <systemc>
using namespace sc_core;
using namespace sc_dt;
class timer_if :virtual public sc_interface
{
public:
	virtual void wait(sc_time sTime) = 0;

};