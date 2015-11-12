#pragma once
#include <systemc>
#include "car_if.h"
#include "bus_if.h"
#include "hardwareAddr.h"
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(car_driver),public car_if
{
	sc_port<bus_if> busIf;

	
	void setCarStatus(bool status);
	bool isCarPresent();
	SC_CTOR(car_driver) 
	{
	}
};



