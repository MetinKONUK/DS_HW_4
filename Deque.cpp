#include "Deque.h"

///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	this->head = NULL;
	this->tail = NULL;
	this->noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	delete this->head;
	delete this->tail;
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	DequeNode* newNode = new DequeNode(item);
	if (this->head == NULL && this->tail == NULL) {
		this->head = newNode;
		this->tail = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
		return;
	}
	newNode->next = this->head;
	if (this->head != NULL) {
		this->head->prev = newNode;
	}
	newNode->prev = NULL;
	this->head = newNode;

} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	DequeNode* newNode = new DequeNode(item);
	if (this->head == NULL && this->tail == NULL) {
		this->head = newNode;
		this->tail = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
		return;
	}
	newNode->next = NULL;
	newNode->prev = this->tail;
	if (this->tail != NULL) {
		this->tail->next = newNode;
	}
	this->tail = newNode;

} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	if (this->head == NULL) {
		throw invalid_argument("The list is empty!");
		return 0;
	}
	if (this->head->next == NULL) {
		int holder = this->head->item;
		this->head = NULL;
		this->tail = NULL;
		return holder;
	}
	DequeNode* newHead;
	int holder = this->head->item;
	newHead = this->head->next;
	newHead->prev = NULL;
	delete this->head;
	this->head = newHead;
	return holder;
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	if (this->tail == NULL) {
		throw invalid_argument("The list is empty!");
		return 0;
	}
	if (this->tail->prev == NULL) {
		int holder = this->tail->item;
		this->tail = NULL;
		this->head = NULL;
		return holder;
	}
	DequeNode* newTail;
	int holder = this->tail->item;
	newTail = this->tail->prev;
	newTail->next = NULL;
	delete this->tail;
	this->tail = newTail;
	return holder;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	if (this->head == NULL) {
		throw invalid_argument("The list is empty!");
		return 0;
	}
	return this->head->item;
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	if (this->tail == NULL) {
		throw invalid_argument("The list is empty!");
		return 0;
	}
	return this->tail->item;
} //end-Rear
