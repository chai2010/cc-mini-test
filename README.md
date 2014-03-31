# C++ Mini UnitTest

This package implements a C++ mini unittest library.

This is a example:

	#include "test.h"
	
	int Sum(int a, int b) {
		return a+b;
	}
	
	TEST(Sum, Simple) {
		ASSERT_TRUE(Sum(1,2) == 3);
	}
	
	TEST(Sum, For) {
		for(int i = 0; i < 10; ++i) {
			ASSERT_TRUE_MSG(Sum(i,i) == i*2, "i = %d", i);
		}
	}

Please report bugs to <chaishushan@gmail.com>.

Thanks!
