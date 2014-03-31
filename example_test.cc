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
