
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool hasLowercase(char password[100]){
    int i;
    for(i = 0; i < strlen(password); i++){
        if(islower(password[i])){
            return true;
        }
    }
    return false;
}

bool hasUppercase(char password[100]){
    int i;
    for(i = 0; i < strlen(password); i++){
        if(isupper(password[i])){
            return true;
        }
    }
    return false;
}

bool hasDigit(char password[100]){
    int i;
    for(i = 0; i < strlen(password); i++){
        if(isdigit(password[i])){
            return true;
        }
    }
    return false;
}

bool hasSpecialChar(char password[100]){
    int i;
    for(i = 0; i < strlen(password); i++){
        if(!isalpha(password[i]) && !isdigit(password[i])){
            return true;
        }
    }
    return false;
}

int evaluateStrength(char password[100]){
    int strength_points = 0;
    if(hasUppercase(password)){
        strength_points++;
        
    }
    if(hasLowercase(password)){
        strength_points++;
       
    }
    if(hasDigit(password)){
        strength_points++;
       
    }
    if(hasSpecialChar(password)){
        strength_points++;
        
    }
    if(strlen(password) >= 12){
        strength_points++;
      
    }
    return strength_points;
}

void score(int strength_points){
    if(strength_points == 0 | strength_points == 1 | strength_points == 2){
        printf("Weak\n");
    }
    else if(strength_points == 3 | strength_points == 4){
        printf("Moderate\n");
    }
    else{
        printf("Strong\n");
    }
}

void main()
{
    bool done = false;
    while(!done){
        char choice[100];
        printf("\nPassword Resilience Analyzer\n1. Test a new password \n");
        printf("2. View strength of the last tested password\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s",&choice);
    
        switch(choice[0]){
            case '1': 
                printf("Enter the password: ");
                char password[100];
                scanf("%s",&password);
                if(strlen(password) < 8){
                    printf("Error: Password should be at least 8 characters long.\n");
                    break;
                }
                else{
                    printf("Password Strength: ");
                    score(evaluateStrength(password));
                    break;
                }
            case '2':
                if(strlen(password) > 0){
                    printf("Last tested password strength: ");
                    score(evaluateStrength(password));  
                }
                else{
                    printf("No previous password\n");
                }
                
                break;
                
            case '3':
                printf("Exiting...");
                done = true;
                break;
            
            default:
               printf("Invalid choice\n");
               break;
            
        }
    }
}