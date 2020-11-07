//Created by Vatsal Parikh
//Date: 10/27/20
//.h file for student class

//imports
#include <iostream>
#include <cstring>

using namespace std;

class student {
 public:
  student(); //constructor
  char* getFirst(); //returns first name
  char* getLast(); //returns last name
  void setId(int newid); //sets id
  int getId(); //returns id
  void setGpa(float newgpa); //sets gpa
  float getGpa(); //returns gpa
 private:
  char first[100]; //store first name
  char last[100]; //store last name
  int id; //store id
  float gpa; //store gpa
};

