#ifndef __ANALOG_PUSH_BUTTON_H__
#define __ANALOG_PUSH_BUTTON_H__
#include <Arduino.h>
#include <PushButton.h>

class AnalogPushButton : public PushButton {
	private:
		uint8_t _minPercent;
		uint8_t _maxPercent;
	protected:
		bool isActive();
	public:
		AnalogPushButton(uint8_t pin, uint8_t minPercent = 0, uint8_t maxPercent = 100) : PushButton(pin), _minPercent(minPercent), _maxPercent(maxPercent) {};
		virtual ~AnalogPushButton() {};
		virtual void begin();

};

#endif