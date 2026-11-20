#include "studentas.h"
#include <algorithm>
#include <numeric>
#include <sstream>

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
