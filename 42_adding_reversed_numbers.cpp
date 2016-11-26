#include "stdafx.h"
#include "common_includes.h"

using namespace std;

uint32_t test_42()
{
	uint32_t num_tests = 0;
	string line;

	getline(cin, line);
	num_tests = stoi(line, NULL, 10);
	
	vector<string> numbers;
	for (size_t i = 0; i < num_tests; i++)
	{
		getline(cin, line);
		split_string(line, numbers, ' ');

		uint32_t num1 = stoi(numbers[0], NULL, 10);
		uint32_t rev_num1 = reverse_integer(num1);
		
		uint32_t num2 = stoi(numbers[1], NULL, 10);
		uint32_t rev_num2 = reverse_integer(num2);

		uint32_t result = reverse_integer(rev_num1 + rev_num2);
		cout << result << endl;

		numbers.clear();
	}
	return 0;
}