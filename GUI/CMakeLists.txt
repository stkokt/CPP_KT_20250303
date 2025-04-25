cmake_minimum_required(VERSION 3.16)

project(wxwidgets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(wxWidgets_ROOT_DIR c:/WX1)
find_package(wxWidgets COMPONENTS gl core base OPTIONAL_COMPONENTS net)
set(SOURCES main.cpp ${SOURCES})
add_executable(wxwidgets main.cpp)

if (wxWidgets_FOUND)
include(${wxWidgets_USE_FILE})
target_link_libraries(wxwidgets ${wxWidgets_LIBRARIES})
endif()

include(GNUInstallDirs)
install(TARGETS wxwidgets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
