#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int PokemonCount, ProblemCount;
    std::cin >> PokemonCount >> ProblemCount;

    std::unordered_map<std::string, int> NameToNumberMap;
    std::unordered_map<int, std::string> NumberToNameMap;

    for (int i = 0; i < PokemonCount; i++)
    {
        std::string PokemonName;
        std::cin >> PokemonName;
        
        const int Number = i + 1;
        NameToNumberMap[PokemonName] = Number;
        NumberToNameMap[Number] = PokemonName;
    }
    
    for (int i = 0; i < ProblemCount; i++)
    {
        std::string Problem;
        std::cin >> Problem;

        if (std::isdigit(Problem[0]))
        {
            std::cout << NumberToNameMap[std::stoi(Problem)] << "\n";
        }
        else
        {
            std::cout << NameToNumberMap[Problem] << "\n";
        }
    }
}
