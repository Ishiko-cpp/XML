/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_ELEMENTTESTS_H_
#define _ISHIKO_XML_TESTS_ELEMENTTESTS_H_

#include <Ishiko/TestFramework/TestFrameworkCore.h>

class ElementTests : public Ishiko::Tests::TestSequence
{
public:
    ElementTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
};

#endif
