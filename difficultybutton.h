// Reid Jordan - 324003349
// Part 2 - difficultybutton.h

#include "GUI.h" 
#include "Graph.h"
#include "initialsheader.h"

using namespace Graph_lib;

// Class for window with different buttons for different levels
struct Diff_window : Graph_lib::Window {
	Diff_window(Point xy, int w, int h, const string& title);
	
private:
	Button quit_button;		// button to stop game
	Button difficulty_1;	// button to pick level 1
	Button difficulty_2;	// button to pick level 2
	Button difficulty_3;	// button to pick level 3
	Button difficulty_4;	// button to pick level 4
	Button difficulty_5;	// button to pick level 5
	
	Image background;		// background image will cover buttons
	Rectangle mock_quit;	// rectangle to go over background, button_quit
	Text mock_quit_text;	// text to go over background, button_quit
	Rectangle mock_diff1;	// rectangle to go over background, button1
	Text mock_diff1_text;	// text to go over background, button1
	Rectangle mock_diff2;	// rectangle to go over background, button2
	Text mock_diff2_text;	// text to go over background, button2
	Rectangle mock_diff3;	// rectangle to go over background, button3
	Text mock_diff3_text;	// text to go over background, button3
	Rectangle mock_diff4;	// rectangle to go over background, button4
	Text mock_diff4_text;	// text to go over background, button4
	Rectangle mock_diff5;	// rectangle to go over background, button5
	Text mock_diff5_text;	// text to go over background, button5
	Text diff_words;		// Instructions for window
	
	void quit();			// closes game
	void diff_1();			// sets difficulty_level and goes to next window
	void diff_2();			// sets difficulty_level and goes to next window	
	void diff_3();			// sets difficulty_level and goes to next window
	void diff_4();			// sets difficulty_level and goes to next window
	void diff_5();			// sets difficulty_level and goes to next window
	void color_objects(); 	// sets colors of all objects seen by user
	
	int difficulty_level = 0;	// stores difficulty level (1-5)
};

