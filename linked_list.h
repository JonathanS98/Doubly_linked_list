/*
	Jonathan Shahi
	2022-04-28
	Objektbaserad programmering
	Lab 2 - Linked list
*/

#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <cstddef>
class Linked_list {
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	Linked_list();
	/// <summary>
	/// copyconstructor
	/// </summary>
	/// <param name="src">gets the referenced list </param>
	Linked_list(const Linked_list& src);

	~Linked_list();
	/// <summary>
	/// Copy operator 
	/// </summary>
	/// <param name="rhs"> Takes the value of the list on the rhs</param>
	/// <returns>Returns what "this" is pointing at, which in our case its lhs list </returns>
	Linked_list& operator=(const Linked_list& rhs);
	/// <summary>
	/// assignment operator
	/// </summary>
	/// <param name="rhs">Takes the value of the list on the rhs</param>
	/// <returns>Returns what "this" is pointing at, which in our case its lhs list</returns>
	Linked_list& operator+=(const Linked_list& rhs);

	void insert(size_t pos);
	/// <summary>
	/// push elements at front
	/// </summary>
	/// <param name="value">is the value that gets pushed from the front</param>
	void push_front(double value);
	/// <summary>
	/// push elements at back
	/// </summary>
	/// <param name="value">is the value that gets pushed from the back</param>
	void push_back(double value);
	
	/// <summary>
	/// Adds elemenets from the front
	/// </summary>
	/// <returns>Returns the value</returns>
	double front() const;
	/// <summary>
	/// Adds elemenets from the back
	/// </summary>
	/// <returns>Returns the value</returns>
	double back() const;
	/// <summary>
	/// Points at an element 
	/// </summary>
	/// <param name="pos">point at the giving position</param>
	/// <returns>Returns the position</returns>
	double at(size_t pos) const;
	/// <summary>
	/// Removes an element
	/// </summary>
	/// <param name="pos">Gets the position of elements its going to remove</param>
	void remove(size_t pos);
	/// <summary>
	/// pops element from the front
	/// </summary>
	/// <returns>Return the value</returns>
	double pop_front();
	/// <summary>
	/// pops element from the front
	/// </summary>
	/// <returns>Return the value</returns>
	double pop_back();
	/// <summary>
	/// calculates the size of an element
	/// </summary>
	/// <returns>Returns size</returns>
	size_t size() const;
	/// <summary>
	/// checks if the list is empty
	/// </summary>
	/// <returns>Return true if the list is empty OR false if the list contains elements</returns>
	bool is_empty() const;
	/// <summary>
	/// prints the function
	/// </summary>
	void print() const;
	/// <summary>
	/// prints the function in reverse
	/// </summary>
	void print_reverse() const;
private:
	struct node {
		/// <summary>
		/// Creates a node
		/// </summary>
		/// <param name="value">Will recieve the value</param>
		node(double value);
		double value;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;

};

#endif