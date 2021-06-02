#include <stdio.h>

// Function to count number of letters in a string
int len (char name[]){
    int i ;
    for (i = 0; name[i] != '\0'; ++i);
    return i ;





}

// Function to convert upper case to lower case
int lower_case(char name[]){
    int i ;
    for (i = 0; name[i] != '\0'; ++i){
        if (name[i]>=65 && name[i]<=90) {

            name[i] = name[i] + 32;
        }



    }
    printf("%s", name );
    return 0 ;




}

// Checking the vowels and words in a string

int count_vowels(char name[]){
    int i ;
    int vowel=0;
    for (i=0; name[i] != '\0'; i++ ){

        if (name[i]=='A'|| name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U' ){
            vowel = vowel +1;

        }
    }
    return vowel ;

}

// Checking whether the string is valid or not ( i.e it is contains only numbers and alphabets
int valid_string(char name[]){
    for (int i =0 ; name[i] !='\0' ; i++){
        if (!(name[i]==32) && !(name[i]>=65 && name[i]<=90) && !(name[i]>=98 && name[i]<=122)){
            return 0 ;
        }

    }
    return 1 ;
}

// Reversing a string
int reverse(char name[]){
    char temp ;
    int i =0, j =0 ;
    for ( j =0 ; name[j]!= '\0' ; j ++ );

    j = j-1;

    for (i =0  ; i<j ; i ++ , j-- ){
        temp = name[i];
        name[i] = name[j];
        name[j] = temp;


    }
    printf("%s" , name);
    return 0;
}






int main() {
    char s[] = "PROGRAMMING IS FUN";

    reverse(s);


    return 0 ;
}
