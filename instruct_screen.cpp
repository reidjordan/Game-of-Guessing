// Francis Jacob Herron 924009805
// Part 1 - instruct_screen.cpp

#include "instruct_screen.h"

Instruct_window::Instruct_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	background(Point{0,0},"background.jpg"),
	mock_diff(Point{235,300}, 130, 20),
	mock_diff_text(Point{240,315}, "Choose Difficulty"),
	instructions(Point(260, 20),"HOW TO PLAY"),
	instructions1(Point(50, 70),"Start off by choosing a difficulty, there are 5 difficulties"),
	instructions2(Point(50, 110),"After choosing a difficulty, enter your initials in the box and hit next to continue."),
	instructions3(Point(50, 130),"Next enter your choices for who will die, and pick as randomly as possible."),
	instructions4(Point(50, 150),"Do this by clicking one of the three buttons on the screen"),
	instructions5(Point(50, 180),"The object of the game is to outsmart the computer aka the reader."),
	instructions6(Point(50, 200),"When the game starts make your choice again for who dies."),
	instructions7(Point(50, 220),"For every guess, if the computer guesses correctly, you get no points."),
	instructions8(Point(50, 240),"If the computer is incorrect, you get 10 points."), 
	instructions9(Point(50, 260),"When the game is over you may quit or start a new game."),
	difficulty_button(Point{235, 300}, 130, 20, "Choose Difficulty", cb_difficulty)
	{
		color_objects(); 		// color all objects 
		attach(background);		// attach all objects
		attach(mock_diff);
		attach(mock_diff_text);
		attach(instructions);
		attach(instructions1);
		attach(instructions2);
		attach(instructions3);
		attach(instructions4);
		attach(instructions5);
		attach(instructions6);
		attach(instructions7);
		attach(instructions8);
		attach(instructions9);
		attach(difficulty_button);
	}
	
// goes to next window	
void Instruct_window::diff_select()
{
	hide();
	Diff_window* d_win = new Diff_window {Point(100,100),600,400,"Difficulty"};
}

// color all objects correct color aka white
void Instruct_window::color_objects()
{
		mock_diff.set_fill_color(Color::white);
		instructions.set_color(Color::white);
		instructions1.set_color(Color::white);
		instructions2.set_color(Color::white);
		instructions3.set_color(Color::white);
		instructions4.set_color(Color::white);
		instructions5.set_color(Color::white);
		instructions6.set_color(Color::white);
		instructions7.set_color(Color::white);
		instructions8.set_color(Color::white);
		instructions9.set_color(Color::white);
}	

// callback function for difficulty button, calls diff_select function
void Instruct_window::cb_difficulty(Address, Address pw)
{
 	reference_to<Instruct_window>(pw).diff_select(); 
}