#ifndef __PUSH_BUTTON_H__
#define __PUSH_BUTTON_H__
#include <Arduino.h>
#include <Button.h>

class PushButton : public Button {
	private:		
		bool _clicked = false;
		bool _pressed = false;
		unsigned long _lastChanged = 0;
		unsigned long _lastClick = 0;

		uint16_t _holdInterval = 0;
		unsigned long _lastHold = 0;

		ButtonEventCallback _onClick = nullptr;
		ButtonEventCallback _onDoubleClick = nullptr;
		ButtonEventCallback _onPress = nullptr;
		ButtonEventCallback _onHold = nullptr;
		
		ButtonEvent getEvent();
	protected:
		PushButton(uint8_t pin) : Button(pin) {};
		bool _lastActive;
		virtual bool isActive() = 0;
 
	public:
		static  uint16_t	ClickMinTime;
		static  uint16_t 	ClickMaxTime;
		static  uint16_t 	DoubleClickWaitTime;
		static  uint16_t 	PressMinTime;		
		static  uint16_t 	HoldMinTime;
		
		virtual ~PushButton() {};

		void onClick(ButtonEventCallback event) {
			_onClick = event;
		};
		
		void onDoubleClick(ButtonEventCallback event) {
			_onDoubleClick = event;
		};
		
		void onPress(ButtonEventCallback event) {
			_onPress = event;
		};
		
		void onHold(ButtonEventCallback event, uint16_t interval = 0) {
			_onHold = event;
			_holdInterval = interval;
		};

		virtual void update();
};

#endif