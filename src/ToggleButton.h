#ifndef __TOGGLE_BUTTON_H__
#define __TOGGLE_BUTTON_H__
#include <Arduino.h>
#include <Button.h>

class ToggleButton : public Button {
	private:
		uint8_t _pin;
		bool _state;
		unsigned long 	_changeTime;
		unsigned long 	_prevChangeTime;

		ButtonEventCallback _onChange = nullptr;
		ButtonEventCallback _onStateBack = nullptr;

	protected:
		ButtonEvent getEvent() override;

	public:
		static  uint16_t ChangeTime;
		static  uint16_t BackOnTime;		
		
		ToggleButton(uint8_t pin) : _pin(pin), _changeTime(0), _prevChangeTime(0){
			_state = digitalRead(_pin);
		};

		~ToggleButton() {};

		void begin() override;

		void onChange(ButtonEventCallback event) {
			_onChange = event;
		};
		
		void onStateBack(ButtonEventCallback event) {
			_onStateBack = event;
		};

		void update() override;
};

#endif