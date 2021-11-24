#include "unity.h"
#include <ev_operations.h>

/* Modify these two lines according to the project */
#include <ev_operations.h>
#define PROJECT_NAME    "EVConsole"

/* Prototypes for all the test functions */
// void test_add(void);
// void test_subtract(void);
// void test_multiply(void);
// void test_divide(void);
float Fspeed(int WRPM, char Gear);
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_Fspeed);
//   RUN_TEST(test_subtract);
//   RUN_TEST(test_multiply);
//   RUN_TEST(test_divide);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 


void test_Fspeed(int A, char B) {
  TEST_ASSERT_EQUAL(10.53 , Fspeed(200, 'F'));
  
  /* Dummy fail*/
  //TEST_ASSERT_EQUAL(10.53 , Fspeed(300, 'F'));
}


void test_Rspeed(void) {
  TEST_ASSERT_EQUAL(10.53 , Rspeed(200, 'R'));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(10.53 , Rspeed(300, 'R'));
}



// void test_subtract(void) {
//   TEST_ASSERT_EQUAL(-3, subtract(0, 3));
  
//   /* Dummy fail*/
//   TEST_ASSERT_EQUAL(100, subtract(1000, 900));
// }

// void test_multiply(void) {
//   TEST_ASSERT_EQUAL(0, multiply(1, 0));
  
//   /* Dummy fail*/
//   TEST_ASSERT_EQUAL(10, multiply(2, 5));
// }

// void test_divide(void) {
//   TEST_ASSERT_EQUAL(0, divide(1, 0));
  
//   /* Dummy fail*/
//   TEST_ASSERT_EQUAL(1, divide(2, 2));
// }
