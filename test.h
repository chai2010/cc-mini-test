// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef TEST_H_
#define TEST_H_

#define TEST(x, y) \
	static void x##y(void); \
	static TestRegisterer r##x##y(x##y, # x "." # y); \
	static void x##y(void)

#define ASSERT_TRUE(x) TestAssertTrue((x), __FILE__, __LINE__, "")
#define ASSERT_EQ(x, y) TestAssertEQ((x), (y), __FILE__, __LINE__, "")
#define ASSERT_STREQ(x, y)TestAssertStrEQ((x), (y), __FILE__, __LINE__, "")
#define ASSERT_NEAR(x, y, abs_error) TestAssertNear((x), (y), (abs_error), __FILE__, __LINE__, "")

#if !defined(_MSC_VER) || (_MSC_VER >= 1600)
#	define ASSERT_TRUE_MSG(x, fmt, ...) TestAssertTrue((x), __FILE__, __LINE__, (fmt), __VA_ARGS__)
#	define ASSERT_EQ_MSG(x, y, fmt, ...) TestAssertEQ((x), (y), __FILE__, __LINE__, (fmt), __VA_ARGS__)
#	define ASSERT_STREQ_MSG(x, y, fmt, ...)TestAssertStrEQ((x), (y), __FILE__, __LINE__, (fmt), __VA_ARGS__)
#	define ASSERT_NEAR_MSG(x, y, abs_error, fmt, ...) TestAssertNear((x), (y), (abs_error), __FILE__, __LINE__, (fmt), __VA_ARGS__)
#endif

void RegisterTest(void (*fn)(void), const char *tname);
void TestAssertTrue(bool condition, const char* fname, int lineno, const char* fmt, ...);
void TestAssertEQ(int a, int b, const char* fname, int lineno, const char* fmt, ...);
void TestAssertStrEQ(const char* a, const char* b, const char* fname, int lineno, const char* fmt, ...);
void TestAssertNear(float a, float b, float abs_error, const char* fname, int lineno, const char* fmt, ...);

struct TestRegisterer {
	TestRegisterer(void (*fn)(void), const char *s) {
		RegisterTest(fn, s);
	}
};

#endif  // TEST_H_
