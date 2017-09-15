// Francis Jacob Herron 924009805
// Part 1 splash_screen.h

#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Window.h"
#include "Simple_window.h"

using namespace Graph_lib;

// Starting window class 
struct Splash_window : Graph_lib::Window{
	Splash_window(Point xy, int w, int h, const string& title);
	
private:
	Button start_button;		// button hit to move to instruction window
	Image game_of_thrones;		// background image will cover button
	Rectangle mock_start;		// rectangle to go over start button
	Text mock_start_text;		// text to go over start button
	Text game_title;			// text for game title
	Text team_number;			// text with team name and number
	Text team_name_1;			// text with team member name
	Text team_name_2;			// text with team member name
	Text team_name_3;			// text with team member name
	
	void start();				// function performed after start button hit
	void color_objects();
	
	static void cb_start(Address, Address window);	// call back function: start 
};	

