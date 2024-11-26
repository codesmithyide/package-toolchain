// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianPackageControlFileTests.hpp"
#include "CodeSmithy/PackageToolchains/DebianPackageControlFile.hpp"
#include <Ishiko/FileSystem.hpp>

using namespace CodeSmithy;

DebianPackageControlFileTests::DebianPackageControlFileTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "DebianPackageControlFile tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("write test 1", WriteTest1);
}

void DebianPackageControlFileTests::ConstructorTest1(Ishiko::Test& test)
{
    DebianPackageControlFile control_file("DebianPackageControlFileTests_ConstructorTest1", "0.0.1", "amd64");

    ISHIKO_TEST_PASS();
}

void DebianPackageControlFileTests::WriteTest1(Ishiko::Test& test)
{
    const char* output_name = "DebianPackageControlFileTests_WriteTest1";
    boost::filesystem::path output_path = test.context().getOutputPath(output_name);

    DebianPackageControlFile control_file(output_name, "0.0.1", "amd64");

    Ishiko::Error error;
    Ishiko::TextFile output_file;
    // TODO: create and use throwing variant of TextFile::Create
    output_file.create(output_path, error);

    control_file.write(output_file);

    output_file.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}
