// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianPackageControlFile.hpp"

using namespace CodeSmithy;

DebianPackageControlFile::DebianPackageControlFile(const std::string& package_name, const std::string& version_string,
    const std::string& architecture)
    : m_package_name(package_name), m_version_string(version_string), m_architecture(architecture)
{
}

void DebianPackageControlFile::setMaintainer(const std::string& maintainer)
{
    m_maintainer = maintainer;
}

void DebianPackageControlFile::setShortDescription(const std::string& short_description)
{
    m_short_description = short_description;
}

void DebianPackageControlFile::write(Ishiko::TextFile& file)
{
    file.write("Package: " + m_package_name + "\n");
    file.write("Version: " + m_version_string + "\n");
    if (m_maintainer)
    {
        file.write("Maintainer: " + *m_maintainer + "\n");
    }
    file.write("Architecture: " + m_architecture + "\n");
    if (m_short_description)
    {
        file.write("Description: " + *m_short_description + "\n");
    }
}
