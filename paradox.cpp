#include "stdafx.h"
#include "common_includes.h"

using namespace std;

enum node_value_enum
{
	FALSE = 0,
	TRUE = 1,
	UNASSIGNED = 3
};

struct statement
{
	uint16_t line_num;
	node_value_enum value;
};

vector<string> split(string s)
{
	vector<string> result;
	stringstream stream(s);

	string temp;
	while (stream >> temp)
	{
		result.push_back(temp);
	}
	return result;
}

bool examine_statements(vector<statement>& nodes)
{
	vector<bool> node_visited(nodes.size(), false);
	

	for (size_t node_idx = 0; node_idx < nodes.size(); node_idx++)
	{
		vector<node_value_enum> node_value(nodes.size(), UNASSIGNED);
		node_value_enum incoming_value = TRUE;
		if (node_visited[node_idx] == false)
		{
			size_t group_node_idx = node_idx;
			while (1)
			{
				if (node_visited[group_node_idx] == false)
				{
					statement line_i = nodes[group_node_idx];
					node_visited[group_node_idx] = true;
					node_value[group_node_idx] = incoming_value;

					//Set Values for next node
					if (incoming_value == TRUE)
					{
						incoming_value = line_i.value;
					}
					else
					{
						incoming_value = line_i.value == TRUE ? FALSE : TRUE;
					}
					group_node_idx = line_i.line_num;
				}
				else
				{
					if (node_value[group_node_idx] == UNASSIGNED)
					{
						assert(1);
					}
					else if (node_value[group_node_idx] != incoming_value) //PARADOX
					{
						return true;
					}
					else //NOT PARADOX
					{
						break;
					}
				}
			}
		}
		else
		{
			continue;
		}
	}
	return false; //NOT PARADOX
}

bool test_paradox()
{
	/***********PROCESS FROM TEXT FILE BEGIN***********/
	string line;
	uint32_t num_statements = 0;
	ifstream myfile("paradox_data.txt");
	

	while (myfile.good())
	{
		getline(myfile, line);
		num_statements = stoi(line, NULL, 10);

		vector<statement> statements;
		if (num_statements > 0)
		{
			//Read groups of statements
			for (size_t i = 0; i < num_statements; i++)
			{
				statement l;

				string line;
				getline(myfile, line);
				vector<string> lines = split(line);
				l.line_num = stoi(lines[0], NULL, 10) - 1;
				l.value = (lines[1] == "true") ? TRUE : FALSE;

				statements.push_back(l);
			}

			bool result = examine_statements(statements);

			if (result)
			{
				cout << "PARADOX" << endl;
			}
			else
			{
				cout << "NOT PARADOX" << endl;
			}
		}
		else
		{
			break;
		}
	}
	return 0;
	/***********PROCESS FROM TEXT FILE END***********/

	/***********PROCESS FROM CONSOLE BEGIN***********/
	
	/*uint32_t num_statements = 0;

	while (1)
	{
		string line;
		getline(cin, line);
		num_statements = stoi(line, NULL, 10);
		if (num_statements > 0)
		{
			vector<statement> statements;

			for (size_t i = 0; i < num_statements; i++)
			{
				statement l;


				getline(cin, line);
				vector<string> lines = split(line);
				l.line_num = stoi(lines[0], NULL, 10) - 1;
				l.value = (lines[1] == "true") ? TRUE : FALSE;

				statements.push_back(l);
			}

			bool result = examine_statements(statements);

			if (result)
			{
				cout << "PARADOX" << endl;
			}
			else
			{
				cout << "NOT PARADOX" << endl;
			}
		}
		else
		{
			break;
		}
	}
	return 0;*/
	/***********PROCESS FROM CONSOLE END***********/
}