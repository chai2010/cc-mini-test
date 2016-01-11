# Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

test.exe: test.cc example.cc example_test.cc
	g++ -I. -O3 test.cc example.cc example_test.cc -o $@

test: test.exe
	test.exe -test.bench

