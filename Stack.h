#ifndef STACK_H
#define STACK_H

const int MAX_CAPACITY = 128;
const int MAX_EXP = 50;
typedef int StackElement;

class Stack
{
private:
	StackElement myTop,
		arr[MAX_CAPACITY] = { 0 };

public:
	Stack();
	bool const empty();
	bool const full();
	StackElement top();
	void pop();
	void push(int value);
	

};

#endif