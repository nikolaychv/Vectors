#ifndef INCLUDED_MENU_H
#define INCLUDED_MENU_H
#include <fstream>
#include "Tetrahedron.h"

static bool finished = false; // indicates whether the user has finished with the main menu or not
static bool inFile = false; // indicates whether the input will be from a file or not

class Menu {
public:
	int main_menu(); // Main menu
	void point_menu(); // Point menu
	void vector_menu(); // Vector menu
	void line_menu(); // Line menu
	void segment_menu(); // Segment menu
	void triangle_menu(); // Triangle menu
	void tetrahedron_menu(); // Tetrahedron menu
};

#endif