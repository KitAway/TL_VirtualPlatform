#pragma once
#include <systemc>
#include "timer_if.h"
#include "bus_if.h"


SC_MODULE( TimerDriver),public timer_if
{
public:
	sc_port<bus_if> busIf;
	void wait_for_sec(sc_time sTime);
	SC_CTOR(TimerDriver)
	{

	}
};