#include <algorithm>
#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <vector>
#include <format>
#include <iostream>

namespace Day2
{

constexpr bool is_valid_diff(int diff)
{
    return (diff >= 1 && diff <= 3) || (diff <= -1 && diff >= -3);
}

bool is_safe_report(std::vector<int> &report)
{
    int init = report[1] - report[0];

    if (!is_valid_diff(init))
    {
        return false;
    }
    else
    {
        for (int i = 1; i < report.size() - 1; i++)
        {
            int diff = report[i + 1] - report[i];
            if (!is_valid_diff(diff) || init * diff < 0) // init and diff have different sign(+, -)
            {
                return false;
            }
        }
        return true;
    }
}

void day2_1()
{
    std::fstream ifs{"day2.txt", std::ios::in};

    std::string line;
    std::stringstream iss;

    int safe_count = 0;
    while (std::getline(ifs, line))
    {
        iss.clear();
        iss.str(line);

        std::vector<int> current_report;

        int a = 0;
        while (iss >> a)
        {
            current_report.push_back(a);
        }

        // calculate differences between all numbers
        std::vector<int> diffs;
        for (int i = 0; i < current_report.size() - 1; i++)
        {
            diffs.push_back(current_report[i + 1] - current_report[i]);
        }

        // find the starting order: ascending or descending
        bool is_ascending = diffs[0] > 0;

        // all number differences should be 'valid difference number + same sign as the first difference number'
        bool is_safe_report =
            std::all_of(diffs.begin(), diffs.end(), [&](int diff)
                        { return is_valid_diff(diff) && ((is_ascending && diff > 0) || (!is_ascending && diff < 0)); });

        if (is_safe_report)
        {
            safe_count++;
        }
    }

    std::cout << std::format("Safe count: {}\n", safe_count);
}

void day2_2()
{
    std::fstream ifs{"day2.txt", std::ios::in};

    std::string line;
    std::stringstream iss;

    int safe_count = 0;
    while (std::getline(ifs, line))
    {
        iss.clear();
        iss.str(line);

        std::vector<int> current_report;

        int a = 0;
        while (iss >> a)
        {
            current_report.push_back(a);
        }

        bool result = is_safe_report(current_report);
        if (result)
        {
            safe_count++;
        }
        else
        {
            for (int i = 0; i < current_report.size(); i++)
            {
                auto copy_report = current_report;
                copy_report.erase(copy_report.begin() + i);
                bool result = is_safe_report(copy_report);
                if (result)
                {
                    safe_count++;
                    break;
                }
            }
        }
    }

    std::cout << std::format("Safe count: {}\n", safe_count);
}

} // namespace Day2

int main()
{
    Day2::day2_1();
    // Day2::day2_2();
}