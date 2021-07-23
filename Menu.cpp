#include "Menu.h"

ofstream out_file;
ifstream in_file;

int Menu::main_menu() {
	int choice;
	cout << "Do you want to enter from a file (press 1) or enter from the console (press 2), " << endl;
	cout << "If you press anything else, the program will end." << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;

	if (choice != 1 && choice != 2) {
		cout << "Goodbye!" << endl;
		return 0;
	}

	out_file.open("ProjectVectors.txt");
	
	if (out_file.fail())
	{
		cout << "The file cannot be opened. " << endl;
		return -1;
	}

	if (choice == 1) {
		inFile = true;
		in_file.open("Vector.txt");
	}

	if (in_file.fail())
	{
		cout << "The file cannot be opened. " << endl;
		return -1;
	}

	while (!finished) {

		int object_choice;
		if (inFile) {
		in_file >> object_choice;
		}
		else {
			cout << endl;
			cout << "~~~~~~~~~~~  M E N U  ~~~~~~~~~~~" << endl;
			cout << "~~~ Select a geometric object ~~~" << endl;
			cout << "1. Point" << endl;
			cout << "2. Vector" << endl;
			cout << "3. Line" << endl;
			cout << "4. Segment" << endl;
			cout << "5. Triangle" << endl;
			cout << "6. Tetrahedron" << endl << endl;

			do {
				cout << endl;
				cout << "Enter a geometric object (Enter a number between 1 and 6): ";
				cin >> object_choice;
			} while (object_choice > 6 || object_choice < 1);

			// Another way to handle the situation
			/*
			if (object_choice > 6 || object_choice < 1) {
				cout << "Invalid input! Bye!" << endl;
				return -1;
			}
			*/
		}

			cout << endl;
			cout << "Selected: ";
			out_file << "Selected: ";
			switch (object_choice) {
			case 1:
				cout << "Point" << endl << endl;
				out_file << "Point" << endl << endl;
				point_menu();
				break;
			case 2:
				cout << "Vector" << endl << endl;
				out_file << "Vector" << endl << endl;
				vector_menu();
				break;
			case 3:
				cout << "Line" << endl << endl;
				out_file << "Line" << endl << endl;
				line_menu();
				break;
			case 4:
				cout << "Segment" << endl << endl;
				out_file << "Segment" << endl << endl;
				segment_menu();
				break;
			case 5:
				cout << "Triangle" << endl << endl;
				out_file << "Triangle" << endl << endl;
				triangle_menu();
				break;
			case 6:
				cout << "Tetrahedron" << endl << endl;
				out_file << "Tetrahedron" << endl << endl;
				tetrahedron_menu();
				break;
			}
			cout << endl;
		}

	in_file.close();
	out_file.close();

	cout << endl;
	int save_in_file_choice;
	cout << "Do you want to save the information in file? Press 1 to save the information or press anything else to not." << endl;
	cin >> save_in_file_choice;

	if (save_in_file_choice != 1)
	{
		remove("ProjectVectors.txt");
	}

	return 0;
}

void Menu::point_menu() {
	cout << endl;
	if (!inFile) {
		double x1, y1, z1;
		cout << "Enter values to initialize the first point: " << endl;
		cout << "x1: "; cin >> x1;
		cout << "y1: "; cin >> y1;
		cout << "z1: "; cin >> z1;
		Point p1(x1, y1, z1);
		cout << "P1: " << p1 << endl << endl;
		out_file << "P1: " << p1 << endl << endl;

		while (!finished) {
			int operation_choice;
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~ P O I N T - M E N U ~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~ Choose operation(1) or anything else to go to main menu ~~" << endl;
			cout << "1. Check if a point coincides with another point" << endl;
			cout << endl;
			cin >> operation_choice;

			if (operation_choice == 1) {
				double x2, y2, z2;
				cout << "Enter values to initialize the second point: " << endl;
				cout << "x2: "; cin >> x2;
				cout << "y2: "; cin >> y2;
				cout << "z2: "; cin >> z2;
				Point p2(x2, y2, z2);
				cout << "P2: " << p2 << endl << endl;
				out_file << "P2: " << p2 << endl << endl;

				if (p1 == p2) {
					cout << "The points p1 (" << p1 << ") and p2 (" << p2 << ") coincide. ( P1 == P2 )"<< endl << endl;
					out_file << "The points p1 (" << p1 << ") and p2 (" << p2 << ") coincide. ( P1 == P2 )" << endl << endl;
				}
				else {
					cout << "The points p1 (" << p1 << ") and p2 (" << p2 << ") don't coincide. ( P1 != P2 )" << endl << endl;
					out_file << "The points p1 (" << p1 << ") and p2 (" << p2 << ") don't coincide. ( P1 != P2 )" << endl << endl;
				}
				
				cout << endl;
				char another_choice;
				cout << "Do you want to select another operation? ( y / n ): ";
				cin >> another_choice;

				if (another_choice == 'y') {
					continue;
				}
				else {
					do {
						cout << endl;
						cout << "Do you want to select another object? ( y / n ): ";
						cin >> another_choice;
					} while (another_choice != 'y' && another_choice != 'n');

					if (another_choice == 'n') {
						finished = true;
						break;
					}
					else {
						break;
					}
				}

			}
			else {
				break;
			}
		}
	}
	else {
		double x1, y1, z1;
		in_file >> x1;
		in_file >> y1;
		in_file >> z1;

		Point p1(x1, y1, z1);
		out_file << "P1: " << p1 << endl << endl;

		while (!finished) {
			int operation_choice;
			in_file >> operation_choice;

			if (operation_choice == 1) {
				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Point p2(x2, y2, z2);
				out_file << "P2: " << p2 << endl << endl;

				if (p1 == p2) {
					cout << "The points p1 (" << p1 << ") and p2 (" << p2 << ") coincide. ( P1 == P2 )" << endl << endl;
					out_file << "The points p1 (" << p1 << ") and p2 (" << p2 << ") coincide. ( P1 == P2 )" << endl << endl;
				}
				else {
					cout << "The points p1 (" << p1 << ") and p2 (" << p2 << ") don't coincide. ( P1 != P2 )" << endl << endl;
					out_file << "The points p1 (" << p1 << ") and p2 (" << p2 << ") don't coincide. ( P1 != P2 )" << endl << endl;
				}

				/*
				cout << endl;
				char another_choice;
				cout << "Do you want to select another operation? ( y / n ): ";
				cin >> another_choice;

				if (another_choice == 'y') {
					continue;
				}
				else {
					do {
						cout << endl;
						cout << "Do you want to select another object? ( y / n ): ";
						cin >> another_choice;
					} while (another_choice != 'y' && another_choice != 'n');

					if (another_choice == 'n') {
						finished = true;
						break;
					}
					else {
						break;
					}
				}
				*/
				finished = true;
				break;
			}
			else {
				break;
			}
		}
	}
}


