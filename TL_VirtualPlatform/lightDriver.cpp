#include "lightDriver.h"

void light_driver::setLightColor(LightColor MainColor, LightColor SideColor)
{
	sc_uint<32> data = 0;
	data.range(6, 4) = MainColor;
	data.range(3, 1) = SideColor;
	busIf->write(addr_PIO_LIGHT, data);
}