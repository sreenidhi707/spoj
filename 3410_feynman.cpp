#include "stdafx.h"
#include "common_includes.h"

using namespace std;

uint32_t test_3410()
{
	uint32_t num_sides = 0;

	scanf("%d", &num_sides);

	while(num_sides > 0)
	{
		cout << sum_of_n_squared(num_sides) << endl;
		scanf("%d", &num_sides);
	}
	return 0;
}