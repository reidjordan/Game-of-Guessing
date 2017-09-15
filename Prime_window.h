// Haley Hutson UIN-723003473
// CSCE 121-515 Group-17
// Project-Part 4
// "Prime_window.h"

#include "GUI.h"
#include "Graph.h"
#include "Game_window.h"

using namespace Graph_lib;

// Class for window to start priming computer with a record of guesses
struct Prime_window : Graph_lib::Window {
    Prime_window(Point xy, int w, int h, const string& title, int diff_level,
		string initial);

private:   
	Button rock_button;		// 1st choice button
	Button paper_button;	// 2nd choice button
	Button scissor_button;	// 3rd choice button
	Button quit_button;		// close game button
	
	Image background;		// background image will cover buttons
	Rectangle mock_quit;	// rectangle to go over background, button_quit
	Text mock_quit_text;	// text to go over background, button_quit
	Rectangle mock_rock;	// rectangle to go over background, rock_button
	Text mock_rock_text;	// text to go over background, rock_button
	Rectangle mock_paper;	// rectangle to go over background, paper_button
	Text mock_paper_text;	// text to go over background, paper_button
	Rectangle mock_scissor;	// rectangle to go over background, scissor_button
	Text mock_scissor_text;	// text to go over background, scissor_button
	Text detail;			// instruction to be random
	Text choices_left;		// how many choices left message
	string initials;		// user initials
	
	vector<int> guesses;	// vector of past guesses (ints from 0-2)
	int diff_level;			// difficulty level (32,64,128,256,512)
	int guesses_left;		// guesses left before start of game
	
	void rock();			// updates variables with choice of option 0
	void paper();			// updates variables with choice of option 1
	void scissor();			// updates variables with choice of option 2
	void quit();			// ends game and extis window
	void color_objects(); 	// color all objects as needed
};

