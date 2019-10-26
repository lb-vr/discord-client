
enable_testing()

set(GTEST_LIBRARY ${PROJECT_SOURCE_DIR}/lib/googletest/lib/gtest.lib)
set(GTEST_MAIN_LIBRARY ${PROJECT_SOURCE_DIR}/lib/googletest/lib/gtest_main.lib)
set(GTEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/googletest/include)

find_package(GTest REQUIRED)
include(GoogleTest)

add_subdirectory(HogehogeTest)

# add_subdirectory(shirao-works)
# add_subdirectory(yshigeno-works)
