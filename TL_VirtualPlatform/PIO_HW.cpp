#include "PIO_HW.h"
#include <iostream>
void PIO::write(sc_uint<32> addr, sc_uint<32> data)
{
	sc_uint<32> newData,oldData = this->data.read();
	switch (addr)
	{
	case addr_PIO_CAR:
		newData = oldData&(~0x01) + data & 0x01;
		break;
	case addr_PIO_LIGHT:
		newData = oldData & 0x01 + data&(~0x01);
		break;
	default:
		newData = oldData;
		break;
	}
	this->data.write(newData); //unfinished
}

sc_uint<32> PIO::read(sc_uint<32> addr)
{
	return this->data.read();
}

void PIO::run()
{
	std::cout << data.read() << std::endl;
}