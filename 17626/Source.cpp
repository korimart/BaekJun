#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int Number;
    std::cin >> Number;

    std::vector<int> MemoizationCache(Number + 1);
    for (int i = 1; i < Number + 1; i++)
    {
        int MinCount = 5;
        for (int j = 1; j * j <= i; j++)
        {
            const int Term = j * j;
            const int Remaining = i - Term;
            MinCount = std::min(MinCount, MemoizationCache[Remaining] + 1);
        }
        MemoizationCache[i] = MinCount;
    }

    std::cout << MemoizationCache.back();
}