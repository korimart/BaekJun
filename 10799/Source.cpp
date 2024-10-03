#include <iostream>
#include <string>

int main()
{
    std::string Parentheses;
    std::cin >> Parentheses;

    int PieceCount = 0;
    int BarCount = 0;
    for (int i = 0; i < Parentheses.size(); i++)
    {
        if (Parentheses[i] == '(')
        {
            PieceCount++;
            BarCount++;
            continue;
        }

        const bool bLaser = i > 0 && Parentheses[i - 1] == '(';
        
        if (bLaser)
        {
            // ()는 막대기가 아니라 레이저임 그래서 아까 1 올린 거 다시 내림
            PieceCount--;
            BarCount--;

            // 레이저로 잘랐으므로 조각 카운트 막대기의 개수만큼 UP
            PieceCount += BarCount;
        }
        else
        {
            BarCount--;
        }
    }

    std::cout << PieceCount << std::endl;
}
