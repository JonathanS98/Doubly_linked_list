/*
    Jonathan Shahi
    2022-04-28
    Objektbaserad programmering
    Lab 2 - Linked list
*/

#include <iostream>
#include <string>
#include <ctime>
#include "linked_list.h"

using std::cout;
using std::cin;
using std::endl;

void print_list(Linked_list l);
bool sorted(const Linked_list& list);
Linked_list merge(Linked_list& list1, Linked_list& list2);


int main() {
    
    Linked_list list1, list2, list3, list4;
    srand(time(NULL));

    cout << "--------------------TASK 1--------------------" << endl;
    cout << "Make two lists that cantain 50 random numbers with a range between 0-4" << endl;
    cout << "\n";


    for (size_t i = 0; i < 50; i++) {
        if (i == 0) {
            list1.push_back(0);
            list2.push_back(0);

        } 
        else {
            list1.push_back(list1.back() + (rand() % 5));
            list2.push_back(list2.back() + (rand() % 5));
        }
    }
    cout << "List 1: ";
    list1.print();    
    cout << "List 2: ";
    list2.print();


    cout << "--------------------TASK 2--------------------" << endl;
    cout << "Look for the 25th element in the lists above and remove the largest" << endl;
    cout << "\n";

    double num1 = list1.at(24);
    double num2 = list2.at(24);

    if (num1 > num2) {
        list1.remove(24);
        cout << num1 << " is larger than " << num2 << ". Removing " << num1 << " from list 1 " << endl;
        cout << endl;
    }
    else if (num1 < num2) {
        list2.remove(24);
        cout << num2 << " is larger than " << num1 << ". Removing " << num2 << " from list 2 " << endl;
        cout << endl;
    }
    else {
        int opt;
        cout << "Which list would you like to remove: ";
        cin >> opt;
        if (opt == 1) {
            list1.remove(24);
        }
        else if (opt == 2) {
            list2.remove(24);
        }
        else {
            cout << "Invalid input" << endl;
        }
    }

    cout << "List 1: Has " << list1.size() << " elements" << endl;
    cout << "List 2: Has " << list2.size() << " elements" << endl;
    cout << "\n";


    cout << "--------------------TASK 3--------------------" << endl;
    cout << "Print the list that contains less elements in another list, reversed" << endl;

    if (list1.size() > list2.size()) {
        list3 = list2; 
        cout << "\nlist3: ";
        list3.print_reverse();
    }
    else {
        list3 = list1;
        cout << "\nlist3: ";
        list3.print_reverse();
    }
    cout << "\n\n";
    

    
    cout << "--------------------TASK 4--------------------" << endl;
    cout << "Remove every other element in the list that contains 50 elements" << endl;
    cout << "\n";


    if (list1.size() > list2.size()) {
        for (size_t i = 0; i <= 24; i++) {
            list1.pop_back();
            list1.push_front(list1.pop_back());
        }
        cout << "List 1 has been cut in half." << endl;
        cout << "\n";
        list1.print();
    }
    else {
        for (size_t i = 0; i <= 24; i++) {
            list2.pop_back();
            list2.push_front(list2.pop_back());
        }
        cout << "List 2 has been cut in half." << endl;
        cout << "\n";
        list2.print();
    } 

    cout << "--------------------TASK 5--------------------" << endl;
    cout << "Print the list that now have been cut in half with the help of print_list() function" << endl;
    cout << "\n";
    
    if (list1.size() == 24) print_list(list1);
    else print_list(list2);
    //cout << "list1 " << list1.size() << endl;
    //cout << "list2 " << list2.size() << endl;

    cout << "--------------------TASK 6--------------------" << endl;
    cout << "Merge the two lists that were created in task 1" << endl;
    cout << "\n";


    list4 = merge(list1, list2);
    list4.print();
    //print_list(list4);

    cout << "--------------------TASK 7--------------------" << endl;
    cout << "Checks if the merge in the task above is sorted or not" << endl;
    cout << "\n";

    if (sorted(list4)) {
        cout << "List sorted" << endl;
        cout << "\n";
    }
    else {
        cout << "List not sorted" << endl;
        cout << "\n";
    }
    
    cout << "---------------------THE END-------------------------" << endl;
    cout << "\n";

	return 0;
    
}

void print_list(Linked_list l) {
    l.print();
}

Linked_list merge(Linked_list& list1, Linked_list& list2) {

    Linked_list merge_list;

    while (!list1.is_empty() && !list2.is_empty()) {
        if (list1.front() < list2.front()) {
            merge_list.push_back(list1.front());
            list1.pop_front();

        }
        else if (list1.front() > list2.front()) {

            merge_list.push_back(list2.front());
            list2.pop_front();

        }
        else if (list1.front() == list2.front()) {
            merge_list.push_back(list1.front());
            list1.pop_front();
            list2.pop_front();

        }
        else if (list1.front() == list1.front()) {
            merge_list.push_back(list1.front());
            list1.pop_front();

        }
        else if (list2.front() == list2.front()) {

            merge_list.push_back(list2.front());
            list2.pop_front();

        }

    }
    if (!list1.is_empty()) {
        merge_list += list1;
    }
    else if (!list2.is_empty()) {
        merge_list += list2;
    }
    return merge_list;
}

bool sorted(const Linked_list& l) {

    for (size_t i = 0; i < l.size() - 1 ; i++) {
        if (l.at(i + 1) < l.at(i)) {
            return false;
        }
    }
    return true;
}