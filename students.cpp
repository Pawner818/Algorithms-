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
    // Additional extension - it shows how much time our program is running. 
    auto start = chrono::high_resolution_clock::now();

    // Our vector 
    vector <Person> Students {
        Person("Zakhar",192,22),
        Person("Misha", 129,21),
        Person("Sergey", 200, 16),
        Person("Anastasia", 200,21),
        Person("Aleksandr",129,33),
        Person("Ignat",123,34),
        Person("Dmitriy",139,32),
        Person("Katya",194,19),
        Person("Polina",199,18),
        Person("Marina", 181,17),
        Person("Artur", 189,19),
        Person("Masha", 85,21)
    };
    
    // Algorithm remove_if successfully switch position of our students. In the first part of the vector, there will be students whose age is between 18 and 30.
    // We use the labda - function as a third parameter to choose, what term we will use to remove students.

    auto SuitableStudents = remove_if(Students.begin(), Students.end(), [](const Person& person)

        {
            return person.age < 18;
        }
    );
    
    // The next step is to actually delete unnecessary data using the algorittm erase(). Our variable SuitableStudents now is a pointer 
    // to the beggining of our vector Students which already stores all the necessary students
   
    Students.erase(SuitableStudents, Students.end());
    
    // Now let's cout what we got after cleaning!

    cout<<endl;
    cout<<"*** STUDENTS ***\n";
    
    for (auto el : Students)
    {
        cout<<"Applicant "<< el.name << " can be accepted as a student!"<<endl;
    }
    
    // You can add additional verifications to clean your vector or another container, it's up to you. But if you don't want to remove anything
    // we can use sorting methods to create another vector that will already be sorted.

    vector <Person> NewStudents;
    copy_if(Students.begin(), Students.end(), back_inserter(NewStudents), [](const Person& SmartStudents) 
    {
        return SmartStudents.score > 150;
    }
    );
    
    // We copied the students to the new vector, based on the old already cleaned vector.
    // Let's see our perfect candidates!

    cout<<endl;
    for (auto fel : NewStudents)
    {
        cout<<"Congratulations! Applicant "<< fel.name << " scored enough poits and he/she can be accepted as a student!"<<endl;
    }
    
    // Logic of our simple timer. This is not neccessary here but in a big projects when you're working with algorithms 
    // it's better to know how much time it takes to work. 

    cout<<endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float>duration = end - start;
    cout << "Duration is = " << duration.count() << " sec" << endl;

    return 0;
}

