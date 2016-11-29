#include "stdafx.h"
#include "common_includes.h"

using namespace std;
const uint8_t NUM_OPERATORS = 6;

char precedence[NUM_OPERATORS] = { '(', '-', '+', '/', '*', '^' };

bool is_greater(char op1, char op2)
{
	uint8_t op1_idx = -1;
	for (size_t i = 0; i < NUM_OPERATORS; i++)
	{
		if (op1 == precedence[i])
		{
			op1_idx = i;
			break;
		}
		assert(1);
	}

	uint8_t op2_idx = -1;
	for (size_t i = 0; i < NUM_OPERATORS; i++)
	{
		if (op2 == precedence[i])
		{
			op2_idx = i;
			break;
		}
		assert(1);
	}

	return op1_idx > op2_idx ? true : false;
}

string infix_to_rpn(string s)
{
	stack<char> operators;
	string rpn;

	for (size_t i = 0; i < s.size(); i++)
	{
		//If s[i] is a character then push to output
		if (0 <= s[i] - 'a' && s[i] - 'a' <= 26)
		{
			rpn += s[i];
		}
		else if (s[i] == '(')
		{
			operators.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (operators.top() != '(')
			{
				rpn += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			if (operators.size() == 0 || is_greater(s[i], operators.top()))
			{
				operators.push(s[i]);
			}
			else
			{
				while (!is_greater(s[i], operators.top()) || operators.top() == '(')
				{
					rpn += operators.top();
					operators.pop();

					if (operators.empty())
					{
						break;
					}
				}
				operators.push(s[i]);
			}
		}
	}

	//numbers or operator stack could be non empty
	//Copy all operators
	while (operators.size())
	{
		if (operators.top() != '(')
		{
			rpn += operators.top();
		}		
		operators.pop();
	}

	return rpn;
}

uint32_t test_4()
{
	uint32_t num_tests = 0;
	string line;

	getline(cin, line);
	num_tests = stoi(line, NULL, 10);

	for (size_t i = 0; i < num_tests; i++)
	{
		getline(cin, line);
		string rpn = infix_to_rpn(line);
		cout << rpn << endl;
	}

	return 0;
}