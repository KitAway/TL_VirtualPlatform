#include "lightDriver.h"

void light_driver::setLightColor(LightColor MainColor, LightColor SideColor)
{
	sc_uint<32> data = 0;
	data = ((sc_uint<32>)MainColor) << 1 + ((sc_uint<32>)SideColor) << 4;
	busIf->write(addr_PIO_LIGHT, data);
}