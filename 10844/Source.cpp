#include <iostream>
#include <array>

int main()
{
    int DigitCount;
    std::cin >> DigitCount;

    std::array<std::array<int, 100>, 10> NumbersEndingWithCount{};
    NumbersEndingWithCount[1][0] = 1;
    NumbersEndingWithCount[2][0] = 1;
    NumbersEndingWithCount[3][0] = 1;
    NumbersEndingWithCount[4][0] = 1;
    NumbersEndingWithCount[5][0] = 1;
    NumbersEndingWithCount[6][0] = 1;
    NumbersEndingWithCount[7][0] = 1;
    NumbersEndingWithCount[8][0] = 1;
    NumbersEndingWithCount[9][0] = 1;

    for (int DigitIndex = 1; DigitIndex < DigitCount; ++DigitIndex)
    {
        NumbersEndingWithCount[1][DigitIndex] += NumbersEndingWithCount[0][DigitIndex - 1];
        NumbersEndingWithCount[8][DigitIndex] += NumbersEndingWithCount[9][DigitIndex - 1];

        for (int Number = 1; Number < 9; ++Number)
        {
            NumbersEndingWithCount[Number - 1][DigitIndex] += NumbersEndingWithCount[Number][DigitIndex - 1];
            NumbersEndingWithCount[Number + 1][DigitIndex] += NumbersEndingWithCount[Number][DigitIndex - 1];
        }

        for (auto& Each : NumbersEndingWithCount)
        {
            Each[DigitIndex] %= 1'000'000'000;
        }
    }

    int Sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        Sum += NumbersEndingWithCount[i][DigitCount - 1];
        Sum %= 1'000'000'000;
    }
    std::cout << Sum << std::endl;
}