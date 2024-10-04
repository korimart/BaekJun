#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Dimension;
    std::cin >> Dimension;

    std::priority_queue<int, std::vector<int>, std::greater<>> PriorityQueue;
    for (int i = 0; i < Dimension * Dimension; i++)
    {
        int Entry;
        std::cin >> Entry;
        PriorityQueue.push(Entry);

        while (PriorityQueue.size() > Dimension)
        {
            PriorityQueue.pop();
        }
    }

    std::cout << PriorityQueue.top() << std::endl;
}
