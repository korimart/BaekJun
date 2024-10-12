#include <iostream>
#include <array>
#include <algorithm>

std::array<int, 10'000> Wines;
std::array<int, 10'000> MaxWine_DidNotDrink;
std::array<int, 10'000> MaxWine_DrankOneInARow;
std::array<int, 10'000> MaxWine_DrankTwoInARow;

int main()
{
    int WineCount;
    std::cin >> WineCount;

    for (int i = 0; i < WineCount; ++i)
    {
        std::cin >> Wines[i];
    }

    MaxWine_DrankOneInARow[0] = Wines[0];
    MaxWine_DrankTwoInARow[0] = Wines[0];

    if (WineCount > 1)
    {
        MaxWine_DidNotDrink[1] = Wines[0];
        MaxWine_DrankOneInARow[1] = Wines[1];
        MaxWine_DrankTwoInARow[1] = Wines[0] + Wines[1];
    }

    for (int i = 2; i < WineCount; ++i)
    {
        MaxWine_DidNotDrink[i] = std::max({
            MaxWine_DidNotDrink[i - 1],
            MaxWine_DrankOneInARow[i - 1],
            MaxWine_DrankTwoInARow[i - 1],
        });
        MaxWine_DrankOneInARow[i] = Wines[i] + MaxWine_DidNotDrink[i - 1];
        MaxWine_DrankTwoInARow[i] = Wines[i] + MaxWine_DrankOneInARow[i - 1];
    }

    std::cout << std::max({
        MaxWine_DidNotDrink[WineCount - 1],
        MaxWine_DrankOneInARow[WineCount - 1],
        MaxWine_DrankTwoInARow[WineCount - 1],
    });
}
