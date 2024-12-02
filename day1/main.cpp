#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <cmath>

/*
DAY 1:
Pair up the numbers from two lists, and measure how far apart they are. (Calculate absolute difference)
Pair up the smallest number in the left list with the smallest number in the right list,
then the second-smallest left number with the second-smallest right number, and so on.
And add them all together.
*/
int main()
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