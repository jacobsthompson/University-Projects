#pragma once

#include <iostream>

struct Stack {
	struct Link {
		//changed to double data
		double data;
		Link* next;
		
		//changed to double dat
		void initialize(double dat, Link* nxt) {
			data = dat;
			next = nxt;
		}
	}* head;

	//empty constructor, just initialize head
	Stack(){
		initialize();
	}

	//constructor that takes in n, and pushes n values in stack
	Stack(int n){
		//initialize head
		initialize();
		//set value to be pushed equal to 1
		double base = 1;
		//loop n times
		for(int i = 0; i < n; i++){
			//push number into stack
			push(base);
			//increase number by 0.1
			base += 0.1;
		}
		//runs cleanup code so stack is outputted into terminal for testing purposes
		//IF TESTING ENVIRONMENT IS DIFFERENT AND THE CPP INCLUDES CLEANUP, REMOVE THIS CLEANUP
		cleanup();
	}
	
	void initialize() {
		head = 0;
	}
	
	//changed to (double dat)
	void push(double dat) {
		Link* newLink = new Link;
		newLink->initialize(dat, head);
		head = newLink;
	}
	
	//changed to double peek()
	double peek() {
		if (head == 0) {
			std::cout << "Stack is empty";
		}
		return head->data;
	}
	
	//changed to double pop()
	double pop() {
		if(head == 0)
			return 0;
		
		double result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}
	
	void cleanup() {
		if (head == 0){
			std::cout << "Stack is empty";
		}
		else {
			//if stack is not empty, loop til it is
			while(head != 0){
				//print the top of the stack
				std::cout << peek() << " ";
				//pop from stack
				pop();
			}
		}
	}
};
