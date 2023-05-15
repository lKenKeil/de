#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 1000


bool is_alphanumeric(char c) {
    return isalpha(c) || isdigit(c);
}


char to_lower(char c) {
    return tolower(c);
}


bool is_palindrome(char* str) {
    int len = strlen(str);
    char deque[MAX_LEN];
    int front = 0, rear = -1;
  
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (is_alphanumeric(c)) {
            c = to_lower(c);
            deque[++rear] = c;
        }
    }
   
    while (front < rear) {
        if (deque[front++] != deque[rear--]) {
            return false;
        }
    }
    return true;
}


int main() {
    char input[MAX_LEN];
    while (true) {
        printf("Enter a string (type 'exit' to quit): ");
        fgets(input, MAX_LEN, stdin);
        input[strcspn(input, "\n")] = '\0'; 
        if (strcmp(input, "exit") == 0) {
            break;
        }
        else if (is_palindrome(input)) {
            printf("%s is a palindrome\n", input);
        }
        else {
            printf("%s is not a palindrome\n", input);
        }
    }
    return 0;
}
