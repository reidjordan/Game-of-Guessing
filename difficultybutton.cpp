// Reid Jordan - 324003349
// Part 2 - difficultybutton.cpp

#include "GUI.h"    
#include "Graph.h"
#include "difficultybutton.h"

using namespace Graph_lib;

// Constructor: create objects with correct color and attach them to window
Diff_window::Diff_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	quit_button{Point{x_max()-70,0},70,20,"Quit",
	[](Address, Address pw){reference_to<Diff_window>(pw).quit();}},
	difficulty_1{Point{200,50},160,20,"Ned Stark - 1",
	[](Address, Address pw){reference_to<Diff_window>(pw).diff_1();}},
	difficulty_2{Point{200,125},160,20,"Mad King - 2",
	[](Address, Address pw){reference_to<Diff_window>(pw).diff_2();}},
	difficulty_3{Point{200,200},160,20,"Dragon - 3",
	[](Address, Address pw){reference_to<Diff_window>(pw).diff_3();}},
	difficulty_4{Point{200,275},160,20,"White Walker - 4",
	[](Address, Address pw){reference_to<Diff_window>(pw).diff_4();}},
	difficulty_5{Point{200,350},160,20,"God of Light - 5",
	[](Address, Address pw){reference_to<Diff_window>(pw).diff_5();}},
	background(Point{0,0},"background.jpg"),
	mock_quit(Point{x_max()-70,0}, 70, 20),
	mock_quit_text(Point{x_max()-50,15}, "Quit"),
	mock_diff1(Point{200,50}, 160, 20),
	mock_diff1_text(Point{240,65}, "Ned Stark - 1"),
	mock_diff2(Point{200,125}, 160, 20),
	mock_diff2_text(Point{240,140}, "Mad King - 2"),
	mock_diff3(Point{200,200}, 160, 20),
	mock_diff3_text(Point{245,215}, "Dragon - 3"),
	mock_diff4(Point{200,275}, 160, 20),
	mock_diff4_text(Point{225,290}, "White Walker - 4"),
	mock_diff5(Point{200,350}, 160, 20),
	mock_diff5_text(Point{227,365}, "God of Light - 5"),
	diff_words{Point{50,20},"Choose a difficulty level"}
	{
		color_objects();		// color all objects
		attach(quit_button);	// attach all objects
		attach(difficulty_1);
		attach(difficulty_2);
		attach(difficulty_3);
		attach(difficulty_4);
		attach(difficulty_5);
		attach(background);
		attach(mock_quit);
		attach(mock_quit_text);
		attach(mock_diff1);
		attach(mock_diff1_text);
		attach(mock_diff2);
		attach(mock_diff2_text);
		attach(mock_diff3);
		attach(mock_diff3_text);
		attach(mock_diff4);
		attach(mock_diff4_text);
		attach(mock_diff5);
		attach(mock_diff5_text);
		attach(diff_words);
	}
	
// end game 	
void Diff_window::quit()
{
	hide();
}

//Stores difficulty level as 1 when selected and goes to next window
void Diff_window::diff_1() 
{
	hide();
	difficulty_level = 1;
	Initials_window* i_win = new Initials_window {Point{100,100},600,400, 
		"GOT_Parody",difficulty_level};
}

//Stores difficulty level as 2 when selected and goes to next window
void Diff_window::diff_2() 
{
	difficulty_level = 2;
	Initials_window* i_win = new Initials_window {Point{100,100},600,400, 
		"GOT_Parody",difficulty_level};
	hide();
}

//Stores difficulty level as 3 when selected and goes to next window
void Diff_window::diff_3() 
{
	difficulty_level = 3;
	Initials_window* i_win = new Initials_window {Point{100,100},600,400, 
		"GOT_Parody",difficulty_level};
	hide();
}

//Stores difficulty level as 4 when selected and goes to next window
void Diff_window::diff_4() 
{
	difficulty_level = 4;
	Initials_window* i_win = new Initials_window {Point{100,100},600,400, 
		"GOT_Parody",difficulty_level};
	hide();
}

//Stores difficulty level as 5 when selected and goes to next window
void Diff_window::diff_5() 
{
	difficulty_level = 5;
	Initials_window* i_win = new Initials_window {Point{100,100},600,400, 
		"GOT_Parody",difficulty_level};
	hide();
}

// color all objects correct color aka white
void Diff_window::color_objects()
{
	mock_quit.set_fill_color(Color::white);
	mock_diff1.set_fill_color(Color::white);
	mock_diff2.set_fill_color(Color::white);
	mock_diff3.set_fill_color(Color::white);
	mock_diff4.set_fill_color(Color::white);
	mock_diff5.set_fill_color(Color::white);
	diff_words.set_color(Color::white);
}	