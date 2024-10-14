#include <iostream>
#include <array>

std::array<std::array<int, 1024>, 1024> SumsToOrigin;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int BoardWidth, BoardHeight;
    std::cin >> BoardHeight >> BoardWidth;

    for (int Y = 0; Y < BoardHeight; ++Y)
    {
        for (int X = 0; X < BoardWidth; ++X)
        {
            std::cin >> SumsToOrigin[Y][X];
            SumsToOrigin[Y][X] += X > 0 ? SumsToOrigin[Y][X - 1] : 0;
            SumsToOrigin[Y][X] += Y > 0 ? SumsToOrigin[Y - 1][X] : 0;
            SumsToOrigin[Y][X] -= X > 0 && Y > 0 ? SumsToOrigin[Y - 1][X - 1] : 0;
        }
    }

    int ProblemCount;
    std::cin >> ProblemCount;

    for (int i = 0; i < ProblemCount; ++i)
    {
        int X0, X1, Y0, Y1;
        std::cin >> Y0 >> X0 >> Y1 >> X1;
        X0--; X1--; Y0--; Y1--;

        int Sum = SumsToOrigin[Y1][X1];
        Sum -= X0 > 0 ? SumsToOrigin[Y1][X0 - 1] : 0;
        Sum -= Y0 > 0 ? SumsToOrigin[Y0 - 1][X1] : 0;
        Sum += X0 > 0 && Y0 > 0 ? SumsToOrigin[Y0 - 1][X0 - 1] : 0;
        std::cout << Sum << "\n";
    }
}
