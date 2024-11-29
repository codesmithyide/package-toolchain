// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_PACKAGETOOLCHAINS_TESTS_DEBIANPACKAGETOOLCHAINTESTS_HPP
#define GUARD_CODESMITHYIDE_PACKAGETOOLCHAINS_TESTS_DEBIANPACKAGETOOLCHAINTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class DebianPackageToolchainTests : public Ishiko::TestSequence
{
public:
    DebianPackageToolchainTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void BuildTest1(Ishiko::Test& test);
};

#endif
