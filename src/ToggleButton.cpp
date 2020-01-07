#include <Arduino.h>
#include <ToggleButton.h>

uint16_t ToggleButton::ChangeTime = 50;
uint16_t ToggleButton::BackOnTime = 500;


void ToggleButton::begin() {
    pinMode(_pin, INPUT_PULLUP);
	_state = digitalRead(_pin);
	_changeTime = millis();
	_prevChangeTime = millis();
};

ButtonEvent ToggleButton::getEvent() {
    const bool cState = digitalRead(_pin); //Read current state
    unsigned long cTime = millis();	//Current time
	unsigned long waitTime = (cTime - _changeTime);//Calculate wait time
	
	if ((_state != cState) && (waitTime > ChangeTime) ) {	
		
        _changeTime = cTime;
		_state = cState;

		if (waitTime < BackOnTime) {
			return ButtonEvent::StateBack;
		}
		else {
			return ButtonEvent::Changed;
		}		
	}
	
	return ButtonEvent::None;
};



void ToggleButton::update() {

    const ButtonEvent event = getEvent();

    switch (event) {
        case ButtonEvent::Changed:
            _onChange();
            break;
        case:: ButtonEvent::StateBack:
            _onStateBack();
            break;
        default:
            break;
    }

};