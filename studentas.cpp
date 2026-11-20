#include "studentas.h"
#include <algorithm>
#include <numeric>
#include <sstream>

studentas::studentas(std::istream& is): egzaminas_(0), galutinisv_(0.0), galutinism_(0.0){
    read_studenta(is);
}

studentas::studentas(const studentas& kitas)
    : vardas_(kitas.vardas_), pavarde_(kitas.pavarde_),
    pazymys_(kitas.pazymys_), egzaminas_(kitas.egzaminas_),
    galutinisv_(kitas.galutinisv_), galutinism_(kitas.galutinism_) {}

studentas& studentas::operator=(const studentas& kitas){
    if(this!=&kitas){
        vardas_=kitas.vardas_;
        pavarde_=kitas.pavarde_;
        pazymys_=kitas.pazymys_;
        egzaminas_=kitas.egzaminas_;
        galutinism_=kitas.galutinism_;
        galutinisv_=kitas.galutinisv_;
    }
    return *this;

}

studentas::~studentas(){
    pazymys_.clear();
}

std::istream& studentas::read_studenta(std::istream& is){

    pazymys_.clear();
    if(!(is>>vardas_>>pavarde_)){return is;}

    std::vector<int> skaiciai;
    int skaicius;
    while(is>>skaicius){skaiciai.push_back(skaicius);}

    if(skaiciai.size()>=2){
        egzaminas_ = skaiciai.back();
        skaiciai.pop_back();
        pazymys_ = skaiciai;
        skaiciuoti_galutini();
    } else {
        egzaminas_ = 0;
        galutinisv_ = 0.0;
        galutinism_ = 0.0;
    }
    return is;

}

void studentas::skaiciuoti_galutini(){
    double v=vidurkis(pazymys_);
    double m=mediana(pazymys_);
    galutinisv_ = 0.4*v + 0.6*egzaminas_;
    galutinism_ = 0.4*m + 0.6*egzaminas_;
}


double vidurkis(const std::vector<int>& pazymiai)
{
    if(pazymiai.empty()) return 0.0;
    double suma = std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
    return suma / pazymiai.size();
}
double mediana(std::vector<int> pazymiai)
{
     if(pazymiai.empty()) return 0.0;
     std::sort(pazymiai.begin(), pazymiai.end());
     size_t n = pazymiai.size();
     if (n%2 == 0)
     {
         return (pazymiai[n/2-1]+pazymiai[n/2])/ 2.0;
     }
     return pazymiai[n/2];
}
bool compare_pagal_varda(const studentas& A, const studentas& B)
{
    return A.vardas()<B.vardas();
}
bool compare_pagal_pavarde(const studentas& A, const studentas& B)
{
    return A.pavarde()<B.pavarde();
}
bool compare_pagal_galutini(const studentas& A, const studentas& B)
{
    return A.galutinisv()<B.galutinisv();
}