void Menu::vector_menu() {
	cout << endl;
	if (!inFile) {
		double x1, y1, z1;
		cout << "Enter values to initialize the first vector: " << endl;
		cout << "x1: "; cin >> x1;
		cout << "y1: "; cin >> y1;
		cout << "z1: "; cin >> z1;
		Vector v1(x1, y1, z1);
		cout << "V1: " << v1 << endl;
		out_file << "V1: " << v1 << endl;

		while (!finished) {
			int operation_choice;
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~ V E C T O R - M E N U ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~ Choose operation (1-10) or anything else to go to main menu ~~~~" << endl;
			cout << "1.Find the direction of vector" << endl;
			cout << "2.Find the length of vector" << endl;
			cout << "3.Zero vector check" << endl;
			cout << "4.Check if two vectors are parallel" << endl;
			cout << "5.Check if two vectors are perpendicular" << endl;
			cout << "6.Sum of two vectors" << endl;
			cout << "7.Subtraction of two vectors" << endl;
			cout << "8.Multiplication of a vector by a real number" << endl;
			cout << "9.Scalar product of two vectors" << endl;
			cout << "10.Vector product of two vectors" << endl;
			cout << "11.Mixed product of three vectors" << endl;
			cout << endl;
			cin >> operation_choice;

			if (operation_choice > 11 || operation_choice < 1) {
				break;
			}

			switch (operation_choice) {
			case 1:
			{
				cout << "Vector direction: " << v1.vector_direction() << endl;
				out_file << "Vector direction: " << v1.vector_direction() << endl;
				break;
			}
			case 2:
			{
				cout << "Vector length: " << v1.vector_length() << endl;
				out_file << "Vector length: " << v1.vector_length() << endl;
				break;
			}
			case 3:
			{
				if (v1.is_null_vector())
				{
					cout << v1 << " is NULL vector " << endl;
					out_file << v1 << " is NULL vector " << endl;
				}
				else
				{
					cout << v1 << " isn't NULL vector " << endl;
					out_file << v1 << " isn't NULL vector " << endl;
				}
				break;
			}
			case 4:
			{
				double x2, y2, z2;
				cout << "Enter values to initialize the second vector: " << endl;
				cout << "x2: "; cin >> x2;
				cout << "y2: "; cin >> y2;
				cout << "z2: "; cin >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;
				if (v1.is_parallelism(v2))
				{
					cout << v1 << " and " << v2 << " are parallel" << endl;
					out_file << v1 << " and " << v2 << " are parallel" << endl;
				}
				else
				{
					cout << v1 << " and " << v2 << " aren't parallel" << endl;
					out_file << v1 << " and " << v2 << " aren't parallel" << endl;
				}
				break;
			}
			case 5:
			{
				double x2, y2, z2;
				cout << "Enter values to initialize the second vector: " << endl;
				cout << "x2: "; cin >> x2;
				cout << "y2: "; cin >> y2;
				cout << "z2: "; cin >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;
				if (v1.is_perpendicularity(v2))
				{
					cout << v1 << " and " << v2 << " are perpendicular" << endl;
					out_file << v1 << " and " << v2 << " are perpendicular" << endl;
				}
				else
				{
					cout << v1 << " and " << v2 << " aren't perpendicular" << endl;
					out_file << v1 << " and " << v2 << " aren't perpendicular" << endl;
				}
				break;
			}
			case 6:
			{
				double x2, y2, z2;
				cout << "Enter values to initialize the second vector: " << endl;
				cout << "x2: "; cin >> x2;
				cout << "y2: "; cin >> y2;
				cout << "z2: "; cin >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				Vector v3 = v1 + v2;
				cout << v1 << " + " << v2 << " = " << v3 << endl;
				out_file << v1 << " + " << v2 << " = " << v3 << endl;
				break;
			}
			case 7:
			{
				double x2, y2, z2;
				cout << "Enter values to initialize the second vector: " << endl;
				cout << "x2: "; cin >> x2;
				cout << "y2: "; cin >> y2;
				cout << "z2: "; cin >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				Vector v3 = v1 - v2;
				cout << v1 << " - " << v2 << " = " << v3 << endl;
				out_file << v1 << " - " << v2 << " = " << v3 << endl;
				break;
			}
			case 8:
			{
				double number;
				cout << "Enter the number: " << endl;
				cin >> number;

				Vector v2 = v1 * number;
				cout << v1 << " * " << number << " = " << v2 << endl;
				out_file << v1 << " * " << number << " = " << v2 << endl;
				break;
			}
			case 9:
			{
				double x2, y2, z2;
				cout << "Enter values to initialize the second vector: " << endl;
				cout << "x2: "; cin >> x2;
				cout << "y2: "; cin >> y2;
				cout << "z2: "; cin >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				double scalarProduct = v1 * v2;
				cout << v1 << " * " << v2 << " = " << scalarProduct << endl;
				out_file << v1 << " * " << v2 << " = " << scalarProduct << endl;
				break;
			}
			case 10:
			{
				double x2, y2, z2;
				cout << "Enter values to initialize the second vector: " << endl;
				cout << "x2: "; cin >> x2;
				cout << "y2: "; cin >> y2;
				cout << "z2: "; cin >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				Vector v3 = v1 ^ v2;
				cout << v1 << " ^ " << v2 << " = " << v3 << endl;
				out_file << v1 << " ^ " << v2 << " = " << v3 << endl;
				break;
			}
			case 11:
			{
				double x2, y2, z2;
				cout << "Enter values to initialize the second vector: " << endl;
				cout << "x2: "; cin >> x2;
				cout << "y2: "; cin >> y2;
				cout << "z2: "; cin >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				double x3, y3, z3;
				cout << "Enter values to initialize the third vector: " << endl;
				cout << "x3: "; cin >> x3;
				cout << "y3: "; cin >> y3;
				cout << "z3: "; cin >> z3;
				Vector v3(x3, y3, z3);
				cout << "V3: " << v3 << endl;
				out_file << "V3: " << v3 << endl;

				double mixedProduct = v1.operator()(v2, v3);
				cout << "Mixed product of " << v1 << ", " << v2 << " and " << v3 << " = " << mixedProduct << endl;
				out_file << "Mixed product of " << v1 << ", " << v2 << " and " << v3 << " = " << mixedProduct << endl;
				break;
			}
			default:
			{
				break;
			}
			}

			cout << endl;
			char another_choice;
			cout << "Do you want to select another operation? ( y / n ): ";
			cin >> another_choice;

			if (another_choice == 'y') {
				continue;
			}
			else {
				do {
					cout << endl;
					cout << "Do you want to select another object? ( y / n ): ";
					cin >> another_choice;
				} while (another_choice != 'y' && another_choice != 'n');

				if (another_choice == 'n') {
					finished = true;
					break;
				}
				else {
					break;
				}
			}

		}
	}
	else {
		double x1, y1, z1;
		in_file >> x1;
		in_file >> y1;
		in_file >> z1;
		Vector v1(x1, y1, z1);
		cout << "V1: " << v1 << endl;
		out_file << "V1: " << v1 << endl;

		while (!finished) {
			int operation_choice;
			in_file >> operation_choice;

			switch (operation_choice) {
			case 1:
			{
				cout << "Vector direction: " << v1.vector_direction() << endl;
				out_file << "Vector direction: " << v1.vector_direction() << endl;
				break;
			}
			case 2:
			{
				cout << "Vector length: " << v1.vector_length() << endl;
				out_file << "Vector length: " << v1.vector_length() << endl;
				break;
			}
			case 3:
			{
				if (v1.is_null_vector())
				{
					cout << v1 << " is NULL vector " << endl;
					out_file << v1 << " is NULL vector " << endl;
				}
				else
				{
					cout << v1 << " isn't NULL vector " << endl;
					out_file << v1 << " isn't NULL vector " << endl;
				}
				break;
			}
			case 4:
			{
				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;
				if (v1.is_parallelism(v2))
				{
					cout << v1 << " and " << v2 << " are parallel" << endl;
					out_file << v1 << " and " << v2 << " are parallel" << endl;
				}
				else
				{
					cout << v1 << " and " << v2 << " aren't parallel" << endl;
					out_file << v1 << " and " << v2 << " aren't parallel" << endl;
				}
				break;
			}
			case 5:
			{
				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;
				if (v1.is_perpendicularity(v2))
				{
					cout << v1 << " and " << v2 << " are perpendicular" << endl;
					out_file << v1 << " and " << v2 << " are perpendicular" << endl;
				}
				else
				{
					cout << v1 << " and " << v2 << " aren't perpendicular" << endl;
					out_file << v1 << " and " << v2 << " aren't perpendicular" << endl;
				}
				break;
			}
			case 6:
			{
				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				Vector v3 = v1 + v2;
				cout << v1 << " + " << v2 << " = " << v3 << endl;
				out_file << v1 << " + " << v2 << " = " << v3 << endl;
				break;
			}
			case 7:
			{
				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				Vector v3 = v1 - v2;
				cout << v1 << " - " << v2 << " = " << v3 << endl;
				out_file << v1 << " - " << v2 << " = " << v3 << endl;
				break;
			}
			case 8:
			{
				double number;
				in_file >> number;

				Vector v2 = v1 * number;
				cout << v1 << " * " << number << " = " << v2 << endl;
				out_file << v1 << " * " << number << " = " << v2 << endl;
				break;
			}
			case 9:
			{
				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				double scalarProduct = v1 * v2;
				cout << v1 << " * " << v2 << " = " << scalarProduct << endl;
				out_file << v1 << " * " << v2 << " = " << scalarProduct << endl;
				break;
			}
			case 10:
			{
				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				Vector v3 = v1 ^ v2;
				cout << v1 << " ^ " << v2 << " = " << v3 << endl;
				out_file << v1 << " ^ " << v2 << " = " << v3 << endl;
				break;
			}
			case 11:
			{
				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Vector v2(x2, y2, z2);
				cout << "V2: " << v2 << endl;
				out_file << "V2: " << v2 << endl;

				double x3, y3, z3;
				in_file >> x3;
				in_file >> y3;
				in_file >> z3;
				Vector v3(x3, y3, z3);
				cout << "V3: " << v3 << endl;
				out_file << "V3: " << v3 << endl;

				double mixedProduct = v1.operator()(v2, v3);
				cout << "Mixed product of " << v1 << ", " << v2 << " and " << v3 << " = " << mixedProduct << endl;
				out_file << "Mixed product of " << v1 << ", " << v2 << " and " << v3 << " = " << mixedProduct << endl;
				break;
			}
			default:
			{
				break;
			}
			}
			/*
			cout << endl;
			char another_choice;
			cout << "Do you want to select another operation? ( y / n ): ";
			cin >> another_choice;

			if (another_choice == 'y') {
				continue;
			}
			else {
				do {
					cout << endl;
					cout << "Do you want to select another object? ( y / n ): ";
					cin >> another_choice;
				} while (another_choice != 'y' && another_choice != 'n');

				if (another_choice == 'n') {
					finished = true;
					break;
				}
				else {
					break;
				}
			}
			*/
			finished = true;
			break;
		}
	}
}


