#include <iostream>
#include<string>
#include<map>
#include<set>
#include<list>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<limits>
#include <algorithm>
//znajduje najkrotsza droge miedzy wezlami
//przypisuje sie odległosci do nieskonczonosci
//leci sie po kolei z wezlow 


typedef std::map<std::string, 
    std::set<std::pair<std::string, double>>> Graph;
//odczytywanie grafu z pliku

Graph LoadFromFile(const std::string& fileName) {
    std::ifstream in(fileName);
    Graph graph;
    std::string line;
    if(in) {
        while(std::getline(in, line)) {
            std::stringstream ss(line);
            std::string node1, node2; //wezly 1 i 2
            double lenght;
            if(!(ss >> node1)) continue;
            if(!(ss >> node2)) continue;
            if(!(ss >> lenght)) continue;
            graph[node1].insert({node2, lenght});
            graph[node2].insert({node1, lenght});
        }
        in.close();
    }
    return graph;
}








std::map<std::string, double> Dijkstra(const Graph graph, const std::string node){
    std::map<std::string, double> result;
    for(const auto& el : graph) result[el.first] = std::numeric_limits<double>::infinity();
    if(graph.find(node) == graph.end()) return result;
    std::set<std::string> nodes;
    result[node] = 0.0;
    while(true) {
        for(const auto& el : graph.at(node)) {
            if(result[el.first] > result[node] + el.second) {
                result[el.first] = result[node] + el.second;
                nodes.insert(el.first);
            }
        }
        if(nodes.empty()) break;
        node = *std::min_element(nodes.begin(), nodes.end(), 
            [&result](const auto& l, const auto& r) {return result[l] < result[r];});
        nodes.erase(node);
    }
    return result; 
}

void Show(const std::map<std::string, double>& d){
    for(const auto& el : d) {
        std::cout << std::setw(10) << el.first << " | " << el.second << std::endl;
    }
}











int main() {
   auto graph = LoadFromFile("graph.txt");
   Show(Dijkstra(graph, "A"));

}