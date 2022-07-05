/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLEscapedStringTests.hpp"
#include "Ishiko/XML/XMLEscapedString.hpp"

using namespace Ishiko;

XMLEscapedStringTests::XMLEscapedStringTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "XMLEscapedString tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void XMLEscapedStringTests::ConstructorTest1(Test& test)
{
    XMLEscapedString escapedString;

    ISHIKO_TEST_FAIL_IF_NEQ(escapedString.size(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(escapedString.asEscapedString(), "");
    ISHIKO_TEST_FAIL_IF_NEQ(escapedString.toUnescapedString(), "");
    ISHIKO_TEST_PASS();
}
