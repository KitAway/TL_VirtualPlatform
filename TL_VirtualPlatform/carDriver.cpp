#include "carDriver.h"

void car_driver::setCarStatus(bool status)
{
	if (status)
	{
		busIf->write(addr_PIO_CAR, 0x01);
		car.notify();
	}
	else
		busIf->write(addr_PIO_CAR, 0x00);
}

bool car_driver::isCarPresent()
{
	sc_uint<32> data=busIf->read(addr_PIO_CAR);
	return data.range(0, 0);
}
