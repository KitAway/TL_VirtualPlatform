#include "PIO_HW.h"
#include "lightColor.h"
#include <iostream>
using namespace std;
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
	sc_uint<32> data = this->data.read();
	
	if (data.range(0, 0) == 1)
	{
		cout << "car is present." << endl;
	}
	else
		cout << "no car is present." << endl;

	switch (data.range(3,1))
	{
	case Red:
		cout << "The main road is Red" << endl;
	case Green:
		cout << "The main road is Green" << endl;
	case Yellow:
		cout << "The main road is Yellow" << endl;
	default:
		cout << "The main light is broken." << endl;
		break;
	}

	switch (data.range(6, 4))
	{
	case Red:
		cout << "The side road is Red" << endl;
	case Green:
		cout << "The side road is Green" << endl;
	case Yellow:
		cout << "The side road is Yellow" << endl;
	default:
		cout << "The side light is broken." << endl;
		break;
	}

	cout << '@' << sc_time_stamp() << endl;
}