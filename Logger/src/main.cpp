#include <MyLogger/Logger.hpp>
#include <MyLogger/File.hpp>
#include "project_info.hpp"

int main()
{
    CONFIG_LOG(mylogger::project::Info(
        project::info::mode == project::info::debug,
        project::info::application_name.c_str(),
        project::info::major_version,
        project::info::minor_version,
        project::info::git_branch.c_str(),
        project::info::git_sha1.c_str(),
        project::info::data_path.c_str(),
        project::info::tmp_path.c_str(),
        project::info::log_name.c_str(),
        project::info::log_path.c_str()
    ));

    LOGI("An information %s", "the info");
    LOGD("A debug %s", "the debug");
    LOGW("A warning %s", "the warning");
    LOGF("A failure %s", "the failure");

    LOGD("Base Name of %s is %s",
         "/home/foo/tests/common/FileTests.cpp",
         File::baseName("/home/foo/tests/common/FileTests.cpp"));

    return 0;
}
