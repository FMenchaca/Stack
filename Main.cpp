#include <iostream> 

#include <fstream>
#include "Stack.h"
using namespace std;


int main()
{
	ifstream fin("postfix.txt");
	//fin.open("postfix.txt");
	
	Stack st;
	char exp[50];
	StackElement n1 = 0, n2 = 0;
	double sum = 0;

	while (fin)
	{
		fin.getline(exp, 50);

		if (fin)
		{
			cout << "Expression is: "<< exp << endl;

			while (st.empty())
			{
				for (int i = 0; i < sizeof(exp); i++) // to se size of char array
				{
					if (exp[i] >= '0' && exp[i] <= '9')
						st.push(exp[i] - '0');
					else
					{
						if (exp[i] == '+')
						{
								n2 = st.top();
								st.pop();
								n1 = st.top();
								st.pop();
								sum = n1 + n2;
								st.push(sum);
						}

						if (exp[i] == '-')
						{
								n2 = st.top();
								st.pop();
								n1 = st.top();
								st.pop();
								sum = n1 - n2;
								st.push(sum);
						}

						if (exp[i] == '*')
						{
							if (!st.empty())
							{
								n2 = st.top();
								st.pop();
								n1 = st.top();
								st.pop();
								sum = n1 * n2;
								st.push(sum);
							}
							else
								cout << "ERROR" << endl;
						}
					

						if (exp[i] == '/')
						{
								n2 = st.top();
								st.pop();
								n1 = st.top();
								st.pop();
								sum = n1 / n2;
								st.push(sum);
						}

					}
				}
			}
			cout << "Answer for " << exp << " is: " << st.top() << endl << endl;
			st.pop();
		}
	}

	system("pause");
	fin.close();
	return(0);
}