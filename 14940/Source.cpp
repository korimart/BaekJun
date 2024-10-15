#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <iterator>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Height, Width;
    std::cin >> Height >> Width;

    std::vector<std::vector<int>> World(Height, [&]()
    {
        std::vector<int> Ret;
        Ret.reserve(Width);
        return Ret;
    }());

    std::vector<std::vector<int>> Distances(Height, std::vector<int>(Width, -1));

    int TargetX = 0;
    int TargetY = 0;
    for (int Y = 0; Y < Height; ++Y)
    {
        for (int X = 0; X < Width; ++X)
        {
            int Terrain;
            std::cin >> Terrain;
            World[Y].push_back(Terrain);

            if (Terrain == 0)
            {
                Distances[Y][X] = 0;
            }
            else if (Terrain == 2)
            {
                TargetX = X;
                TargetY = Y;
                Distances[TargetY][TargetX] = 0;
            }
        }
    }

    const auto CanVisit = [&](int X, int Y)
    {
        return X >= 0 && Y >= 0 && X < Width && Y < Height && World[Y][X] == 1 && Distances[Y][X] < 0;
    };

    std::queue<std::tuple<int, int>> ToVisit;
    ToVisit.emplace(TargetX, TargetY);

    const auto SetDistAndQueueIfCanVisit = [&](int X, int Y, int Dist)
    {
        if (CanVisit(X, Y))
        {
            Distances[Y][X] = Dist;
            ToVisit.emplace(X, Y);
        }
    };

    while (!ToVisit.empty())
    {
        const auto [ThisX, ThisY] = ToVisit.front();
        ToVisit.pop();

        const int NextDistnace = Distances[ThisY][ThisX] + 1;
        SetDistAndQueueIfCanVisit(ThisX - 1, ThisY, NextDistnace);
        SetDistAndQueueIfCanVisit(ThisX + 1, ThisY, NextDistnace);
        SetDistAndQueueIfCanVisit(ThisX, ThisY - 1, NextDistnace);
        SetDistAndQueueIfCanVisit(ThisX, ThisY + 1, NextDistnace);
    }

    for (auto& Each : Distances)
    {
        std::copy(Each.begin(), Each.end(), std::ostream_iterator<int>{std::cout, " "});
        std::cout << '\n';
    }
}
