#include "PIO_HW.h"
#include <iostream>
using namespace std;
void PIO::write(sc_uint<32> addr, sc_uint<32> data)
{
	sc_uint<32> newData,oldData = this->data;
	switch (addr)
	{
	case addr_PIO_CAR:
		this->data.range(0, 0) = data.range(0, 0);
		break;
	case addr_PIO_LIGHT:
		this->data.range(31, 1) = data.range(31, 1);
		break;
	default:
		break;
	}
	run();
}

sc_uint<32> PIO::read(sc_uint<32> addr)
{
	return this->data;
}

void PIO::run()
{	
	if (data.range(0, 0) == 1)
	{
		cout << "Car is present.   " << ' ';
	}
	else
		cout << "No car is present." << ' ';

	switch (data.range(6,4).to_uint())
	{
	case Red:
		cout << "The main road is Red   " << ' ';
		break;
	case Green:
		cout << "The main road is Green " << ' ';
		break;
	case Yellow:
		cout << "The main road is Yellow" << ' ';
		break;
	default:
		cout << "The main light is broken." << ' ';
		break;
	}

	switch (data.range(3, 1).to_uint())
	{
	case Red:
		cout << "The side road is Red   " << ' ';
		break;
	case Green:
		cout << "The side road is Green " << ' ';
		break;
	case Yellow:
		cout << "The side road is Yellow" << ' ';
		break;
	default:
		cout << "The side light is broken." << ' ';
		break;
	}

	cout << '@' << sc_time_stamp() << endl;
}