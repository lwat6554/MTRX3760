
#ifndef _SPEAKER_H
#define _SPEAKER_H

class CSpeaker {

    public:

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
        }


    private:
        //std::string _Greeting;
};

class CFrench

#endif