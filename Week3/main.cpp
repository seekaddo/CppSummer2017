/* =============================================================================== */
/* CPP Programming (Summer2017)                                                    */
/* Created by Addo Dennis on 21/07/2017.                                           */
/* =============================================================================== */
/*                                                                                 */
/* Tested with g++ 6.3.0 , You can use clang++                                     */
/* =============================================================================== */
/* Author: Dennis Addo                                                             */


/* =============================================================================== */

#include <cmath>
#include <vector>
#include <iostream>
#include <fmt/printf.h>
#include <string>

class Rectangle {
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {};

    Rectangle() : width(0.0), height(0.0) {};

    double area();


};

double Rectangle::area() {
    return width * height;
}


class Person {

    std::string fname;
    std::string lname;
    char gender;
    int age;

public:

    class Invalidparam {
        std::string w;
    public:
        Invalidparam(std::string e) : w(e) {};

        inline std::string what() { return w; }

    };

    Person(std::string fn, std::string ln, int g) : fname(fn), lname(ln), gender('?'), age(g) {
        if (g < 0) throw Invalidparam("Cannot handle negative age");
    };

    Person() : fname(), lname(), gender('?'), age(0) {
        if (age < 0) throw Invalidparam("Cannot handle negative age");
    };

    std::string getFullName();

    inline int getAge() {
        return age;
    }

    inline void setGender(char g) {
        gender = g;
    }

    inline char getGender() {
        return gender;
    }


};

std::string Person::getFullName() {

    return std::string(fname + " " + lname);
}


static bool comparePbyFname(Person a, Person b) {
    std::string str = a.getFullName();
    std::string str2 = b.getFullName();

    return (str2.substr(0, str2.find(' '))) > (str.substr(0, str.find(' ')));
}

int main() {

    Rectangle rect1(4.5, 6), rect2(6.5, 7);


    fmt::printf("The areas of rect1 is %.2f\n", rect1.area());
    fmt::printf("The areas of rect2 is %.2f\n", rect2.area());


    Person p1, p2, p3, p4, p5;

    try {

        p3 = {"Marry", "Himmler", -15};
        p3.setGender('F');


    } catch (Person::Invalidparam &e) {
        fmt::print(stderr, "{0} \n", e.what());
    }

    p1 = {"James", "Adams", 45};
    p1.setGender('M');

    p2 = {"Jacob", "Haller", 25};
    p2.setGender('M');

    p4 = {"Agnes", "Mous", 52};
    p4.setGender('F');

    p5 = {"Fifi", "Klaus", 32};
    p5.setGender('M');


    std::vector<Person> people;

    people.emplace_back(p1);
    people.emplace_back(p2);
    people.emplace_back(p3);
    people.emplace_back(p4);
    people.emplace_back(p5);



    std::sort(people.begin(), people.end(), comparePbyFname);

    fmt::print("List of People: \n");
    for (Person p: people) {
        fmt::printf("Name: %-.*s   Age: %d  Gender %c \n", 10, p.getFullName(), p.getAge(), p.getGender());

    }

    return 0;
}
