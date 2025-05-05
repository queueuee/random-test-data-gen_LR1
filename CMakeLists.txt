cmake_minimum_required(VERSION 3.16)

project(kakieto-test-datas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(random-test-data-gen_LR1 main.cpp)

include(GNUInstallDirs)
install(TARGETS random-test-data-gen_LR1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
