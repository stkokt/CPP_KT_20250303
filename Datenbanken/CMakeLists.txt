cmake_minimum_required(VERSION 3.16)

project(datenbanken LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SQLITE_INCLUDE_DIR "C:/SQLite")
set(SQLITE_SOURCES
    "C:/SQLite"
)

add_executable(datenbanken main.cpp ${SQLITE_SOURCES})

include(GNUInstallDirs)
install(TARGETS datenbanken
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(datenbanken PRIVATE ${SQLITE_INCLUDE_DIR})
target_link_libraries(datenbanken PRIVATE SQLite)
