cmake_minimum_required(VERSION 3.20)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Set debug profile, also maximum level of debug info g3 and format of debug info to dwarf-4 (requires gdb in version 7)
set(CMAKE_BUILD_TYPE Debug)
if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
endif()
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4")
endif()

enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

project(Poll_system_init)

set(SOURCE_FILES
        src/main.cpp
        src/Analyzer.cpp
        src/BudgetAnalyzer.cpp
        src/BudgetVote.cpp
        src/GeneralAnalyzer.cpp
        src/SportsAnalyzer.cpp
        src/SportsVote.cpp
        src/Vote.cpp
        src/Voter.cpp
        include/Analyzer.h
        include/BudgetAnalyzer.h
        include/BudgetVote.h
        include/GeneralAnalyzer.h
        include/SportsAnalyzer.h
        include/SportsVote.h
        include/Vote.h
        include/Voter.h
        include/UserInterface.h
        src/UserInterface.cpp
        include/functions.h
        src/functions.cpp)

add_executable(Poll_system_init ${SOURCE_FILES})

add_library(poll ${SOURCE_FILES} )

if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(VOTE_TEST_FILES
        test/master.cpp
        test/VoteTests.cpp)

set(VOTER_TEST_FILES
        test/master.cpp
        test/VoterTests.cpp)

set(ANALYZER_TEST_FILES
        test/master.cpp
        test/AnalyzerTests.cpp)

add_executable(VoteTest ${VOTE_TEST_FILES})

add_executable(VoterTest ${VOTER_TEST_FILES})

add_executable(AnalyzerTest ${ANALYZER_TEST_FILES})

target_link_libraries (VoteTest
        poll
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

target_link_libraries (VoterTest
        poll
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

target_link_libraries (AnalyzerTest
        poll
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_test(VoteTest VoteTest)
add_test(VoterTest VoterTest)
add_test(AnalyzerTest AnalyzerTest)