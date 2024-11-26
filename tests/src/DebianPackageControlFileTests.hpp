// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_PACKAGETOOLCHAINS_DEBIANPACKAGECONTROLFILETESTS_HPP
#define GUARD_CODESMITHYIDE_PACKAGETOOLCHAINS_DEBIANPACKAGECONTROLFILETESTS_HPP

#include <Ishiko/TestFramework.hpp>

class DebianPackageControlFileTests : public Ishiko::TestSequence
{
public:
    DebianPackageControlFileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void WriteTest1(Ishiko::Test& test);
    static void WriteTest2(Ishiko::Test& test);
};

#endif
