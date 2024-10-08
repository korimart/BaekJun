#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> MemoizationCache(N);
    MemoizationCache[0] = 1;
    MemoizationCache[1] = 3;
    for (int i = 2; i < N; i++)
    {
        MemoizationCache[i] = MemoizationCache[i - 1] + 2 * MemoizationCache[i - 2];
        MemoizationCache[i] %= 10'007;
    }

    std::cout << MemoizationCache.back();
}