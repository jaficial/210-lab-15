// COMSC-210 || Jed Aficial || Lab 15
// https://github.com/jaficial/210-lab-15

#include <iostream>
#include <iomanip>
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
private:
	string movie_title;
	int year_released;
	string screen_writer;

public:
	string get_movie_title() {return movie_title;}
	void set_title(string title) {movie_title = title;}
	
	int get_year_released() {return year_released;}
	void set_year(int year) {year_released = year;}

	string get_screen_writer() {return screen_writer;}
	void set_writer(string writer) {screen_writer = writer;}

	// COME BACK TO THIS FUNCTION AFTERWARDS
	void print(){
		cout << "Movie: " << movie_title << endl;
		cout << setw(18) << "Year released: " << year_released << endl;
		cout << setw(17) << "Screenwriter: " << screen_writer << endl;
	}
};

void print(Movie);

// NOTE: to READ a line of STRING DATA: getline(fin, var_name);
//	 to READ a line of INT DATA: fin >> var_name;
//	 fin.ignore anytime between "fin >>" and "getline()"
int main(){
	ifstream fin ("input.txt");
	array<Movie, 4> movies;
	
	string temp_title;
	int temp_year;
	string temp_writer;
	int i = 0; 
	
	if (fin.good()){
		while (getline(fin, temp_writer)){
			fin >> temp_year;
			fin.ignore();
			getline(fin, temp_title);

			Movie temp_object;
			temp_object.set_title(temp_title);
			temp_object.set_year(temp_year);
			temp_object.set_writer(temp_writer);

			movies[i] = temp_object;
			i++;
		}
	}
	else{
		cout << "Invalid File and/or File Not Found." << endl;

	}
	fin.close();

	// movie_num represents an object including members to that object
	for (auto movie_num : movies){
		movie_num.print();
		cout << endl;
	}

	return 0;
}
