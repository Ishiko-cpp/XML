/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_XMLDOCUMENTTESTS_H_
#define _ISHIKO_XML_TESTS_XMLDOCUMENTTESTS_H_

#include <Ishiko/TestFramework/TestFrameworkCore.h>

class XMLDocumentTests : public Ishiko::Tests::TestSequence
{
public:
    XMLDocumentTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);
};

#endif