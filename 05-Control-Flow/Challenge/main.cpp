// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    char choice {'0'};
    vector <int> list {};
    
    while(true){
           cout << "P - Print numbers" << endl;
           cout << "A - Add a number" << endl;
           cout << "M - Display mean of the numbers" << endl;
           cout << "S- Display the smallest number" << endl;
           cout << " L - Display the largest number" << endl;
           cout << "Q - Quit" << endl;
           cout << "\nEnter your choice: ";
           cin >> choice;
           if(choice == 'Q' || choice == 'q') {
               cout << "Goodbye!" << endl;
               break;
            }
           
           else{
               switch(choice){
                   case 'P':
                   case 'p':
                        if(list.size() == 0){
                            cout << "[] - the list is empty" << endl;
                        }
                        else{
                            cout << "[ ";
                            for(auto integer: list)
                                cout << integer << " ";
                            cout << "]" << endl;
                        }
                        break;
                        
                    case 'A':
                    case 'a':
                        int num;
                        cout << "Enter an integer to add to list: ";
                        cin >> num;
                        list.push_back(num);
                        cout << num << " added." << endl;
                        break;
                    
                    case 'M':
                    case 'm':
                        if(list.size() == 0) {
                            cout << "Unable to calcualte mean - no data." << endl;
                        }
                        else{
                            int results {0};
                            for(auto integer: list){
                                results += integer;
                            }
                            cout << "Mean: " << results/list.size() << endl;
                        }
                        break;
                    
                    case 'S':
                    case 's':
                        if(list.size() == 0){
                            cout << "Unable to determine smallest number - list is empty." << endl;
                        }
                        else{
                            int smallest {list.at(0)};
                            for(auto integer: list){
                                if(integer < smallest) smallest = integer;
                            }
                            cout << "Smallest number is: " <<  smallest << endl;
                        }
                        break;
                        
                    case 'L':
                    case 'l':
                        if(list.size() == 0){
                            cout << "Unable to determine largest number - list is empty." << endl;
                        }
                        else{
                            int largest {list.at(0)};
                            for(auto integer: list){
                                if(integer > largest) largest = integer;
                            }
                            cout << "Largest number is: " <<  largest << endl;
                        }
                        break;
                        
                    default: break;
                   
               } // switch
           }  // else
    } // while
    return 0;
}

