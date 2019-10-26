
add_executable(HogehogeTestEx test.cpp)
target_link_libraries(HogehogeTestEx discord-client GTest::GTest GTest::Main)
gtest_add_tests(TARGET HogehogeTestEx)
