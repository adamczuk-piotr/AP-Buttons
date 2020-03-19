#include <AnalogPushButton.h>

void AnalogPushButton::begin() {
		_lastActive = false;
};

bool AnalogPushButton::isActive() {
	uint8_t value = map(analogRead(_pin), 0, PWMRANGE, 0, 100);
	return (value >= _minPercent && value <= _maxPercent);
} ;