void Menu::line_menu() {
	cout << endl;
	if (!inFile) {
			double x1, y1, z1;
			cout << "Enter values to initialize the first point: " << endl;
			cout << "x1: "; cin >> x1;
			cout << "y1: "; cin >> y1;
			cout << "z1: "; cin >> z1;
			Point p1(x1, y1, z1);
			cout << "p1: " << p1 << endl;
			out_file << "p1: " << p1 << endl;

			double x2, y2, z2;
			cout << "Enter values to initialize the second point: " << endl;
			cout << "x2: "; cin >> x2;
			cout << "y2: "; cin >> y2;
			cout << "z2: "; cin >> z2;
			Point p2(x2, y2, z2);
			cout << "p2: " << p2 << endl;
			out_file << "p2: " << p2 << endl;

			Line l1(p1, p2);

			cout << l1 << endl;
			out_file << l1 << endl;
		
		while (!finished) {
			int operation_choice;
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~ L I N E - M E N U ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~ Choose operation (1-9) or anything else to go to main menu ~~~~" << endl;
			cout << "1.Find the line direction" << endl;
			cout << "2.Find the normal vector" << endl;
			cout << "3.Find the angle between two lines (in radians)" << endl;
			cout << "4.Check if a point lies on a line" << endl;
			cout << "5.Check if a line is parallel to another line" << endl;
			cout << "6.Check if a line coincides with another line" << endl;
			cout << "7.Check if a line intersects another line" << endl;
			cout << "8.Check if a line is crossed with another line" << endl;
			cout << "9.Check if a line is perpendicular to another line" << endl;
			cout << endl;
			cin >> operation_choice;

			if (operation_choice > 9 || operation_choice < 1) {
				break;
			}

			switch (operation_choice) {
			case 1:
			{
				cout << "Line direction: " << l1.line_direction() << endl;
				out_file << "Line direction: " << l1.line_direction() << endl;
				break;
			}
			case 2:
			{
				cout << "Normal vector: " << l1.normal_vector() << endl;
				out_file << "Normal vector: " << l1.normal_vector() << endl;
				break;
			}
			case 3:
			{
					double x1, y1, z1;
					cout << "Enter values to initialize the first point of the second line: " << endl;
					cout << "x1: "; cin >> x1;
					cout << "y1: "; cin >> y1;
					cout << "z1: "; cin >> z1;
					Point p1(x1, y1, z1);
					cout << "p1 (second line): " << p1 << endl;
					out_file << "p1 (second line): " << p1 << endl;

					double x2, y2, z2;
					cout << "Enter values to initialize the second point of the second line: " << endl;
					cout << "x2: "; cin >> x2;
					cout << "y2: "; cin >> y2;
					cout << "z2: "; cin >> z2;
					Point p2(x2, y2, z2);
					cout << "p2 (second line): " << p2 << endl;
					out_file << "p2 (second line): " << p2 << endl;

					Line l2(p1, p2);

					cout << l2 << endl;
					out_file << l2 << endl;


				cout << "The angle between the two lines is " << l1.angle_between_lines(l2) << " radians." << endl;
				out_file << "The angle between the two lines is " << l1.angle_between_lines(l2) << " radians." << endl;
				break;
			}
			case 4:
			{
				double x, y, z;
				cout << "Enter values to initialize the point: " << endl;
				cout << "x: "; cin >> x;
				cout << "y: "; cin >> y;
				cout << "z: "; cin >> z;
				Point p(x, y, z);
				cout << "p: " << p << endl;
				out_file << "p: " << p << endl;

				if (l1 + p) // overloaded operator+
				{
					cout << p << " lies on the line" << endl;
					out_file << p << " lies on the line" << endl;
				}
				else
				{
					cout << p << " doesn't lie on the line" << endl;
					out_file << p << " doesn't lie on the line" << endl;
				}

				break;
			}
			case 5:
			{
				
					double x1, y1, z1;
					cout << "Enter values to initialize the first point of the second line: " << endl;
					cout << "x1: "; cin >> x1;
					cout << "y1: "; cin >> y1;
					cout << "z1: "; cin >> z1;
					Point p1(x1, y1, z1);
					cout << "p1 (second line): " << p1 << endl;
					out_file << "p1 (second line): " << p1 << endl;

					double x2, y2, z2;
					cout << "Enter values to initialize the second point of the second line: " << endl;
					cout << "x2: "; cin >> x2;
					cout << "y2: "; cin >> y2;
					cout << "z2: "; cin >> z2;
					Point p2(x2, y2, z2);
					cout << "p2 (second line): " << p2 << endl;
					out_file << "p2 (second line): " << p2 << endl;

					Line l2(p1, p2);

					cout << l2 << endl;
					out_file << l2 << endl;

				if (l1 || l2) // overloaded operator ||
				{
					cout << "The lines are parallel." << endl;
					out_file << "The lines are parallel." << endl;
				}
				else {
					cout << "The lines are NOT parallel." << endl;
					out_file << "The lines are NOT parallel." << endl;
				}
				break;
			}
			case 6:
			{
				
					double x1, y1, z1;
					cout << "Enter values to initialize the first point of the second line: " << endl;
					cout << "x1: "; cin >> x1;
					cout << "y1: "; cin >> y1;
					cout << "z1: "; cin >> z1;
					Point p1(x1, y1, z1);
					cout << "p1 (second line): " << p1 << endl;
					out_file << "p1 (second line): " << p1 << endl;

					double x2, y2, z2;
					cout << "Enter values to initialize the second point of the second line: " << endl;
					cout << "x2: "; cin >> x2;
					cout << "y2: "; cin >> y2;
					cout << "z2: "; cin >> z2;
					Point p2(x2, y2, z2);
					cout << "p2 (second line): " << p2 << endl;
					out_file << "p2 (second line): " << p2 << endl;

					Line l2(p1, p2);

					cout << l2 << endl;
					out_file << l2 << endl;

				if (l1 == l2) // overloaded operator ==
				{
					cout << "Òhe two lines coincide." << endl;
					out_file << "Òhe two lines coincide." << endl;
				}
				else
				{
					cout << "Òhe two lines do NOT coincide." << endl;
					out_file << "Òhe two lines do NOT coincide." << endl;
				}
				break;
			}
			case 7:
			{
			
					double x1, y1, z1;
					cout << "Enter values to initialize the first point of the second line: " << endl;
					cout << "x1: "; cin >> x1;
					cout << "y1: "; cin >> y1;
					cout << "z1: "; cin >> z1;
					Point p1(x1, y1, z1);
					cout << "p1 (second line): " << p1 << endl;
					out_file << "p1 (second line): " << p1 << endl;

					double x2, y2, z2;
					cout << "Enter values to initialize the second point of the second line: " << endl;
					cout << "x2: "; cin >> x2;
					cout << "y2: "; cin >> y2;
					cout << "z2: "; cin >> z2;
					Point p2(x2, y2, z2);
					cout << "p2 (second line): " << p2 << endl;
					out_file << "p2 (second line): " << p2 << endl;

					Line l2(p1, p2);

					cout << l2 << endl;
					out_file << l2 << endl;


				if (l1 && l2) // overloaded operator &&
				{
					cout << "The two lines intersect." << endl;
					out_file << "The two lines intersect." << endl;
				}
				else
				{
					cout << "The two lines do NOT intersect." << endl;
					out_file << "The two lines do NOT intersect." << endl;
				}
				break;
			}

			case 8:
			{
				
					double x1, y1, z1;
					cout << "Enter values to initialize the first point of the second line: " << endl;
					cout << "x1: "; cin >> x1;
					cout << "y1: "; cin >> y1;
					cout << "z1: "; cin >> z1;
					Point p1(x1, y1, z1);
					cout << "p1 (second line): " << p1 << endl;
					out_file << "p1 (second line): " << p1 << endl;

					double x2, y2, z2;
					cout << "Enter values to initialize the second point of the second line: " << endl;
					cout << "x2: "; cin >> x2;
					cout << "y2: "; cin >> y2;
					cout << "z2: "; cin >> z2;
					Point p2(x2, y2, z2);
					cout << "p2 (second line): " << p2 << endl;
					out_file << "p2 (second line): " << p2 << endl;

					Line l2(p1, p2);

					cout << l2 << endl;
					out_file << l2 << endl;
			

				if (l1 != l2) // overloaded operator !=
				{
					cout << "The two lines are crossed." << endl;
					out_file << "The two lines are crossed." << endl;
				}
				else
				{
					cout << "The two lines are NOT crossed." << endl;
					out_file << "The two lines are NOT crossed." << endl;
				}
				break;
			}
			case 9:
			{
				
					double x1, y1, z1;
					cout << "Enter values to initialize the first point of the second line: " << endl;
					cout << "x1: "; cin >> x1;
					cout << "y1: "; cin >> y1;
					cout << "z1: "; cin >> z1;
					Point p1(x1, y1, z1);
					cout << "p1 (second line): " << p1 << endl;
					out_file << "p1 (second line): " << p1 << endl;

					double x2, y2, z2;
					cout << "Enter values to initialize the second point of the second line: " << endl;
					cout << "x2: "; cin >> x2;
					cout << "y2: "; cin >> y2;
					cout << "z2: "; cin >> z2;
					Point p2(x2, y2, z2);
					cout << "p2 (second line): " << p2 << endl;
					out_file << "p2 (second line): " << p2 << endl;

					Line l2(p1, p2);

					cout << l2 << endl;
					out_file << l2 << endl;
		

				if (l1 | l2) // overloaded operator |
				{
					cout << "The two lines are perpendicular." << endl;
					out_file << "The two lines are perpendicular." << endl;
				}
				else
				{
					cout << "The two lines are NOT perpendicular." << endl;
					out_file << "The two lines are NOT perpendicular." << endl;
				}
				break;
			}
			default:
			{
				break;
			}
			}
		
			cout << endl;
			char another_choice;
			cout << "Do you want to select another operation? ( y / n ): ";
			cin >> another_choice;

			if (another_choice == 'y') {
				continue;
			}
			else {
				do {
					cout << endl;
					cout << "Do you want to select another object? ( y / n ): ";
					cin >> another_choice;
				} while (another_choice != 'y' && another_choice != 'n');

				if (another_choice == 'n') {
					finished = true;
					break;
				}
				else {
					break;
				}
			}

		}
	}
	else {

	cout << endl;

		double x1, y1, z1;
		in_file >> x1;
		in_file >> y1;
		in_file >> z1;
		Point p1(x1, y1, z1);
		cout << "p1: " << p1 << endl;
		out_file << "p1: " << p1 << endl;

		double x2, y2, z2;
		in_file >> x2;
		in_file >> y2;
		in_file >> z2;
		Point p2(x2, y2, z2);
		cout << "p2: " << p2 << endl;
		out_file << "p2: " << p2 << endl;

		Line l1(p1, p2);

		cout << l1 << endl;
		out_file << l1 << endl;

	while (!finished) {
		int operation_choice;
		in_file >> operation_choice;

		switch (operation_choice) {
		case 1:
		{
			cout << "Line direction: " << l1.line_direction() << endl;
			out_file << "Line direction: " << l1.line_direction() << endl;
			break;
		}
		case 2:
		{
			cout << "Normal vector: " << l1.normal_vector() << endl;
			out_file << "Normal vector: " << l1.normal_vector() << endl;
			break;
		}
		case 3:
		{
				double x1, y1, z1;
				in_file >> x1;
				in_file >> y1;
				in_file >> z1;
				Point p1(x1, y1, z1);
				cout << "p1 (second line): " << p1 << endl;
				out_file << "p1 (second line): " << p1 << endl;

				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Point p2(x2, y2, z2);
				cout << "p2 (second line): " << p2 << endl;
				out_file << "p2 (second line): " << p2 << endl;

				Line l2(p1, p2);

				cout << l2 << endl;
				out_file << l2 << endl;


			cout << "The angle between the two lines is " << l1.angle_between_lines(l2) << " radians." << endl;
			out_file << "The angle between the two lines is " << l1.angle_between_lines(l2) << " radians." << endl;
			break;
		}
		case 4:
		{
			double x, y, z;
			in_file >> x;
			in_file >> y;
			in_file >> z;
			Point p(x, y, z);
			cout << "p: " << p << endl;
			out_file << "p: " << p << endl;

			if (l1 + p) // overloaded operator+
			{
				cout << p << " lies on the line" << endl;
				out_file << p << " lies on the line" << endl;
			}
			else
			{
				cout << p << " doesn't lie on the line" << endl;
				out_file << p << " doesn't lie on the line" << endl;
			}

			break;
		}
		case 5:
		{
				double x1, y1, z1;
				in_file >> x1;
				in_file >> y1;
				in_file >> z1;
				Point p1(x1, y1, z1);
				cout << "p1 (second line): " << p1 << endl;
				out_file << "p1 (second line): " << p1 << endl;

				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Point p2(x2, y2, z2);
				cout << "p2 (second line): " << p2 << endl;
				out_file << "p2 (second line): " << p2 << endl;

				Line l2(p1, p2);

				cout << l2 << endl;
				out_file << l2 << endl;
			

			if (l1 || l2) // overloaded operator ||
			{
				cout << "The lines are parallel." << endl;
				out_file << "The lines are parallel." << endl;
			}
			else {
				cout << "The lines are NOT parallel." << endl;
				out_file << "The lines are NOT parallel." << endl;
			}
			break;
		}
		case 6:
		{
				double x1, y1, z1;
				in_file >> x1;
				in_file >> y1;
				in_file >> z1;
				Point p1(x1, y1, z1);
				cout << "p1 (second line): " << p1 << endl;
				out_file << "p1 (second line): " << p1 << endl;

				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Point p2(x2, y2, z2);
				cout << "p2 (second line): " << p2 << endl;
				out_file << "p2 (second line): " << p2 << endl;

				Line l2(p1, p2);

				cout << l2 << endl;
				out_file << l2 << endl;


			if (l1 == l2) // overloaded operator ==
			{
				cout << "Òhe two lines coincide." << endl;
				out_file << "Òhe two lines coincide." << endl;
			}
			else
			{
				cout << "Òhe two lines do NOT coincide." << endl;
				out_file << "Òhe two lines do NOT coincide." << endl;
			}
			break;
		}
		case 7:
		{
				double x1, y1, z1;
				in_file >> x1;
				in_file >> y1;
				in_file >> z1;
				Point p1(x1, y1, z1);
				cout << "p1 (second line): " << p1 << endl;
				out_file << "p1 (second line): " << p1 << endl;

				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Point p2(x2, y2, z2);
				cout << "p2 (second line): " << p2 << endl;
				out_file << "p2 (second line): " << p2 << endl;

				Line l2(p1, p2);

				cout << l2 << endl;
				out_file << l2 << endl;

			if (l1 && l2) // overloaded operator &&
			{
				cout << "The two lines intersect." << endl;
				out_file << "The two lines intersect." << endl;
			}
			else
			{
				cout << "The two lines do NOT intersect." << endl;
				out_file << "The two lines do NOT intersect." << endl;
			}
			break;
		}

		case 8:
		{
				double x1, y1, z1;
				in_file >> x1;
				in_file >> y1;
				in_file >> z1;
				Point p1(x1, y1, z1);
				cout << "p1 (second line): " << p1 << endl;
				out_file << "p1 (second line): " << p1 << endl;

				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Point p2(x2, y2, z2);
				cout << "p2 (second line): " << p2 << endl;
				out_file << "p2 (second line): " << p2 << endl;

				Line l2(p1, p2);

				cout << l2 << endl;
				out_file << l2 << endl;

			if (l1 != l2) // overloaded operator !=
			{
				cout << "The two lines are crossed." << endl;
				out_file << "The two lines are crossed." << endl;
			}
			else
			{
				cout << "The two lines are NOT crossed." << endl;
				out_file << "The two lines are NOT crossed." << endl;
			}
			break;
		}
		case 9:
		{
				double x1, y1, z1;
				in_file >> x1;
				in_file >> y1;
				in_file >> z1;
				Point p1(x1, y1, z1);
				cout << "p1 (second line): " << p1 << endl;
				out_file << "p1 (second line): " << p1 << endl;

				double x2, y2, z2;
				in_file >> x2;
				in_file >> y2;
				in_file >> z2;
				Point p2(x2, y2, z2);
				cout << "p2 (second line): " << p2 << endl;
				out_file << "p2 (second line): " << p2 << endl;

				Line l2(p1, p2);

				cout << l2 << endl;
				out_file << l2 << endl;
			

			if (l1 | l2) // overloaded operator |
			{
				cout << "The two lines are perpendicular." << endl;
				out_file << "The two lines are perpendicular." << endl;
			}
			else
			{
				cout << "The two lines are NOT perpendicular." << endl;
				out_file << "The two lines are NOT perpendicular." << endl;
			}
			break;
		}
		default:
		{
			break;
		}
		}
		/*
		cout << endl;
		char another_choice;
		cout << "Do you want to select another operation? ( y / n ): ";
		cin >> another_choice;

		if (another_choice == 'y') {
			continue;
		}
		else {
			do {
				cout << endl;
				cout << "Do you want to select another object? ( y / n ): ";
				cin >> another_choice;
			} while (another_choice != 'y' && another_choice != 'n');

			if (another_choice == 'n') {
				finished = true;
				break;
			}
			else {
				break;
			}
			*/
		finished = true;
		break;
		}
	}
}

