// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "test.h"
#include "example.h"

TEST(Sum, Simple) {
	ASSERT_TRUE(Sum(1,2) == 3);
}

TEST(Sum, For) {
	for(int i = 0; i < 10; ++i) {
		ASSERT_TRUE_MSG(Sum(i,i) == i*2, "i = %d", i);
	}
}

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

BENCH(Sum, For2000) {
	for(int i = 0; i < BenchN(); ++i) {
		for(int j = 0; j < 2000; ++j) {
			Sum(i, i);
		}
	}
}

static int fib[10];

INIT(Fibonacci, init) {
	fib[0] = fib[1] = 1;
	for(int i = 2; i < sizeof(fib)/sizeof(fib[0]); ++i) {
		fib[i] = fib[i-1] + fib[i-2];
	}
}
INIT(Fibonacci, initx) {
	// ...
}
TEST(Fibonacci, TestInit) {
	for(int i = 0; i < sizeof(fib)/sizeof(fib[0]); ++i) {
		ASSERT_TRUE_MSG(FibonacciFast(i) == fib[i], "i = %d", i);
	}
}

TEST(Fibonacci, Slow) {
	ASSERT_TRUE(FibonacciSlow(0) == 1);
	ASSERT_TRUE(FibonacciSlow(1) == 1);
	ASSERT_TRUE(FibonacciSlow(2) == 2);
	ASSERT_TRUE(FibonacciSlow(3) == 3);
	ASSERT_TRUE(FibonacciSlow(4) == 5);
	ASSERT_TRUE(FibonacciSlow(5) == 8);
}
TEST(Fibonacci, Fast) {
	ASSERT_TRUE(FibonacciFast(0) == 1);
	ASSERT_TRUE(FibonacciFast(1) == 1);
	ASSERT_TRUE(FibonacciFast(2) == 2);
	ASSERT_TRUE(FibonacciFast(3) == 3);
	ASSERT_TRUE(FibonacciFast(4) == 5);
	ASSERT_TRUE(FibonacciFast(5) == 8);
}

BENCH(Fibonacci, Slow5) {
	for(int i = 0; i < BenchN(); ++i) {
		FibonacciSlow(5);
	}
}
BENCH(Fibonacci, Slow10) {
	for(int i = 0; i < BenchN(); ++i) {
		FibonacciSlow(10);
	}
}
BENCH(Fibonacci, Slow15) {
	for(int i = 0; i < BenchN(); ++i) {
		FibonacciSlow(15);
	}
}

BENCH(Fibonacci, Fast5) {
	for(int i = 0; i < BenchN(); ++i) {
		FibonacciFast(5);
	}
}
BENCH(Fibonacci, Fast10) {
	for(int i = 0; i < BenchN(); ++i) {
		FibonacciFast(10);
	}
}
BENCH(Fibonacci, Fast15) {
	for(int i = 0; i < BenchN(); ++i) {
		FibonacciFast(15);
	}
}

