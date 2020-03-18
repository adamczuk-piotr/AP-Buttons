#ifndef __ANALOG_PUSH_BUTTON_H__
#define __ANALOG_PUSH_BUTTON_H__
#include <Arduino.h>
#include <PushButton.h>

class AnalogPushButton : public PushButton {
	private:
		uint8_t _minPercent = 0;
		uint8_t _maxPercent = 10;
	protected:
		bool isActive();
	public:
		AnalogPushButton(uint8_t pin) : PushButton(pin) {};
		virtual ~AnalogPushButton() {};
		void begin();
		void begin(uint8_t minPercent, uint8_t maxPercent);

};

#endif