/***************************
Jadyn Reid
Date: June 24, 2025

Description:
This C++ program stores data for four animals using a class that
shows encapsulation. It shows off default and value
constructors, setters/getters, user input, and formatted output.
***************************/

#include <iostream>
#include <string>
using namespace std;

// Class declaration  
class Animal
{
public:
    Animal();                                      // default constructor
    Animal(string, string, int, double, double);   // explicit-value constructor

    // mutator (setter) functions
    void SetName(string);
    void SetType(string);
    void SetID(int);
    void SetAge(double);
    void SetWeight(double);

    // accessor (getter) functions
    string GetName()  const;
    string GetType()  const;
    int    GetID()    const;
    double GetAge()   const;
    double GetWeight()const;

private: // five private data members
    string name;
    string type;
    int    id;
    double age;
    double weight;
};

// Member Function Bodies
Animal::Animal()
{
    name = "Cat";
    type = "Mammal";
    id   = 123;
    age  = 3.0;
    weight = 16.0;
}

Animal::Animal(string name, string type, int id, double age, double weight)
{
    this->name   = name;
    this->type   = type;
    this->id     = id;
    this->age    = age;
    this->weight = weight;
}

// Setters
void Animal::SetName(string name)   { this->name = name; }
void Animal::SetType(string type)   { this->type = type; }
void Animal::SetID(int id)          { this->id   = id;   }
void Animal::SetAge(double age)     { this->age  = age;  }
void Animal::SetWeight(double wt)   { weight     = wt;   }

// Getters
string Animal::GetName()  const { return name;   }
string Animal::GetType()  const { return type;   }
int    Animal::GetID()    const { return id;     }
double Animal::GetAge()   const { return age;    }
double Animal::GetWeight()const { return weight; }

// Function Prototypes slay 
void getAnimalInfo(Animal& animal);         // input animal (by ref)
void printAnimalInfo(const Animal& animal); // output animal (const ref)


// Main function
int main()
{
    // 1 explicit-value object
    Animal animal1("Bird", "Aves", 101, 24.0, 55.5);

    // 3 default objects
    Animal animal2, animal3, animal4;

    // fill two via user input
    getAnimalInfo(animal3);
    getAnimalInfo(animal4);

    // print all 
    printAnimalInfo(animal1);
    printAnimalInfo(animal2);
    printAnimalInfo(animal3);
    printAnimalInfo(animal4);

    return 0;
}

// Programmer Functions
void getAnimalInfo(Animal& animal)
{
    string  name, type;
    int     id;
    double  age, weight;

    cout << "\n\n------Getting Animal Information-----\n";
    cout << "Enter name  : ";  cin >> name;
    cout << "Enter type  : ";  cin >> type;
    cout << "Enter ID    : ";  cin  >> id;
    cout << "Enter age (months) : ";  cin >> age;
    cout << "Enter weight (lbs) : ";  cin >> weight;

    // Use mutators to store values
    animal.SetName(name);
    animal.SetType(type);
    animal.SetID(id);
    animal.SetAge(age);
    animal.SetWeight(weight);
}

void printAnimalInfo(const Animal& animal)
{
    // Set the number of decimal places for doubles 
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "\n\n------Animal Info-----\n";
    cout << "Name   : " << animal.GetName()   << '\n';
    cout << "Type   : " << animal.GetType()   << '\n';
    cout << "ID     : " << animal.GetID()     << '\n';
    cout << "Age    : " << animal.GetAge()    << " months\n";
    cout << "Weight : " << animal.GetWeight() << " lbs\n";
}