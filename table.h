// Alayne Anderson
// hw3, table.h
// this file contains the declaration of the class table

#include "list.h"

class table {
public:
  table();
  ~table();
  int load_file(); // load in and organize all the activities into the table
                   // from outside file
  int retrieve(char location[], list &collection); // pass all the activities in
                                                   // the same pocation as a
                                                   // list
  int display(
      char location[]); // display all the activities in the same location
  int display_all();    // display all the activities in the table
  int remove(char location[]); // remove all the activities in the same location
                               // in the table
private:
  list **array;
  int hash(char location[]); // return the hash value of every location
};

