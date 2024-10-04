#include <iomanip>
#include <iostream>
#include <string>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TotalTreeCount = 0;
    std::map<std::string, int> TreeToCountMap;

    std::string Line;
    while (std::getline(std::cin, Line) && !Line.empty())
    {
        TotalTreeCount++;
        TreeToCountMap[Line]++;
    }

    std::cout << std::fixed << std::setprecision(4);
    for (const auto& [Tree, Count] : TreeToCountMap)
    {
        std::cout
            << Tree
            << " "
            << TreeToCountMap.at(Tree) * 100.f / TotalTreeCount
            << "\n";
    }
}
