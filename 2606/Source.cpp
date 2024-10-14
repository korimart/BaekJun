#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ComputerCount, EdgeCount;
    std::cin >> ComputerCount >> EdgeCount;

    std::vector<std::vector<int>> DirectionConnections(ComputerCount);
    for (int i = 0; i < EdgeCount; ++i)
    {
        int From, To;
        std::cin >> From >> To;
        DirectionConnections[From - 1].push_back(To - 1);
        DirectionConnections[To - 1].push_back(From - 1);
    }

    std::vector<bool> Visited(ComputerCount, false);
    Visited[0] = true;

    std::queue<int> ToVisit;
    ToVisit.push(0);

    while (!ToVisit.empty())
    {
        const int ThisComputer = ToVisit.front(); ToVisit.pop();
        for (int NextComputer : DirectionConnections[ThisComputer])
        {
            if (!Visited[NextComputer])
            {
                Visited[NextComputer] = true;
                ToVisit.push(NextComputer);
            }
        }
    }

    std::cout << std::count(Visited.begin() + 1, Visited.end(), true);
}