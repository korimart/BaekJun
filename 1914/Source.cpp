#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

#ifdef _MSC_VER
    uint64_t StepCount = 1;
#else
        __uint128_t StepCount = 1;
#endif
    for (int i = 0; i < N - 1; ++i)
    {
        StepCount = StepCount * 2 + 1;
    }

    std::string StepCountString;
    while (StepCount > 0)
    {
        StepCountString.push_back('0' + StepCount % 10);
        StepCount /= 10;
    }
    std::reverse(StepCountString.begin(), StepCountString.end());
    std::cout << StepCountString << '\n';

    if (N <= 20)
    {
        const auto MoveDisc = [&](const auto& Self, int From, int Intermediate, int To, int Count)
        {
            if (Count == 1)
            {
                std::cout << From << ' ' << To << '\n';
                return;
            }

            Self(Self, From, To, Intermediate, Count - 1);
            Self(Self, From, Intermediate, To, 1);
            Self(Self, Intermediate, From, To, Count - 1);
        };

        MoveDisc(MoveDisc, 1, 2, 3, N);
    }
}
