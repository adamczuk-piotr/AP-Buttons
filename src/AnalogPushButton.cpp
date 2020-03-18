#include <AnalogPushButton.h>

void AnalogPushButton::begin(uint8_t minPercent, uint8_t maxPercent) {
	_minPercent = minPercent;
	_maxPercent = maxPercent;
	//Set state to false to turn off on sturtup
	_lastActive = false;
};
void AnalogPushButton::begin() {
	begin(0, 10);
};

bool AnalogPushButton::isActive() {
	uint8_t value = map(analogRead(_pin), 0, PWMRANGE, 0, 100);
	return (value >= _minPercent && value <= _maxPercent);
} ;