#include "TLC.h"

void TLC::run()
{
	sc_time greenTime(20, SC_SEC), yellowTime(5, SC_SEC), redTime(10, SC_SEC);
	while (true)
	{
		lightIf->setLightColor(Green, Red);
		timerIf->wait(greenTime);
		WAIT_UNTIL(carIf->isCarPresent());
		lightIf->setLightColor(Yellow, Red);
		timerIf->wait(yellowTime);
		lightIf->setLightColor(Red, Green);
		timerIf->wait(redTime);
		lightIf->setLightColor(Red, Yellow);
		timerIf->wait(yellowTime);
	}
}