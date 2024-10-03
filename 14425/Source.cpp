#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int SetSize, ProblemCount;
    std::cin >> SetSize >> ProblemCount;

    std::unordered_set<std::string> TheSet;
    for (int i = 0; i < SetSize; i++)
    {
        std::string Word;
        std::cin >> Word;
        TheSet.insert(Word);
    }

    int IsInSetCount = 0;
    for (int i = 0 ; i < ProblemCount; i++)
    {
        std::string Word;
        std::cin >> Word;

        if (TheSet.find(Word) != TheSet.end())
        {
            IsInSetCount++;
        }
    }

    std::cout << IsInSetCount << std::endl;
}
