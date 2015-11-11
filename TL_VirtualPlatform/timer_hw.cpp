#include "TIMER_HW.h"
#include "hardwareAddr.h"
void TIMER::write(sc_uint<32> addr, sc_uint<32> data)
{
	switch (addr)
	{
	case addr_TIMER_CONTROL:
		control = data;
		break;
	case addr_TIMER_COUNTER:
		counter = data;
		break;
	case addr_TIMER_MAX:
		max = data;
		break;
	default:
		break;
	}
}

sc_uint<32> TIMER::read(sc_uint<32> addr)
{
	sc_uint<32> data;
	switch (addr)
	{
	case addr_TIMER_CONTROL:
		data = control;
		break;
	case addr_TIMER_COUNTER:
		data = counter;
		break;
	case addr_TIMER_MAX:
		data = max;
		break;
	default:
		data = 0;
		break;
	}
	return data;
}

void TIMER::run()
{
	sc_uint<32> data = control;
	if (data&0x02!= 0x02)
		return;
	sc_uint<32> tmp = counter.read();
	while (tmp!=max.read())
	{
		wait(sc_time(1, SC_MS));
		tmp++;
	}
	data = 0x01;
	control.write(data);
}