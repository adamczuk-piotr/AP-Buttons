#include <DigitalPushButton.h>

void DigitalPushButton::begin() {
	pinMode(_pin, INPUT_PULLUP);
	//Set state to false to turn off on sturtup
	_lastActive = false;

};

bool DigitalPushButton::isActive() {
	return !digitalRead(_pin);
} ;