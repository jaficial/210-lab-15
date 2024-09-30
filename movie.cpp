// COMSC-210 | Lab 15 | Jed Aficial
// github link: https://github.com/jaficial/210-lab-15

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>

using namespace std;

/* NOTE: movie class requires these three members:
	movie_title and screen_writer type is expected to be a string
	year_released type is expected to be an int*/
class Movie {
private:
	string movie_title;
	int year_released;
	string screen_writer;

/* getter and setter functions for each private member*/
public:
	string get_movie_title() {return movie_title;}
	void set_title(string title) {movie_title = title;}
	
	int get_year_released() {return year_released;}
	void set_year(int year) {year_released = year;}

	string get_screen_writer() {return screen_writer;}
	void set_writer(string writer) {screen_writer = writer;}

	// print function prints out the object members in a simple format when print() is called
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

/* CITED: Cited the class lecture code/lecture video (Containers of Objects) to 
   learn how to use an array container to store an object.*/
   
// main function creates an array container that holds the four movie objects, 
int main(){
	ifstream fin ("input.txt");
	array<Movie, 4> movies;
	
	// temporary variables are used for the member functions
	string temp_title;
	int temp_year;
	string temp_writer;
	int i = 0; 
	
	if (fin.good()){
		// use temporary object to hold data that is being read from input text file
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

	/* movie_num represents an object including members to that object, print function
	   is then called to output the data for each Movie object that is stored in the 
	   array container. */ 
	for (auto movie_num : movies){
		movie_num.print();
		cout << endl;
	}

	return 0;
}
