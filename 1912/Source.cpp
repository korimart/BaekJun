#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int SequenceSize;
    std::cin >> SequenceSize;

    std::vector<int> Sequence;
    Sequence.reserve(SequenceSize);
    for (int i = 0; i < SequenceSize; ++i)
    {
        int Element;
        std::cin >> Element;
        Sequence.push_back(Element);
    }

    int PrevMax = Sequence[0];
    int AllTimeMax = PrevMax;
    for (int i = 1; i < SequenceSize; ++i)
    {
        const int This = Sequence[i];
        const int PrevMaxPlusThis = PrevMax + This;
        const int ThisMax = This < PrevMaxPlusThis ? PrevMaxPlusThis : This;
        AllTimeMax = std::max(AllTimeMax, ThisMax);
        PrevMax = ThisMax;
    }
    
    std::cout << AllTimeMax;
}