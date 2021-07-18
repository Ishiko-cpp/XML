/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_WRITERTESTS_H_
#define _ISHIKO_XML_TESTS_WRITERTESTS_H_

#include <Ishiko/Tests/Core.h>

class WriterTests : public Ishiko::Tests::TestSequence
{
public:
    WriterTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void CreateTest1(Ishiko::Tests::FileComparisonTest& test);
    static void WriteStartDocumentTest1(Ishiko::Tests::FileComparisonTest& test);
};

#endif
