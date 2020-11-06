//Created Vatsal Parikh
//Date: 10/27/20
//main file for LL code

//imports
#include <iostream>
#include <cstring>
#include <iomanip>

#ifndef STUDENT_H
#define STUDENT_H
#include "student.h"
#endif

#ifndef NODE_H
#define NODE_H
#include "node.h"
#endif

using namespace std;

//prototype
void ADD(node* &n, student* std);
void PRINT(node* next);
void DELETE(node* &n, node* h, int id);
void AVERAGE(node* n, float* sum, int* counter);

int main()
{
  
  node* head = NULL; //creates a head node pointer to point to first node in list

  //variables for game loop
  bool quit = false;
  char input[20];

  //for average calculations
  float sum = 0;
  int counter = 0;
  float average = 0;

  cout << "Welcome to Linked List your commands are ADD, PRINT, DELETE, AVERAGE and QUIT" << endl;
  
  //while quit is false
  while (quit == false) {
    cin >> input; //get input

    //if input is add then:
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {

      //creates a student to pass into add
      student* newstd = new student();
      int in;
      float fl;

      //gets all the studnet info
      cout << "First name: ";
      cin >> newstd->getFirst();
      cout << "Last name: ";
      cin >> newstd->getLast();
      cout << "ID: ";
      cin >> in;
      newstd->setId(in);
      cout << "GPA: ";
      cin >> fl;
      newstd->setGpa(fl);
      ADD(head, newstd); //call add
    }

    //else if input is print then:
    else if (strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0) {
      PRINT(head); //call print
    }

    //else if input is delete then:
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      int id; 
      cout << "Enter the id for the student profile you would like to delete: ";
      cin >> id; //get id to delete
      DELETE(head, head, id); //call delete
    }

    //else if input is average then:
    else if (strcmp(input, "AVERAGE") == 0 || strcmp(input, "average") == 0) {
      AVERAGE(head, &sum, &counter); //call average
      average = sum/counter; //do final calculation
      cout << "The average is: " << fixed << setprecision(2) << average << endl;

      //set all variables back to zero for next time average is called
      sum = 0;
      counter = 0;
      average = 0;
    }

    //else if input is quit then:
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      quit = true; //sets quit to true which will result in the end of the game loop
    }

    //else it's an invalid command
    else {
      cout << "Invalid command" << endl;
    }
  }
}

//adds student in correct location in list based on id
void ADD(node* &n, student* std) //parameters: node pointer by reference to the node to check and the student info
{

  //n is null then just create the node there and set n to it
  if (n == NULL) {
    n = new node(std);
  }

  //else if the id is less than the current head make it new head
  else if (std->getId() <= n->getStudent()->getId()) {
    node* temp = n;
    n = new node(std);
    n->setNext(temp);
  }

  //else if the next node is null then just add in the new node
  else if (n->getNext() == NULL) {
    node* temp = new node(std);
    n->setNext(temp);
  }

  //else if insert in the middle of the list between two nodes
  else if (std->getId() >= n->getStudent()->getId() &&
	   std->getId() <= n->getNext()->getStudent()->getId()) {
    node* temp = new node(std);
    temp->setNext(n->getNext());
    n->setNext(temp);
  }

  //else use recursion to proceed to the next node
  else {
    node* temp = n->getNext();
    ADD(temp, std);
  }
}

//prints out all the students in sorted order
void PRINT(node* next) //parameters: node pointer to node to start at
{

  //if the node isn't null then print out the student info and use recursion to go to the next node
  if (next != NULL) {
    cout << next->getStudent()->getFirst() << " " << next->getStudent()->getLast()
	 << ", " << next->getStudent()->getId() << ", " << fixed << setprecision(2)
	 << next->getStudent()->getGpa() << endl;
    next = next->getNext();
    PRINT(next);
  }
}

//deletes a student based on the id inputted
void DELETE(node* &n, node* h, int id) //parameters: node pointer by reference, head node, and id
{
  char input[20];

  //if id is the head node then delete it as so
  if (n == h && n->getStudent()->getId() == id) {
    cout << "Would you like to remove this student from the list y/n: " << n->getStudent()->getFirst()
	 << " " << n->getStudent()->getLast() << ", " << n->getStudent()->getId() << ", " << fixed
	 << setprecision(2) << n->getStudent()->getGpa() << "? ";
    cin >> input;
    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
      cout << n->getStudent()->getFirst() << " " << n->getStudent()->getLast() << ", "
	   << n->getStudent()->getId() << ", " << fixed << setprecision(2)
	   << n->getStudent()->getGpa() << " has been removed from the list" <<endl;
      node* temp = n->getNext();
      n->~node();
      n = NULL;
      n = temp;
    }
  }

  //else if node is somewhere else in list delete as so
  else if (n->getNext()->getStudent()->getId() == id) {
    cout << "Would you like to remove this student from the list y/n: "
	 << n->getNext()->getStudent()->getFirst() << " "
	 << n->getNext()->getStudent()->getLast() << ", "
	 << n->getNext()->getStudent()->getId() << ", "
	 << fixed << setprecision(2) <<  n->getNext()->getStudent()->getGpa()
	 << "? ";
    cin >> input;
    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
      cout << n->getNext()->getStudent()->getFirst() << " "
	   << n->getNext()->getStudent()->getLast() << ", "
	   << n->getNext()->getStudent()->getId()	<< ", "
	   << fixed << setprecision(2) << n->getNext()->getStudent()->getGpa()
	   << " has been removed from the list"  << endl;
      node* temp = n->getNext()->getNext();
      n->getNext()->~node();
      n->setNext(temp);
    }
  }

  //if we reached end and nothing found return
  else if (n->getNext() == NULL) {
    return;
  }

  //else use recursion to move onto next node
  else {
    node* temp = n->getNext();
    DELETE(temp, h, id);
  }
}

//calculates average gpa of all students
void AVERAGE(node* n, float* sum, int* counter) //parameters: node pointer, float pointer, int pointer
{

  //if node isn't null get info add to variables and use recursion to get next student gpa
  if (n != NULL) {
    *sum += n->getStudent()->getGpa();
    *counter += 1;
    AVERAGE(n->getNext(), sum, counter);
  }
}
