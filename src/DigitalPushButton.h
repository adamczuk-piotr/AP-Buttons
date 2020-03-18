#ifndef __DIGITAL_PUSH_BUTTON_H__
#define __DIGITAL_PUSH_BUTTON_H__
#include <Arduino.h>
#include <PushButton.h>

class DigitalPushButton : public PushButton {

	protected:
		bool isActive();
	
	public:
		DigitalPushButton(uint8_t pin) : PushButton(pin) {};
		virtual ~DigitalPushButton() {};
		void begin();

};

#endif