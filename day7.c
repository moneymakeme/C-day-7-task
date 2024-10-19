/*1.Write a program to check the given string is anagram or not

Input Format

Accept two strings as input

Constraints

NIL

Output Format

Anagrams / Not Anagrams

Sample Input 0

Tom
Mom
Sample Output 0

Tom and Mom are Not Anagrams.
Sample Input 1

listen
silent
Sample Output 1

listen and silent are Anagrams.
Sample Input 2

arc 
car
Sample Output 2

arc and car are Anagrams.

sollution :*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void trim_whitespace(char *str) {
    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing whitespace
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';
}

int are_anagrams(const char *str1, const char *str2) {
    int count[256] = {0}; // ASCII character count

    // If lengths are not equal, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    // Count characters in the first string
    for (int i = 0; str1[i]; i++) {
        count[(unsigned char)str1[i]]++;
    }

    // Subtract counts using the second string
    for (int i = 0; str2[i]; i++) {
        count[(unsigned char)str2[i]]--;
    }

    // Check if counts are all zero
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1; // They are anagrams
}

int main() {
    char original_str1[MAX_LEN], original_str2[MAX_LEN];
    char str1[MAX_LEN], str2[MAX_LEN];

    // Input two strings
    
    fgets(original_str1, MAX_LEN, stdin);
    
    fgets(original_str2, MAX_LEN, stdin);

    // Remove newline character if present
    original_str1[strcspn(original_str1, "\n")] = 0;
    original_str2[strcspn(original_str2, "\n")] = 0;

    // Trim whitespace
    trim_whitespace(original_str1);
    trim_whitespace(original_str2);

    // Convert to lowercase for comparison
    strcpy(str1, original_str1);
    strcpy(str2, original_str2);
    
    for (int i = 0; str1[i]; i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; str2[i]; i++) {
        str2[i] = tolower(str2[i]);
    }

    // Check if they are anagrams
    if (are_anagrams(str1, str2)) {
        printf("%s and %s are Anagrams.\n", original_str1, original_str2);
    } else {
        printf("%s and %s are Not Anagrams.\n", original_str1, original_str2);
    }

    return 0;
}

/*2.Write a program to check given string are equal or not equal

Input Format

Accept two string as a input

Constraints

NIL

Output Format

EQUAL OR NOT EQUAL

Sample Input 0

myslate
myslate
Sample Output 0

Equal

sollution :*/
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    // Input two strings
   // printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
  //  printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters from the strings if present
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    // Check if the strings are equal
    if (strcmp(str1, str2) == 0) {
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }

    return 0;
}

