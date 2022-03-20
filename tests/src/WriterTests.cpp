/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "WriterTests.h"
#include "Ishiko/XML/Writer.h"
#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Ishiko::XML;

WriterTests::WriterTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Writer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
    append<FileComparisonTest>("writeStartDocument test 1", WriteStartDocumentTest1);
}

void WriterTests::ConstructorTest1(Test& test)
{
    Writer writer;

    ISHIKO_TEST_PASS();
}

void WriterTests::CreateTest1(FileComparisonTest& test)
{
    path outputPath = test.context().getTestOutputPath("WriterTests_CreateTest1.xml");

    Writer writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataPath("WriterTests_CreateTest1.xml"));

    ISHIKO_TEST_PASS();
}

void WriterTests::WriteStartDocumentTest1(FileComparisonTest& test)
{
    path outputPath = test.context().getTestOutputPath("WriterTests_WriteStartDocumentTest1.xml");

    Writer writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeStartDocument();

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataPath("WriterTests_WriteStartDocumentTest1.xml"));

    ISHIKO_TEST_PASS();
}
