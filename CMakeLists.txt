cmake_minimum_required(VERSION 3.16)

project(kakieto-test-datas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kakieto-test-datas main.cpp)

include(GNUInstallDirs)
install(TARGETS kakieto-test-datas
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
