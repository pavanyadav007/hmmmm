#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "./inc/program.h"

const int number_of_ques = 5;                              // Total Number of questions per topic.

qna_t *question_array = NULL;                              // Pointer to array of questions in each questionbank.


int main()
{
    
    error_t status;                                      
    

    char round1_questions[300],round2_questions[300];
    char name_of_participant[50];
    char choice,topic_1,topic_2;
   // printf("starting program\n");

mainhome:    game_intro();
	scanf("%c",&choice);
    getchar();
    choice = toupper(choice);
    switch(choice)    
    {
        case 'S':
            system("cls || clear");
            break;
        case 'H':
            system("cls || clear");
            please_help();
            scanf("%c",&choice);
            getchar();
			choice = toupper(choice);
            if (choice == 'Y')
            {
                time_delay(2);
                goto mainhome;
            }
            else
            {
                system("cls || clear");
                return 0;
            }
            
        case 'Q':
            system("cls || clear");
            return 0;
        default:
            goto mainhome;
    }
    printf("Please enter your Name: ");
    fgets(name_of_participant,50,stdin);

    select_again:    system("cls || clear");
    printf("please Enter your two choices\n");
    printf("1. Science and Technology      |  [T]     \n");
    printf("2. LTTS history                |  [L]     \n");
    printf("3. General Knowledge           |  [G]     \n");
    printf("4. sports                      |  [S]     \n");
    printf("Enter your First Topic :");
    scanf("%c",&topic_1);
    getchar();
	topic_1 = toupper(topic_1);
    printf("Enter your Second Topic :");
    scanf("%c",&topic_2);                                       //selection of 2 topics for the quiz
    getchar();
	topic_2 = toupper(topic_2);
    
        if (topic_1 == topic_2)
        {
            printf("selection of same topics is prohibited\n");
            printf("Please select two DIFFERENT options.\n");
            printf("Press Enter to select the topics : %c\n",getchar());
            goto select_again;
        }
        else
        {
           switch (topic_1)
            {
               case'T':
                      strcpy(round1_questions,"questionbank/Science_and_Technology.csv");
                      break;
                case 'L':
                        strcpy(round1_questions,"questionbank/LTTS_Company.csv");
                      break;
                case 'G':
                        strcpy(round1_questions,"questionbank/General_Knowledge.csv") ;
                      break; 
                case 'S':
                        strcpy(round1_questions,"questionbank/sports.csv") ;
                      break; 
                default: 
                        printf(" Kindly enter a correct KEY for first topic :\n");
                        printf("%c",getchar());
                        goto select_again;
            }
            switch (topic_2)
            {
                case 'L':
                        strcpy(round2_questions,"questionbank/LTTS_Company.csv");
                        break;
                case 'S':
                        strcpy(round2_questions,"questionbank/sports.csv") ;
                        break;
                case'T':
                        strcpy(round2_questions,"questionbank/Science_and_Technology.csv");
                        break;
            
                case 'G':
                        strcpy(round2_questions,"questionbank/General_Knowledge.csv") ;
                        break; 
            
                default: 
                        printf(" Kindly enter a correct KEY for second topic :\n");
                        printf("%c",getchar());
                        time_delay(3);
                        goto select_again;
            }
        }
    
                            //starting of 1st round
            question_array = create_question_array(number_of_ques);
            status = read_file(question_array,round1_questions);
            if(status == NO_FILE)
            {
                printf("sorry! the file cant be opened\n");
                time_delay(3);
                return 0;
            }
            else if(status == NULL_PTR)
             {
                 printf("Memory allocation error\n");
               time_delay(3);
                return 0;
             }
            else
            {
                status = play(question_array,name_of_participant,number_of_ques);
                if(status == PLAYER_OUT)
                {
                    time_delay(3);
                    return 0;
                }
            }
         free(question_array);
         question_array = create_question_array(number_of_ques);
        
        system("cls || clear");
        printf("****************************************************************************\n");
        printf("brilliant, you have cleared 1st round and are appearing for the second round\n");
        printf("your score after 1st round is 100\n");
        printf("_____________________________________________________________________________\n\n");
        printf("Press Enter to continue ");
        getchar();

                    //starting of round 2
        status = read_file(question_array,round2_questions);
        if(status == NO_FILE)
        {
            printf("We cannot open the file\n");
            return 0;
        }
        else if(status == NULL_PTR)
        {
            printf("Memory allocation error\n");
            return 0;
        }
        else
        {
            status = play(question_array,name_of_participant,number_of_ques);
            if(status == PLAYER_OUT){
               
                printf("\n\n lifes over,sorry you are not qualified");
                time_delay(3);
                return 0;
            }

            system("cls || clear");
            printf("_____________________________________________________________________________________________________\n");
            printf("| congrats! you are a true champion.. you have cleared the quiz \n");
            printf("your score after round 2 is 200 \n");
            printf("you are a awarded a cash prize of $1million \n");
            printf("_____________________________________________________________________________________________________\n\n\n");
            printf("click enter to quit the program");
		    getchar();    
        }
    
   
    free(question_array);
    time_delay(3);
    return 0;

}