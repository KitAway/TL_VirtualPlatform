#pragma once
#include <systemc>
#include "hardwareAddr.h"
#include "lightColor.h"
using namespace sc_core;

class light_interface :virtual public sc_interface
{
public:
	virtual void setLightColor(LightColor MainColor, LightColor SideColor)=0;
};