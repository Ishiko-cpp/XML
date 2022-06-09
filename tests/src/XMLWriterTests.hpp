/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_XMLWRITERTESTS_HPP_
#define _ISHIKO_XML_TESTS_XMLWRITERTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class XMLWriterTests : public Ishiko::TestSequence
{
public:
    XMLWriterTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CreateTest1(Ishiko::FileComparisonTest& test);
    static void WriteXMLDeclarationTest1(Ishiko::FileComparisonTest& test);
    static void WriteElementStartTest1(Ishiko::Test& test);
};

#endif
