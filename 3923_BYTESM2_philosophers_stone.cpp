#include "stdafx.h"
#include "common_includes.h"

using namespace std;

uint32_t test_3923()
{
	uint32_t num_tests;
	cin >> num_tests;

	for (size_t test_idx = 0; test_idx < num_tests; test_idx++)
	{
		vector< vector<uint32_t> > input_grid;
		vector< vector<uint32_t> > output_grid;
		uint32_t rows;
		uint32_t cols;

		cin >> rows;
		cin >> cols;

		//Read numbers
		for (size_t j = 0; j < rows; j++)
		{
			uint32_t num;
			vector<uint32_t> row;

			for (size_t k = 0; k < cols; k++)
			{
				cin >> num;
				row.push_back(num);
			}
			input_grid.push_back(row);
		}

		//Special Case: Handle only one column separately
		if (cols == 1)
		{
			uint32_t maximum = 0;
			//Sum all numbers and return 
			for (size_t row_idx = 0; row_idx < rows; row_idx++)
			{
				maximum += input_grid[row_idx][0];
			}
			cout << maximum << endl;
			continue;
		}

		//Create output grid
		for (size_t j = 0; j < rows; j++)
		{
			vector<uint32_t> temp(cols, 0);
			output_grid.push_back(temp);
		}

		//Copy last row
		for (size_t j = 0; j < cols; j++)
		{
			output_grid[rows - 1][j] = input_grid[rows - 1][j];
		}

		uint32_t rev_row_idx = rows - 2;
		for (size_t row_idx = 0; row_idx < rows - 1; row_idx++)
		{
			for (size_t col_idx = 0; col_idx < cols; col_idx++)
			{
				if (col_idx == 0) //Left most number
				{
					output_grid[rev_row_idx][col_idx] = max(output_grid[rev_row_idx + 1][col_idx], output_grid[rev_row_idx + 1][col_idx + 1]) + input_grid[rev_row_idx][col_idx];
				}
				else if (col_idx == cols - 1) //Right most number
				{
					output_grid[rev_row_idx][col_idx] = max(output_grid[rev_row_idx + 1][col_idx - 1], output_grid[rev_row_idx + 1][col_idx]) + input_grid[rev_row_idx][col_idx];
				}
				else //Middle number
				{
					output_grid[rev_row_idx][col_idx] = max(output_grid[rev_row_idx + 1][col_idx - 1],
														max(output_grid[rev_row_idx + 1][col_idx],
															output_grid[rev_row_idx + 1][col_idx + 1])) + input_grid[rev_row_idx][col_idx];
				}
			}
			rev_row_idx--;
		}

		//Find Max
		uint32_t maximum = 0;
		for (size_t col_idx = 0; col_idx < cols; col_idx++)
		{
			if (output_grid[0][col_idx] > maximum)
			{
				maximum = output_grid[0][col_idx];
			}
		}
		cout << maximum << endl;
	}
	return 0;
}