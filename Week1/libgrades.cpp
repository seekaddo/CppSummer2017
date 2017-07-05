/* =============================================================================== */
/* CPP Programming (Summer2017)                                                    */
/* Created by Addo Dennis on 05/07/2017.                                           */
/* =============================================================================== */
/* Header file for the grades.c. All the definition her                            */
/*                                                                                 */
/* Tested with g++ 6.3.0 , You can use clang++                                     */
/* =============================================================================== */
/* Author: Dennis Addo                                                             */
/* =============================================================================== */

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "libgrades.h"


static inline bool is_Pass(const Student_info stdnt) {

    return do_grades(stdnt.projktSumme) != 5;
}


/**\brief
 *
 * @param   stud
 * */
int calculateGrades(std::vector<Student_info> &stud) {

    if (stud.empty()) {
        std::cerr << "Sorry the database is empty";
        return 0;
    }
    for (std::vector<Student_info>::iterator i = stud.begin(); i != stud.end(); ++i) {

        i->projktSumme = getProjktSumme(i->projt);
        i->grade = do_grades(i->projktSumme);

    }


    return 0;
}


/**\brief
 *
 * @param   bspl
 * */
double getProjktSumme(const std::vector<Projects> &bspl) {

    static std::size_t size;

    if (bspl.empty()) {
        std::cerr << "Sorry Student has no Beispiel records" << std::endl;
        return 0;
    }

    if (size != 0 && size != bspl.size()) {
        std::cerr << "Sorry the size of this Projects is not the same als the others" << std::endl;
        exit(EXIT_FAILURE);
    }


    double sum = 0;

    for (std::vector<Projects>::const_iterator i = bspl.begin(); i != bspl.end(); ++i) {

        sum += i->pnkts;
    }

    size = bspl.size();

    return ((sum / (100 * bspl.size()) * 100));
}


/**\brief
 *
 * @param   pnkt
 * */
std::size_t do_grades(const double pnkt) {


    if (pnkt >= 88 && pnkt <= 100) {
        return 1;
    } else if (pnkt >= 75 && pnkt <= 87) {
        return 2;
    } else if (pnkt >= 63 && pnkt <= 74) {
        return 3;
    } else if (pnkt >= 50 && pnkt <= 62) {
        return 4;
    } else {
        return 5;
    }
}


/**\brief
 *
 * @param   students
 * */
std::vector<Student_info> get_PassStudents(const std::vector<Student_info> &students) {

    if (students.empty()) {

        std::cerr << "Sorry the Student container is empty" << std::endl;
        return std::vector<Student_info>();
    }

    std::vector<Student_info> passStudents;
    std::copy_if(students.begin(), students.end(), std::back_inserter(passStudents), is_Pass);

    return passStudents;

}


/**\brief
 *
 * @param   info
 * */
void printDetails(const std::vector<Student_info> &info) {

    std::cout << "----------------------- - ------------- - ------------------------------------ - -------------------"
            "--- - " << std::endl;

    for (std::vector<Student_info>::const_iterator i = info.begin(); i != info.end(); ++i) {

        std::fprintf(stdout, "| Name: %s\t\t| ID: %s\t| NoOf Projects: %zu"
                             " | \tProjects grades in : %.2lf\t| Grade : %zu |\n",
                     i->name.c_str(), i->id.c_str(), i->projt.size(), i->projktSumme, i->grade);
    }

    std::cout << "----------------------- - ------------- - ------------------------------------ - -------------------"
            "--- - " << std::endl;

}

/**\brief
 *
 * @param   i
 * */
void printDetails(const Student_info &i) {


    std::fprintf(stdout, "| Name: %s\t\t| ID: %s\t| NoOf Projects: %zu"
                         " | \tProjects grades in : %.2lf\t| Grade : %zu |\n",
                 i.name.c_str(), i.id.c_str(), i.projt.size(), i.projktSumme, i.grade);

}
