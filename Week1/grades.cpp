//
// Created by Addo Dennis on 05/07/2017.
//

#include <vector>
#include <iostream>
#include "libgrades.h"



int main(){

    std::vector<Student_info> stdt_info = {
            Student_info{
                    "Mike Jasson",
                    "ic14b023",
                    std::vector<Projects>{Projects{"Myfind",89},Projects{"Pipes and Process",69},Projects{"Sharedmemory",99}}
                    ,0,0
            },
            Student_info{
                    "Alex moore",
                    "ic14b003",
                    std::vector<Projects>{Projects{"Myfind",33},Projects{"Pipes and Process",39},Projects{"Sharedmemory",19}},0,0
            },
            Student_info{
                    "Morris Addi",
                    "ic14b003",
                    std::vector<Projects>{Projects{"Myfind",66},Projects{"Pipes and Process",59},Projects{"Sharedmemory",70}},0,0
            }
    };



    calculateGrades(stdt_info);


    std::cout << "The List of student for Betrieb System Projects:" <<std::endl;
    printDetails(stdt_info);



    std::vector<Student_info> pass_student = get_PassStudents(stdt_info);

   // std::cout << "Size is "+std::to_string(pass_student.size()) <<std::endl;

    std::cout <<std::endl;
    std::cout << "The List of Passed Students are: "<<std::endl;

    for (std::vector<Student_info>::iterator i = pass_student.begin(); i != pass_student.end() ; ++i) {


        printDetails(*i);
    }

    return 0;
}