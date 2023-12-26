#include<iostream>
#include<string>
#include<map>
#include<set>
#include<list>
#include<fstream>
#include<sstream>
#include<vector>


typedef std::map<std::string, 
    std::set<std::pair<std::string, double>>> Graph;

struct wezel {
    std::string nazwa;
    bool odwiedzone = 0;
    double dystans;
    std::vector<wezel> sasiedzi;
};

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



std::set<std::string> BFS(const Graph& graph, const std::string& node) {
    if(graph.find(node) == graph.end()) return {};
    std::set<std::string> result { node };
    std::list<std::string> nodes { node };
    while(nodes.size()) {
        for(const auto& el : graph.at(nodes.front())) {
            if(result.count(el.first) == 0) {
                result.insert(el.first);
                nodes.push_back(el.first);
            }                            //el to para - wezel i dystans
        }
        nodes.pop_front();
    }
    return result;
}
