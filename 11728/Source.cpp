#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ASize, BSize;
    std::cin >> ASize >> BSize;

    std::vector<int> A, B;
    A.reserve(ASize);
    B.reserve(BSize);

    for (int i = 0; i < ASize; ++i)
    {
        int Element;
        std::cin >> Element;
        A.push_back(Element);
    }

    for (int i = 0; i < BSize; ++i)
    {
        int Element;
        std::cin >> Element;
        B.push_back(Element);
    }

    auto AIt = A.begin();
    auto BIt = B.begin();
    while (AIt != A.end() && BIt != B.end())
    {
        if (*AIt < *BIt)
        {
            std::cout << *AIt << " ";
            ++AIt;
        }
        else
        {
            std::cout << *BIt << " ";
            ++BIt;
        }
    }

    std::copy(AIt, A.end(), std::ostream_iterator<int>{std::cout, " "});
    std::copy(BIt, B.end(), std::ostream_iterator<int>{std::cout, " "});
}