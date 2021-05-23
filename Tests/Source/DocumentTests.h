/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_DOCUMENTTESTS_H_
#define _ISHIKO_XML_TESTS_DOCUMENTTESTS_H_

#include <Ishiko/TestFramework/TestFrameworkCore.h>

class DocumentTests : public Ishiko::Tests::TestSequence
{
public:
    DocumentTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void CreateTest1(Ishiko::Tests::FileComparisonTest& test);
};

#endif
