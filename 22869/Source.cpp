#include <iostream>
#include <array>
#include <cmath>

std::array<int, 5'000> Stones;
std::array<bool, 5'000> CanArriveHere;

int main()
{
    int StoneCount, MaxPower;
    std::cin >> StoneCount >> MaxPower;

    for (int i = 0; i < StoneCount; ++i)
    {
        std::cin >> Stones[i];
    }

    CanArriveHere[0] = true;
    
    for (int i = 1; i < StoneCount; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            const int PowerRequiredToJump = (i - j) * (1 + std::abs(Stones[j] - Stones[i]));
            if (CanArriveHere[j] && PowerRequiredToJump <= MaxPower)
            {
                CanArriveHere[i] = true;
            }
        }
    }

    std::cout << (CanArriveHere[StoneCount - 1] ? "YES" : "NO");
}
