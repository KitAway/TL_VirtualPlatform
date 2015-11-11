#include "timerDriver.h"
#include "hardwareAddr.h"

void TimerDriver::wait(sc_time sTime)
{
	sc_uint<32> data;
	busIf->write(addr_TIMER_MAX, sTime.to_seconds() * 1000);
	busIf->write(addr_TIMER_COUNTER, 0);
	busIf->write(addr_TIMER_CONTROL, 0x02);
	
	while (true)
	{
		data = busIf->read(addr_TIMER_CONTROL);
		if (data.range(0, 0) == 1)
			break;
		else
			sc_core::wait(sc_time(10,SC_MS));
	}

	busIf->write(addr_TIMER_CONTROL, 0x00);

}