// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "example.h"

int Sum(int a, int b) {
	return a+b;
}

// 1, 1, 2, 3, 5, ...
int FibonacciSlow(int i) {
	return (i < 2)? 1: FibonacciSlow(i-1) + FibonacciSlow(i-2);
}

// 1, 1, 2, 3, 5, ...
int FibonacciFast(int i) {
	static int fib[47];
	return (fib[i] != 0)? fib[i]: (
		fib[i] = (i < 2)? 1: FibonacciFast(i-1) + FibonacciFast(i-2)
	);
}

