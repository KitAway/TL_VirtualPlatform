#include"TestBench.h"

void testbench::run()
{
	carIf->setCarStatus(false);
	wait(30, SC_SEC);
	carIf->setCarStatus(true);
	wait(7, SC_SEC);
	carIf->setCarStatus(false);
	wait(12, SC_SEC);
	carIf->setCarStatus(true);
	wait(30, SC_SEC);
	carIf->setCarStatus(false);
	wait(15, SC_SEC);
	carIf->setCarStatus(true);
	wait(70, SC_SEC);
	carIf->setCarStatus(false);
}