/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLPushParserTests.hpp"

using namespace Ishiko;

XMLPushParserTests::XMLPushParserTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "XMLPushParser tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void XMLPushParserTests::ConstructorTest1(Test& test)
{
}
