#include <iostream>
#include <array>
#include <algorithm>

std::array<int, 100'000> StickerScores0;
std::array<int, 100'000> StickerScores1;

void Solve()
{
    int Width;
    std::cin >> Width;

    for (int i = 0; i < Width; ++i)
    {
        std::cin >> StickerScores0[i];
    }

    for (int i = 0; i < Width; ++i)
    {
        std::cin >> StickerScores1[i];
    }

    int UpWasChosenPrevScore = 0;
    int DownWasChosenPrevScore = 0;
    int NoChoicePrevScore = 0;

    for (int i = 0; i < Width; ++i)
    {
        const int ChooseUpScore = StickerScores0[i] + std::max(DownWasChosenPrevScore, NoChoicePrevScore);
        const int ChooseDownScore = StickerScores1[i] + std::max(UpWasChosenPrevScore, NoChoicePrevScore);
        const int NoChoiceScore = std::max(UpWasChosenPrevScore, DownWasChosenPrevScore);

        UpWasChosenPrevScore = ChooseUpScore;
        DownWasChosenPrevScore = ChooseDownScore;
        NoChoicePrevScore = NoChoiceScore;
    }

    std::cout << std::max({UpWasChosenPrevScore, DownWasChosenPrevScore, NoChoicePrevScore}) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TestCaseCount;
    std::cin >> TestCaseCount;
    for (int i = 0; i < TestCaseCount; ++i)
    {
        Solve();
    }
}
