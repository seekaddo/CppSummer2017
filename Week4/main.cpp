/* =============================================================================== */
/* CPP Programming (Summer2017)                                                    */
/* Created by Addo Dennis on 28/07/2017.                                           */
/* =============================================================================== */
/*               Hackerrank C++ question Virtual Functions                         */
/*                The main function provided by Hackerrank                         */
/* Tested with g++ 6.3.0 , You can use clang++                                     */
/* =============================================================================== */
/* Author: Dennis Addo                                                             */


/* =============================================================================== */
/* Question:
 * This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student.
 * The class Person should have data members name and age. The classes Professor and Student should inherit from the
 * class Person.
 The class Professor should have two integer members: publications and cur_id.
 There will be two member functions: getdata and putdata. The function getdata should get the input
 from the user: the name, age and publications of the professor. The function putdata should print the name,
 age, publications and the cur_id of the professor.
 
 The class Student should have two data members: marks, which is an array of size  and cur_id.
 It has two member functions: getdata and putdata. The function getdata should get the input
 from the user: the name, age, and the marks of the student in  subjects. The function putdata
 should print the name, age, sum of the marks and the cur_id of the student.
 
 For each object being created of the Professor or the Student class, sequential id's should
 be assigned to them starting from .
 
 Solve this problem using virtual functions, constructors and static variables.
 You can create more data members if you want.
 */






#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Person {
    
protected:
    string name;
    size_t age;
    
public:
    Person() {
        name = "";
        age = 0;
    }
    
    virtual void getdata() {}
    
    virtual void putdata() {}
    
};

class Professor : public Person { //1
    
public:
    int publications, id;
    inline static int cur_id = 0; // only in c++11 upwards
    
    
    void getdata() override {
        cur_id++;
        cin >> name >> age >> publications;
        id = cur_id;
    }
    
    
    void putdata() override {
        cout << name << " " << age << " " << publications << " " << id << endl;
    }
    
};


class Student : public Person { //2
    
public:
    inline static int cur_id = 0; // only in c++11 upwards
    int marks[6];
    int id, sum = 0;
    
    void getdata() override {
        cur_id++;
        cin >> name >> age;
        for (int i = 0; i < 6; ++i) {
            cin >> marks[i];
            sum += marks[i];
            id = cur_id;
        }
    }
    
    void putdata() override {
        cout << name << " " << age << " " << sum << " " << id << endl;
    }
    
};

