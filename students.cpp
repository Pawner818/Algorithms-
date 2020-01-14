#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

// This is simple example with one file so I can use namespace std.
using namespace std;


// Creating a class. The class will contain some parameters.
class Person
{
public:
	
    // Overloaded constructor with some parameters
	Person(string name, double score, int age)
	{
		this->name = name;
		this->score = score;
		this->age = age;
	}
    
    // Overloaded operator () 
	bool operator()(const Person& p)
	{
		return p.score > 180;
	}
	
	int age;
	string name;
	double score;
};

int main()
{
    // Additional extension - it shows how much time our 
    auto start = chrono::high_resolution_clock::now();

          



    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float>duration = end - start;
    cout << "Duration is = " << duration.count() << " sec" << endl;

    return 0;
}

