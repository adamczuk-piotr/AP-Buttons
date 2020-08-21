#ifndef AP_BUTTON_H__
#define AP_BUTTON_H__
#include <Arduino.h>


#ifdef __AVR__
	typedef void (*ButtonEventCallback)(void);  //Function pointer only, cannot be use in object method
#else
	#include <functional>
	typedef std::function<void()> ButtonEventCallback; //On ESP we can assign callbacks inside methods
#endif
typedef enum Class {None, Clicked, Pressed, Hold, Changed, StateBack, DoubleClicked} ButtonEvent;

class Button {
	public:		
		Button(uint8_t pin) : _pin(pin) {};
		virtual ~Button();
		virtual void begin() = 0;	
		virtual void update() = 0;
		virtual uint8_t pin() final {return _pin;};
	protected:
		uint8_t _pin;
		virtual ButtonEvent getEvent() = 0;

};

#endif