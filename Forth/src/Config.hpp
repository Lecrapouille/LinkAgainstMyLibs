#ifndef CONFIG_HPP_
#  define CONFIG_HPP_

#  include "version.h"

#  define PROJECT_DATA_PATH "."
#  define PROJECT_TEMP_DIR "/tmp/"

namespace config
{
  //! \brief
  const Mode mode = config::Debug;
  //! \brief Used for logs and GUI.
  const std::string project_name("SimForthTest");
  //! \brief Major version of project
  const uint32_t major_version(PROJECT_MAJOR_VERSION);
  //! \brief Minor version of project
  const uint32_t minor_version(PROJECT_MINOR_VERSION);
  //! \brief Save the git SHA1
  const std::string git_sha1(PROJECT_SHA1);
  //! \brief Save the git branch
  const std::string git_branch(PROJECT_BRANCH);
  //! \brief Pathes where default project resources have been installed
  //! (when called  by the shell command: sudo make install).
  const std::string data_path(PROJECT_DATA_PATH);
  //! \brief Location for storing temporary files
  const std::string tmp_path(PROJECT_TEMP_DIR);
  //! \brief Give a name to the default project log file.
  const std::string log_name(project_name + ".log");
  //! \brief Define the full path for the project.
  const std::string log_path(tmp_path + log_name);
}

#endif /* CONFIG_HPP_ */
