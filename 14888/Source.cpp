#include <iostream>
#include <algorithm>
#include <limits>

int main()
{
    int NumberCount;
    std::cin >> NumberCount;
    const int OperationCount = NumberCount - 1;

    int Numbers[11];
    std::for_each_n(Numbers, NumberCount, [](int& Each) { std::cin >> Each; });

    int PlusCount, MinusCount, MulCount, DivCount;
    std::cin >> PlusCount >> MinusCount >> MulCount >> DivCount;

    enum class EOperation
    {
        Plus,
        Minus,
        Mul,
        Div,
    };
    EOperation Operations[10];

    const auto DoOperations = [&]()
    {
        int Ret = Numbers[0];
        for (int i = 0; i < OperationCount; ++i)
        {
            const EOperation Operation = Operations[i];
            const int RightOperand = Numbers[i + 1];

            if (Operation == EOperation::Plus)
            {
                Ret += RightOperand;
            }
            else if (Operation == EOperation::Minus)
            {
                Ret -= RightOperand;
            }
            else if (Operation == EOperation::Mul)
            {
                Ret *= RightOperand;
            }
            else if (Operation == EOperation::Div)
            {
                Ret /= RightOperand;
            }
        }
        return Ret;
    };

    int MaxResult = std::numeric_limits<int>::min();
    int MinResult = std::numeric_limits<int>::max();
    const auto ChooseOperationForIndex = [&](const auto& Self, int Index)
    {
        if (Index >= OperationCount)
        {
            const int Result = DoOperations();
            MaxResult = std::max(MaxResult, Result);
            MinResult = std::min(MinResult, Result);
            return;
        }

        const auto ChooseOpIfAvailable = [&](EOperation Operation, int& Availability)
        {
            if (Availability > 0)
            {
                --Availability;
                Operations[Index] = Operation;
                Self(Self, Index + 1);
                ++Availability;
            }
        };

        ChooseOpIfAvailable(EOperation::Plus, PlusCount);
        ChooseOpIfAvailable(EOperation::Minus, MinusCount);
        ChooseOpIfAvailable(EOperation::Mul, MulCount);
        ChooseOpIfAvailable(EOperation::Div, DivCount);
    };

    ChooseOperationForIndex(ChooseOperationForIndex, 0);

    std::cout << MaxResult << '\n' << MinResult << std::endl;
}
