/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#include "WriterTests.h"
#include "Ishiko/XML/linkoptions.h"
#include <Ishiko/TestFramework/TestFrameworkCore.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoXML");

    theTestHarness.environment().setTestOutputDirectory("../../TestOutput");
    theTestHarness.environment().setReferenceDataDirectory("../../ReferenceData");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<WriterTests>();
    
    return theTestHarness.run();
}
