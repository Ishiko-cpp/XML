/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#include "DocumentTests.h"
#include "Ishiko/XML/Document.h"

using namespace Ishiko;
using namespace Ishiko::Tests;
using namespace Ishiko::XML;

DocumentTests::DocumentTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Document tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
}

void DocumentTests::ConstructorTest1(Test& test)
{
    Document document;

    ISHTF_PASS();
}

void DocumentTests::CreateTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath("DocumentTests_CreateTest1.xml");

    Document document;

    Error error;
    document.create(outputPath, "DocumentTests_CreateTest1_Root", error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath("DocumentTests_CreateTest1.xml"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}
