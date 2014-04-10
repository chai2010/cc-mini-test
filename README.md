# C++ Mini UnitTest and Benchmark Library

This package implements a C++ mini unittest and benchmark library.

## Unittest

Use `TEST` define a unit test:

	#include "test.h"

	// 1, 1, 2, 3, 5, ...
	int Fibonacci(int i) {
		return (i < 2)? 1: Fibonacci(i-1) + Fibonacci(i-2);
	}

	TEST(Fibonacci, Simple) {
		ASSERT_TRUE(Fibonacci(0) == 1);
		ASSERT_TRUE(Fibonacci(1) == 1);
		ASSERT_TRUE(Fibonacci(2) == 2);
		ASSERT_TRUE(Fibonacci(3) == 3);
		ASSERT_TRUE(Fibonacci(4) == 5);
		ASSERT_TRUE(Fibonacci(5) == 8);
	}

	TEST(Fibonacci, All) {
		static const int fib[] = { 1, 1, 2, 3, 5, ... };
		for(int i = 0; i < sizeof(fib)/sizeof(fib[0]); ++i) {
			ASSERT_TRUE_MSG(Fibonacci(i) == fib[i],
				"failed on fib[%d], expected = %d, got = %d",
				i, fib[i], Fibonacci(i)
			);
		}
	}

Run test: `./a.out` (or `./a.out -test=regexp`):

	[test] Fibonacci.Simple ok
	[test] Fibonacci.All ok
	PASS

We can also use `INIT` define some init funcs (this is optional):

	static int fib[10]; // global test data

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

The init funcs run before the tests.

## Benchmark

Use `BENCH` define a bench test:

	BENCH(Fibonacci, 5) {
		for(int i = 0; i < BenchN(); ++i) {
			Fibonacci(5);
		}
	}
	BENCH(Fibonacci, 10) {
		for(int i = 0; i < BenchN(); ++i) {
			Fibonacci(10);
		}
	}
	BENCH(Fibonacci, 15) {
		for(int i = 0; i < BenchN(); ++i) {
			Fibonacci(15);
		}
	}

Run benchmark: `./a.out -test.bench`:

	[bench] Fibonacci.5 20000000 65.5 ns/op
	[bench] Fibonacci.10 2000000 763 ns/op
	[bench] Fibonacci.15 200000 8740 ns/op

The output means that the loop ran 20000000 times at a speed of 65.5 ns per loop.

If a benchmark needs some expensive setup before running, the timer may be reset:

	BENCH(Name, case1) {
		auto big = NewBig();
		BenchResetTimer();

		for(int i = 0; i < BenchN(); ++i) {
			big.Len();
		}
	}

	BENCH(Name, case2) {
		BenchStopTimer();
		auto big = NewBig();
		BenchStartTimer();

		for(int i = 0; i < BenchN(); ++i) {
			big.Len();
		}
		BenchStopTimer();
		delete big;
	}

## Usage

	./a.out -help
	usage: a.out
	  [-list=.*]
	  [-init=.*]
	  [-test=.*]
	  [-test.bench=]
	  [-test.benchtime=1second]
	  [-help]
	  [-h]

## BUGS

Please report bugs to <chaishushan@gmail.com>.

Thanks!
