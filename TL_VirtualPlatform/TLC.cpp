#include "TLC.h"

void TLC::run()
{
	sc_time greenTime(20, SC_SEC), yellowTime(5, SC_SEC), redTime(10, SC_SEC);
	while (true)
	{
		lightIf->setLightColor(Green, Red);
		timerIf->wait_for_sec(greenTime);
		if (!carIf->isCarPresent())
			wait(carIf->car);
		lightIf->setLightColor(Yellow, Red);
		timerIf->wait_for_sec(yellowTime);
		lightIf->setLightColor(Red, Green);
		timerIf->wait_for_sec(redTime);
		lightIf->setLightColor(Red, Yellow);
		timerIf->wait_for_sec(yellowTime);
	}
}