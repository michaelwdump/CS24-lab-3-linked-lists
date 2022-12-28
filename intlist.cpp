// intlist.cpp
// Implements class IntList
//Michael Wong 6209282
//Daryon Roshanzaer 5701388

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {

	Node* h = source.first;
	Node* temp1 = nullptr;
	Node* temp2 = nullptr;
	if (!h) (first = nullptr);
	else {
		temp1 = new Node {h->info, nullptr};
		first = temp1;
		while (h) {//wb if h->next->info has no info?
			if (!h->next) temp2 = nullptr;
			else (temp2 = new Node {h->next->info, nullptr});
			temp1->next = temp2;
			temp1 = temp2;
			h = h->next;
		}
	}
		
}

// destructor helper 
void IntList::clear(Node* h) {
	if (!h) return;
	clear(h->next);
	delete h;
}

// destructor deletes all nodes
IntList::~IntList() {
	clear(first);
	first = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    Node* temp = first;
	int sum = 0;
	while (temp) {
		sum += temp->info;
		temp = temp->next;
	}
	return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
	Node* temp = first;
	while (temp) {
		if (temp->info == value) return true;
		else temp = temp->next;
	}	
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
	Node* temp = first;
	if (!temp) return 0;
	int max = temp->info;
	while (temp && temp->next) {
		if (temp->next->info > max) {
			max = temp->next->info;
		}
		temp = temp->next;
	}
	return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
	Node* temp = first;
	if (!temp) return 0;
	double sum = 0;
	double count = 0;
	while (temp) {
		count += 1;
		sum += temp->info;
		temp = temp->next;
	}
	return sum/count;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
	Node* newHead = new Node {value, first};
	first = newHead;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
	clear(first);
	Node* h = source.first;
	Node* temp1 = nullptr;
	Node* temp2 = nullptr;
	if (!h) (first = nullptr);
	else {
		temp1 = new Node {h->info, nullptr};
		first = temp1;
		while (h) {//wb if h->next->info has no info?
			if (!h->next) temp2 = nullptr;
			else (temp2 = new Node {h->next->info, nullptr});
			temp1->next = temp2;
			temp1 = temp2;
			h = h->next;
		}
	}
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
