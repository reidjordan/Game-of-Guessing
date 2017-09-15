// TEAM 17 aka cin >> team_name
// TEAM MEMBERS: Haley Hutson, Francis Jacob Herron, Reid Jordan

#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "splash_screen.h"

int main()
try {
	// open up starting window, then wait for user action
	Splash_window win(Point{100, 100},600, 400, "Start_Screen");
	return gui_main();
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
