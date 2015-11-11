#include "Bus.h"
#include "hardwareAddr.h"
void Bus::write(sc_uint<32> addr, sc_uint<32> data)
{
	switch (addr)
	{
	case addr_PIO_CAR:
	case addr_PIO_LIGHT:
		PIO->write(addr,data);
		break;
	case addr_TIMER_MAX:
	case addr_TIMER_CONTROL: 
	case addr_TIMER_COUNTER:
		TIMER->write(addr, data);
		break;
	default:
		break;
	}
}

sc_uint<32> Bus::read(sc_uint<32> addr)
{
	sc_uint<32> data;
	switch (addr)
	{
	case addr_PIO_CAR:
	case addr_PIO_LIGHT:
		data=PIO->read(addr);
		break;
	case addr_TIMER_MAX:
	case addr_TIMER_CONTROL:
	case addr_TIMER_COUNTER:
		data=TIMER->read(addr);
		break;
	default:
		break;
	}

	return data;
}