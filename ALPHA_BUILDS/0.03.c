#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//---FUNCTIONS---//
//MULTICHOICE CHECKER (note: im writing this at 2am, if you dont understand this when you wake up tough luck lmao)
char* multi(char* prompt){
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
            printf("invalid input\n");
            continue;
        }
        if(strcmp(userprompt, "A") == 0 || strcmp(userprompt, "a") == 0){
            return "A";
        }
        if(strcmp(userprompt, "B") == 0 || strcmp(userprompt, "b") == 0){
            return "B";
        }
        if(strcmp(userprompt, "C") == 0 || strcmp(userprompt, "c") == 0){
            return "C";
        }
        if(strcmp(userprompt, "D") == 0 || strcmp(userprompt, "d") == 0){
            return "D";
        }
    }

}

char* stringcheck(){ //NOTE: THIS PASSES BACK A MALLOCED VARIABLE, FREE THE VARIABLE AFTER USAGE
    char uinput[100];
    int buffercheck = 0;
    fgets(uinput, 100, stdin);
    for(int x = 0; x<strlen(uinput); x++){
        if(uinput[x] == '\n'){
            buffercheck = 1;
        }
    }
    if(buffercheck == 0){
        while((getchar()) != '\n');
    }
    uinput[strlen(uinput) -1] = 0;
    char *ret = malloc(strlen(uinput));
    for(int x = 0; x<strlen(uinput); x++){
        ret[x] = uinput[x];
    }
    return ret;
}

int question(char* prompt, char* answer, int qtype, int points){
    char* userprompt;
    if(qtype == 0){ //codeblock for doing multichoice questions
        userprompt = multi(prompt);
        if(strcmp(userprompt, answer) == 0){
            printf("Correct!\nYou got %d points!\n", points);
            return points;
        }
        else{
            printf("incorrect\n");
            return 0;
        }
    } // well thats the easy bit done prolly, good luck awake me lmaoooooo
    if(qtype == 1){    //Block for dealing with non-multichoice questions
        printf("%s\n", prompt);
        char uinput[100]; //i know this is inefficient, but comparing strings when one's made with malloc() really doesnt work
        int buffercheck = 0;
        fgets(uinput, 100, stdin);
        for(int x = 0; x<strlen(uinput); x++){
            if(uinput[x] == '\n'){
                buffercheck = 1;
            }
            else{
                uinput[x] = tolower(uinput[x]);
            }
        }
        if(buffercheck == 0){
            while((getchar()) != '\n');
        }

        uinput[strlen(uinput) -1] = 0;
        if(strcmp(uinput, answer) == 0){
            printf("Correct!\nYou got %d points!\n", points);
            return points;
        }
        else{
            printf("Incorrect\n");
            return 0;
        }
    }
}

//this introduces the user to the quiz and takes their name
char* intro(){
    printf("Welcome to the quiz, what's your name?\n");
    char *uname = stringcheck();
    printf("welcome, %s!\n", uname);
    char *ret = malloc(100);
    for(int x = 0; x<strlen(uname); x++){
        ret[x] = uname[x];
    }
    free(uname);
    return ret;
}

int main(){
    int points = 0;
    char *uname = intro();
    points += question("This is a test, the correct answer is a", "A", 0, 3);
    printf("You are now on %d points!\n", points);
    points += question("Answer is Test", "test\0", 1, 5);
    //add more questions here

    //
    printf("The quiz is over! you got %d points %s!", points, uname);
    free(uname);
}

//TODO: FIX VARIABLE NAMES AND ADD COMMENTS