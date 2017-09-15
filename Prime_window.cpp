// Haley Hutson UIN-723003473	
// CSCE 121-515 Group-17
// Project-Part 4
// Prime_window.cpp

#include "Prime_window.h"
#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

// Constructor: creates objects, attaches them, and initializes variables
Prime_window::Prime_window(Point xy,int w, int h, const string& title, int diff, 
				string initial) 
	:Window{xy,w,h,title},
	rock_button{Point{w/20,(h/5)*2},5*w/20,h/5,"Jon Snow", 
		[](Address, Address pw){reference_to<Prime_window>(pw).rock();}},
	paper_button{Point{7*w/20,(h/5)*2},5*w/20,h/5,"Cersei Lannister", 
		[](Address, Address pw){reference_to<Prime_window>(pw).paper();}},
	scissor_button{Point{13*w/20,(h/5)*2},6*w/20,h/5,"Daenerys Targaryen", 
		[](Address, Address pw){reference_to<Prime_window>(pw).scissor();}},	
	quit_button{Point{x_max()-70,0},70,20,"Quit", 
		[](Address, Address pw){reference_to<Prime_window>(pw).quit();}},
	background(Point{0,0},"background.jpg"),
	mock_quit(Point{x_max()-70,0}, 70, 20),
	mock_quit_text(Point{x_max()-50,15}, "Quit"),
	mock_rock(Point{w/20,(h/5)*2},5*w/20,h/5),
	mock_rock_text(Point{w/20+40,(h/5)*2+45}, "Jon Snow"),
	mock_paper(Point{7*w/20,(h/5)*2},5*w/20,h/5),
	mock_paper_text(Point{7*w/20+20,(h/5)*2+45}, "Cersei Lannister"),
	mock_scissor(Point{13*w/20,(h/5)*2},6*w/20,h/5),
	mock_scissor_text(Point{13*w/20+20,(h/5)*2+45}, "Daenerys Targaryen"),
	detail{Point{w/10,h/5}, "Please pick who to kill as randomly as possible, like George R. R. Martin."},
	initials{initial},
	guesses{},
	choices_left{Point{w/5,3*h/10}, "Choices remaining:"}
{		
	diff_level = pow(2,diff+4);
	guesses_left = diff_level;
	color_objects();
	
	ostringstream ss;				// make correct label for choices_left 
	ss << "Choices remaining: " << guesses_left; 
	ss << "; click one of the three choices.";
	choices_left.set_label(ss.str());
	
	attach(rock_button);
	attach(paper_button);
	attach(scissor_button);
	attach(background);
	attach(mock_quit);
	attach(mock_quit_text);
	attach(mock_rock);
	attach(mock_rock_text);
	attach(mock_paper);
	attach(mock_paper_text);
	attach(mock_scissor);
	attach(mock_scissor_text);
	attach(choices_left);
	attach(quit_button);
	attach(detail);
}	
	
// user pushed option 0, update variables and redraw window or draw next window	
void Prime_window::rock()
{
	// update variables
	--guesses_left;
	guesses.push_back(0);
	
	// go to next window if done with all guesses
	if(guesses_left == 0) {
		hide();
		Game_window* g_win = new Game_window {Point{100,100},600,400, "GOT_Parody", 
			diff_level, initials, guesses};
		return;
	}	
	
	// redraw window with updated objects
	ostringstream ss;
	ss << "Choices remaining: " << guesses_left;
	ss << "; click one of the three choices.";
	choices_left.set_label(ss.str());
	redraw();
}

// user pushed option 1, update variables and redraw window or draw next window	
void Prime_window::paper()
{
	// update variables
	--guesses_left;
	guesses.push_back(1);
	
	// go to next window if done with all guesses
	if(guesses_left == 0) {
		hide();
		Game_window* g_win = new Game_window {Point{100,100},600,400, "GOT_Parody", 
			diff_level, initials, guesses};
		return;
	}	
	
	// redraw window with updated objects
	ostringstream ss;
	ss << "Choices remaining: " << guesses_left;
	ss << "; click one of the three choices.";
	choices_left.set_label(ss.str());
	redraw();
}

// user pushed option 2, update variables and redraw window or draw next window	
void Prime_window::scissor()
{
	// update variables
	--guesses_left;
	guesses.push_back(2);
	
	// go to next window if done with all guesses
	if(guesses_left == 0) {
		hide();
		Game_window* g_win = new Game_window {Point{100,100},600,400, "GOT_Parody", 
			diff_level, initials, guesses};
		return;
	}	
	
	// redraw window with updated objects
	ostringstream ss;
	ss << "Choices remaining: " << guesses_left;
	ss << "; click one of the three choices.";
	choices_left.set_label(ss.str());
	redraw();
}	
	
// end game and exit window	
void Prime_window::quit() 
{
	hide();
}
// color all objects that need their color changed from black
void Prime_window::color_objects()
{
	mock_quit.set_fill_color(Color::white);
	mock_rock.set_fill_color(Color::white);
	mock_paper.set_fill_color(Color::white);
	mock_scissor.set_fill_color(Color::white);
	detail.set_color(Color::white);
	choices_left.set_color(Color::white);
}	

	
