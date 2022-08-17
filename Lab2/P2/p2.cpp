// SID: 500490778
// P2 lab 2
// 11/2022

#include <iostream>
#include <string>

#include "speaker.h"

int main() {
/*
    CEnglish Boy;
    CFrench Garcon;
    CGerman Junge;
    CTalkativeEnglish Jeremy;


    Boy.GreetUser();
    Garcon.GreetUser();
    Junge.GreetUser();
    Jeremy.GreetUser();
*/
    std::cout << "Enter 6 numbers between 0-3: " << std::endl;


    int aElements[6];

    for(int i=0; i<6; i++) {
        std::cin >> aElements[i];
        //std::cout << " " << std::ends;
    }
    
    //CSpeaker Person[6];

    for(int i = 0; i<6; i++) {

        std::cout << i << ": " << aElements[i] << std::endl;

        if(aElements[i] == 0){
            CEnglish A;
        } else if(aElements[i]==1) {
            CFrench B;
        } else if(aElements[i]==2){
            CGerman C;
        } else if(aElements[i]==3){
            CTalkativeEnglish D;
        }

    }

    return 0;
}