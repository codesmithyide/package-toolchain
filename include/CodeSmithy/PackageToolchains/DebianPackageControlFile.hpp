// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_PACKAGETOOLCHAINS_DEBIANPACKAGECONTROLFILE_HPP
#define GUARD_CODESMITHYIDE_PACKAGETOOLCHAINS_DEBIANPACKAGECONTROLFILE_HPP

#include <Ishiko/FileSystem.hpp>
#include <boost/optional.hpp>
#include <string>

namespace CodeSmithy
{
    /// This class implements the Debian package control file. The specification can be found at
    /// https://manpages.debian.org/bookworm/dpkg-dev/deb-control.5.en.html.
    class DebianPackageControlFile
    {
    public:
        DebianPackageControlFile(const std::string& package_name, const std::string& version_string,
            const std::string& architecture);

        void setMaintainer(const std::string& maintainer);
        void setShortDescription(const std::string& short_description);

        void write(Ishiko::TextFile& file);

    private:
        std::string m_package_name;
        std::string m_version_string;
        std::string m_architecture;
        boost::optional<std::string> m_maintainer;
        boost::optional<std::string> m_short_description;
    };
}

#endif
