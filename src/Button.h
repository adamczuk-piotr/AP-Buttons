#ifndef AP_BUTTON_H__
#define AP_BUTTON_H__
#include <Arduino.h>
#include <functional>

#ifdef __AVR__
	typedef void (*ButtonEventCallback)(void);  //Function pointer only, cannot be use in object method
#else
	typedef std::function<void()> ButtonEventCallback; //On ESP we can assign callbacks inside methods
#endif
typedef enum Class {None, Clicked, Pressed, Hold, Changed, StateBack, DoubleClicked} ButtonEvent;

class Button {
	public:		
		virtual ~Button();
		virtual void begin() = 0;	
		virtual void update() = 0;
	
	protected:
		virtual ButtonEvent getEvent() = 0;

};

#endif