#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int DayCount, WindowSize;
    std::cin >> DayCount >> WindowSize;

    std::vector<int> VisitorCounts;
    VisitorCounts.reserve(DayCount);
    for (int i = 0; i < DayCount; ++i)
    {
        int VisitorCount;
        std::cin >> VisitorCount;
        VisitorCounts.push_back(VisitorCount);
    }

    int LargestSum = 0;
    int LargestSumCount = 0;

    auto WindowFirst = VisitorCounts.begin();
    auto WindowLast = VisitorCounts.begin() + WindowSize - 1;
    
    int WindowSum = std::accumulate(WindowFirst, WindowLast + 1, 0);
    WindowSum -= *WindowLast;
    
    while (WindowLast != VisitorCounts.end())
    {
        WindowSum += *WindowLast;

        if (WindowSum > LargestSum)
        {
            LargestSum = WindowSum;
            LargestSumCount = 1;
        }
        else if (WindowSum == LargestSum)
        {
            LargestSumCount++;
        }
        
        WindowSum -= *WindowFirst;
        ++WindowFirst;
        ++WindowLast;
    }

    if (LargestSum == 0)
    {
        std::cout << "SAD";
    }
    else
    {
        std::cout << LargestSum << "\n" << LargestSumCount;
    }
}
