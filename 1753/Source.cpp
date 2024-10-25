#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int VertexCount, EdgeCount, FirstVertex;
    std::cin >> VertexCount >> EdgeCount >> FirstVertex;

    std::vector<std::vector<std::pair<int, int>>> Neighbors(VertexCount + 1);
    for (int i = 0; i < EdgeCount; ++i)
    {
        int From, To, Weight;
        std::cin >> From >> To >> Weight;
        Neighbors[From].emplace_back(Weight, To);
    }

    std::vector<int> Distances(VertexCount + 1, std::numeric_limits<int>::max());
    Distances[FirstVertex] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> NextVisit;
    NextVisit.emplace(0, FirstVertex);

    std::vector<bool> Visited(VertexCount + 1);

    while (!NextVisit.empty())
    {
        const auto [DistToThisVertex, ThisVertex] = NextVisit.top();
        NextVisit.pop();

        if (Visited[ThisVertex])
        {
            continue;
        }

        Visited[ThisVertex] = true;

        for (const auto [DistToThisNeighbor, Neighbor] : Neighbors[ThisVertex])
        {
            const int NewDistanceToNeighbor = DistToThisVertex + DistToThisNeighbor;
            if (NewDistanceToNeighbor < Distances[Neighbor])
            {
                Distances[Neighbor] = NewDistanceToNeighbor;

                if (!Visited[Neighbor])
                {
                    NextVisit.emplace(NewDistanceToNeighbor, Neighbor);
                }
            }
        }
    }

    std::for_each(Distances.begin() + 1, Distances.end(), [](int Each)
    {
        if (Each == std::numeric_limits<int>::max())
        {
            std::cout << "INF" << '\n';
        }
        else
        {
            std::cout << Each << '\n';
        }
    });
}
