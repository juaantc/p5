# GTest include code for fetch content over the internet 
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
# End GTest include code

# Testing persons library
add_executable(persons-test persons-test.cc)
target_link_libraries(persons-test PRIVATE GTest::gtest_main persons)
gtest_discover_tests(persons-test)

# Testing catalog library
add_executable(catalog-test catalog-test.cc)
target_include_directories(catalog-test PRIVATE ${CMAKE_SOURCE_DIR}/src/persons)
target_link_libraries(catalog-test PRIVATE GTest::gtest_main catalog persons)
gtest_discover_tests(catalog-test)

# Testing stage library
add_executable(stage-test stage-test.cc)
target_include_directories(stage-test PRIVATE ${CMAKE_SOURCE_DIR}/src/catalog)
target_link_libraries(stage-test PRIVATE GTest::gtest_main stage persons catalog)
gtest_discover_tests(stage-test)

# Testing gclist library
add_executable(gclist-test gclist-test.cc)
target_link_libraries(gclist-test PRIVATE GTest::gtest_main gclist)
gtest_discover_tests(gclist-test)

