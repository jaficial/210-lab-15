// COMSC-210 || Jed Aficial || Lab 15
// https://github.com/jaficial/210-lab-15

#include <iostream>
#include <fstream>
#include <array>

using namespace std;

/* NOTE: movie class needs these functions:
 * string screen writer
 * int year released
 * string title 
 * print add print function
 *
 * input has to come from the provided input file
 *
 * read the data into a temp Movie object, then append the object to a container
 * container can be either an <array> class array, or a <vector> class vector
 * all four movie objects have to be in the array/vector
 * */

class Movie {
pritvate:
	string movie_title;
	int year_released;
	string screen_writer;

public:
	string get_movie_title() {return movie_title;}
	void set_title(string title) {movie_title = title;}
	
	int get_year_released() {return year_released;}
	void set_year(int year) {year_released = year;}

	string screen_writer() {return screen_writer;}
	void set_writer(string writer) {screen_writer = writer;}

	// COME BACK TO THIS FUNCTION AFTERWARDS
	void print(){
		cout << "nothing for right now" << endl;
	}
};

void print(Movie);

// NOTE: to READ a line of STRING DATA: getline(fin, var_name);
//	 to READ a line of INT DATA: fin >> var_name;
int main(){
	ifstream fin ("input.txt");
	array<Movie, 4> movies;
	
	string temp_title;
	int temp_year;
	string temp_writer;
	
	int i = 0; // iterator
	if (fin.good()){
		while (fin >> g){
			fin.ignore();
			getline(fin, n);
			fin >> 
		}
	}

	fout.close("input.txt");
	return 0;
}
