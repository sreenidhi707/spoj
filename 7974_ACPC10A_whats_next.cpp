#include "stdafx.h"
#include "common_includes.h"

using namespace std;

uint32_t test_7974()
{
	string line;

	getline(cin, line);

	while (line != "0 0 0")
	{
		vector<string> nos;
		split_string(line, nos, ' ');

		int32_t numbers[3];
		for (size_t i = 0; i < 3; i++)
		{
			numbers[i] = stoi(nos[i], NULL, 10);
		}

		if ((numbers[2] - numbers[1]) == (numbers[1] - numbers[0]))
		{
			cout << "AP " << numbers[2] + numbers[2] - numbers[1] << endl;
		}
		else
		{
			float ratio = float(numbers[2]) / float(numbers[1]);
			int32_t next_num = ratio * numbers[2];
			cout << "GP " << next_num << endl;
		}
		getline(cin, line);
	}
	return 0;
}