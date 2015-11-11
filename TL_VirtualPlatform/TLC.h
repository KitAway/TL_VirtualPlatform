#pragma once
#include <systemc>
#include "light_if.h"
#include "car_if.h"
#include "timer_if.h"
#include "lightColor.h"
using namespace sc_dt;

SC_MODULE(TLC)
{
	sc_port<car_if> carIf;
	sc_port<light_interface> lightIf;
	sc_port<timer_if> timerIf;

	SC_CTOR(TLC)
	{
		SC_THREAD(run);
	}
	void run();
};