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
	TLC tlc("TLC");
	Bus bus("Bus");
	TIMER timer("Timer");
	PIO pio("PIO");

	car_driver carDv("car driver");
	light_driver lightDv("light driver");
	TimerDriver timerDv("timer driver");

	carDv.busIf(bus);
	lightDv.busIf(bus);
	timerDv.busIf(bus);

	tlc.carIf(carDv);
	tlc.lightIf(lightDv);
	tlc.timerIf(timerDv);

	bus.PIO(pio);
	bus.TIMER(timer);

	testbench TB("test bench");
	TB.carIf(carDv);

	sc_start(100, SC_SEC);

	return 0;
}