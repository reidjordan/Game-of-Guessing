// Francis Jacob Herron 924009805
// Part 1 instruct_screen.h

#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Window.h"
#include "Simple_window.h"
#include "difficultybutton.h"

using namespace Graph_lib;

// Instruction window class 
struct Instruct_window : Graph_lib::Window{
	Instruct_window(Point xy, int w, int h, const string& title);
	
private:
	Image background;		// background image will cover buttons
	Rectangle mock_diff;	// rectangle to go over background, button
	Text mock_diff_text;	// text to go over rectangle, background, button
	Text instructions;		// title for instructions
	
	Text instructions1;		// lines for instructions
	Text instructions2;
	Text instructions3;
	Text instructions4;
	Text instructions5;
	Text instructions6;
	Text instructions7;
	Text instructions8;
	Text instructions9;
	
	Button difficulty_button; // button to move on to difficulty window
	
	void diff_select();		  // moves to next window when button hit
	void color_objects();	  // color all objects correct color -> white	
	
	static void cb_difficulty(Address, Address window); // callback function: diff_select
};

	