// Haley Hutson UIN-723003473	
// CSCE 121-515 Group-17
// Project-Part 5
// "Game_window.h"

#include "GUI.h"
#include "Graph.h"
#include "final_scores.h"

using namespace Graph_lib;

// Class for window that asks for a guess and displays result of that guess
struct Game_window : Graph_lib::Window {
	Game_window(Point xy, int w, int h, const string& title, int diff, 
		string intial, vector<int> guess);
private:   
	Button start_button; 	// start the point part of the game
	Button rock_button;		// option 1 button
	Button paper_button;	// option 2 button
	Button scissor_button;	// option 3 button
	Button quit_button;		// exit the window and end game button
	Button cont_button;		// continue to next guess button
	
	Image background;		// background image will cover buttons
	Rectangle mock_start;	// rectangle to go over background, start_button
	Text mock_start_text;	// text to go over background, start_button
	Rectangle mock_quit;	// rectangle to go over background, button_quit
	Text mock_quit_text;	// text to go over background, button_quit
	Rectangle mock_rock;	// rectangle to go over background, rock_button
	Text mock_rock_text;	// text to go over background, rock_button
	Rectangle mock_paper;	// rectangle to go over background, paper_button
	Text mock_paper_text;	// text to go over background, paper_button
	Rectangle mock_scissor;	// rectangle to go over background, scissor_button
	Text mock_scissor_text;	// text to go over background, scissor_button
	Rectangle mock_cont; 	// rectangle to go over background, cont_button
	Text mock_cont_text; 	// text to go over background, cont_button
	Text result;			// won or lost message
	Text instruction;		// instuction message for guessing
	Text score_text;		// current score message
	Text computer_score;	// percentage computer guessed correctly message
	
	string initials;		// user initials
	vector<int> guesses;	// vector of past guesses
	int diff_level;			// difficulty level of the game (32,64,128,256,512)
	int guesses_left;		// how many guesses the user still has
	int computer_guess;		// choice the computer will pick
	int rock_hits;			// number of times rock's hit in past 'diff' guesses
	int paper_hits;			// number of times paper's hit in past 'diff' guesses
	int scissor_hits;		// number of times scissor's hit in past 'diff' guesses
	int past_guess;			// the 1st guess of the past 'difficulty' guesses
	int score;				// current score of user
	double computer_percent;// current percentage computer guessed correctly
	double rock_percent;	// percent the rock was chosen in past 'diff' guesses
	double paper_percent;	// percent the paper was chosen in past 'diff' guesses
	double rand_number;		// random number from 0 to 100
	
	void move_guess_objects();		// remove and add objects for result
	void move_result_objects();		// remove and add objects for next guess
	void comp_percent();			// calculate new computer_percent
	void update_score(int guess);	// update current score and score_text
	void color_objects();			// color all objects needed
	
	void start();			// starts this portion of the game
	void rock(); 			// user picked guess 0, update variables, show result
	void paper();			// user picked guess 1, update variables, show result
	void scissor();			// user picked guess 2, update variables, show result
	void quit();			// end game and exit window
	void cont();			// continue to next guess
	
};


	

	

