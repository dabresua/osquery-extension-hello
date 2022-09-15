#include <gtest/gtest.h>

GTEST_API_ int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(dummy_tests, print_os) {
  #ifdef _WIN32
  #ifdef _WIN64
  printf("Windows 64 bits\n");
  #else /* _WIN64 */
  printf("Windows 32 bits\n");
  #endif /*_WIN64 */
  #endif /* _WIN32 */

  #ifdef __unix__
  #ifdef __linux__
  printf("The OS is a linux\n");
  #else /* __linux__ */
  printf("The OS is a unix different from linux\n");
  #endif /* __linux__ */
  #endif /* __unix__ */

  #ifdef __APPLE__
  printf("The OS is an apple\n");
  #endif /* __APPLE__ */  
}