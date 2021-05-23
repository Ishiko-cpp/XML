/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#include "DocumentTests.h"
#include "Ishiko/XML/Document.h"

using namespace Ishiko::Tests;
using namespace Ishiko::XML;

DocumentTests::DocumentTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Document tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DocumentTests::ConstructorTest1(Test& test)
{
    Document document;

    ISHTF_PASS();
}
