#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

int CountTrustedComputers(const std::vector<std::vector<int>>& DirectTrusts, int StartIndex)
{
    std::vector<bool> Visited(DirectTrusts.size(), false);
    Visited[StartIndex] = true;

    std::queue<int> ToVisit;
    ToVisit.push(StartIndex);

    int Ret = 1;
    while (!ToVisit.empty())
    {
        const int ThisVisit = ToVisit.front();
        ToVisit.pop();

        for (int NextVisit : DirectTrusts[ThisVisit])
        {
            if (!Visited[NextVisit])
            {
                Visited[NextVisit] = true;
                ToVisit.push(NextVisit);
                Ret++;
            }
        }
    }

    return Ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ComputerCount, TrustCount;
    std::cin >> ComputerCount >> TrustCount;

    std::vector<std::vector<int>> TrustedComputers(ComputerCount);
    for (int i = 0; i < TrustCount; ++i)
    {
        int From, To;
        std::cin >> To >> From;
        TrustedComputers[From - 1].push_back(To - 1);
    }

    int LargestTrustCount = 0;
    std::vector<int> Vulnerables;
    for (int i = 0; i < ComputerCount; ++i)
    {
        const int Count = CountTrustedComputers(TrustedComputers, i);
        if (Count > LargestTrustCount)
        {
            LargestTrustCount = Count;
            Vulnerables = { i + 1 };
        }
        else if (Count == LargestTrustCount)
        {
            Vulnerables.push_back(i + 1);
        }
    }

    std::sort(Vulnerables.begin(), Vulnerables.end());
    std::copy(Vulnerables.begin(), Vulnerables.end(), std::ostream_iterator<int>{std::cout, " "});
}
