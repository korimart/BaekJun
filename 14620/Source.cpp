#include <iostream>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <limits>

int main()
{
    int Dimension;
    std::cin >> Dimension;

    int Costs[10][10];
    for (int i = 0; i < Dimension; ++i)
    {
        for (int j = 0; j < Dimension; ++j)
        {
            std::cin >> Costs[i][j];
        }
    }

    const int PlantableBoxSize = (Dimension - 2) * (Dimension - 2);

    const auto GetXY = [&](int PlantableBoxIndex)
    {
        return std::make_tuple(PlantableBoxIndex % (Dimension - 2) + 1, PlantableBoxIndex / (Dimension - 2) + 1);
    };
    
    const auto GetDistance = [&](int PlantableBoxIndex0, int PlantableBoxIndex1)
    {
        const auto [X0, Y0] = GetXY(PlantableBoxIndex0);
        const auto [X1, Y1] = GetXY(PlantableBoxIndex1);
        return std::abs(X1 - X0) + std::abs(Y1 - Y0);
    };

    const auto GetCost = [&](int PlantableBoxIndex)
    {
        const auto [X, Y] = GetXY(PlantableBoxIndex);
        return Costs[Y][X] + Costs[Y - 1][X] + Costs[Y + 1][X] + Costs[Y][X - 1] + Costs[Y][X + 1];
    };

    int MinCost = std::numeric_limits<int>::max();
    for (int SeedIndex0 = 0; SeedIndex0 < PlantableBoxSize; ++SeedIndex0)
    {
        for (int SeedIndex1 = SeedIndex0 + 1; SeedIndex1 < PlantableBoxSize; ++SeedIndex1)
        {
            for (int SeedIndex2 = SeedIndex1 + 1; SeedIndex2 < PlantableBoxSize; ++SeedIndex2)
            {
                if (GetDistance(SeedIndex0, SeedIndex1) >= 3
                    && GetDistance(SeedIndex0, SeedIndex2) >= 3
                    && GetDistance(SeedIndex1, SeedIndex2) >= 3)
                {
                    MinCost = std::min(MinCost, GetCost(SeedIndex0) + GetCost(SeedIndex1) + GetCost(SeedIndex2));
                }
            }
        }
    }

    std::cout << MinCost;
}
