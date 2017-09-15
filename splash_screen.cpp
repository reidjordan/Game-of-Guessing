// Francis Jacob Herron 924009805
// Part 1 splash_screen.cpp

#include "splash_screen.h"
#include "instruct_screen.h"

// Constructor: attach all objects with correct color, size, and positioning
Splash_window::Splash_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	start_button(Point{250,300}, 90, 20, "Start Game", cb_start),
	game_of_thrones(Point{0,0},"GOT.jpg"),
	mock_start(Point{250,300}, 90, 20),
	mock_start_text(Point{256,315}, "Start Game"),
	game_title(Point{60, 125}, "Guessing Game of Thrones"),
	team_number(Point{370, 315},"cin >> team_name aka Team 17"),
	team_name_1(Point{60, 300},"Haley A. Hutson"),
	team_name_2(Point{63, 315},"F. Jacob Herron"),
	team_name_3(Point{66, 330},"Reid A. Jordan")
	{
		game_title.set_font_size(35);	// change font size of title
		color_objects();				// color objects correct color
		
		attach(start_button);			// attach all objects
		attach(game_of_thrones);
		attach(mock_start);
		attach(mock_start_text);
		attach(game_title);
		attach(team_number);
		attach(team_name_1);
		attach(team_name_2);
		attach(team_name_3);
	}
	
// function performed once start button hit, goes to instruction window	
void Splash_window::start()
{
	hide();
	Instruct_window* i_win = new Instruct_window(Point(100, 100), 600, 400, 
			"Instruct_Screen");
}

// function called when start button hit, links to start function
void Splash_window::cb_start(Address, Address pw)
{
 	reference_to<Splash_window>(pw).start(); 
}

// colors all objects the corect color aka white
void Splash_window::color_objects()
{
	mock_start.set_fill_color(Color::white);
	mock_start.set_color(Color::dark_blue);
	game_title.set_color(Color::white);
	team_number.set_color(Color::white);
	team_name_1.set_color(Color::white);
	team_name_2.set_color(Color::white);
	team_name_3.set_color(Color::white);
}	
	