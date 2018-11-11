cmake_minimum_required(VERSION 3.2)

project(rapidjson-download NONE)

include(ExternalProject)
ExternalProject_Add(rapidjson
        DOWNLOAD_COMMAND git clone --depth 1 https://github.com/Tencent/rapidjson.git .
        DOWNLOAD_DIR "CMAKEBINARYDIR/{DEPENDENCY_DIR}/rapidjson/src"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        GIT_SUBMODULES "")