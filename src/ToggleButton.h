#ifndef __TOGGLE_BUTTON_H__
#define __TOGGLE_BUTTON_H__
#include <Arduino.h>
#include <Button.h>

class ToggleButton : public Button {
	private:
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
		
		ToggleButton(uint8_t pin) : Button(pin), _changeTime(0), _prevChangeTime(0){
			_state = digitalRead(_pin);
		};

		~ToggleButton() {};


		void onChange(ButtonEventCallback event) {
			_onChange = event;
		};
		
		void onStateBack(ButtonEventCallback event) {
			_onStateBack = event;
		};
		
		virtual void begin() override;

		virtual void update() override;
};

#endif