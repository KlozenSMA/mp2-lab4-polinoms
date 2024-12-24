set(target ${PLNM_TESTS})

file(GLOB hdrs "*.h")
file(GLOB srcs "test_main.cpp test_list.cpp")

add_executable (${target} "test_main.cpp" "test_list.cpp")

target_link_libraries(${target} gtest)