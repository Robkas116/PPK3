#include<iostream>
#include<string>
#include<map>
#include<set>
#include<list>
#include<fstream>
#include<sstream>

//grafy
//mozna zapisac w postaci macierzy sasiedztwa i jesli sa polaczone to jest wartosc miedzy nimi czyli
//odleglosc miedzy wezlami poszczegolnymi
//mozna uzyc mapy - struktura zawierajaca nazwe wezla z kim sie łączy + wartość 

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
//przeszukiwanie wszerz patryzmy na sasiedztwo węzła wybranego, daje informacje o spójności
//patrzy sie na sasiadow i dodaje sie do tymczasowych sprawdzonych wezlow, pozniej dokładnie po kolei
//pokazuje to które wezły moga byc polaczone ze soba lub nie

//wgłąb to skakanie po następnymch węzłach, które mają najbliżej do początku, ignoruje się już przetworzone
//bardzo dobrze się sprawdzi algorytm rekurencyjny do tego


//algorytm przeszukiwania wszerz
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


int main() {
    auto graph = LoadFromFile("graph.txt");
    auto bfs = BFS(graph, "A");
    if(graph.size() == bfs.size())
        std::cout << "Graf jest spójny";
}