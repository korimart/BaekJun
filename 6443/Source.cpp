#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TestCaseCount;
    std::cin >> TestCaseCount;

    for (int i = 0; i < TestCaseCount; ++i)
    {
        std::string Letters;
        std::cin >> Letters;
        std::sort(Letters.begin(), Letters.end());

        std::string Anagram(Letters.size(), ' ');
        std::vector<bool> LetterTaken(Letters.size());
        const auto ChooseLetterForIndex = [&](const auto& Self, int Index)
        {
            if (Index >= Letters.size())
            {
                std::cout << Anagram << '\n';
                return;
            }

            for (int i = 0; i < Letters.size(); ++i)
            {
                if (Letters[i] != Anagram[Index] && !LetterTaken[i])
                {
                    LetterTaken[i] = true;
                    Anagram[Index] = Letters[i];
                    Self(Self, Index + 1);
                    LetterTaken[i] = false;
                }
            }

            Anagram[Index] = ' ';
        };

        ChooseLetterForIndex(ChooseLetterForIndex, 0);
    }
}
