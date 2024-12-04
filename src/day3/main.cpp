#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <regex>
#include <iostream>
#include <format>

namespace Day3
{

void day3_1()
{
    std::fstream ifs{"day3.txt", std::ios_base::in};
    std::string line;
    std::stringstream iss;

    std::regex test_regex("mul\\(\\d{1,3},\\d{1,3}\\)");
    std::regex find_number_regex("\\d{1,3}");
    int sum = 0;
    while (std::getline(ifs, line))
    {
        iss.clear();
        iss.str(line);

        auto begin = std::sregex_iterator(line.begin(), line.end(), test_regex);
        auto end = std::sregex_iterator();

        for (std::sregex_iterator i = begin; i != end; i++)
        {
            std::string match = (*i).str();
            int mul = 1;
            for (std::smatch sm; std::regex_search(match, sm, find_number_regex);)
            {
                mul *= std::stoi(sm.str());
                match = sm.suffix();
            }
            sum += mul;
        }
    }
    std::cout << std::format("Sum: {}", sum) << std::endl;
}

void day3_2()
{
    std::fstream ifs{"day3.txt", std::ios_base::in};
    std::string line;
    std::stringstream iss;

    std::regex test_regex("(?:mul\\(\\d{1,3},\\d{1,3}\\))|(?:do\\(\\))|(?:don't\\(\\))");
    std::regex find_number_regex("\\d{1,3}");
    long sum = 0;
    bool is_active = true;
    while (std::getline(ifs, line))
    {
        iss.clear();
        iss.str(line);

        for (std::smatch sm; std::regex_search(line, sm, test_regex);)
        {
            std::string match = sm.str();

            if (match == "do()")
            {
                is_active = true;
            }
            else if (match == "don't()")
            {
                is_active = false;
            }
            else
            {
                long mul = 1;
                for (std::smatch _sm; std::regex_search(match, _sm, find_number_regex);)
                {
                    mul *= std::stol(_sm.str());
                    match = _sm.suffix();
                }
                if (is_active)
                {
                    sum += mul;
                }
            }

            line = sm.suffix();
        }
    }
    std::cout << std::format("Sum: {}", sum) << std::endl;
}

} // namespace Day3

int main()
{
    Day3::day3_2();
}