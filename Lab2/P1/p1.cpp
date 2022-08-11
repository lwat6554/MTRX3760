// SID: 500490778
// 11/2022

#include <iostream>
#include <string>

class CCountry;

class CPlanet {
    public:
        CPlanet(std::string Name, int NumNations)
            : _Name(Name),
            _NumCountries(NumNations)
        {
            std::cout << "Planet CTor, ID: " << _Name << std::endl;
        }
  
        ~CPlanet() {
            std::cout << "Planet DTor, ID: " << _Name << std::endl;
        }

        void ReportEquatorials();

    private:
        int _NumCountries;
        std::string _Name;
};

class CCountry {
    public:
        CCountry(std::string Name, bool Equ) 
          : _Name(Name),
             _OnEquator(Equ)
        {
            std::cout << "Country CTor, ID: " << _Name << std::endl;
        }

        ~CCountry() {
           std::cout << "Country DTor, ID: " << _Name << std::endl;
        }

        //returns if country is on equator
        bool IsOnEquator() {
           return _OnEquator;
        };

        std::string ReportName(){
            return _Name;
        }



    private:

        bool _OnEquator;
        std::string _Name;
};


int main() {

    CPlanet Mars("Mars", 5);
    Mars.ReportEquatorials();

}


void CPlanet::ReportEquatorials(){

    for(int i=0; i<_NumCountries; i++) {
                
                std::string aName[5] = {"A", "B", "C", "D", "E"};
                bool equ;
                if(rand()%4 > 1) {
                    equ = true;
                    //std::cout << rand()%3 << std:: endl;
                } else {
                    equ = false;
                }


                CCountry* pNation = new CCountry(aName[i], equ);

                if (pNation->IsOnEquator()) {
                    std::cout << pNation->ReportName() << " is on the equator" << std::endl;
                }

        delete pNation;
    }

}
