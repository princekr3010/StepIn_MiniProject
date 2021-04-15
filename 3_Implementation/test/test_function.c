#include "filter.h"
#include "unity.h"

input_val right1={0.3,10,0,0};      // correct input
input_val wrong1={10,0.1,0,0};      //Av lower limit check
input_val wrong2={0.015,150,0,0};   //freq lower limit and Av upper limit check
input_val wrong3={0.02,100,0,0};    //freq lower limit check
input_val wrong4={300,50,0,0};      //freq upper limit check

input_val right2={0,20,10,50};      //correct input
input_val wrong5={0,20,0.01,100};   //freq lower limit check
input_val wrong6={0,20,10,300};     //freq upper limit check
input_val wrong7={0,1020,30,10};    //Av upper limit check

void setUp(){}
void tearDown(){}

void test_choose(void){
    TEST_ASSERT_EQUAL(Success,check_code('A'));
    TEST_ASSERT_EQUAL(code_error,check_code('a'));

}

void test_FLP(void){
    TEST_ASSERT_EQUAL(Success,FLP(&right1));
    TEST_ASSERT_EQUAL(Limit_error,FLP(&wrong1));
    TEST_ASSERT_EQUAL(Limit_error,FLP(&wrong2));
    TEST_ASSERT_EQUAL(Limit_error,FLP(&wrong3));
    TEST_ASSERT_EQUAL(Limit_error,FLP(&wrong4));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

void test_FHP(void){
    TEST_ASSERT_EQUAL(Success,FHP(&right1));
    TEST_ASSERT_EQUAL(Limit_error,FHP(&wrong1));
    TEST_ASSERT_EQUAL(Limit_error,FHP(&wrong2));
    TEST_ASSERT_EQUAL(Limit_error,FHP(&wrong3));
    TEST_ASSERT_EQUAL(Limit_error,FHP(&wrong4));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

void test_SLP(void){
    TEST_ASSERT_EQUAL(Success,SLP(&right1));
    TEST_ASSERT_EQUAL(Limit_error,SLP(&wrong1));
    TEST_ASSERT_EQUAL(Limit_error,SLP(&wrong2));
    TEST_ASSERT_EQUAL(Limit_error,SLP(&wrong3));
    TEST_ASSERT_EQUAL(Limit_error,SLP(&wrong4));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

void test_SHP(void){
    TEST_ASSERT_EQUAL(Success,SHP(&right1));
    TEST_ASSERT_EQUAL(Limit_error,SHP(&wrong1));
    TEST_ASSERT_EQUAL(Limit_error,SHP(&wrong2));
    TEST_ASSERT_EQUAL(Limit_error,SHP(&wrong3));
    TEST_ASSERT_EQUAL(Limit_error,SHP(&wrong4));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

void test_BPF(void){
    TEST_ASSERT_EQUAL(Success,BPF(&right2));
    TEST_ASSERT_EQUAL(Limit_error,BPF(&wrong5));
    TEST_ASSERT_EQUAL(Limit_error,BPF(&wrong6));
    TEST_ASSERT_EQUAL(Limit_error,BPF(&wrong7));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_choose);
    RUN_TEST(test_FLP);
    RUN_TEST(test_FHP);
    RUN_TEST(test_SLP);
    RUN_TEST(test_SHP);
    RUN_TEST(test_BPF);
    return UNITY_END();
}