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
//    numatytas
    studentas(): egzaminas_(0), galutinisv_(0.0), galutinism_(0.0) {}

    studentas(std::istream& is);

    studentas(const studentas& kitas);

    studentas& operator=(const studentas& kitas);

    ~studentas();


};

double vidurkis(const std::vector<int>& pazymiai);
double mediana(std::vector<int> pazymiai);
void galutinis(studentas& a);

#endif // STUDENTAS_H_INCLUDED
