// Reid Jordan - 324003349
// Part 3 - initialsheader.cpp

#include "GUI.h"    
#include "Graph.h"
#include <fstream>
#include <string>
#include "initialsheader.h"

using namespace Graph_lib;

//Constructor: creates all objects and attaches objects to be displayed
Initials_window::Initials_window(Point xy, int w, int h, const string& title, 
		int diff)
	:Window{xy,w,h,title},
	background(Point{0,0},"background.jpg"),
	background_hole(Point{0,0},"background_hole.png"),
	quit_button{Point{x_max()-70,0},70,20,"Quit",
	[](Address, Address pw){reference_to<Initials_window>(pw).quit();}},
	next_button{Point{x_max()-130,0},50,20,"Next",
	[](Address, Address pw){reference_to<Initials_window>(pw).next();}},
	start_button{Point{x_max()-150,0},70,20,"Start",
	[](Address, Address pw){reference_to<Initials_window>(pw).start();}},
	initials{Point{x_max()-235,0},100,30,"Initials"},
	initials_text{Point{x_max()-290,15},"Initials"},
	final_initials{Point{200,290},""},
	file_initials1{Point{200,50},""},
	file_initials2{Point{200,100},""},
	file_initials3{Point{200,150},""},
	file_initials4{Point{200,200},""},
	file_initials5{Point{200,250},""},
	mock_quit(Point{x_max()-70,0}, 70, 20),
	mock_quit_text(Point{x_max()-50,15}, "Quit"),
	mock_next(Point{x_max()-130,0}, 50, 20),
	mock_next_text(Point{x_max()-125,15}, "Next"),
	mock_start(Point{x_max()-150,0}, 70, 20),
	mock_start_text(Point{x_max()-135,15}, "Start"),
	difficulty_level{diff}
	{
		file_initials1.set_label(line1());	// set labels for the 5 top scores
		file_initials2.set_label(line2());
		file_initials3.set_label(line3());
		file_initials4.set_label(line4());
		file_initials5.set_label(line5());
		color_objects();					// color all objects
		
		attach(background_hole);			// attach objects needed now
		attach(quit_button);
		attach(next_button);
		attach(start_button);
		attach(initials);
		attach(initials_text);
		attach(file_initials1);
		attach(file_initials2);
		attach(file_initials3);
		attach(file_initials4);
		attach(file_initials5);
		attach(final_initials);
		attach(mock_quit);
		attach(mock_quit_text);
		attach(mock_next);
		attach(mock_next_text);
		start_button.hide();
	}

//Gets 1st line of file since sorting is not necessary at this point
string Initials_window::line1() 
{
	string value1, value2;
	ostringstream file_name;
	file_name << "difficulty" << difficulty_level << ".txt";    // e.g., difficulty1.txt
	ifstream ist{file_name.str()};
	ist >> value1 >> value2;
	return value1 + " - " + value2;
}

//Gets 2nd line of file since sorting is not necessary at this point
string Initials_window::line2() 
{
	int i = 0;
	string value1, value2;
	ostringstream file_name;
	file_name << "difficulty" << difficulty_level << ".txt";    
	ifstream ist{file_name.str()};
	for (i = 0; i < 2; ++i) {
		ist >> value1 >> value2;
		}
	return value1 + " - " + value2;
}

//Gets 3rd line of file since sorting is not necessary at this point
string Initials_window::line3() 
{
	int i = 0;
	string value1, value2;
	ostringstream file_name;
	file_name << "difficulty" << difficulty_level << ".txt";    
	ifstream ist{file_name.str()};
	for (i = 0; i < 3; ++i) {
		ist >> value1 >> value2;
		}
	return value1 + " - " + value2;
}

//Gets 4th line of file since sorting is not necessary at this point
string Initials_window::line4() 
{
	int i = 0;
	string value1, value2;
	ostringstream file_name;
	file_name << "difficulty" << difficulty_level << ".txt";    
	ifstream ist{file_name.str()};
	for (i = 0; i < 4; ++i) {
		ist >> value1 >> value2;
		}
	return value1 + " - " + value2;
}

//Gets 5th line of file since sorting is not necessary at this point
string Initials_window::line5() 
{
	int i = 0;  //Gets 5th line of file since sorting is not necessary at this point
	string value1, value2;
	ostringstream file_name;
	file_name << "difficulty" << difficulty_level << ".txt";    
	ifstream ist{file_name.str()};
	for (i = 0; i < 5; ++i) {
		ist >> value1 >> value2;
		}
	return value1 + " - " + value2;
}

// end game and close window
void Initials_window::quit()
{
	hide();
}

// displays initials under top scores and hides in-box 
void Initials_window::next()
{
	start_button.show();		// hide in-box and show start button
	next_button.hide();
	attach(background);
	attach(mock_start);
	attach(mock_start_text);
	initials.hide();
	detach(initials_text);
	detach(background_hole);
	detach(mock_next);
	detach(mock_next_text);
	
	reorder();		// put new background on bottom
	
	initial_string = initials.get_string(); //Gets user inputted initials
	if (initial_string == "") initial_string = "---";
	ostringstream ss; //Write initials and starting score (0) to end of file
    ss << initial_string << " - 0";
    final_initials.set_label(ss.str());

	redraw();
}

// goes to next window
void Initials_window::start() 
{
	hide(); 
	Prime_window* p_win = new Prime_window {Point{100,100},600,400, "GOT_Parody", 
			difficulty_level,initial_string};
}

// colors all objects whose color needs to be changed
void Initials_window::color_objects()
{
	mock_quit.set_fill_color(Color::white);
	mock_next.set_fill_color(Color::white);
	mock_start.set_fill_color(Color::white);
	initials_text.set_color(Color::white);
	file_initials1.set_color(Color::white);
	file_initials2.set_color(Color::white);
	file_initials3.set_color(Color::white);
	file_initials4.set_color(Color::white);
	file_initials5.set_color(Color::white);
	final_initials.set_color(Color::white);
}	

// put objects in correct order inorder to be visible
void Initials_window::reorder()
{
	put_on_top(mock_quit);
	put_on_top(mock_quit_text);
	put_on_top(file_initials1);
	put_on_top(file_initials2);
	put_on_top(file_initials3);
	put_on_top(file_initials4);
	put_on_top(file_initials5);
	put_on_top(final_initials);
}	