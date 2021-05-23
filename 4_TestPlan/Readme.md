# TEST PLAN:

## Table no: High level Test Plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01|Display of Menu| None | "(1).start(2).help(3).quit" | PASS | Requirement based|
|  H_02|Starting of quiz  |"1.Character ’S’ from the user 2. Name the participant" |quiz topics display|PASS|Requirement based |
|  H_03|Display of topics| "1.Keywords like L,S,T,G| Questions based on the selected topic|PASS|Requirement based |
| H_04| checking of correct answer to the questions| (1).Character'A'or'B'or'C'or'D'| displaying correct or incorrect | PASS | Requirement based |
| H_05| Check if the help option is working | 1.Character’H’ from the user | Displays the rules of the quiz game |PASS| Scenario |
|H_06| Check if the quit option works well|Character’Q’ from the user|Exit out of the program|PASS|Scenario|
|H_07|Check if the life feature works or not|wrong answer to the question|reduced life|PASS|requirement based|




## Table no: Low level Test Plan

| **Test ID** | **HLT ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01|H_04| check  if the questions are available or not once answered the previous question|character 'A'or'B'or'C'or'D'| result of previous question followed by the next question|SUCCESS |Requirement based |
|  L_02|H_07|check if the life decrements its value when wrong answer is given|wrong answer|life decrements from 2 to 1|SUCCESS|Requirement based|
|  L_03 |H_07|check if 2 wrong answers are given then the contestant is logged out of the quiz| 2 incorrect answers|message displaying that the user is out of the quiz | SUCCESS |Requirement based|
|  L_04 ||display of message "congrats! you have cleared the quiz and won $1million"| minimum 4 correct answers in each topic|displaying of the message "congrats! you have cleared the quiz and won $1million" | SUCCESS |Requirement based|
|  L_05 |H_02|For correct answer print "well done!"| Users choice for the given question|well done! | well done! |Requirement based|
|  L_06 |   |exit the program once the quiz is done by pressing enter|enter|successful logout from the quiz|successful|requirement based|
