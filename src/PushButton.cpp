#include <PushButton.h>
#include <Arduino.h>


ButtonEvent PushButton::getEvent() {

	bool active = isActive(); //Read current state

    unsigned long cTime = millis();	//Current time
	unsigned long waitTime = (cTime - _lastChanged);//Calculate wait time
	ButtonEvent event = ButtonEvent::None;

	if (_lastActive != active) {	               			
		if (! active) {
			if (waitTime > _clickMinTime && ( waitTime  < _clickMaxTime)) {

				if (_clicked && ((cTime - _lastClick) < _doubleClickWaitTime)) {//Check for double click 
					event = ButtonEvent::DoubleClicked;
					_clicked = false;
				}
				else {
					if (nullptr == _onDoubleClick) {
						event = ButtonEvent::Clicked; //Return Click event immediatelly if no double click is registered
					}
					else {
						_clicked = true; //store click event and time
						_lastClick = cTime;	
					}
				}
			}
			else if (_pressed) {
				event = ButtonEvent::Pressed;
				_pressed = false; 
			}
		}
		else {//Go to Active, reset pressed
			_pressed = false;
		}
		_lastChanged = cTime;
		_lastActive = active;
	}
	else {
		if ( active) {	
			if (waitTime > _holdMinTime) {
				_pressed = false;//reset press event
				if ((cTime - _lastHold) >= _holdInterval) {
					event = ButtonEvent::Hold;	
					_lastHold = cTime;
				}
			}	
			else if ( !_pressed && waitTime >= _pressMinTime ) {
				//Set press event once
				_pressed = true;
			}
		}
		else {
			if (_clicked &&  ((cTime - _lastClick ) >=  _doubleClickWaitTime) ) {
				event = ButtonEvent::Clicked;
				_clicked = false;
			}
		}
	}
	
	return event;
};

void PushButton::update() {
	const ButtonEvent  e = getEvent();
	if (ButtonEvent::None == e) {
		return;
	} 

	switch (e) {
		case ButtonEvent::Clicked:
			if (_onClick != nullptr) {
				_onClick();
			}
			break;
		case ButtonEvent::DoubleClicked:
			if (_onDoubleClick != nullptr) {
				_onDoubleClick();
			}
			break;
		case ButtonEvent::Pressed:
			if (_onPress != nullptr) {
				_onPress();
			}
			break;
		case ButtonEvent::Hold:
			if (_onHold != nullptr) {
				_onHold();
			}
			break;
		default:
			break;
	}
};
