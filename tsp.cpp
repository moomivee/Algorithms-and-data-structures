#include <iostream> 
#include <vector>
#include <climits>
#include <algorithm>
 

void tsp(std::vector <std::vector <int>> graph, std::vector<bool>& v,
         int current_position, int cities, int count, int cost, int &answer) 
{ 

	if ((count == cities) && (graph[current_position][0]) )
	{ 
	    answer = std::min(answer, cost + graph[current_position][0]);
		return; 
	} 

	for (int i = 0; i < cities; i++) 
    { 
		if ((!v[i]) && (graph[current_position][i]))
        { 
			v[i] = true; 
			tsp(graph, v, i, cities, count + 1, cost + graph[current_position][i], answer); 
			v[i] = false; 
		} 
	} 
}; 


int main() 
{ 
    int cities; 
    int answer = INT_MAX;
    std::vector<bool> v(cities);
    std::cin >> cities;

    std::vector <std::vector <int> > graph (cities, std::vector<int> (cities)); // creation of vector for cities lines with cities elements in each 

    for (int i = 0; i < cities; i++) // cycle for lines 
    {
        for (int j = 0; j < cities; j++) // cycle for elements 
            {
                std::cin >> graph[i][j];
            }
    }
    

	for (int i = 0; i < cities; i++)
    {
        v[i] = false; 
    } 
	v[0] = true; 
	

	tsp(graph, v, 0, cities, 1, 0, answer); 
	
    if( cities == 1 )
	{
	    std::cout << 0;
	}
    else if(answer == INT_MAX )
    {
        std::cout << -1;
    }
    else
    {
        std::cout << answer;
    }
	return 0; 
} 