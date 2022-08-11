
#ifndef _SPEAKER_H
#define _SPEAKER_H

class CSpeaker {

    public:
        CSpeaker() {}
        ~CSpeaker() {}

        void GreetUser();       //greets user


    protected:
        std::string _Greeting;


    private:
        std::string _Name;
        int _Language;
        
};


class CEnglish: public CSpeaker {

    public:
        CEnglish(){
            _Greeting = "Hello, World!";
            std::cout << "CTor English" << std::endl;
        }
        ~CEnglish() {
            std::cout << "DTor English" << std::endl;
        }
};

class CTalkativeEnglish: public CEnglish {
    public:
        CTalkativeEnglish() {
            _Greeting = "Hello, World! What a wonderful day it is today.";
        }
        ~CTalkativeEnglish() {
            std::cout << "DTor Talkative English" << std::endl;
        }
};

class CFrench: public CSpeaker {

    public:
        CFrench() {
            _Greeting = "Bonjour le Monde!";
            std::cout << "CTor French" << std::endl;
        }
        ~CFrench() {
            std::cout << "DTor French" << std::endl;
        }
};

class CGerman: public CSpeaker {

    public:
        CGerman() {
            _Greeting = "Hallo Welt!";
            std::cout << "CTor German" << std::endl;
        }
        ~CGerman() {
            std::cout << "DTor German" << std::endl;
        }
};




#endif