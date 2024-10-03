#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <optional>


class FKongNetwork
{
public:
    void AddConnectionById(int Switch0, int Switch1, int Cost)
    {
        SwitchConnections[Switch0].push_back({Switch1, Cost});
        SwitchConnections[Switch1].push_back({Switch0, Cost});
    }
    
    struct FSearchResult
    {
        int Cost;
        std::vector<std::tuple<int, int>> Connections;
    };
    
    FSearchResult FindShortestRoute() const
    {
        FSearchResult Ret;
        
        std::vector<int> Path;
        Ret.Cost = *FindShortestRouteImpl(0, Path);
        
        for (int i = 0; i < Path.size() - 1; i++)
        {
            Ret.Connections.push_back(std::make_tuple(Path[i], Path[i + 1]));
        }
        
        return Ret;
    }
    
private:
    struct FConnection
    {
        int To;
        int Cost;
    };
    
    std::map<int, std::vector<FConnection>> SwitchConnections;
    
    std::optional<int> FindShortestRouteImpl(int FromHere, std::vector<int>& Path) const
    {
        Path.push_back(FromHere);
        
        if (Path.size() >= SwitchConnections.size())
        {
            return 0;
        }
        
        std::optional<int> Cost;
        std::vector<int> OutPath;
        for (const FConnection& Each : SwitchConnections.at(FromHere))
        {
            if (std::find(Path.begin(), Path.end(), Each.To) != Path.end())
            {
                continue;
            }
            
            auto PathCopy = Path;
            if (const auto SubRouteCost = FindShortestRouteImpl(Each.To, PathCopy))
            {
                const int ThisCost = Each.Cost + *SubRouteCost;
                std::cout << ThisCost << std::endl;
                if (!Cost || ThisCost < *Cost)
                {
                    Cost = ThisCost;
                    OutPath = std::move(PathCopy);
                }
            }
        }
        
        Path = std::move(OutPath);
        return Cost;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int SwitchCount, ConnectionCount;
    std::cin >> SwitchCount >> ConnectionCount;

    FKongNetwork KongNetwork;
    for (int i = 0; i < ConnectionCount; i++)
    {
        int From, To, Cost;
        std::cin >> From >> To >> Cost;
        KongNetwork.AddConnectionById(From, To, Cost);
    }

    const FKongNetwork::FSearchResult ShortestRoute = KongNetwork.FindShortestRoute();
    std::cout << ShortestRoute.Cost << std::endl;
    for (const auto [FromId, ToId] : ShortestRoute.Connections)
    {
        std::cout << FromId << " " << ToId << std::endl;
    }

    return 0;
}
