cmake_minimum_required(VERSION 2.8)
project(interview)

if(${CMAKE_C_COMPILER_ID} STREQUAL "GNU" OR
        ${CMAKE_C_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_C_FLAGS "-Wall -Werror -std=c99 ${CMAKE_C_FLAGS}")
endif()

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR
        ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-Wall -Werror -std=c99 ${CMAKE_CXX_FLAGS}")
endif()

enable_testing()
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB_RECURSE testhelper_src ${PROJECT_SOURCE_DIR}/lib/*)
add_library(testhelper ${testhelper_src})

file(GLOB all_src ${PROJECT_SOURCE_DIR}/src/*)

foreach(src ${all_src})
    get_filename_component(exec_name ${src} NAME_WE)
    add_executable(${exec_name} ${src})

    target_link_libraries(${exec_name} testhelper)

    add_dependencies(check ${exec_name})
    add_test(test-${exec_name} ${PROJECT_BINARY_DIR}/${exec_name})
endforeach()
