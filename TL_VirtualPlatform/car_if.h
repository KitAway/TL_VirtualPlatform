#pragma once
#include <systemc>

using namespace sc_core;

class car_if : virtual public sc_interface
{
	
public:
	sc_event car;
	virtual void setCarStatus(bool status) = 0;
	virtual bool isCarPresent() = 0;
};