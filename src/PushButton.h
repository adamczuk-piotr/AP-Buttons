#ifndef __PUSH_BUTTON_H__
#define __PUSH_BUTTON_H__
#include <Arduino.h>
#include <Button.h>

class PushButton : public Button{
	private:
		uint8_t _pin;
		
		bool _lastState;
		bool _clicked;
		bool _pressed;
		unsigned long _lastChanged;
		unsigned long _lastClick;

		ButtonEventCallback _onClick = NULL;
		ButtonEventCallback _onDoubleClick = NULL;
		ButtonEventCallback _onPress = NULL;
		ButtonEventCallback _onHold = NULL;

	protected:
		bool _digital = true;
		
	public:
		static const uint16_t 		ClickMinTime = 50;
		static const uint16_t 		ClickMaxTime = 200;
		static const uint16_t 		DoubleClickWaitTime = 220;
		static const uint16_t 		PressMinTime = 400;		
		static const uint16_t 		HoldMinTime = 800;
		
		PushButton() : Button() {};
		PushButton(uint8_t pin) : Button(), _pin(pin){};
		~PushButton() {};

		ButtonEvent getEvent();

		void  begin();

		void onClick(ButtonEventCallback event) {
			_onClick = event;
		};
		
		void onDoubleClick(ButtonEventCallback event) {
			_onDoubleClick = event;
		};
		
		void onPress(ButtonEventCallback event) {
			_onPress = event;
		};
		
		void onHold(ButtonEventCallback event) {
			_onHold = event;
		};

		void update();
};

#endif