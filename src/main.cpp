//
// Created by simon on 25/02/23.
//
#include <iostream>
#include <filesystem>
#include "day_2022_01.h"
#include "day_2022_02.h"
#include "day_2022_03.h"
#include "day_2022_04.h"
#include "day_2022_05.h"
#include "day_2022_06.h"
#include "day_2022_07.h"
#include "day_2022_08.h"
#include "day_2022_09.h"
#include "day_2022_10.h"
#include "day_2022_11.h"
#include "day_2022_12.h"
#include "day_2022_13.h"
#include "day_2022_14.h"
#include "day_2022_15.h"
#include "day_2022_16.h"
#include "day_2022_17.h"
#include "day_2022_18.h"
#include "day_2022_19.h"
#include "day_2022_20.h"
#include "day_2022_21.h"
#include "day_2022_22.h"
#include "day_2022_23.h"
#include "day_2022_24.h"
#include "day_2022_25.h"
#include "day_2023_01.h"
#include "day_2023_02.h"
#include "day_2023_03.h"
#include "day_2023_04.h"
#include "day_2023_05.h"
#include "day_2023_06.h"
#include "day_2023_07.h"
#include "day_2023_08.h"
#include "day_2023_09.h"
#include "day_2023_10.h"
#include "day_2023_11.h"
#include "day_2023_12.h"
#include "day_2023_13.h"
#include "day_2023_14.h"
#include "day_2023_15.h"
#include "day_2023_16.h"
#include "day_2023_17.h"
#include "day_2023_18.h"
#include "day_2023_19.h"
#include "day_2023_20.h"
#include "day_2023_21.h"
#include "day_2023_22.h"
#include "day_2023_23.h"
#include "day_2023_24.h"
#include "day_2023_25.h"


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
            day_dir = "02";
            day202202::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202203:
        {
            day_dir = "03";
            day202203::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202204:
        {
            day_dir = "04";
            day202204::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202205:
        {
            day_dir = "05";
            day202205::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202206:
        {
            day_dir = "06";
            day202206::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202207:
        {
            day_dir = "07";
            day202207::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202208:
        {
            day_dir = "08";
            day202208::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202209:
        {
            day_dir = "09";
            day202209::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202210:
        {
            day_dir = "10";
            day202210::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202211:
        {
            day_dir = "11";
            day202211::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202212:
        {
            day_dir = "12";
            day202212::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202213:
        {
            day_dir = "13";
            day202213::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202214:
        {
            day_dir = "14";
            day202214::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202215:
        {
            day_dir = "15";
            day202215::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202216:
        {
            day_dir = "16";
            day202216::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202217:
        {
            day_dir = "17";
            day202217::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202218:
        {
            day_dir = "18";
            day202218::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202219:
        {
            day_dir = "19";
            day202219::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202220:
        {
            day_dir = "20";
            day202220::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202221:
        {
            day_dir = "21";
            day202221::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202222:
        {
            day_dir = "22";
            day202222::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202223:
        {
            day_dir = "23";
            day202223::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202224:
        {
            day_dir = "24";
            day202224::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202225:
        {
            day_dir = "25";
            day202225::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202301:
        {
            day_dir = "01";
            day202301::run(cwd / year_dir / day_dir / data_name);
            break;

        }
        case 202302:
        {
            day_dir = "02";
            day202302::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202303:
        {
            day_dir = "03";
            day202303::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202304:
        {
            day_dir = "04";
            day202304::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202305:
        {
            day_dir = "05";
            day202305::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202306:
        {
            day_dir = "06";
            day202306::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202307:
        {
            day_dir = "07";
            day202307::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202308:
        {
            day_dir = "08";
            day202308::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202309:
        {
            day_dir = "09";
            day202309::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202310:
        {
            day_dir = "10";
            day202310::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202311:
        {
            day_dir = "11";
            day202311::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202312:
        {
            day_dir = "12";
            day202312::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202313:
        {
            day_dir = "13";
            day202313::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202314:
        {
            day_dir = "14";
            day202314::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202315:
        {
            day_dir = "15";
            day202315::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202316:
        {
            day_dir = "16";
            day202316::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202317:
        {
            day_dir = "17";
            day202317::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202318:
        {
            day_dir = "18";
            day202318::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202319:
        {
            day_dir = "19";
            day202319::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202320:
        {
            day_dir = "20";
            day202320::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202321:
        {
            day_dir = "21";
            day202321::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202322:
        {
            day_dir = "22";
            day202322::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202323:
        {
            day_dir = "23";
            day202323::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202324:
        {
            day_dir = "24";
            day202324::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        case 202325:
        {
            day_dir = "25";
            day202325::run(cwd / year_dir / day_dir / data_name);

            break;
        }
        default:
        {

        }
    };

    return 0;
}