void Menu::segment_menu() {
	cout << endl;
	if (!inFile) {
		double x1, y1, z1;
		cout << "Enter values to initialize the first point: " << endl;
		cout << "x1: "; cin >> x1;
		cout << "y1: "; cin >> y1;
		cout << "z1: "; cin >> z1;
		Point p1(x1, y1, z1);
		cout << "p1: " << p1 << endl;
		out_file << "p1: " << p1 << endl;

		double x2, y2, z2;
		cout << "Enter values to initialize the second point: " << endl;
		cout << "x2: "; cin >> x2;
		cout << "y2: "; cin >> y2;
		cout << "z2: "; cin >> z2;
		Point p2(x2, y2, z2);
		cout << "p2: " << p2 << endl;
		out_file << "p2: " << p2 << endl;

		Segment s1(p1, p2);

		while (!finished) {
			int operation_choice;
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~ S E G M E N T - M E N U ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~ Choose operation (1-3) or anything else to go to main menu ~~~~" << endl;
			cout << "1.Find the length of the segment " << endl;
			cout << "2.Find the midpoint of the segment" << endl;
			cout << "3.Check if a point lies on a segment" << endl;
			cout << endl;
			cin >> operation_choice;

			if (operation_choice > 3 || operation_choice < 1) {
				break;
			}

			if (operation_choice == 1) {
				cout << "Length of the segment: " << s1.segment_length() << endl; 
				out_file << "Length of the segment: " << s1.segment_length() << endl; 
			}
			else if (operation_choice == 2) {
				cout << "Midpoint of the segment: " << s1.middle_of_segment() << endl; 
				out_file << "Midpoint of the segment: " << s1.middle_of_segment() << endl;
			}
			else if (operation_choice == 3) {
				double x, y, z;
				cout << "Enter values to initialize the point: " << endl;
				cout << "x: "; cin >> x;
				cout << "y: "; cin >> y;
				cout << "z: "; cin >> z;
				Point p(x, y, z);
				cout << "p: " << p << endl;
				out_file << "p: " << p << endl;


				if (s1 == p) // overloaded operator ==
				{
					cout << "The point lies on the segment." << endl;
					out_file << "The point lies on the segment." << endl;
				}
				else
				{
					cout << "The point does not lie on the segment." << endl;
					out_file << "The point does not lie on the segment." << endl;
				}
			}
			else {
				break;
			}

			char another_choice;
			cout << "Do you want to select another operation? ( y / n ): ";
			cin >> another_choice;

			if (another_choice == 'y') {
				continue;
			}
			else {
				do {
					cout << "Do you want to select another object? ( y / n ): ";
					cin >> another_choice;
				} while (another_choice != 'y' && another_choice != 'n');

				if (another_choice == 'n') {
					finished = true;
					break;
				}
				else {
					break;
				}
			}

		}
	}
	else {
		double x1, y1, z1;
		in_file >> x1;
		in_file >> y1;
		in_file >> z1;
		Point p1(x1, y1, z1);
		cout << "p1: " << p1 << endl;
		out_file << "p1: " << p1 << endl;

		double x2, y2, z2;
		in_file >> x2;
		in_file >> y2;
		in_file >> z2;
		Point p2(x2, y2, z2);
		cout << "p2: " << p2 << endl;
		out_file << "p2: " << p2 << endl;

		Segment s1(p1, p2);

		while (!finished) {
			int operation_choice;
			in_file >> operation_choice;

			if (operation_choice == 1) {
				cout << "Length of the segment: " << s1.segment_length() << endl;
				out_file << "Length of the segment: " << s1.segment_length() << endl;
			}
			else if (operation_choice == 2) {
				cout << "Midpoint of the segment: " << s1.middle_of_segment() << endl;
				out_file << "Midpoint of the segment: " << s1.middle_of_segment() << endl;
			}
			else if (operation_choice == 3) {
				double x, y, z;
				cout << "Enter values to initialize the point: " << endl;
				in_file >> x;
				in_file >> y;
				in_file >> z;
				Point p(x, y, z);
				cout << "p: " << p << endl;
				out_file << "p: " << p << endl;


				if (s1 == p) // overloaded operator ==
				{
					cout << "The point lies on the segment." << endl;
					out_file << "The point lies on the segment." << endl;
				}
				else
				{
					cout << "The point does not lie on the segment." << endl;
					out_file << "The point does not lie on the segment." << endl;
				}
			}
			else {
				break;
			}

			/*
			cout << endl;
			char another_choice;
			cout << "Do you want to select another operation? ( y / n ): ";
			cin >> another_choice;

			if (another_choice == 'y') {
				continue;
			}
			else {
				do {
					cout << endl;
					cout << "Do you want to select another object? ( y / n ): ";
					cin >> another_choice;
				} while (another_choice != 'y' && another_choice != 'n');

				if (another_choice == 'n') {
					finished = true;
					break;
				}
				else {
					break;
				}
			}
			*/
			finished = true;
			break;
		}
	}
}

