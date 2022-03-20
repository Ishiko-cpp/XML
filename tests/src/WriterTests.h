/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_WRITERTESTS_H_
#define _ISHIKO_XML_TESTS_WRITERTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class WriterTests : public Ishiko::TestSequence
{
public:
    WriterTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CreateTest1(Ishiko::FileComparisonTest& test);
    static void WriteStartDocumentTest1(Ishiko::FileComparisonTest& test);
};

#endif
