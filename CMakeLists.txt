cmake_minimum_required(VERSION 3.27)
project(oop_a10_Jevan2004)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)#modificat ultima data delete if it not works when running

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "D:/QT/6.7.0/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        Charts
        REQUIRED)


QT6_WRAP_UI(UI_HEADERS ${UI_FILES})

add_executable(oop_a10_Jevan2004
        main.cpp
        AdoptionListCsvRepo.cpp
        AdoptionListHtmlRepo.cpp
        AdoptionListMemoryRepo.cpp
        AdoptionListService.cpp
        AdoptionListTextFileRepo.cpp
        CsvFileRepo.cpp
        gui1.cpp
        gui_user.cpp
        HtmlRepo.cpp
        load.cpp
        main_modes.cpp
        MemoryRepo.cpp
        pets_domain.cpp
        RepositoryException.cpp
        RepositoryManager.cpp
        repotype.cpp
        service.cpp
        tests.cpp
        TextFileRepo.cpp
        Action.h
        Action.cpp
        ModelView.h)

set_target_properties(oop_a10_Jevan2004 PROPERTIES
        WIN32_EXECUTABLE TRUE)

target_link_libraries(oop_a10_Jevan2004
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::Charts
        Qt6::Network

)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
