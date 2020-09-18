#include "unity.h"
#include "biosensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
int t[100],n,i;

void test_prime(void)
{
  TEST_ASSERT_EQUAL(1, biosensor (t[0],t[1],t[2],t[3],t[4]));
 // TEST_ASSERT_EQUAL(1, biosensor (t[1]));
}
/*void test_zero_one(void)
{
  TEST_ASSERT_EQUAL(0, biosensor(t[0]));
}
void test_negative(void)
{
  TEST_ASSERT_EQUAL(0, biosensor(-5));
  TEST_ASSERT_EQUAL(0, biosensor(-10));
}
*/
int test_main(void)
{
void getBioData()
{
    int b=1;
    char *token;
    char help[256];
    FILE *myFile;
    myFile=fopen("re.txt","r");
    fscanf(myFile, "%s",help);
    token=strtok(help,",");
    i=0;
    while(token !=NULL)
    {
        t[i]=atoi(token);
        token=strtok(NULL,",");
        i++;
    }
    n=i;
}
/*void p(){
 for (i = 0; i < n; i++){
        printf("%d",t[i]);
 }
}*/
getBioData();
//p();

/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_prime);
 // RUN_TEST(test_zero_one);
 // RUN_TEST(test_negative);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
