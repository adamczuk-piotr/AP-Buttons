#ifndef AP_BUTTON_H__
#define AP_BUTTON_H__
#include <Arduino.h>

typedef void (*ButtonEventCallback)(void);  //Function pointer 

typedef enum Class {None, Clicked, Pressed, Hold, Changed, StateBack, DoubleClicked} ButtonEvent;

class Button {
	public:		
		Button();
		virtual ~Button();
		virtual void begin();	
		virtual void update();
		virtual ButtonEvent getEvent();

};

#endif