void Menu::triangle_menu() {
	cout << endl;
	if (!inFile) {
		double x1, y1, z1;
		cout << "Enter values to initialize the first point: " << endl;
		cout << "x1: "; cin >> x1;
		cout << "y1: "; cin >> y1;
		cout << "z1: "; cin >> z1;
		Point p1(x1, y1, z1);
		cout << "p1: " << p1 << endl;
		out_file << "p1: " << p1 << endl;

		double x2, y2, z2;
		cout << "Enter values to initialize the second point: " << endl;
		cout << "x2: "; cin >> x2;
		cout << "y2: "; cin >> y2;
		cout << "z2: "; cin >> z2;
		Point p2(x2, y2, z2);
		cout << "p2: " << p2 << endl;
		out_file << "p2: " << p2 << endl;

		double x3, y3, z3;
		cout << "Enter values to initialize the third point: " << endl;
		cout << "x3: "; cin >> x3;
		cout << "y3: "; cin >> y3;
		cout << "z3: "; cin >> z3;
		Point p3(x3, y3, z3);
		cout << "p3: " << p3 << endl;
		out_file << "p3: " << p3 << endl;

		Triangle t1(p1, p2, p3);

		while (!finished)
		{
			cout << endl;
			int operation_choice;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~ T R I A N G L E - M E N U ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~~~~ Choose operation (1-7) or anything else to go to main menu ~~~~~~" << endl;
			cout << "1.Determine the type of the triangle " << endl;
			cout << "2.Find the area of the triangle" << endl;
			cout << "3.Find the perimeter of the triangle" << endl;
			cout << "4.Find the centroid of the triangle" << endl;
			cout << "5.Check if a point lies inside a triangle" << endl;
			cout << "6.Check if a point lies outside a triangle" << endl;
			cout << "7.Check if a point lies on one of the sides of a triangle" << endl;
			cin >> operation_choice;

			if (operation_choice > 7 || operation_choice < 1) {
				break;
			}

			switch (operation_choice) { 
			case 1: 
			{
				t1.triangle_type();
				break;
			}
			case 2: 
			{
				cout << "The area of the triangle: " << t1.triangle_area() << endl; 
				out_file << "The area of the triangle: " << t1.triangle_area() << endl; 
				break;
			}
			case 3: 
			{
				cout << "The perimeter of the triangle: " << t1.triangle_perimeter() << endl;
				out_file << "The perimeter of the triangle: " << t1.triangle_perimeter() << endl; 
				break;
			}
			case 4: 
			{
				cout << "The centroid of the triangle:" << t1.triangle_centroid() << endl; 
				out_file << "The centroid of the triangle: " << t1.triangle_centroid() << endl; 
				break;
			}
			case 5: 
			{
				double x, y, z;
				cout << "Enter values to initialize the point: " << endl;
				cout << "x: "; cin >> x;
				cout << "y: "; cin >> y;
				cout << "z: "; cin >> z;
				Point p(x, y, z);
				cout << "p: " << p << endl;
				out_file << "p: " << p << endl;

				if (t1 < p) // overloaded operator <
				{
					cout << "The point lies inside the triangle. (and on the surface of the triangle)" << endl;
					out_file << "The point lies inside the triangle. (and on the surface of the triangle)" << endl;
				}
				else {
					cout << "Òhe point does NOT lie inside the triangle. (or on the surface of the triangle)" << endl;
					out_file << "Òhe point does NOT lie inside the triangle. (or on the surface of the triangle)" << endl;
				}
				break;
			}
			case 6: 
			{
				double x, y, z;
				cout << "Enter values to initialize the point: " << endl;
				cout << "x: "; cin >> x;
				cout << "y: "; cin >> y;
				cout << "z: "; cin >> z;
				Point p(x, y, z);
				cout << "p: " << p << endl;
				out_file << "p: " << p << endl;

				if (t1 > p) // overloaded operator >
				{
					cout << "The point lies outside the triangle. (and on the surface of the triangle)" << endl;
					out_file << "The point lies outside the triangle. (and on the surface of the triangle)" << endl;
				}
				else {
					cout << "Òhe point does NOT lie outside the triangle. (or on the surface of the triangle)" << endl;
					out_file << "Òhe point does NOT lie outside the triangle. (or on the surface of the triangle)" << endl;
				}
				break;
			}
			case 7:
			{
				double x, y, z;
				cout << "Enter values to initialize the point: " << endl;
				cout << "x: "; cin >> x;
				cout << "y: "; cin >> y;
				cout << "z: "; cin >> z;
				Point p(x, y, z);
				cout << "p: " << p << endl;
				out_file << "p: " << p << endl;

				if (t1 == p) // overloaded operator ==
				{
					cout << "The point lies on one of the sides of the triangle." << endl;
					out_file << "The point lies on one of the sides of the triangle." << endl;
				}
				else
				{
					cout << "The point doesn't lie on one of the sides of the triangle." << endl;
					out_file << "The point doesn't lie on one of the sides of the triangle." << endl;
				}
				break;
			}
			default:
			{
				break;
			}
			}
			
			cout << endl;
			char another_choice;
			cout << "Do you want to select another operation? ( y / n ): ";
			cin >> another_choice;

			if (another_choice == 'y') {
				continue;
			}
			else {
				do {
					cout << endl;
					cout << "Do you want to select another object? ( y / n ): ";
					cin >> another_choice;
				} while (another_choice != 'y' && another_choice != 'n');

				if (another_choice == 'n') {
					finished = true;
					break;
				}
				else {
					break;
				}
			}
		}
	}
	else {
	double x1, y1, z1;
	in_file >> x1;
	in_file >> y1;
	in_file >> z1;
	Point p1(x1, y1, z1);
	cout << "p1: " << p1 << endl;
	out_file << "p1: " << p1 << endl;

	double x2, y2, z2;
	in_file >> x2;
	in_file >> y2;
	in_file >> z2;
	Point p2(x2, y2, z2);
	cout << "p2: " << p2 << endl;
	out_file << "p2: " << p2 << endl;

	double x3, y3, z3;
	in_file >> x3;
	in_file >> y3;
	in_file >> z3;
	Point p3(x3, y3, z3);
	cout << "p3: " << p3 << endl;
	out_file << "p3: " << p3 << endl;

	Triangle t1(p1, p2, p3);

	while (!finished)
	{
		int operation_choice;
		in_file >> operation_choice;

		switch (operation_choice) {
		case 1:
		{
			t1.triangle_type();
			break;
		}
		case 2:
		{
			cout << "The area of the triangle: " << t1.triangle_area() << endl;
			out_file << "The area of the triangle: " << t1.triangle_area() << endl;
			break;
		}
		case 3:
		{
			cout << "The perimeter of the triangle: " << t1.triangle_perimeter() << endl;
			out_file << "The perimeter of the triangle: " << t1.triangle_perimeter() << endl;
			break;
		}
		case 4:
		{
			cout << "The centroid of the triangle:" << t1.triangle_centroid() << endl;
			out_file << "The centroid of the triangle: " << t1.triangle_centroid() << endl;
			break;
		}
		case 5:
		{
			double x, y, z;
			in_file >> x;
			in_file >> y;
			in_file >> z;
			Point p(x, y, z);
			cout << "p: " << p << endl;
			out_file << "p: " << p << endl;

			if (t1 < p) // overloaded operator <
			{
				cout << "The point lies inside the triangle. (and on the surface of the triangle)" << endl;
				out_file << "The point lies inside the triangle. (and on the surface of the triangle)" << endl;
			}
			else {
				cout << "Òhe point does NOT lie inside the triangle. (or on the surface of the triangle)" << endl;
				out_file << "Òhe point does NOT lie inside the triangle. (or on the surface of the triangle)" << endl;
			}
			break;
		}
		case 6:
		{
			double x, y, z;
			in_file >> x;
			in_file >> y;
			in_file >> z;
			Point p(x, y, z);
			cout << "p: " << p << endl;
			out_file << "p: " << p << endl;

			if (t1 > p) // overloaded operator >
			{
				cout << "The point lies outside the triangle. (and on the surface of the triangle)" << endl;
				out_file << "The point lies outside the triangle. (and on the surface of the triangle)" << endl;
			}
			else {
				cout << "Òhe point does NOT lie outside the triangle. (or on the surface of the triangle)" << endl;
				out_file << "Òhe point does NOT lie outside the triangle. (or on the surface of the triangle)" << endl;
			}
			break;
		}
		case 7:
		{
			double x, y, z;
			in_file >> x;
			in_file >> y;
			in_file >> z;
			Point p(x, y, z);
			cout << "p: " << p << endl;
			out_file << "p: " << p << endl;

			if (t1 == p) // overloaded operator ==
			{
				cout << "The point lies on one of the sides of the triangle." << endl;
				out_file << "The point lies on one of the sides of the triangle." << endl;
			}
			else
			{
				cout << "The point doesn't lie on one of the sides of the triangle." << endl;
				out_file << "The point doesn't lie on one of the sides of the triangle." << endl;
			}
			break;
		}
		default:
		{
			break;
		}
		}

		/*
		cout << endl;
		char another_choice;
		cout << "Do you want to select another operation? ( y / n ): ";
		cin >> another_choice;

		if (another_choice == 'y') {
			continue;
		}
		else {
			do {
				cout << endl;
				cout << "Do you want to select another object? ( y / n ): ";
				cin >> another_choice;
			} while (another_choice != 'y' && another_choice != 'n');

			if (another_choice == 'n') {
				finished = true;
				break;
			}
			else {
				break;
			}
		}
		*/
		finished = true;
		break;
	}
	}
}

