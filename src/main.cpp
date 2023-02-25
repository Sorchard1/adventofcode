//
// Created by simon on 25/02/23.
//
#include <iostream>
#include <filesystem>
#include "day_2022_01.h"


int main() {
    int year;
    int day;
    int yearDay;


    // Input year and day
    std::cout << "Enter the year: \n";
    std::cin >> year;
    std::cout << "Enter the day: \n";
    std::cin >> day;

    // Get the path to this file.
    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path data_path;
    cwd = cwd.parent_path();

    // Get the path to the data file.
    std::filesystem::path data_name = "data.txt";
    std::filesystem::path year_dir = std::to_string(year);
    std::filesystem::path day_dir;

    // Scale the year and add the day for a unique integer
    yearDay = year * 100 + day;
    switch (yearDay)
    {
        case 202201:
        {
            day_dir = "01";
            day202201::run(cwd / year_dir / day_dir / data_name);
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