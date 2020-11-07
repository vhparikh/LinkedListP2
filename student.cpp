//Created by Vatsal Parikh
//Date: 10/27/20
//.cpp file for student class all comments are in .h file

#include <iostream>
#include <cstring>

#ifndef STUDENT_H
#define STUDENT_H
#include "student.h"
#endif

using namespace std;

student::student() {

}

char* student::getFirst() {
  return first;
}

char* student::getLast() {
  return last;
}

void student::setId(int newid) {
  id = newid;
}

int student::getId() {
  return id;
}

void student::setGpa(float newgpa) {
  gpa = newgpa;
}

float student::getGpa() {
  return gpa;
}
