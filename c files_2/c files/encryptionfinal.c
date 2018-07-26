//header files used in the gramm
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
//function prototypes
void /*char * */ encryptString(char * sToEncrypt);
int getIntValue(char character);
char * encryptChar(char character,char *encryptedChar);
char getLetter(int intValue);
char * convertToString(char ch);
char *substring(char *original, char *additional, char *temporary);
const char * encrypted_strings[1000]={"kdkkdk","jdjjjjd"};
int main() {
    puts("start of main");
      
    // call function encryptString with string to be encrypted
    //char * encryptedString = encryptString("zz"/*stringtobeencrypted*/);
    encryptString("zz"/*stringtobeencrypted*/);
    int i;
    for(i=0;i<5;i++){
    printf(".....%s.....", encrypted_strings[i]);	
    }
    
    puts("end of main");
    return 0; //end of main
}
//begining of function encryptString

void /*char * */ encryptString(char * sToEncrypt) {
    puts("start of encryptString");
    // = ""; // array to store encrypted string for the entire string
    // determine the length of the string
    //strlen uses the <string.h> header file
    char * char_encrypted_string; // string to store encrypted text for one character
    int stringLen = strlen(sToEncrypt);
    printf("the string length %d",stringLen);
    //loop through the string and encrypt character per character
    // using the encryptChar() function
    int i;
    for (i = 0; i < stringLen; i++) {

        //get acharacter from the array and get its integer value
        char character = sToEncrypt[i]; // get first char in array sToEncrypt
        char *finalfinali;

        char_encrypted_string = encryptChar(character,finalfinali/*character to be encrypted*/);

        printf("char encrypted string %s\n", char_encrypted_string);
        puts("before string cat");
        encrypted_strings[i]= char_encrypted_string;
        //strcat(encrypted_strings, char_encrypted_string);

        puts(string);
        puts("after string cat");
        printf("encryptedString %s ...............\n", encrypted_strings[i]);
        bzero(finalfinali,strlen(finalfinali));
    }

    //return char_encrypted_string;


}

int getIntValue(char character) {
    puts("start of getIntValue");
    char cipherArray[] = "?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // loop through cipher array to find the index at which
    // the value @ that index is equal to the character
    int char_int_val; // integer to contain the int value
    int i;
    for (i = 0; i <=52; i++) {
        if (character == cipherArray[i]) {//check for equality
            char_int_val = i; //index is the integer value of acharacter
            break;
        }
    }
    puts("end of get int value");
    return char_int_val;
}

char * encryptChar(char character,char *encryptedChar) {
    char cipherArray[] = "?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
     // array to store the character's encrypted string
    char capitalLetter, smallLetter;
    char convertedString[15];
    char finali[1000];
    int char_int_value = getIntValue(character); // get int value
    printf("int value \n%d\n",char_int_value);
    // do first encryption step
    if (char_int_value <= 9) {
        capitalLetter = toupper(character);
        // return insert_substring(encryptedChar, "capitalLetter", 1);
        //return insert_substring(encryptedChar, convertToString(capitalLetter), 1);
        return substring(encryptedChar, convertToString(capitalLetter), finali);
        printf(encryptedChar);
        //return encryptedChar;
    }
    else {
        sprintf(convertedString, "%d", char_int_value);
        puts("after sprintf");
        puts("the fkkdkdk");
        puts("converted stringintvalue");
        puts(convertedString);
        //char * std = insert_substring(encryptedChar, convertedString, 1);
        substring(encryptedChar, convertedString, finali);
        puts("after using substring");
        puts(encryptedChar);
        puts(finali);
        puts("the fk");
        int subtOne = char_int_value - 1; // first encryption step
        puts("after subone");
        smallLetter = getLetter(subtOne);

        puts("after small letter");
        substring(encryptedChar, convertToString(smallLetter), finali);
        // second step
        puts("after using substring second time");
        puts(encryptedChar);
        puts(finali);
        int subNine = char_int_value - 9;
        if (subNine <= 9) {
            char chara = toupper(getLetter(subNine));
            return substring(encryptedChar, convertToString(chara), finali);
        puts("after using substring third time");
        puts(encryptedChar);
        puts(finali);
        } else {
            char chara = getLetter(subNine);
            return encryptChar(chara,finali);
                    puts("after using substring fourth time");
        puts(encryptedChar);
        puts(finali);
        }
    }

}

char getLetter(int intValue) {
    puts("start of getLetter");
    char cipherArray[] = "?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char letter;
    int i;
    for (i = 0; i <= 52; i++) {
        if (intValue == i) {//check for equality
            letter = cipherArray[i]; //value at that index is the small letter
            break;
        }
    }
    puts("end of getLetter");
    return letter;
    //puts("end of getLetter");
}

char * convertToString(char ch) {
    char *str = malloc(2 * sizeof (char));
    str[0] = ch;
    str[1] = '\0';
    return str;
}

char *substring(char *original, char *additional, char *temporary) { //Create Temporary Array to hold contents from both original and additional
    int n, length = strlen(original);
    if (length % 2 == 0) //If the length is an even value
        n = length / 2;
    else //If the length is an odd value
        n = (length + 1) / 2;
    strncpy(temporary, original, n); //Copy the first n values from the original array into the temporary array
    temporary[n] = '\0'; //Add the end of string
    strcat(temporary, additional); //Concatenate the additional string to the temporary
    strcat(temporary, original + n); //Concatenate the the original string to the temporary starting from the nth index
    // set original to be equal to temporary
    strcpy(original,temporary);
    return original;
}



