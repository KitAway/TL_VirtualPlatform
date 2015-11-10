#pragma once
#include <systemc>
#include "light_if.h"
#include "bus_if.h"
#include "hardwareAddr.h"
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(light_driver),public light_interface
{
	sc_port<light_interface> carIf;
	sc_port<bus_if> busIf;

	void setLightColor(LightColor MainColor, LightColor SideColor);
};



