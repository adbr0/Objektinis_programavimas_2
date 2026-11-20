#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

class studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> pazymys_;
    int egzaminas_;
    double galutinisv_;
    double galutinism_;

public:
//  numatytas
    studentas(): egzaminas_(0), galutinisv_(0.0), galutinism_(0.0) {}

    studentas(std::istream& is);

    studentas(const studentas& kitas);

    studentas& operator=(const studentas& kitas);

    ~studentas();

    inline std::string vardas() const {return vardas_;}
    inline std::string pavarde() const {return pavarde_;}
    inline double galutinisv() const {return galutinisv_;}
    inline double galutinism() const {return galutinism_;}

    void set_vardas(const std::string& v) {vardas_=v;}
    void set_pavarde(const std::string& p) {pavarde_=p;}
    void set_egz(int e) {egzaminas_=e;}
    void set_pazymiai(const std::vector<int>& paz) {pazymys_=paz;}
    void add_pazymys(int p) {pazymys_.push_back(p);}

    std::istream& read_studenta(std::istream& is);
    void skaiciuoti_galutini();

};

double vidurkis(const std::vector<int>& pazymiai);
double mediana(std::vector<int> pazymiai);
bool compare_pagal_varda(const studentas& A, const studentas& B);
bool compare_pagal_pavarde(const studentas& A, const studentas& B);
bool compare_pagal_galutini(const studentas& A, const studentas& B);
#endif // STUDENTAS_H_INCLUDED
