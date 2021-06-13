/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#include "ElementTests.h"
#include "Ishiko/XML/Element.h"

using namespace Ishiko;
using namespace Ishiko::Tests;
using namespace Ishiko::XML;

ElementTests::ElementTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Element tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void ElementTests::ConstructorTest1(Test& test)
{
    Element element;

    ISHTF_PASS();
}
