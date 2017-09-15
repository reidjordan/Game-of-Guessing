// Haley Hutson UIN-723003473	
// CSCE 121-515 Group-17
// Project-Part 5
// "Game_window.cpp"

#include "Game_window.h"
#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;


// Constructor: create objects, initialize variables, attach needed objects
Game_window::Game_window(Point xy,int w, int h, const string& title, int diff, 
				string initial, vector<int> guess) 
	:Window{xy,w,h,title},
	start_button{Point{3*w/10,h/5*3},2*w/5,h/5,"Start earning points!",
		[](Address, Address pw){reference_to<Game_window>(pw).start();}},
	rock_button{Point{w/20,(h/5)*2},5*w/20,h/5,"Jon Snow", 
		[](Address, Address pw){reference_to<Game_window>(pw).rock();}},
	paper_button{Point{7*w/20,(h/5)*2},5*w/20,h/5,"Cersei Lannister", 
		[](Address, Address pw){reference_to<Game_window>(pw).paper();}},
	scissor_button{Point{13*w/20,(h/5)*2},6*w/20,h/5,"Daenerys Targaryen", 
		[](Address, Address pw){reference_to<Game_window>(pw).scissor();}},	
	quit_button{Point{x_max()-70,0},70,20,"Quit", 
		[](Address, Address pw){reference_to<Game_window>(pw).quit();}},
	cont_button{Point{(w/10)*4,(h/10)*4},w/5,h/5,"Continue",
		[](Address, Address pw){reference_to<Game_window>(pw).cont();}},
	background(Point{0,0},"background.jpg"),
	mock_start(Point{3*w/10,h/5*3},2*w/5,h/5),
	mock_start_text(Point{3*w/10+50,h/5*3+45}, "Start earning points!"),
	mock_quit(Point{x_max()-70,0}, 70, 20),
	mock_quit_text(Point{x_max()-50,15}, "Quit"),
	mock_rock(Point{w/20,(h/5)*2},5*w/20,h/5),
	mock_rock_text(Point{w/20+40,(h/5)*2+45}, "Jon Snow"),
	mock_paper(Point{7*w/20,(h/5)*2},5*w/20,h/5),
	mock_paper_text(Point{7*w/20+20,(h/5)*2+45}, "Cersei Lannister"),
	mock_scissor(Point{13*w/20,(h/5)*2},6*w/20,h/5),
	mock_scissor_text(Point{13*w/20+20,(h/5)*2+45}, "Daenerys Targaryen"),
	mock_cont(Point{(w/10)*4,(h/10)*4},w/5,h/5),
	mock_cont_text(Point{(w/10)*4+25,(h/10)*4+45}, "Continue"),
	result{Point{w/10,h/5}, "You win for now - win 10 points."},
	instruction{Point{w/10,h/5}, "Please choose who will die. Be as random as possible!"},
	score_text{Point{0,20}, "Score: 0"},
	computer_score{Point{w/10,(h/10)*7}, "The computer has guessed correctly"},
	initials{initial},
	guesses{guess},
	diff_level{diff},
	guesses_left{diff},
	past_guess{guess[guess.size()-diff_level]},
	score{0},
	computer_percent{0},
	rock_percent{1.0*rock_hits/diff_level},
	paper_percent{1.0*paper_hits/diff_level},
	rock_hits{0},
	paper_hits{0},
	scissor_hits{0}
{
	rand_number = rand() % 101 / 100.0;
	if (rand_number < rock_percent) computer_guess = 0;
	else if (rand_number < (rock_percent+paper_percent)) computer_guess = 1;
	else computer_guess = 2;
	
	ostringstream st;
	st << "The computer has guessed correctly " << computer_percent;
	st << "% of the time.";
	computer_score.set_label(st.str());
	
	for (int i : guesses) {
		if (i == 0) ++rock_hits;
		else if (i == 1) ++paper_hits;
		else ++scissor_hits;
	}	
	
	color_objects();
	
	attach(start_button);
	attach(background);
	attach(mock_start);
	attach(mock_start_text);
}	

// move to guessing by adding and removing objects	
void Game_window::start()
{
	detach(start_button);
	detach(mock_start);
	detach(mock_start_text);
	attach(computer_score);
	attach(rock_button);
	attach(paper_button);
	attach(scissor_button);
	attach(quit_button);
	attach(mock_quit);
	attach(mock_quit_text);
	attach(mock_rock);
	attach(mock_rock_text);
	attach(mock_paper);
	attach(mock_paper_text);
	attach(mock_scissor);
	attach(mock_scissor_text);
	attach(instruction);
	attach(score_text);
}	

