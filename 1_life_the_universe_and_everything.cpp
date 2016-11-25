#include "stdafx.h"
#include "common_includes.h"

using namespace std;

uint32_t test_1()
{
	uint32_t num = 0;

	cin >> num;
	while (num != 42)
	{
		cout << num << endl;
		cin >> num;
	}
	return 0;

}