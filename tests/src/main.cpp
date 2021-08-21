/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "WriterTests.h"
#include "Ishiko/XML/linkoptions.h"
#include <Ishiko/Tests/Core.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoXML");

    theTestHarness.environment().setTestOutputDirectory("../../output");
    theTestHarness.environment().setReferenceDataDirectory("../../reference");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<WriterTests>();
    
    return theTestHarness.run();
}
