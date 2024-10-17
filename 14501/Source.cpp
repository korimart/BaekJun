#include <iostream>
#include <algorithm>

int main()
{
    int DayCount;
    int TimeItTakes[15];
    int Prices[15];

    std::cin >> DayCount;
    for (int i = 0; i < DayCount; ++i)
    {
        std::cin >> TimeItTakes[i] >> Prices[i];
    }

    const auto ShowMeTheMoney = [&](auto& Self, int FromIndex)
    {
        if (FromIndex >= DayCount) return 0;
        const int NextDayIfTodayIncluded = FromIndex + TimeItTakes[FromIndex];
        const int IncludeToday = NextDayIfTodayIncluded <= DayCount ? Prices[FromIndex] + Self(Self, NextDayIfTodayIncluded) : 0;
        const int ExcludeToday = Self(Self, FromIndex + 1);
        return std::max(IncludeToday, ExcludeToday);
    };

    std::cout << ShowMeTheMoney(ShowMeTheMoney, 0);
}
