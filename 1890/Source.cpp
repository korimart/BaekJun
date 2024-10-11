#include <iostream>
#include <array>
#include <algorithm>

int64_t BoardSize;
std::array<std::array<int64_t, 100>, 100> Board;
std::array<std::array<int64_t, 100>, 100> RouteCounts;

int64_t FindOrGetRouteCountAt(int64_t X, int64_t Y)
{
    if (RouteCounts[X][Y] >= 0)
    {
        return RouteCounts[X][Y];
    }

    int64_t RouteCount = 0;
    for (int64_t i = 1; i < 10; i++)
    {
        const int64_t LeftPos = X - i;
        const int64_t UpPos = Y - i;

        if (LeftPos >= 0 && Board[LeftPos][Y] + LeftPos == X)
        {
            RouteCount += FindOrGetRouteCountAt(LeftPos, Y);
        }

        if (UpPos >= 0 && Board[X][UpPos] + UpPos == Y)
        {
            RouteCount += FindOrGetRouteCountAt(X, UpPos);
        }
    }

    return RouteCounts[X][Y] = RouteCount;
}

int main()
{
    std::cin >> BoardSize;
    for (int64_t i = 0; i < BoardSize; ++i)
    {
        for (int64_t j = 0; j < BoardSize; ++j)
        {
            std::cin >> Board[j][i];
        }
    }

    for (auto& Each : RouteCounts)
    {
        std::fill(Each.begin(), Each.end(), -1);
    }
    RouteCounts[0][0] = 1;

    std::cout << FindOrGetRouteCountAt(BoardSize - 1, BoardSize - 1);
}
