//this contains the main file
// Alayne Anderson
// hw3, main.cpp
// this file contains the main fucntion

#include "table.h"
using namespace std;

int main() {
  table temp;
  temp.load_file();
  cout << "\n\n\n---------------display_all---------------" << endl;
  temp.display_all();

  cout << "\n\n\n---------------display_location---------------" << endl;
  char test[50];
  cout << "enter the location you want to display: ";
  cin.get(test, 50, '\n');
  cin.ignore(100, '\n');
  temp.display(test);

  cout << "\n\n\n---------------retrieve_location---------------" << endl;
  char test1[50];
  cout << "enter the location you want to retrieve: ";
  cin.get(test1, 50, '\n');
  cin.ignore(100, '\n');
  list collection;
  temp.retrieve(test1, collection);
  collection.display_all();

  cout << "\n\n\n--------------remove_beyond miles--------------" << endl;
  char test2[50];
  cout << "enter the amount of miles that would be unnecessary: ";
  cin.get(test2, 50, '\n');
  cin.ignore(100, '\n');
  temp.remove(test2);
  temp.display_all();

  return 0;
}

