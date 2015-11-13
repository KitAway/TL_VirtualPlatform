#include "TIMER_HW.h"
#include "hardwareAddr.h"
void TIMER::write(sc_uint<32> addr, sc_uint<32> data)
{
	switch (addr)
	{
	case addr_TIMER_CONTROL:
		control = data;

		runIf = data&RUN;
		continueRun = data&CONTINUOS_RUNNING;

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
		control&=~OVERFLOW_BIT;
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
	if (runIf && (max!= 0))
	{
		counter = (counter+1) % max;
		if (counter == 0)
		{
			runIf = continueRun;
			if(control&INTERUPT_ENABLE)
				control |= OVERFLOW_BIT;
		}
	}
}