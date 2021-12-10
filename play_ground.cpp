#include <iostream>
using namespace std;

struct DequeNode {
	int item;
	DequeNode* prev, * next;

	DequeNode(int item) {
		this->item = item;
		this->prev = this->next = NULL;
	}
};

class Deque {
public:
	DequeNode* head, * tail;
	int noOfItems;
public:
	Deque() {
		this->head = NULL;
		this->tail = NULL;
		this->noOfItems = 0;
	};
	~Deque() {
		delete this->head;
		delete this->tail;
	};
	void PrintReverse() {
		DequeNode* node = this->tail;
		cout << "Listing items" << endl;
		while (node != NULL) {
			cout << node->item << endl;
			node = node->prev;
		};
	};
	void PrintList() {
		DequeNode* node = this->head;
		cout << "Listing items" << endl;
		while (node != NULL) {
			cout << node->item << endl;
			node = node->next;
		};
	};
	void AddFront(int item) { 
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

	};
	void AddRear(int item) {
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

	};

	int RemoveFront() {
		/// Remove and return the item at the front of the Deque
		/// If the Deque is empty, throw an exception
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
	};
	int RemoveRear() {
		/// Remove and return the item at the rear of the Deque
		/// If the Deque is empty, throw an exception
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
	};

	int Front() {
		/// Return the item at the front of the Deque (do not remove the item)
		/// If the Deque is empty, throw an exception
		if (this->head == NULL) {
			throw invalid_argument("The list is empty!");
			return 0;
		}
		return this->head->item;
		
	};
	int Rear() {
		/// Return the item at the rear of the Deque (do not remove the item)
		/// If the Deque is empty, throw an exception
		if (this->tail == NULL) {
			throw invalid_argument("The list is empty!");
			return 0;
		}
		return this->tail->item;
	};
	bool IsEmpty() { return noOfItems == 0; }
	int  Size() { return noOfItems; }
};
int main()
{
	Deque dq;
	dq.AddFront(12);
	dq.AddRear(65);
	dq.AddRear(31);
	//dq.RemoveRear();

}

