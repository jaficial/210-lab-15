#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <fstream>
using namespace std;

const int W15 = 15, SIZE = 5;

class Student {
private:
    double GPA;
    string name;
    int courseLoad;
public:
    // getters and setters
    double getGPA()              { return GPA; }
    void setGPA(double g)        { GPA = g; }
    string getName()             { return name; }
    void setName(string n)       { name = n; }
    int getCourseLoad()          { return courseLoad; }
    void setCourseLoad(int c)    { courseLoad = c; }

    // other methods
    void print() {
        cout << setw(W15) << "GPA: " << GPA << endl;
        cout << setw(W15) << "Name: " << name << endl;
        cout << setw(W15) << "Course load: " << courseLoad << endl;
    }
};

// containers are written in the main function.
// for ex: arr[i] : [stu], [stu], [stu]
// YOU CANNOT DO: arr[i].name
// YOU HAVE TO: .getName(); (use the setter/getter to traverse an array of objects)
// for ex: 
// for (auto(val)) students{
//	cout << val.getname();
//	cout << val.getID();
// }
int main(){ 
	// declarations
    cout << fixed << setprecision(2);
    
    //using both vector and array methods
    vector<Student> students_v;
    array<Student, SIZE> students_a;

    ifstream fin ("input2.txt");
    double g;  // holds temporary GPA
    int l;     // holds temporary load
    string n;  // holds temporary name
    int i = 0; // temporary index
	
    // tests to make sure that file is all good, testing for readable data
    if (fin.good()) {
        while (fin >> g) {
            fin.ignore();
            getline(fin, n);
            fin >> l; 
	
	    // uses temporary student object, afterwards, push the object into the vector
	    // right under, "students_a[i] = tmp" is how to append the object to an array type
            Student tmp;
            tmp.setGPA(g);
            tmp.setName(n);
            tmp.setCourseLoad(l);

	    // vector method doesnt need an iterator, just push in object 
	    // array needs an iterator
            students_v.push_back(tmp);
            students_a[i] = tmp;
            i++;
        }
        fin.close();
    }
    else
        cout << "Input file not found.\n";

    // output vector
    for (auto val : students_v) {
        cout << val.getGPA() << " " << val.getName() 
        << " " << val.getCourseLoad() << endl;
    }
    cout << endl;

    // output array
    for (auto val : students_a) {
        cout << val.getGPA() << " " << val.getName() 
        << " " << val.getCourseLoad() << endl;
    }
    
    return 0;
}
