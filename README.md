# C++ Mini UnitTest and Benchmark Library

This package implements a C++ mini unittest and benchmark library.

Unit test example:

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

Benchmark example:

	BENCH(Sum, For500) {
		for(int i = 0; i < BenchN(); ++i) {
			for(int j = 0; j < 500; ++j) {
				Sum(i, i);
			}
		}
	}
	
	BENCH(Sum, For1000) {
		for(int i = 0; i < BenchN(); ++i) {
			for(int j = 0; j < 1000; ++j) {
				Sum(i, i);
			}
		}
	}

run benchmark: `./a.out -test.bench`.

Usage

	./a.out -help
	usage: a.out
	  [-list=*.]
	  [-test=*.]
	  [-test.bench=]
	  [-test.benchtime=1second]
	  [-help]
	  [-h]

Please report bugs to <chaishushan@gmail.com>.

Thanks!
