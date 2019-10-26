
enable_testing()

set(GTEST_LIBRARY ${PROJECT_SOURCE_DIR}/lib/googletest/lib/gtestd.lib)
set(GTEST_MAIN_LIBRARY ${PROJECT_SOURCE_DIR}/lib/googletest/lib/gtest_maind.lib)
set(GTEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/googletest/include)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(HogehogeTest test-test/test.cpp)
target_link_libraries(HogehogeTest discord-client GTest::GTest GTest::Main)

gtest_add_tests(TARGET HogehogeTest)



# add_subdirectory(shirao-works)
# add_subdirectory(yshigeno-works)
