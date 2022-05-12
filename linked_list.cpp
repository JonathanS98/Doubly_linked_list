/*
	Jonathan Shahi
	2022-04-28
	Objektbaserad programmering
	Lab 2 - Linked list
*/

#include "linked_list.h"
#include <iostream>
#include <cstddef>

using std::cout;
using std::cin;
using std::endl;

Linked_list::Linked_list() {

	head = nullptr;
	tail = nullptr;
}

Linked_list::Linked_list(const Linked_list& src) { 
	
	if (!is_empty()) { // if the list is not empty
		head = nullptr;
		tail = nullptr;
		*this = src; // uses the = operator to put src into *this       
	}
	else {   // if the list is empty a new list will construct
		head = nullptr;
		tail = nullptr;
	}
}

Linked_list::~Linked_list() {
	if (!is_empty()) { // if the list is not empty
		node* it = head;
		while (it != nullptr) { 
			it = it->prev;
			pop_front();
		}
	}
}

Linked_list::node::node(double value) { 
	this->value = value;
	this->next = nullptr;
	this->prev = nullptr;
}

void Linked_list::push_back(double value) {

	node* Newnode = new node(value);
	node* temp;

	if (tail != NULL)
	{

		temp = tail;
		temp->next = Newnode;
		tail = Newnode;
		tail->prev = temp;
		tail->next = NULL;
	}
	else
	{
		head = Newnode;
		tail = head;
		tail->next = NULL;
		tail->prev = NULL;
	}
}

void Linked_list::push_front(double value) {

	node* Newnode = new node(value);
	node* temp;

	if (head != NULL){
		temp = head;
		temp->prev = Newnode;
		head = Newnode;
		head->next = temp;
		head->prev = NULL;

	}
	else{
		head = Newnode;
		tail = head;
		head->prev = NULL;
		tail->next = NULL;
	}
}

void Linked_list::print() const {

	node* Newnode = head;
	while (Newnode != nullptr) {
		cout << Newnode->value << " ";
		Newnode = Newnode->next;
	}
	cout << "\n\n";
}

void Linked_list::print_reverse() const {
	node* Newnode = tail;
	while (Newnode != nullptr) {
		cout << Newnode->value << " ";
		Newnode = Newnode->prev;
	}
}

double Linked_list::back() const {
	if (tail != NULL) {
		return tail->value;
	}
	else {
		exit(1);
	}
}

double Linked_list::front() const {
	if (head != NULL) {
		return head->value;
	}
	else {
		exit(1);
	}
}

double Linked_list::at(size_t pos) const {
	node* Newnode = head;

	for (size_t i = 1; i < pos; i++) {
		Newnode = Newnode->next;
	}
	return Newnode->value;
}

void Linked_list::remove(size_t pos) {
	node* Newnode = head;
	node* n;

	if (head != NULL)
	{ 
		for (size_t i = 0; i < pos; i++) 
		{
			Newnode = Newnode->next;
		}

		if (Newnode->prev != NULL) 
		{
			n = Newnode->prev;
			n->next = Newnode->next;
		}
		if (Newnode->next != NULL) 
		{
			n = Newnode->next;
			n->prev = Newnode->prev;
		}
		delete Newnode; 
	}
}

size_t Linked_list::size() const {
	node* Newnode = head;
	size_t counter = 1;

	if (head != NULL)
	{
		while (Newnode->next != NULL)
		{
			Newnode = Newnode->next;
			counter++;
		}
		return counter;

	}
	return counter;
}



Linked_list& Linked_list::operator=(const Linked_list& rhs) {
	node* Newnode = rhs.head;
	if (this == &rhs) { // self assignment 
		return *this;
	}
	while (!is_empty()) { // pops the lhs list till its empty
		pop_back(); 
	}

	while (Newnode != nullptr) { // pushes back the rhs into the lhs
		push_back(Newnode->value);
		Newnode = Newnode->next;
	}
	return *this; // will return the value of what this is pointing at whitch is lhs
}

Linked_list& Linked_list::operator+=(const Linked_list& rhs) {
	node* Newnode = rhs.head;

	while (Newnode != nullptr) {  
		push_back(Newnode->value);
		Newnode = Newnode->next;
	}
	return *this;
}

double Linked_list::pop_back() {

	node* Newnode;
	double temp = 0;
	if (tail != NULL)
	{
		temp = tail->value;
		Newnode = tail;
		tail = Newnode->prev;
		delete Newnode;
		if (tail != NULL)
		{
			tail->next = NULL;
		}
	}
	return temp;
}

double Linked_list::pop_front() {

	double value = head->value;
	if (size() == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {

		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	
	return value;
}

bool Linked_list::is_empty() const {
	if (head == nullptr && tail == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

