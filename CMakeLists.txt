project("hello_my_friend_extension")

addOsqueryExtension(
  "${PROJECT_NAME}"
  hello.cpp
)

add_executable(
  "${PROJECT_NAME}_test"
  EXCLUDE_FROM_ALL
  test.cpp
)

target_link_libraries("${PROJECT_NAME}_test" PRIVATE
  thirdparty_googletest
)