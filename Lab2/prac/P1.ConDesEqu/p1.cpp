// SID: 500490778
// 11/2022

#include <iostream>
#include <string>


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

class CCountry: public CPlanet {
    public:
    CCountry(std::string Name, bool Equ) 
        : _Name(Name),
          _OnEquator(Equ)

    ~CCountry() {
        std::cout << "Country DTor, ID: " << _Name << std::endl;
    }

    //returns if country is on equator
    bool IsOnEquator() {
        return _OnEquator;
    };


    private:

    bool _OnEquator;
    std::string _Name;
};


int main() {

    CPlanet Mars("Mars", 5);

}

    
