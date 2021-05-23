#include<stdlib.h>
#include <string.h>
#include "../unity/unity.h"
#include "../unity/unity_internals.h"
#include "../inc/program.h"



    void setUp()
    {
        /*requirement of unitytest framework*/
    }


    void tearDown()
    {
        /*requirement of unitytest framework*/
    }

/**
 * @brief to check the reading operation of file and the error meessages for wrong input
 */


qna_t *question_array = NULL;
error_t STATUS;


void reading_file_test_NULLPTR(void)
{
    question_array = NULL;
    STATUS = read_file(question_array,"questionbank/general_knowledge.csv");
    TEST_ASSERT_EQUAL(NULL_PTR,STATUS);

}

void reading_file_success_test(void)
{
    question_array = create_array_of_questions(5);
    STATUS = read_file(question_array,"questionbank/general_knowledge.csv");
    TEST_ASSERT_EQUAL(SUCCESS,STATUS);
    free(question_array);
}

void no_file_read_test(void)
{
    question_array = create_array_of_questions(5);
    STATUS = read_file(question_array,"adfg.csv");
    TEST_ASSERT_EQUAL(NO_FILE,STATUS);
    free(question_array);
}

 /**
 * @brief to test whether the quiz scoring works perfectly or not.
 * also whether all parameters are set.
 */
 void quiz_play_test(void)
{
    int no_of_questions = 5;
    question_array = NULL;
    error_t STATUS = play(question_array,"team aaa119",no_of_questions );
    TEST_ASSERT_EQUAL(NULL_PTR,STATUS);
    

}


int main(void)
{
    
    /*starting the unity test framework*/
    UNITY_BEGIN();
    
    RUN_TEST(no_file_read_test);
    RUN_TEST(reading_file_test_NULLPTR);
    RUN_TEST(reading_file_success_test);                  /*all the test functions*/
    RUN_TEST(quiz_play_test);

    /*closing the unity test framework*/
    return UNITY_END();
}
