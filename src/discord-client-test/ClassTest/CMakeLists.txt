
file(GLOB class_test_sources src/*.cpp)
file(GLOB class_test_headers src/*.hpp)

add_executable(ClassTest ${class_test_sources} ${class_test_headers})

target_link_libraries(ClassTest discord-client GTest::GTest GTest::Main)
gtest_add_tests(TARGET ClassTest)

assign_source_group(${class_test_sources})
assign_source_group(${class_test_headers})