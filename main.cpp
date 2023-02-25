//
// Created by simon on 25/02/23.
//
#include <iostream>
#include "2022/01/day_2022_01.h"


int main() {
    int year;
    int day;
    int yearDay;


    // Input year and day
    std::cout << "Enter the year: \n";
    std::cin >> year;
    std::cout << "Enter the day: \n";
    std::cin >> day;

    // Scale the year and add the day for a unique integer
    yearDay = year*100 + day;
    switch (yearDay)
    {
        case 202201:
        {
            day202201::run();
            break;

        }
        case 202202:
        {
            break;
        }

        default:
        {

        }
    };

    return 0;
}