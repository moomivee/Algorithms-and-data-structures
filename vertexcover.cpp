#include <iostream>
#include <vector>
#include <algorithm>

using Int = unsigned int;

void Creategraph(std::vector<std::vector<int>>& graph, int vertices)
{
    int deg, child;
    for (int i = 0; i < vertices; i++) 
    {
        std:: cin >> deg;
        for (int j = 0; j < deg; j++) 
            {
                std::cin >> child;
                graph[i].push_back(child);
            }
    }
}

Int bestSum(std::vector<std::vector<int>>& graph,
            std::vector<std::vector<int>>& vector, 
            Int root, bool min = false) 
{
    Int s = 0;
    for(Int i = 0; i < graph[root].size(); ++i) 
    {
        int leef = graph[root][i];
        if(min) 
        {
            s += std::min(vector[leef][0], vector[leef][1]);
            continue;
        }
        s += vector[leef][1];
    }
    return s;
}

std::pair<int, int> vertexCoverDP(std::vector<std::vector<int>>& graph,
                                  std::vector<std::vector<int>>& best, 
                                  int root, Int n, std::vector<bool>& visited) 
{
    if(visited[root]) 
        return std::make_pair(0, 0);
    
    visited[root] = true;
    for(Int i = 0; i < graph[root].size(); ++i) 
    {
        int leef = graph[root][i];

        std::pair<int, int> optionalSol = vertexCoverDP(graph, best, leef, n, visited);

        best[leef][0] = optionalSol.first;
        best[leef][1] = optionalSol.second;
    }

    Int withRoot = 1 + bestSum(graph, best, root, true);
    Int withOutRoot = bestSum(graph, best, root);

    return std::make_pair(withOutRoot, withRoot);
}

int main()
{
    Int vertices; 
    int fin = 0;
    std::pair<int, int> result;
    std::cin >> vertices;
    std::vector<int> tmp;
    std::vector<std::vector<int>> graph(vertices, tmp);
    Creategraph(graph, vertices);
    std::vector<int> dynVec (2, 0);
    std::vector<std::vector<int>> best (vertices, dynVec);
    std::vector<bool> visited (vertices, false);
    for( Int i = 0; i < vertices; ++i) 
    {
        result = vertexCoverDP(graph, best, i, vertices, visited);
        fin += std::min(result.first, result.second);
    }
    std::cout << fin;
    return 0;
}
