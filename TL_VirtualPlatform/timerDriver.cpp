#include "timerDriver.h"
#include "hardwareAddr.h"

void TimerDriver::wait_for_sec(sc_time sTime)
{
	sc_uint<32> data;
	busIf->write(addr_TIMER_MAX, sTime.to_seconds() * 1000);
	busIf->write(addr_TIMER_COUNTER, 0);
	busIf->write(addr_TIMER_CONTROL, RUN|INTERUPT_ENABLE);
	
	while (true)
	{
		data = busIf->read(addr_TIMER_CONTROL);
		if (data&OVERFLOW_BIT)
			break;
		else
			sc_core::wait(sc_time(100,SC_MS));
	}
}