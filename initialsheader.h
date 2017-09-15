// Reid Jordan - 324003349
// Part 3 - initialsheader.h

#include "GUI.h"   
#include "Graph.h"
#include <fstream>
#include <string>
#include "Prime_window.h"

using namespace Graph_lib;

// Class for window that recieves initials and displays them with top scores
struct Initials_window : Graph_lib::Window {
	Initials_window(Point xy, int w, int h, const string& title, int diff);
private:
	Image background_hole;	// background w/ hole in it for in-box for intials
	Image background; 		// background w/o hole in it for in-box
	Button quit_button;		// button to end and exit game
	Button next_button;		// button to input the initials in inbox
	Button start_button;	// button to start the next portion of game
	
	In_box initials;		// box to type initials into
	Text initials_text;		// text for in-box
	Text final_initials;	// prints out initials inputed into inbox
	Text file_initials1;	// contains first top score and intials
	Text file_initials2;	// contains second top score and intials
	Text file_initials3;	// contains third top score and intials
	Text file_initials4;	// contains fourth top score and intials
	Text file_initials5;	// contains fifth top score and intials
	
	Rectangle mock_quit;	// rectangle to go over background, quit_button
	Text mock_quit_text;	// text to go over background, quit_button
	Rectangle mock_next;	// rectangle to go over background, next_button
	Text mock_next_text;	// text to go over background, next_button
	Rectangle mock_start;	// rectangle to go over background, start_button
	Text mock_start_text;	// text to go over background, start_button
	
	string initial_string;		// contains user-inputed string after inputed
	int difficulty_level;	// contains difficulty level (1-5)
	
	void quit();			// exits game
	void next();			// displays initials with top scores
	void start();			// goes to next window	
	void color_objects();	// color all objects that need their color changed
	void reorder();			// reorde objects to put new background in back
	string line1();			// gets string for final_initials1
	string line2();			// gets string for final_initials2
	string line3();			// gets string for final_initials3
	string line4();			// gets string for final_initials4
	string line5();			// gets string for final_initials5
};
	
