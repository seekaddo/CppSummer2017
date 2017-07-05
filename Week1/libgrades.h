/* =============================================================================== */
/* CPP Programming (Summer2017)                                                    */
/* Created by Addo Dennis on 05/07/2017.                                           */
/* =============================================================================== */
/* Header file for the grades.c. All the definition here                           */
/*                                                                                 */
/* Tested with g++ 6.3.0 , You can use clang++                                     */
/* =============================================================================== */
/* Author: Dennis Addo                                                             */
/* =============================================================================== */



#ifndef SMC1114_LIBGRADES_H
#define SMC1114_LIBGRADES_H

#include <cstddef>
#include <string>


struct Projects {
    std::string name;
    double pnkts;
};


struct Student_info {

    std::string name;
    std::string id;
    std::vector<Projects> projt;
    double projktSumme;
    size_t grade;
};


int calculateGrades(std::vector<Student_info> &stud);

double getProjktSumme(const std::vector<Projects> &bspl);

size_t do_grades(const double pnkt);

std::vector<Student_info> get_PassStudents(const std::vector<Student_info> &students);

void printDetails(const Student_info &i);

void printDetails(const std::vector<Student_info> &info);


#endif //SMC1114_LIBGRADES_H