// update variables with guess 0, and show result
void Game_window::rock()
{
	move_guess_objects();
	
	if (computer_guess==0) {
		result.set_label("You know nothing Jon Snow - win 0 points.");
	}	
	else {
		result.set_label("You win for now - win 10 points.");
		score = score+10;
	}
	
	--guesses_left;
	comp_percent();
	update_score(0);
	++rock_hits;
	if (past_guess == 0) --rock_hits;
	else if (past_guess == 1) --paper_hits;
	else --scissor_hits;
	redraw();
}

// update variables with guess 1, and show result
void Game_window::paper()
{
	move_guess_objects();
	
	if (computer_guess==1) {
		result.set_label("You know nothing Jon Snow - win 0 points.");
	}	
	else {
		result.set_label("You win for now - win 10 points.");
		score = score+10;
	}	
	--guesses_left;
	comp_percent();
	update_score(1);
	++paper_hits;
	if (past_guess == 0) --rock_hits;
	else if (past_guess == 1) --paper_hits;
	else --scissor_hits;
	redraw();
}

// update variables with guess 2, and show result
void Game_window::scissor()
{
	move_guess_objects();
	
	if (computer_guess==2) {
		result.set_label("You know nothing Jon Snow - win 0 points.");
	}	
	else {
		result.set_label("You win for now - win 10 points.");
		score = score+10;
	}	
	--guesses_left;
	comp_percent();
	update_score(2);
	++scissor_hits;
	if (past_guess == 0) --rock_hits;
	else if (past_guess == 1) --paper_hits;
	else --scissor_hits;
	redraw();
}

// end game and exit window
void Game_window::quit() 
{
	hide();
}	

// go to next window if ended, else go to next guess and get computer's guess
void Game_window::cont()
{
	if(guesses_left == 0) {
		hide();
		Final_window* f_win = new Final_window{Point{100,100}, 630, 423, 
			"GOT Parody", static_cast<int>(log2(diff_level) - 4), initials,
				score};
		return;
	}	
	
	past_guess = guesses[guesses.size()-diff_level]; // get computer's guess
	rand_number = rand() % 101 / 100.0;
	rock_percent = rock_hits/1.0/diff_level;
	paper_percent = paper_hits/1.0/diff_level;
	if (rand_number < rock_percent) computer_guess = 0;
	else if (rand_number < (rock_percent+paper_percent)) computer_guess = 1;
	else computer_guess = 2;
	
	move_result_objects();
	redraw();
}	

// move objects on and off screen for result
void Game_window::move_result_objects() 
{
	attach(rock_button);
	attach(paper_button);
	attach(scissor_button);
	attach(mock_rock);
	attach(mock_rock_text);
	attach(mock_paper);
	attach(mock_paper_text);
	attach(mock_scissor);
	attach(mock_scissor_text);
	attach(instruction);
	detach(result);
	detach(cont_button);
	detach(mock_cont);
	detach(mock_cont_text);
}	

// move objects on and off screen for next guess
void Game_window::move_guess_objects()
{
	detach(rock_button);
	detach(paper_button);
	detach(scissor_button);
	detach(mock_rock);
	detach(mock_rock_text);
	detach(mock_paper);
	detach(mock_paper_text);
	detach(mock_scissor);
	detach(mock_scissor_text);
	detach(instruction);
	attach(cont_button);
	attach(mock_cont);
	attach(mock_cont_text);
	attach(result);
}	

// compute the computer's percentage right
void Game_window::comp_percent()
{
	double guesses_right = diff_level-guesses_left-score/10.0;
	computer_percent = 100.0*guesses_right/(diff_level-guesses_left);
	ostringstream st;
	st << "The computer has guessed correctly " << computer_percent; 
	st << "% of the time.";
	computer_score.set_label(st.str());
}	

// change the score text 
void Game_window::update_score(int guess)
{
	ostringstream ss;
	ss << "Score: " << score;
	score_text.set_label(ss.str());
	guesses.push_back(guess); 
}		

// color all objects as needed
void Game_window::color_objects()
{
	mock_start.set_fill_color(Color::white);
	mock_cont.set_fill_color(Color::white);
	mock_quit.set_fill_color(Color::white);
	mock_rock.set_fill_color(Color::white);
	mock_paper.set_fill_color(Color::white);
	mock_scissor.set_fill_color(Color::white);
	result.set_color(Color::white);
	instruction.set_color(Color::white);
	score_text.set_color(Color::white);
	computer_score.set_color(Color::white);
}
