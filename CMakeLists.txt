cmake_minimum_required(VERSION 3.5)

project(Sculptor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ESTA É A PARTE MAIS IMPORTANTE:
add_executable(Sculptor
    main.cpp
    sculptor.cpp
    sculptor.h
    Voxel.h
)

include(GNUInstallDirs)
install(TARGETS Sculptor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
