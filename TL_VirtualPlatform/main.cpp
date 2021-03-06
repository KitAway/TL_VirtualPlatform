#include "TestBench.h"
#include <iostream>
#include "Bus.h"
#include "TIMER_HW.h"
#include "PIO_HW.h"
#include "TLC.h"
#include "carDriver.h"
#include "lightDriver.h"
#include "timerDriver.h"


int sc_main(int argc, char* argv[])
{
	//sc_set_time_resolution(1, SC_MS);
	TLC tlc("TLC");
	Bus bus("Bus");
	TIMER timer("Timer");
	PIO pio("PIO");
	sc_clock clk("clock",1,SC_MS);

	car_driver carDv("car_driver1");
	light_driver lightDv("light_driver");
	TimerDriver timerDv("timer_driver");

	carDv.busIf(bus);

	lightDv.busIf(bus);
	timerDv.busIf(bus);

	tlc.carIf(carDv);
	tlc.lightIf(lightDv);
	tlc.timerIf(timerDv);

	bus.PIO(pio);
	bus.TIMER(timer);

	timer.clk(clk);

	testbench TB("test_bench");
	TB.carIf(carDv);

	sc_start(200, SC_SEC);

	return 0;
}