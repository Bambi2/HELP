#include <iostream>
#include <string>

using namespace std;


class person                      //class of persons
   {
   protected:
      string name;   
      float salary;             //person's name
   public:
      void setData()              //set the name
      { cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
      }
      void printData()            //display the name
      { cout << endl << name;
        cout << endl << salary;
      }
      string getName()            //return the name
      { return name; }
      float getSalary()
      { return salary; }
   };


   void salSortQ(person** arr, int size){
       int min_idx;

       for (int i = 0; i < size - 1; i++){
           for (int j = i + 1, min_idx = i; j < size; j++){
               if ((*(arr + j))->getSalary() < (*(arr + min_idx))->getSalary()){
                   min_idx = j;
               }
           }
           person* temp = *(arr + min_idx);
           *(arr + min_idx) = *(arr + i);
           *(arr + i) = temp;
       }
   }







////////////////////////////////////////////////////////////////
int main()
   {
   person* persPtr[100];          //array of pointers to persons
   int n = 0;                     //number of persons in array
   char choice;                   //input char
          
   do {                           //put persons in array
      persPtr[n] = new person;    //make new object
      persPtr[n]->setData();      //set person's name
      n++;                        //count new person
      cout << "Enter another (y/n)? "; //enter another
      cin >> choice;              //   person?
      }
   while( choice=='y' );          //quit on 'n'

   cout << "\nUnsorted list:";
   for(int j=0; j < n; j++)         //print unsorted list
      { persPtr[j]->printData(); }     

    salSortQ(persPtr, n);

   cout << "\nSorted list:";
   for(int j = 0; j < n; j++)             //print sorted list
      { persPtr[j]->printData(); }
   cout << endl;

   return 0;
   }  //end main()
