#include "stdafx.h"
#include "common_includes.h"

using namespace std;

uint32_t test_400()
{
	string line;

	getline(cin, line);
	uint32_t columns = stoi(line, NULL, 10);

	while (columns > 0)
	{
		vector< vector<char> > table;
		getline(cin, line);

		vector<char> row;
		uint32_t pos = 0;
		while(pos < line.size())
		{
			//Left to Right
			if (pos < line.size())
			{
				for (size_t i = 0; i < columns; i++)
				{
					row.push_back(line[pos++]);
				}
				table.push_back(row);
				row.clear();
			}
			
			if (pos < line.size())
			{
				//Right to Left
				for (size_t i = 0; i < columns; i++)
				{
					row.insert(row.begin(), line[pos++]);
				}
				table.push_back(row);
				row.clear();
			}
		}

		uint32_t num_of_cols = table[0].size();
		uint32_t num_of_rows = table.size();
		for (size_t i = 0; i < num_of_cols; i++)
		{
			for (size_t j = 0; j < num_of_rows; j++)
			{
				cout << table[j][i];
			}
		}
		cout << endl;

		getline(cin, line);
		columns = stoi(line, NULL, 10);
	}

	return 0;
}