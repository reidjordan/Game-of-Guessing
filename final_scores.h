//Francis Jacob Herron 924009805
// Part 6 - final_scores.h

#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Window.h"
#include "Simple_window.h"

using namespace Graph_lib;

// class for structure representing a line in the top scores file
struct Top_scores{
	string initials;
	int score;
};

// class for the final window of the game that also updates the top scores file
struct Final_window : Graph_lib::Window{
	Final_window(Point xy, int w, int h, const string& title, 
		int difficulty_level, string initials, int score);
	

private:
	Button quit_button;		// button to end game and exit
	Button new_game_button;	// button to start a new game
	Image background;		// background image
	Rectangle mock_quit; 	// rectangle to go over quit button and background
	Text mock_quit_text;	// text to go over quit button and background
	Rectangle mock_new;		// rectangle to go over new game button and background
	Text mock_new_text;		// text to go over new game button and background
	
	void quit();			// ends game and closes window
	void new_game();		// goes to starting window
	
	// rewrites the top scores list with updated 5 top scores
	void rewrite(string new_initials, int new_score, int difficulty_level);
	void bubble_sort(vector<Top_scores>& sl);	// sorts scores
	
	static void cb_quit(Address, Address window);	 // callback function:quit
	static void cb_new_game(Address, Address window);// callback function:new_game
	
};


