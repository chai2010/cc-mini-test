// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "test.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static struct { void (*fn)(void); const char* name; } tests[10000];
static int ntests = 0;

static const char* basename(const char* fname) {
	int len = strlen(fname);
	const char* s = fname + len;
	while(s > fname) {
		if(s[-1] == '/' || s[-1] == '\\') return s;
		s--;
	}
	return s;
}

void RegisterTest(void (*fn)(void), const char* tname) {
	if(ntests >= sizeof(tests)/sizeof(tests[0])) {
		printf("%s %s, line %d: RegisterTest failed\n", tname, basename(__FILE__), __LINE__);
		exit(-1);
	}
	tests[ntests].fn = fn;
	tests[ntests++].name = tname;
}

void TestAssertTrue(bool condition, const char* fname, int lineno, const char* fmt, ...) {
	if(!condition) {
		fname = basename(fname);
		if(fmt != NULL && fmt[0] != '\0') {
			va_list ap;
			va_start(ap, fmt);
			printf("fail, %s, line %d: ASSERT_TRUE(false), ", fname, lineno);
			vprintf(fmt, ap);
			printf("\n");
			va_end(ap);
		} else {
			printf("fail, %s, line %d: ASSERT_TRUE(false)\n", fname, lineno);
		}
		exit(-1);
	}
}
void TestAssertEQ(int a, int b, const char* fname, int lineno, const char* fmt, ...) {
	if(a != b) {
		fname = basename(fname);
		if(fmt != NULL && fmt[0] != '\0') {
			va_list ap;
			va_start(ap, fmt);
			printf("fail, %s, line %d: ASSERT_EQ(%d, %d), ", fname, lineno, a, b);
			vprintf(fmt, ap);
			printf("\n");
			va_end(ap);
		} else {
			printf("fail, %s, line %d: ASSERT_EQ(%d, %d)\n", fname, lineno, a, b);
		}
		exit(-1);
	}
}
void TestAssertStrEQ(const char* a, const char* b, const char* fname, int lineno, const char* fmt, ...) {
	if(strcmp(a, b) != 0) {
		fname = basename(fname);
		if(fmt != NULL && fmt[0] != '\0') {
			va_list ap;
			va_start(ap, fmt);
			printf("fail, %s, line %d: ASSERT_STREQ(\"%s\", \"%s\"), ", fname, lineno, a, b);
			vprintf(fmt, ap);
			printf("\n");
			va_end(ap);
		} else {
			printf("fail, %s, line %d: ASSERT_STREQ(\"%s\", \"%s\")\n", fname, lineno, a, b);
		}
		exit(-1);
	}
}
void TestAssertNear(float a, float b, float abs_error, const char* fname, int lineno, const char* fmt, ...) {
	if(abs(a-b) > abs(abs_error)) {
		fname = basename(fname);
		if(fmt != NULL && fmt[0] != '\0') {
			va_list ap;
			va_start(ap, fmt);
			printf("fail, %s, line %d: ASSERT_NEAR(%f, %f, %f), ", fname, lineno, a, b, abs_error);
			vprintf(fmt, ap);
			printf("\n");
			va_end(ap);
		} else {
			printf("fail, %s, line %d: ASSERT_NEAR(%f, %f, %f)\n", fname, lineno, a, b, abs_error);
		}
		exit(-1);
	}
}

int main(int argc, char* argv[]) {
	for(int id = 0; id < ntests; ++id) {
		printf("%s ", tests[id].name);
		tests[id].fn();
		printf("ok\n");
	}
	printf("PASS\n");
	return 0;
}
