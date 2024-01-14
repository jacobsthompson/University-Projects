#pragma once

#include <iostream>

struct Stack {
	struct Link {
		void* data;
		Link* next;
		
		void initialize(void* dat, Link* nxt) {
			data = dat;
			next = nxt;
		}
	}* head;
	
	void initialize() {
		head = 0;
	}

	//added member variable
	void (*deletecb)(void* pt);
	
	void push(void* dat) {
		Link* newLink = new Link;
		newLink->initialize(dat, head);
		head = newLink;
	}
	
	void* peek() {
		if (head == 0) {
			std::cout << "Stack is empty";
		}
		return head->data;
	}
	
	void* pop() {
		if(head == 0)
			return 0;
		
		void* result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}

	//function to set pointer deletecb
	void setDeleteCallback(void(*delcb) (void* pt)){
		//set the member variable we made at the top to the pointer we want to delete
		deletecb = delcb;
	}
	
	void cleanup() {
		if (head == 0){
			std::cout << "Stack is empty" << std::endl;
		}
		else {
			std::cout << "Stack is not empty" << std::endl;
			//loop until head is gone
			while (head != 0) {
				//pop the pointer deletecb points to
				deletecb(pop());
			}
		}
	}
};