/*3.Write a c program to check whether a given string is Pangram or not

Input Format

Accept the string as input

Constraints

NIL

Output Format

Pangrams / Not Pangrams

Sample Input 0

The quick brown fox jumps over the lazy dog
Sample Output 0

Pangrams
Sample Input 1

this garden is very nice to look
Sample Output 1

Not Pangrams

sollution :*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_COUNT 26

int is_pangram(const char *str) {
    int letter_count[ALPHABET_COUNT] = {0};
    int index;

    // Iterate over each character in the string
    for (int i = 0; str[i]; i++) {
        // Convert to lowercase and check if it's an alphabet
        if (isalpha((unsigned char)str[i])) {
            index = tolower((unsigned char)str[i]) - 'a';
            letter_count[index] = 1; // Mark this letter as found
        }
    }

    // Check if all letters are present
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        if (letter_count[i] == 0) {
            return 0; // Not a pangram
        }
    }

    return 1; // It is a pangram
}

int main() {
    char input[256];

    // Input the string
   // printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Check if the input string is a pangram
    if (is_pangram(input)) {
        printf("Pangrams\n");
    } else {
        printf("Not Pangrams\n");
    }

    return 0;
}

/*4.Write a program to check whether the string is isogram or not

Input Format

Accept the string as input

Constraints

NIL

Output Format

ISOGRAM / NOT ISOGRAM

Sample Input 0

orange
Sample Output 0

ISOGRAM
Sample Input 1

test
Sample Output 1

NOT ISOGRAM

sollution :*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_COUNT 26

int is_isogram(const char *str) {
    int letter_count[ALPHABET_COUNT] = {0};
    int index;

    // Iterate over each character in the string
    for (int i = 0; str[i]; i++) {
        // Convert to lowercase and check if it's an alphabet
        if (isalpha((unsigned char)str[i])) {
            index = tolower((unsigned char)str[i]) - 'a';
            letter_count[index]++;
            
            // If the letter count exceeds 1, it's not an isogram
            if (letter_count[index] > 1) {
                return 0; // Not an isogram
            }
        }
    }

    return 1; // It is an isogram
}

int main() {
    char input[256];

    // Input the string
   // printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Check if the input string is an isogram
    if (is_isogram(input)) {
        printf("ISOGRAM\n");
    } else {
        printf("NOT ISOGRAM\n");
    }

    return 0;
}

/*5.Write a program to reverse the words of the given sentence

Input Format

Accept string as an input

Constraints

NIL

Output Format

Print the reversed sentence

Sample Input 0

I am a heartiology doctor
Sample Output 0

doctor heartiology a am I

sollution :*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

void reverse_words(char *str) {
    int length = strlen(str);
    char reversed[MAX_LEN];
    int j = 0;

    // Traverse the string from end to start
    for (int i = length - 1; i >= 0; i--) {
        // If a space or the start of the string is encountered, we store the word
        if (str[i] == ' ' || i == 0) {
            // If it's the start of the string, we need to include the first character as well
            if (i == 0) {
                reversed[j++] = str[i];
            }
            for (int k = i + 1; k < length && str[k] != ' '; k++) {
                reversed[j++] = str[k];
            }
            reversed[j++] = ' '; // Add a space after the word
        }
    }

    // Null-terminate the reversed string
    reversed[j - 1] = '\0'; // Replace the last space with null character

    // Print the reversed sentence
    printf("%s\n", reversed);
}

int main() {
    char input[MAX_LEN];

    // Input the string
   // printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Reverse the words in the sentence
    reverse_words(input);

    return 0;
}

/*6.Write a program to check the IP address is validate or not

Input Format

IP address

Constraints

nil

Output Format

Valid/Invalid

Sample Input 0

125.16.100.1
Sample Output 0

Valid
Sample Input 1

125.512.100.1
Sample Output 1

Invalid
Sample Input 2

125.def.100.abc
Sample Output 2

Invalid

sollution :*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_valid_ip(const char *ip) {
    int num, dots = 0;
    const char *ptr;

    // Check for valid IP address format
    ptr = ip;
    while (*ptr) {
        // Reset num for the new segment
        num = 0;

        // Check for digits
        while (isdigit(*ptr)) {
            num = num * 10 + (*ptr - '0');
            ptr++;
        }

        // If num is not in the valid range, return invalid
        if (num < 0 || num > 255) {
            return 0;
        }

        // Count the dots
        if (*ptr == '.') {
            dots++;
            ptr++;
        } else if (*ptr != '\0') {
            // If it's not a dot and not the end, it's invalid
            return 0;
        }
    }

    // There should be exactly 3 dots for a valid IP
    return dots == 3;
}

int main() {
    char ip[16];

    // Input the IP address
    //printf("Enter an IP address: ");
    fgets(ip, sizeof(ip), stdin);

    // Remove newline character if present
    ip[strcspn(ip, "\n")] = 0;

    // Check if the IP address is valid
    if (is_valid_ip(ip)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}

/*7.Given a password, check whether it is strong or weak. A strong password is one that has

at least one upper case letter at least one lower case letter at least one digit at least one special character length is at least 10

Input Format

Accept a string as a input

Constraints

nil

Output Format

Strong password or Weak password

Sample Input 0

MySlate@_12
Sample Output 0

Strong password

sollution :*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 10

int is_strong_password(const char *password) {
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    // Check the length of the password
    if (strlen(password) < MIN_LENGTH) {
        return 0; // Weak password
    }

    // Check for different character types
    for (int i = 0; password[i]; i++) {
        if (isupper((unsigned char)password[i])) {
            has_upper = 1;
        } else if (islower((unsigned char)password[i])) {
            has_lower = 1;
        } else if (isdigit((unsigned char)password[i])) {
            has_digit = 1;
        } else {
            has_special = 1; // Assuming any non-alphanumeric character is special
        }
    }

    // Check if all conditions are met
    return has_upper && has_lower && has_digit && has_special;
}

int main() {
    char password[256];

    // Input the password
    //printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character if present
    password[strcspn(password, "\n")] = 0;

    // Check if the password is strong
    if (is_strong_password(password)) {
        printf("Strong password\n");
    } else {
        printf("Weak password\n");
    }

    return 0;
}

/*9.Write a program to check whether brackets are balanced in expression

Input Format

Open and close brackets ( )

Constraints

NIL

Output Format

Balanced/Unbalanced

Sample Input 0

((()))
Sample Output 0

Balanced
Sample Input 1

((())
Sample Output 1

Unbalanced
Sample Input 2

)(
Sample Output 2

Unbalanced

sollution :*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure to hold the brackets
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Function to push an element onto the stack
void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = c;
    }
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (s->top != -1) {
        return s->arr[(s->top)--];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check if the stack is empty
int is_empty(Stack *s) {
    return s->top == -1;
}

// Function to check if the given expression has balanced brackets
int is_balanced(const char *expression) {
    Stack s;
    init(&s);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push(&s, expression[i]);
        } else if (expression[i] == ')') {
            if (is_empty(&s)) {
                return 0; // Unbalanced if there's a closing bracket with no matching opening
            }
            pop(&s); // Pop the matching opening bracket
        }
    }
    
    return is_empty(&s); // If stack is empty, brackets are balanced
}

int main() {
    char expression[100];

    // Input the expression
   // printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    
    // Remove newline character if present
    expression[strcspn(expression, "\n")] = 0;

    // Check if the brackets are balanced
    if (is_balanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Unbalanced\n");
    }

    return 0;
}

/*10.Write a program to validate the given email

Input Format

Accept a string as a input

Constraints

NIL

Output Format

Valid/Invalid

Sample Input 0

sixphrase.myslate@gmail.com
Sample Output 0

Valid
Sample Input 1

sixphrase@gmail
Sample Output 1

Invalid
Sample Input 2

dnfbsj@yahoo.com
Sample Output 2

Valid

sollution :*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_email(const char *email) {
    const char *at_sign = strchr(email, '@');
    const char *dot_sign = strrchr(email, '.');

    // Check for presence of '@' and '.'
    if (at_sign == NULL || dot_sign == NULL) {
        return 0; // Missing '@' or '.' in the email
    }

    // Check if '@' comes before the last '.'
    if (at_sign > dot_sign) {
        return 0; // '@' must be before the last '.'
    }

    // Check if there is at least one character before and after '@'
    if (at_sign == email || at_sign + 1 == dot_sign) {
        return 0; // No characters before '@' or between '@' and '.'
    }

    // Check if the domain part has at least one character after the last '.'
    if (dot_sign + 1 == email + strlen(email)) {
        return 0; // No characters after the last '.'
    }

    // Additional checks for invalid characters in the local part
    for (const char *p = email; p < at_sign; p++) {
        if (!isalnum(*p) && *p != '.' && *p != '_' && *p != '-') {
            return 0; // Invalid character in local part
        }
    }

    // Additional checks for invalid characters in the domain part
    for (const char *p = at_sign + 1; p < dot_sign; p++) {
        if (!isalnum(*p) && *p != '-') {
            return 0; // Invalid character in domain part
        }
    }

    // Check for invalid characters in the top-level domain
    for (const char *p = dot_sign + 1; *p != '\0'; p++) {
        if (!isalnum(*p)) {
            return 0; // Invalid character in top-level domain
        }
    }

    return 1; // Valid email
}

int main() {
    char email[100];

    // Input the email
    
    fgets(email, sizeof(email), stdin);
    
    // Remove newline character if present
    email[strcspn(email, "\n")] = 0;

    // Validate the email
    if (is_valid_email(email)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
