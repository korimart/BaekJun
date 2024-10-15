#include <iostream>
#include <queue>

int main()
{
    int SubinPos, Subin2Pos;
    std::cin >> SubinPos >> Subin2Pos;

    std::vector<bool> Visited(100'001, false);
    std::queue<int> LeftRights, Twices;

    Visited[SubinPos] = true;
    Twices.push(SubinPos);

    int Cost = 0;
    while (true)
    {
        while (!Twices.empty())
        {
            const int CurrentPos = Twices.front();
            Twices.pop();
            LeftRights.push(CurrentPos);

            if (CurrentPos == Subin2Pos)
            {
                goto Done;
            }

            if (CurrentPos == 0)
            {
                continue;
            }

            for (int i = CurrentPos * 2; i <= 100'000; i *= 2)
            {
                if (!Visited[i])
                {
                    Visited[i] = true;
                    LeftRights.push(i);
                }
            }
        }

        while (!LeftRights.empty())
        {
            const int CurrentPos = LeftRights.front();
            LeftRights.pop();

            if (CurrentPos == Subin2Pos)
            {
                goto Done;
            }

            const int Left = CurrentPos - 1;
            const int Right = CurrentPos + 1;

            if (Left >= 0 && !Visited[Left])
            {
                Visited[Left] = true;
                Twices.push(Left);
            }

            if (Right <= 100'000 && !Visited[Right])
            {
                Visited[Right] = true;
                Twices.push(Right);
            }
        }

        Cost++;
    }

Done:
    std::cout << Cost;
}
