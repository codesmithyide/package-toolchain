// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianPackageControlFileTests.hpp"
#include "DebianPackageToolchainTests.hpp"
#include "CodeSmithy/PackageToolchains/linkoptions.hpp"
#include <Ishiko/TestFramework.hpp>
#include <exception>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    try
    {
        TestHarness::CommandLineSpecification command_line_spec;
        Configuration configuration = command_line_spec.createDefaultConfiguration();
        configuration.set("context.data", "../../data");
        configuration.set("context.output", "../../output");
        configuration.set("context.reference", "../../reference");
        CommandLineParser::parse(command_line_spec, argc, argv, configuration);

        TestHarness the_test_harness("CodeSmithyPackageToolchains Library Tests", configuration);

        TestSequence& the_tests = the_test_harness.tests();
        the_tests.append<DebianPackageControlFileTests>();
        the_tests.append<DebianPackageToolchainTests>();

        return the_test_harness.run();
    }
    catch (const std::exception& e)
    {
        return TestApplicationReturnCode::exception;
    }
    catch (...)
    {
        return TestApplicationReturnCode::exception;
    }
}
