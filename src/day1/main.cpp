#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <queue>
#include <cmath>

/*
DAY 1-1:
Pair up the numbers from two lists, and measure how far apart they are. (Calculate absolute difference)
Pair up the smallest number in the left list with the smallest number in the right list,
then the second-smallest left number with the second-smallest right number, and so on.
And add them all together.
*/
void day1_1()
{
    std::fstream ifs{ "day1.txt", std::ios::in };
    
    // priority queue, ordered ascending
    std::priority_queue<int, std::vector<int>, std::less<int>> list1{};
    std::priority_queue<int, std::vector<int>, std::less<int>> list2{};

    std::string line;
    std::stringstream iss;

    // Read all the numbers from day1.txt
    // put them into list1 and list2
    while (std::getline(ifs, line))
    {
        iss.clear();
        iss.str(line);

        int a = 0, b = 0;
        while (iss >> a >> b)
        {
            list1.push(a);
            list2.push(b);
        }
    }

    // pop from each list and calculate difference, add them all.
    int sum = 0;
    while (!list1.empty() || !list2.empty())
    {
        int a = list1.top();
        list1.pop();

        int b = list2.top();
        list2.pop();

        sum += std::abs(a - b);
    }

    std::cout << "Sum: " << sum << std::endl;
}

/*
Day 1-2:
Figure out exactly how often each number from the left list appears in the right list.
Calculate a total similarity score by adding up each number in the left list
after multiplying it by the number of times that number appears in the right list.
*/
void day1_2()
{
    std::fstream ifs{ "day1.txt", std::ios::in };

    std::vector<int> list1{};

    // list2: collect the count of appearance of the number using hash map
    std::unordered_map<int, int> list2_map{};

    std::string line;
    std::stringstream iss;
    while (std::getline(ifs, line)) {
        iss.clear();
        iss.str(line);

        int a = 0, b = 0;
        while (iss >> a >> b) {
            list1.push_back(a);

            try
            {
                // if already inserted into map, increment count
                auto &count = list2_map.at(b);
                count++;
            }
            catch (const std::out_of_range &ex)
            {
                // else if the number hasn't pushed to the map, insert new one.
                list2_map.insert({ b, 1 });
            }
        }
    }

    // sort left list by ascending order.
    std::sort(list1.begin(), list1.end());

    // find answer by iterating left list
    int sum = 0;
    for (auto &a: list1)
    {
        int sameCount = 0;
        try
        {
            // if current number in the left list is in the right list, increment the current count
            auto &b = list2_map.at(a);
            sameCount += b;
        }
        catch (const std::out_of_range &ex)
        {
        }

        // add to similarity score
        sum += a * sameCount;
    }

    std::cout << "Sum: " << sum << std::endl;
}

int main()
{
    // day1_1();
    day1_2();
}