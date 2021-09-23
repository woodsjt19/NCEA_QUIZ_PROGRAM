#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//---FUNCTIONS---//
//MULTICHOICE CHECKER
char* multi(char* prompt){
    for(;;){
        printf("%s\n", prompt);
        char userprompt[2];
        fgets(userprompt, 2, stdin);
        if((getchar()) != '\n'){ //what this block does it it checks to see if theres a newline as the next character in the input buffer, and it keeps grabbing
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
    }
    if(qtype == 1){    //Block for dealing with non-multichoice questions
        printf("%s\n", prompt);
        char u_input[100];
        int buffercheck = 0; //same buffercheck function as on line 85, it used to be it's own function but then i found out it broke on windows for some reason
        fgets(u_input, 100, stdin);
        for(int x = 0; x<strlen(u_input); x++){ //loop for simultaneously checking if the user has overloaded the input buffer and makes the string lowercase aswell
            if(u_input[x] == '\n'){
                buffercheck = 1;
            }
            else{
                u_input[x] = tolower(u_input[x]); //pretty much makes the string lowercase
            }
        }
        if(buffercheck == 0){
            while((getchar()) != '\n');
        }

        u_input[strlen(u_input) -1] = 0;
        if(strcmp(u_input, answer) == 0){
            printf("Correct!\nYou got %d points!\n", points);
            return points;
        }
        else{
            printf("Incorrect\n");
            return 0;
        }
    }
}


int main(){
    int points = 0;
    printf("Welcome to the quiz, what's your name?\n");
    char u_name[100]; // I'd ideally like to keep this in a function, but I tried and its really weird with windows but fine on linux.
    int buffercheck = 0; //This variable is to check if the user has overloaded the input buffer in fgets
    fgets(u_name, 100, stdin);
    for(int x = 0; x<strlen(u_name); x++){
        if(u_name[x] == '\n'){ //basically check if theres a newline in the string grabbed from input buffer to check if the users entered more than max characters
            buffercheck = 1;
        }
    }
    if(buffercheck == 0){
        while((getchar()) != '\n'); //if the user has inputted more than input buffer, clear the rest by grabbing characters until theres a newline
    }
    u_name[strlen(u_name) -1] = 0; //clear the last character in u_input to delete any newlines
    printf("Hello, %s\n", u_name);

    //questions
    points += question("Which country is the company Dodge from?\nA: Australia\nB: Germany\nC: America\nD: England\n", "C", 0, 1);
    points += question("What year did the MK5 Supra release?\nA: 2020\nB: 2013\nC: 1997\nD: 1998\n", "A", 0, 2);
    points += question("What is the oldest car brand?\nA: Ford\nB: Mercedes-Benz\nC: Nissan/Datsun\nD: BMW\n", "B", 0, 3);
    points += question("Which of these cars had the RB26DETT engine in it stock?\nA: Nissan Skyline R32\nB: Nissan 350Z\nC: Toyota A80 Supra\nD: Mazda RX-7 FC\n", "A", 0, 4);
    points += question("How many valves did the RB26DETT's cylinder head have in it?\nA:8\nB:16\nC:24\nD:36", "C", 0, 5);
    points += question("Ok, multichoice question now. \nWhich car company in the US is responsible for 75 percent of all OSHA violations?", "tesla", 1, 5);
    printf("The quiz is over! you got %d points!", points); // tell the user how many points they got
    fgets(u_name, 100, stdin); //i used u_name because i need to declare a varaible to write to but because its the end of the program i can really just use any char ive already declared
}