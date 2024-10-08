#include <iostream>

int main()
{
    int MemoizationCache[11];
    MemoizationCache[1] = 1;
    MemoizationCache[2] = 2;
    MemoizationCache[3] = 4;

    for (int i = 4; i < 11; i++)
    {
        MemoizationCache[i] = 0;
        MemoizationCache[i] += MemoizationCache[i - 1];
        MemoizationCache[i] += MemoizationCache[i - 2];
        MemoizationCache[i] += MemoizationCache[i - 3];
    }

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        int Number;
        std::cin >> Number;
        std::cout << MemoizationCache[Number] << "\n";
    }
}