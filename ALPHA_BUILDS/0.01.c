#include <stdio.h>
#include <stdlib.h>
#include <time.h> //nessesary for randomisation and literally nothing else
#include <ctype.h> //i might remove this in future, i probably won't need it
#include <string.h>
//---VARIABLES---//
//put global variables here//

//---USERSTRUCT---//
//put struct here//

//---FUNCTIONS---//
//MULTICHOICE CHECKER (note: im writing this at 2am, if you dont understand this when you wake up tough luck lmao)
char* multi(char* prompt){ //note: the reason answer is an integer is because its multichoice, possible answers are 1, 2, 3, 4
    for(;;){
        printf("%s\n", prompt);
        char userprompt[2];
        fgets(userprompt, 2, stdin);
        if((getchar()) != '\n'){
            printf("invalid input\n");
            while((getchar()) != '\n');
            continue;
        }
        if(strcmp(userprompt, "A") != 0 && strcmp(userprompt, "a") != 0 && strcmp(userprompt, "b") != 0 && strcmp(userprompt, "B") != 0 && strcmp(userprompt, "c") != 0 && strcmp(userprompt, "C") != 0 && strcmp(userprompt, "D") != 0 && strcmp(userprompt, "d") != 0){
            printf("invalid inpuy\n");
            while((getchar()) != '\n'); // might not need this
            continue;
        }
        if(strcmp(userprompt, "A") == 0 || strcmp(userprompt, "a") == 0){
            printf("1\n");
            return "A";
        }
        if(strcmp(userprompt, "B") == 0 || strcmp(userprompt, "b") == 0){
            printf("2\n");
            return "B";
        }
        if(strcmp(userprompt, "C") == 0 || strcmp(userprompt, "c") == 0){
            printf("3\n");
            return "C";
        }
        if(strcmp(userprompt, "D") == 0 || strcmp(userprompt, "d") == 0){
            printf("4\n");
            return "D";
        }
    }

}

int question(char* prompt, char* answer, int qtype, int points){
    char* userprompt;
    if(qtype == 1){ //codeblock for doing multichoice questions
        userprompt = multi(prompt);
        if(strcmp(userprompt, answer) == 0){
            printf("Correct!\n");
            return points;
        }
        else{
            printf("incorrect\n");
            return 0;
        }
    } // well thats the easy bit done prolly, good luck awake me lmaoooooo
}

int main(){
    int thingy = question("ans A\n", "A", 1, 3);
    printf("%d\n", thingy);
}