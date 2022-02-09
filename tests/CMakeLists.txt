set(BINARY ${CMAKE_PROJECT_NAME}_test)
set(TEST_SOURCES main.cpp ../src/core/glfw_wrapper.cpp ../include/rendervault/core/glfw_wrapper.hpp)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${BINARY} ${TEST_SOURCES})

target_link_libraries(${BINARY} ${LINK_LIBS})
target_link_libraries(${BINARY} PUBLIC
        rendervault::rendervault
        rendervault::rendervault-utils
        glfw
        ${X11_LIBRARIES}
        gtest
        gtest_main
        )

add_test(NAME ${BINARY} COMMAND ${BINARY})
gtest_add_tests(${BINARY} "" AUTO)
