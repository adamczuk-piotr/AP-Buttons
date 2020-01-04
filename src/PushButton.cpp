#include "PushButton.h"
#include <Arduino.h>

void PushButton::begin() {
	pinMode(_pin, INPUT_PULLUP);
	delay(50);
	//Set state to HIGH to turn off on sturtup
	_lastState = HIGH;
	_lastChanged = millis();
	_lastClick = millis();
	_clicked = false;
	_pressed = false;
};

ButtonEvent PushButton::getEvent() {
	unsigned long cState;
	if (_digital) {
		cState = digitalRead(_pin); //Read current state
	}
	else {
		cState = (analogRead(_pin) > 150) ? true : false;
	}
    unsigned long cTime = millis();	//Current time
	unsigned long waitTime = (cTime - _lastChanged);//Calculate wait time
	ButtonEvent event = ButtonEvent::None;
	
		if (_lastState != cState) {	               			
			if (HIGH == cState) {
				if (waitTime > ClickMinTime && ( waitTime  < ClickMaxTime)) {

					if (_clicked && cTime - _lastClick < DoubleClickWaitTime) {//Check for double click 
						event = ButtonEvent::DoubleClicked;
						_clicked = false;
					}
					else {
						_clicked = true;
						_lastClick = cTime;
					}
				}
				else if (_pressed) {
					event = ButtonEvent::Pressed;
				}
			}
			else {//Go to LOW, reset pressed
				_pressed = false;
			}
			_lastChanged = cTime;
			_lastState = cState;
		}
		else {
			if (LOW == cState) {	
				if (waitTime > HoldMinTime) {
					_pressed = false;//reset press event
					event = ButtonEvent::Hold;	
				}	
				else if ( !_pressed && waitTime >= PressMinTime ) {
				   //Set press event once
				   _pressed = true;
				}
			}
			else {
				if (_clicked &&  ((cTime - _lastClick ) >=  DoubleClickWaitTime) ) {
					event = ButtonEvent::Clicked;
					_clicked = false;
				}
			}
		}
		
		return event;
};

void PushButton::update() {
	const ButtonEvent  e = getEvent();

	switch (e)
	{
	case ButtonEvent::Clicked:
		if (_onClick != NULL) {
			_onClick();
		}
		break;
	case ButtonEvent::DoubleClicked:
		if (_onDoubleClick != NULL) {
			_onDoubleClick();
		}
		break;
	case ButtonEvent::Pressed:
		if (_onPress != NULL) {
			_onPress();
		}
		break;
	case ButtonEvent::Hold:
		if (_onHold != NULL) {
			_onHold();
		}
		break;
	default:
		break;
	}
};