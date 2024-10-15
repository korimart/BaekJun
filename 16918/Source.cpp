#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Height, Width, LastSecond;
    std::cin >> Height >> Width >> LastSecond;

    std::vector<std::vector<int>> World(Height, [&]()
    {
        std::vector<int> Ret;
        Ret.reserve(Width);
        return Ret;
    }());

    std::string Line;
    std::getline(std::cin, Line);
    for (int i = 0; i < Height; ++i)
    {
        std::getline(std::cin, Line);
        std::transform(Line.begin(), Line.end(), std::back_inserter(World[i]), [](char Each)
        {
            return Each == '.' ? 0 : 3;
        });
    }

    const auto ClearIfValidPos = [&](int X, int Y)
    {
        if (0 <= X && X < Width && 0 <= Y && Y < Height)
        {
            World[Y][X] = 0;
        }
    };

    const auto Explode = [&](int X, int Y)
    {
        ClearIfValidPos(X, Y);
        ClearIfValidPos(X - 1, Y);
        ClearIfValidPos(X + 1, Y);
        ClearIfValidPos(X, Y - 1);
        ClearIfValidPos(X, Y + 1);
    };

    const auto PrintWorld = [&]()
    {
        for (int Y = 0; Y < Height; ++Y)
        {
            for (int X = 0; X < Width; ++X)
            {
                std::cout << (World[Y][X] == 0 ? '.' : 'O');
            }
            std::cout << '\n';
        }
    };

    int CurrentSeconds = 0;
    while (true)
    {
        std::vector<std::tuple<int, int>> ExpiringBombs;

        for (int Y = 0; Y < Height; ++Y)
        {
            for (int X = 0; X < Width; ++X)
            {
                if (World[Y][X] > 1)
                {
                    World[Y][X]--;
                }

                if (World[Y][X] == 1)
                {
                    ExpiringBombs.emplace_back(X, Y);
                }
            }
        }

        for (auto [X, Y] : ExpiringBombs)
        {
            Explode(X, Y);
        }

        CurrentSeconds++;
        if (CurrentSeconds == LastSecond)
        {
            break;
        }

        for (int Y = 0; Y < Height; ++Y)
        {
            for (int X = 0; X < Width; ++X)
            {
                if (World[Y][X] == 0)
                {
                    World[Y][X] = 3;
                }
            }
        }

        CurrentSeconds++;
        if (CurrentSeconds == LastSecond)
        {
            break;
        }
    }

    PrintWorld();
}
