#pragma once
#include <systemc>

using namespace sc_core;

class car_if : virtual public sc_interface
{
	virtual void setCarStatus(bool status) = 0;
};