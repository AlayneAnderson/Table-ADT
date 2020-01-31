// Alayne Anderson
// hw3, table.cpp
// this file contains all the functions in the table class

#include "table.h"
#include <fstream>
using namespace std;

table::table() {
  array = new list *[5];
  for (int i = 0; i < 5; ++i)
    array[i] = new list;
}

table::~table() {
  for (int i = 0; i < 5; ++i) {
    delete array[i];
    array[i] = NULL;
  }
  delete[] array;
  array = NULL;
}

// this function calculates the hash value deponding on the location
// and return the hash value finally
int table::hash(char location[]) {
  int a = 0;
  int index = strlen(location);
  for (int i = 0; i < index / 2; ++i)
    a = a + location[i] + location[--index];
  return (a % 5);
}

// this function loads in and organizes all the activities form outside file
// finally return 1
int table::load_file() {
  list test;
  activity *temp = new activity;
  temp->name = new char[SIZE];
  temp->description = new char[SIZE];
  temp->location = new char[SIZE];
  temp->sqar_ft = new char[SIZE];
  temp->num_rooms = new char[SIZE];
  ifstream file_in;
  file_in.open("activity.txt");
  if (file_in) {
    file_in.get(temp->name, SIZE, ';');
    while (!file_in.eof()) {
      file_in.ignore(SIZE, ';');
      file_in.get(temp->description, SIZE, ';');
      file_in.ignore(SIZE, ';');
      file_in.get(temp->location, SIZE, ';');
      file_in.ignore(SIZE, ';');
      file_in.get(temp->sqar_ft, SIZE, ';');
      file_in.ignore(SIZE, ';');
      file_in.get(temp->num_rooms, SIZE, ';');
      file_in.ignore(SIZE, ';');
      file_in >> temp->distance_PSU;
      file_in.ignore(SIZE, '\n');
      int index = hash(temp->location);
      array[index]->add(temp);
      file_in.get(temp->name, SIZE, ';');
    }
    file_in.close();
  }
  return 1;
}

// this fuction passes all the activities
// in the same location(which is the argument)
// as a list, and return 1 finally
int table::retrieve(char location[], list &collection) {
  int index = hash(location);
  node *temp;
  array[index]->get_head(temp);
  while (temp) {
    if (strcmp(temp->data->location, location) == 0)
      collection.add(temp->data);
    temp = temp->next;
  }
  return 1;
}

// this fuction displays all the activities
// which locations are the same as the argument
// and return 1 finally
int table::display(char location[]) {
  int index = hash(location);
  array[index]->display(location);
  return 1;
}

// this function displays all the activities in the table
// finally return 1
int table::display_all() {
  for (int i = 0; i < 5; ++i)
    array[i]->display_all();
  return 1;
}

// this functin removes all the activities with the same location as the
// argument
// and return 1 finally
int table::remove(char location[]) {
  int index = hash(location);
  array[index]->remove(location);
  return 1;
}

