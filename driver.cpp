#include "stdafx.h"
#include<stdint.h>

bool test_paradox();

uint32_t driver()
{
	uint32_t res = test_paradox();
	return res;
}