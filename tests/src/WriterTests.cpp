/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "WriterTests.h"
#include "Ishiko/XML/Writer.h"

using namespace Ishiko;
using namespace Ishiko::Tests;
using namespace Ishiko::XML;

WriterTests::WriterTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Writer tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
    append<FileComparisonTest>("writeStartDocument test 1", WriteStartDocumentTest1);
}

void WriterTests::ConstructorTest1(Test& test)
{
    Writer writer;

    ISHIKO_PASS();
}

void WriterTests::CreateTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath("WriterTests_CreateTest1.xml");

    Writer writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_FAIL_IF(error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath("WriterTests_CreateTest1.xml"));

    ISHIKO_PASS();
}

void WriterTests::WriteStartDocumentTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath("WriterTests_WriteStartDocumentTest1.xml");

    Writer writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_FAIL_IF(error);

    writer.writeStartDocument();

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath("WriterTests_WriteStartDocumentTest1.xml"));

    ISHIKO_PASS();
}
