/***************************
Jadyn Reid
Date: June 19, 2025

Description:
This C++ program defines a struct called "animals" to store information
about 3 animals. It reads animal info from a file and prints the data
using separate functions. The program uses structs, reference parameters,
file input, and basic control structures.
***************************/

#include <iostream> 
#include <string>
using namespace std;
#include <fstream> // header file for file i/o 



// Struct animals w/ 5 member variables
// At top of program so it can be used gloabally
struct animals {

    string name; // name of animal
    string type; // type of animal
    int id; // unique id
    double age; // in years 
    double weight; // in lbs

};

void getData(ifstream& in, animals& animal); //read animals info from file
void printAnimalInfo(const animals& animal); //print animals info


int main(){

    //delcaring stuct objects / variable names
    animals animal1, animal2, animal3;

    ifstream in;

    //connecting to the input file 
    in.open("animalInput.txt");


    // if file not found
    if (in.fail()){
        cout << "Input file did not open correctly" << endl;
        return 1;
    } else {

        //Read and display each animal
        getData(in, animal1);
        printAnimalInfo(animal1);

        getData(in, animal2);
        printAnimalInfo(animal2);

        getData(in, animal3);
        printAnimalInfo(animal3);

    }
    
    in.close();
    return 0;

}

// Read each animal's data from file (line by line)
void getData(ifstream& in, animals& animal) {
    getline(in, animal.name);
    getline(in, animal.type);
    in >> animal.id;
    in >> animal.age;
    in >> animal.weight;
    in.ignore(); // skip the newline character after the weight
}

// Print each animal's data
void printAnimalInfo(const animals& animal) {
    cout << "------ Printing Animal Info ------\n";
    cout << "Name: " << animal.name << endl;
    cout << "Type: " << animal.type << endl;
    cout << "ID: " << animal.id << endl;
    cout << "Age: " << animal.age << " years" << endl;
    cout << "Weight: " << animal.weight << " lbs\n\n";
}