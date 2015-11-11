#include "carDriver.h"

void car_driver::setCarStatus(bool status)
{
	busIf->write(addr_PIO_CAR, status);
}

bool car_driver::isCarPresent()
{
	sc_uint<32> data=busIf->read(addr_PIO_CAR);
	return data.range(0, 0);
}