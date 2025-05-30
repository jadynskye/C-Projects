#include <iostream>
using namespace std;

//First void function
//Have to use reference parameters to collect and store info gathered
void get_info(string& name, int& age, int& year ){

    //Print statements to obtain initial information
    cout << "\nWhat is your name? ";
    cin >> name;
    cout << "\nWhat is your age? ";
    cin >> age;
    cout << "\nWhat year were you born in? ";
    cin >> year;
    // "---" for presentability  
    cout << "----------------------------------------------- \n";
}

//Function for finding out what generation each of the 3 people are in
void generation_catagory(string& name, int& year){
    cout << name << "...";

    if(year < 1901){
        cout << "\nYou are apart of the Lost Generation";
    } else if (year >= 1901 && year <= 1927){
        cout << "\nYou are apart of the The Greatest Generation (aka G.I. Generation)";
    } else if (year >= 1928 && year <= 1945){
        cout << "\nYou are apart of the The Silent Generation (Traditionalists)";
    } else if (year >= 1946 && year <= 1980){
        cout << "\nYou are apart of the Generation X";
    } else if (year >= 1981 && year <= 1996){
        cout << "\nYou are apart of the Millennials (Generation Y)";
    } else if (year >= 1997 && year <= 2012){
        cout << "\nYou are apart of Generation Z (Centennials, iGen)";
    } else if (year >= 2012 && year <= 2024){
        cout << "\nYou are apart of Generation Alpha";
    } else if (year >= 2025){
        cout << "\nYou are apart of Generation Beta\n\n";
    }
}

//Function for finding youngest person(s)
void youngest(string name1, string name2, string name3, int age1, int age2, int age3){

    if(age1 < age2 && age1 < age3){
        cout << name1 << ", you are the youngest among the other 2 people.";
    } else if (age2 < age1 && age2 < age3){
        cout << name2 << ", you are the youngest among the other 2 people.";
    } else if (age3 < age1 && age3 < age2){
        cout << name3 << ", you are the youngest among the other 2 people.";
    } else if(age1 == age2 && age1 < age3){
        cout << name1 << " and " << name2 << " are the youngest.";
    } else if(age1 == age3 && age1 < age2){
        cout << name1 << " and " << name3 << " are the youngest.";
    } else if(age2 == age3 && age2 < age1){
        cout << name2 << " and " << name3 << " are the youngest.";
    } else {
        cout << "All three people are the same age.";
    }

}

//Function for finding oldest person(s)
void oldest(string name1, string name2, string name3, int age1, int age2, int age3){

    if(age1 > age2 && age1 > age3){
        cout << name1 << ", you are the oldest among the other 2 people.";
    } else if (age2 > age1 && age2 > age3){
        cout << name2 << ", you are the oldest among the other 2 people.";
    } else if (age3 > age1 && age3 > age2){
        cout << name3 << ", you are the oldest among the other 2 people.";
    } else if(age1 == age2 && age1 > age3){
        cout << name1 << " and " << name2 << " are the oldest.";
    } else if(age1 == age3 && age1 > age2){
        cout << name1 << " and " << name3 << " are the oldest.";
    } else if(age2 == age3 && age2 > age1){
        cout << name2 << " and " << name3 << " are the oldest.";
    } else {
        cout << "All three people are the same age.";
    }

}

// Function to print leap years from birth year to 2025
void leap_years(const string& name, const int& birth_year){
    cout << "\nLeap years " << name << " has lived through:\n";

    for(int year = birth_year; year <= 2025; year++){
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            cout << year << " ";
        }
    }
    cout << "\n-----------------------------------------------\n";
}



int main(){
    char again;

    do{
        //Creating variables needed for all 3 reference parameters 
        string name1, name2, name3;
        int age1, age2, age3;
        int year1, year2, year3;

        //Get info for each person
        get_info(name1, age1, year1);
        generation_catagory(name1, year1);

        get_info(name2, age2, year2);
        generation_catagory(name2, year2);

        get_info(name3, age3, year3);
        generation_catagory(name3, year3);

        // Compare ages
        youngest(name1, name2, name3, age1, age2, age3);
        cout << endl;
        oldest(name1, name2, name3, age1, age2, age3);
        cout << endl;

        // Print leap years
        leap_years(name1, year1);
        leap_years(name2, year2);
        leap_years(name3, year3);

        // Ask if user wants to do it again
        cout << "\nWould you like to enter info for 3 more people? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');




    return 0;
}
