
file(GLOB class_test_sources *.cpp)
file(GLOB class_test_headers *.hpp)

add_executable(ClassTest class_test_sources class_test_headers)

target_link_libraries(ClassTest discord-client GTest::GTest GTest::Main)
gtest_add_tests(TARGET ClassTest)
