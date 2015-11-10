#include "carDriver.h"

void car_driver::setCarStatus(bool status)
{
	busIf->write(addr_PIO_CAR, status);
}