#include "isogram.h"
#include "string.h"

bool islowerCaseLetter(char c){
    return  (c >= 'a' && c <= 'z');
}

bool isANumber(char c) {
    return (c >= '0' && c <= '9');
}

bool isIgnored(char c) {
    return !(islowerCaseLetter(c) || isANumber(c));
}


char toLowerCase(char c){
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a');
    }
    return c;
}

bool is_isogram(const char phrase[]){

       //occurences[65] means number of 'A's
    int occurences[256] = { 0 };

    int len = strlen(phrase);
    for (int i=0; i<len; i++) {
        char currentChar = toLowerCase(phrase[i]);
        if (!isIgnored(currentChar)){
            //check all other chars against currentChar
            //find if there are more than 1 occurences
            occurences[currentChar]++;
        }
    }
    int expectedOccurence = -1;
    for(int i = 0; i < 256; i++){
        if (!isIgnored(i)) {
            if (occurences[i] != 0){
            if(expectedOccurence == -1){
                expectedOccurence = occurences[i];
            } else {
                int currentOccurence = occurences[i];
                if (currentOccurence != expectedOccurence){
                    return false;
                }
            }  
            }
        }
    }
    return true;
}
