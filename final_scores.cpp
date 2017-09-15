//Francis Jacob Herron 924009805
// Part 6 - final_scores.cpp

#include "final_scores.h"
#include "splash_screen.h"

// Constructor: create objects, attach them, and rewrite top scores final
Final_window::Final_window(Point xy, int w, int h, const string& title, 
			int difficulty_level, string initials, int score)
	:Window(xy, w, h, title),
	background(Point(0,0), "meme.jpg"),
	quit_button(Point(350,300), 100, 30, "Quit Game", cb_quit),
	new_game_button(Point(150,300), 100, 30, "New Game",cb_new_game),
	mock_quit(Point(350,300), 100, 30),
	mock_quit_text(Point(360,320), "Quit Game"),
	mock_new(Point(150,300), 100, 30),
	mock_new_text(Point(160,320), "New Game")
	{
		mock_quit.set_fill_color(Color::white);
		mock_new.set_fill_color(Color::white);
		attach(background);
		attach(quit_button);
		attach(new_game_button);
		attach(mock_quit);
		attach(mock_quit_text);
		attach(mock_new);
		attach(mock_new_text);
		rewrite(initials, score, difficulty_level);
	}
	
// end game and exit window	
void Final_window::quit(){
	hide();
}

void Final_window::cb_quit(Address, Address pw){
 	reference_to<Final_window>(pw).quit(); 
}

void Final_window::new_game(){
	hide();
	Splash_window* s_win = new Splash_window(Point(100, 100), 600, 400, 
		"Splash_Screen");
}

void Final_window::cb_new_game(Address, Address pw){
	reference_to<Final_window>(pw).new_game();
}

void Final_window::rewrite(string new_initials, int new_score, 
			int difficulty_level){
	ostringstream fileName;
	fileName << "difficulty" << difficulty_level << ".txt";
	ifstream ist{fileName.str()};
	if (!ist)error("can't open file");
	
	vector<Top_scores> sl;
	string initials;
	int score;
	
	while(ist >> initials >> score){
		sl.push_back(Top_scores{initials, score});
	}
	sl.push_back(Top_scores{new_initials, new_score});
	ist.close();
	
	bubble_sort(sl);
	
	ofstream ost{fileName.str()};
	for(int k = 0; k < 5; ++k){
		 ost << sl[k].initials << "	" << sl[k].score << "\n";
	}
	ost.close();
}

void Final_window::bubble_sort(vector<Top_scores>& sl){
	int i = 0;
	while(i < 6){
		for(unsigned int j = 0; j < sl.size() - 1; ++j){
			if(sl[j].score < sl[j + 1].score){
				swap(sl[j].score, sl[j + 1].score);
				swap(sl[j].initials, sl[j + 1].initials);
			}
		}
		++i;
	}
}