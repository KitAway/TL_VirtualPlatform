#pragma once
#include <systemc>
#include "light_if.h"
#include "bus_if.h"
#include "hardwareAddr.h"
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(light_driver),public light_interface
{

	sc_port<bus_if> busIf;

	SC_CTOR(light_driver)
	{

	}

	void setLightColor(LightColor MainColor, LightColor SideColor);
};



