#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int CityCount, RoadCount, TargetDistance, FirstCity;
    std::cin >> CityCount >> RoadCount >> TargetDistance >> FirstCity;

    std::vector<std::vector<int>> Neighbors(CityCount + 1);
    for (int i = 0; i < RoadCount; ++i)
    {
        int From, To;
        std::cin >> From >> To;
        Neighbors[From].push_back(To);
    }

    std::vector<bool> Visited(CityCount + 1);
    Visited[FirstCity] = true;

    std::vector<int> ToVisitThisRound, ToVisitNextRound;
    ToVisitThisRound.push_back(FirstCity);

    int Distance = 0;
    while (Distance < TargetDistance)
    {
        for (const int VisitingCity : ToVisitThisRound)
        {
            for (int Each : Neighbors[VisitingCity])
            {
                if (!Visited[Each])
                {
                    Visited[Each] = true;
                    ToVisitNextRound.push_back(Each);
                }
            }
        }

        Distance++;
        ToVisitThisRound = std::move(ToVisitNextRound);
        ToVisitNextRound = {};
    }

    if (ToVisitThisRound.empty())
    {
        std::cout << -1;
        return 0;
    }

    std::sort(ToVisitThisRound.begin(), ToVisitThisRound.end());
    for (const int Each : ToVisitThisRound)
    {
        std::cout << Each << '\n';
    }
}
