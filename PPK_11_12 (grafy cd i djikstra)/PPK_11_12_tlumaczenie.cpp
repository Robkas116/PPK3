#include <iostream>
#include<string>
#include<map>
#include<set>
#include<list>
#include<fstream>
#include<sstream>
enum class Color {
    Black,
    Red,
};


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


void dfs(const Graph& graph, const std::string& node, std::set<std::string>& nodes) {
    if(nodes.count(node) == 0) {
        nodes.insert(node); //bierzemy wezel sprawdzamy czy jest w rozwiazaniu i sprawdzamy z jakimi wezlami jest polaczony i leci dalej
        for(const auto& el : graph.at(node)) {
            dfs(graph, el.first, nodes);
        }
        
            }
}



std::map<std::string, Color> GraphColoringBfs(const Graph& graph, const std::string& node) {
    if(graph.find(node) == graph.end()) return {};
    std::map<std::string, Color> result { {node, Color::Black} };
    std::list<std::string> nodes { node };
    while(nodes.size()) {
        for(const auto& el : graph.at(nodes.front())) {
            if(result.count(el.first) == 0) {
                result[el.first] = result[nodes.front()] == Color::Black ? Color::Red : Color::Black;
                nodes.push_back(el.first);
            }                            //el to para - wezel i dystans
        }
        nodes.pop_front();
    }
    return result;
}


//sprawdzanie czy graf jest dwudzielny
bool GraphColoringBfs_check(const Graph& graph, const std::string& node) {
    if(graph.find(node) == graph.end()) return {};
    std::map<std::string, Color> result { {node, Color::Black} };
    std::list<std::string> nodes { node };
    bool prawda = true;
    while(nodes.size()) {
        for(const auto& el : graph.at(nodes.front())) {
            if(result.count(el.first) == 0) {
                result[el.first] = result[nodes.front()] == Color::Black ? Color::Red : Color::Black;
                
            }                            //el to para - wezel i dystans
            if(result[nodes.front()] == Color::Black) {
                if(result[nodes.front()] == Color::Black)
                    continue;
                else
                    prawda = false;
                    break;
            }
            else if (result[nodes.front()] == Color::Red) {
                if(result[nodes.front()] == Color::Red)
                    continue;
                else
                    prawda = false;
                    break;
            }
            nodes.push_back(el.first);
            
            
        }
        nodes.pop_front();
    }
    return prawda;
}




std::set<std::string> Dfs(const Graph& graph, const std::string& node){
    if(graph.find(node) == graph.end()) return {};
    std::set<std::string> nodes;
    dfs(graph, node, nodes);
}
int main() {
    auto graph = LoadFromFile("graph.txt");
    //auto dfs = Dfs(graph, "A");
    auto color = GraphColoringBfs(graph, "A");
    if(GraphColoringBfs_check){
        std::cout << "jest dwudzielny.";
    }
    else 
        std::cout << "Nie jest dwudzielny.";
}