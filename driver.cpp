#include "stdafx.h"
#include<stdint.h>

bool test_paradox();

uint32_t test_1();
uint32_t test_4();
uint32_t test_42();
uint32_t test_3410();

uint32_t driver()
{
	uint32_t res;
	//res = test_1();
	//res = test_4();
	//res = test_42();
	res = test_3410();
	//res = test_paradox();
	return res;
}