void Menu::tetrahedron_menu() {
	cout << endl;
	if (!inFile) {
		double x1, y1, z1;
		cout << "Enter values to initialize the first point: " << endl;
		cout << "x1: "; cin >> x1;
		cout << "y1: "; cin >> y1;
		cout << "z1: "; cin >> z1;
		Point p1(x1, y1, z1);
		cout << "p1: " << p1 << endl;
		out_file << "p1: " << p1 << endl;

		double x2, y2, z2;
		cout << "Enter values to initialize the second point: " << endl;
		cout << "x2: "; cin >> x2;
		cout << "y2: "; cin >> y2;
		cout << "z2: "; cin >> z2;
		Point p2(x2, y2, z2);
		cout << "p2: " << p2 << endl;
		out_file << "p2: " << p2 << endl;

		double x3, y3, z3;
		cout << "Enter values to initialize the third point: " << endl;
		cout << "x3: "; cin >> x3;
		cout << "y3: "; cin >> y3;
		cout << "z3: "; cin >> z3;
		Point p3(x3, y3, z3);
		cout << "p3: " << p3 << endl;
		out_file << "p3: " << p3 << endl;

		double x4, y4, z4;
		cout << "Enter values to initialize the fourth point: " << endl;
		cout << "x4: "; cin >> x4;
		cout << "y4: "; cin >> y4;
		cout << "z4: "; cin >> z4;
		Point p4(x4, y4, z4);
		cout << "p4: " << p4 << endl;
		out_file << "p4: " << p4 << endl;

		Tetrahedron tth1(p1, p2, p3, p4);

		while (!finished) {
			cout << endl;
			int operation_choice;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~ T E T R A H E D R O N - M E N U ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~~~~ Choose operation (1-5) or anything else to go to main menu ~~~~~~" << endl;
			cout << "1.Check if the tetrahedron is regular" << endl;
			cout << "2.Check if the tetrahedron is orthogonal" << endl;
			cout << "3.Find the surface of the tetrahedron" << endl;
			cout << "4.Find the volume of the tetrahedron" << endl;
			cout << "5.Check if a point lies on one of the sides of a tetrahedron" << endl;
			cin >> operation_choice;

			if (operation_choice > 5 || operation_choice < 1) {
				break;
			}

			switch (operation_choice) {
			case 1:
			{
				if (tth1.is_regular())
				{
					cout << "The tetrahedron is regular." << endl;
					out_file << "The tetrahedron is regular." << endl;
				}
				else
				{
					cout << "The tetrahedron isn't regular." << endl;
					out_file << "The tetrahedron isn't regular." << endl;
				}
				break;
			}
			case 2:
			{
				if (tth1.is_orthogonal())
				{
					cout << "The tetrahedron is orthogonal." << endl;
					out_file << "The tetrahedron is orthogonal." << endl;
				}
				else
				{
					cout << "The tetrahedron isn't orthogonal." << endl;
					out_file << "The tetrahedron isn't orthogonal." << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Surface of the tetrahedron: " << tth1.tetrahedron_surface() << endl;
				out_file << "Surface of the tetrahedron: " << tth1.tetrahedron_surface() << endl;
				break;
			}
			case 4:
			{
				cout << "Volume of the tetrahedron: " << tth1.tetrahedron_volume() << endl;
				out_file << "Volume of the Tetrahedron: " << tth1.tetrahedron_volume() << endl;
				break;
			}
			case 5:
			{
				double x, y, z;
				cout << "Enter values to initialize the point: " << endl;
				cout << "x: "; cin >> x;
				cout << "y: "; cin >> y;
				cout << "z: "; cin >> z;
				Point p(x, y, z);
				cout << "p: " << p << endl;
				out_file << "p: " << p << endl;

				if (tth1 == p) // overloaded operator ==
				{
					cout << "The point lies on one of the sides of the tetrahedron." << endl;
					out_file << "The point lies on one of the sides of the tetrahedron." << endl;
				}
				else {
					cout << "The point doesn't lie on one of the sides of the tetrahedron." << endl;
					out_file << "The point doesn't lie on one of the sides of the tetrahedron." << endl;
				}
				break;
			}
			default:
			{
				break;
			}
			}

			cout << endl;
			char another_choice;
			cout << "Do you want to select another operation? ( y / n ): ";
			cin >> another_choice;

			if (another_choice == 'y') {
				continue;
			}
			else {
				do {
					cout << endl;
					cout << "Do you want to select another object? ( y / n ): ";
					cin >> another_choice;
				} while (another_choice != 'y' && another_choice != 'n');

				if (another_choice == 'n') {
					finished = true;
					break;
				}
				else {
					break;
				}
			}
		}
     }
		else {
		double x1, y1, z1;
		in_file >> x1;
		in_file >> y1;
		in_file >> z1;
		Point p1(x1, y1, z1);
		cout << "p1: " << p1 << endl;
		out_file << "p1: " << p1 << endl;

		double x2, y2, z2;
		in_file >> x2;
		in_file >> y2;
		in_file >> z2;
		Point p2(x2, y2, z2);
		cout << "p2: " << p2 << endl;
		out_file << "p2: " << p2 << endl;

		double x3, y3, z3;
		in_file >> x3;
		in_file >> y3;
		in_file >> z3;
		Point p3(x3, y3, z3);
		cout << "p3: " << p3 << endl;
		out_file << "p3: " << p3 << endl;

		double x4, y4, z4;
		in_file >> x4;
		in_file >> y4;
		in_file >> z4;
		Point p4(x4, y4, z4);
		cout << "p4: " << p4 << endl;
		out_file << "p4: " << p4 << endl;

		Tetrahedron tth1(p1, p2, p3, p4);

		while (!finished) {
			int operation_choice;
			in_file >> operation_choice;

			switch (operation_choice) {
			case 1:
			{
				if (tth1.is_regular())
				{
					cout << "The tetrahedron is regular." << endl;
					out_file << "The tetrahedron is regular." << endl;
				}
				else
				{
					cout << "The tetrahedron isn't regular." << endl;
					out_file << "The tetrahedron isn't regular." << endl;
				}
				break;
			}
			case 2:
			{
				if (tth1.is_orthogonal())
				{
					cout << "The tetrahedron is orthogonal." << endl;
					out_file << "The tetrahedron is orthogonal." << endl;
				}
				else
				{
					cout << "The tetrahedron isn't orthogonal." << endl;
					out_file << "The tetrahedron isn't orthogonal." << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Surface of the tetrahedron: " << tth1.tetrahedron_surface() << endl;
				out_file << "Surface of the tetrahedron: " << tth1.tetrahedron_surface() << endl;
				break;
			}
			case 4:
			{
				cout << "Volume of the tetrahedron: " << tth1.tetrahedron_volume() << endl;
				out_file << "Volume of the Tetrahedron: " << tth1.tetrahedron_volume() << endl;
				break;
			}
			case 5:
			{
				double x, y, z;
				cout << "Enter values to initialize the point: " << endl;
				in_file >> x;
				in_file >> y;
				in_file >> z;
				Point p(x, y, z);
				cout << "p: " << p << endl;
				out_file << "p: " << p << endl;

				if (tth1 == p) // overloaded operator ==
				{
					cout << "The point lies on one of the sides of the tetrahedron." << endl;
					out_file << "The point lies on one of the sides of the tetrahedron." << endl;
				}
				else {
					cout << "The point doesn't lie on one of the sides of the tetrahedron." << endl;
					out_file << "The point doesn't lie on one of the sides of the tetrahedron." << endl;
				}
				break;
			}
			default:
			{
				break;
			}
			}

			/*
			cout << endl;
			char another_choice;
			cout << "Do you want to select another operation? ( y / n ): ";
			cin >> another_choice;

			if (another_choice == 'y') {
				continue;
			}
			else {
				do {
					cout << endl;
					cout << "Do you want to select another object? ( y / n ): ";
					cin >> another_choice;
				} while (another_choice != 'y' && another_choice != 'n');

				if (another_choice == 'n') {
					finished = true;
					break;
				}
				else {
					break;
				}
			}
			*/

			finished = true;
			break;
		}
		}
}