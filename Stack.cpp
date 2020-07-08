#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack()
{
	myTop = -1;

}

bool const Stack::empty()
{
	return myTop == -1;
}

bool const Stack::full()
{
	return myTop == MAX_CAPACITY - 1;
}

StackElement Stack::top()
{
	if (!empty())
	{
		return arr[myTop];
	}
	else
		cout << "Stack is empty" << endl;
}

void Stack::pop()
{
	if (!empty())
	{
		myTop--;
	}
	else
		cout << "Stack is empty" << endl;
}

void Stack::push(int value)
{
	if (!full())
	{
		++myTop;
		arr[myTop] = value;
	}
	else
		cout << "Stack is full" << endl;
}