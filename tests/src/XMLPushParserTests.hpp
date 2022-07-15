/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_XMLPUSHPARSERTESTS_HPP_
#define _ISHIKO_XML_TESTS_XMLPUSHPARSERTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class XMLPushParserTests : public Ishiko::TestSequence
{
public:
    XMLPushParserTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void OnDataTest1(Ishiko::Test& test);
};

#endif
