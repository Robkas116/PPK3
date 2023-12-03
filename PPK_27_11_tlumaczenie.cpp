#include<iostream>
#include<string>
#include<fstream>
#include<fstream>
#include<map>
#include<iomanip>
#include<algorithm>

//KONTENER ASOCJACYJNY -> MAPA

std::map<std::string, int> Histogram(const std::string &fileName)
{
    std::map<std::string, int> h;
    std::ifstream in(fileName);
    if(in){
        std::string word;
        while(in >> word) {
            //usuwanie rozdzielności kropek i przecinków
            auto it = std::remove_if(word.begin(), word.end(), [](const unsigned char c) {return !std::isalpha(c);});
            word.erase(it, word.end());
            ++h[word];
        }
        in.close();
    }
    return h;
}


std::map<std::string, int> Histogram2(const std::string &fileName)
{
    std::map<std::pair<std::string, std::string>, int> h;
    std::ifstream in(fileName);
    if(in){
        std::string word, word2;
        while(in >> word) {
            //usuwanie rozdzielności kropek i przecinków
            auto it = std::remove_if(word.begin(), word.end(), [](const unsigned char c) {return !std::isalpha(c);});
            word.erase(it, word.end());
            ++h[{word2, word}];
            word2 = word;
        }
        in.close();
    }
    return h;
}






void Show(std::map<std::string, int>& h){
    for(const auto& el : h){
        std::cout << std::setw(15) << el.first << " | " << el.second << std::endl;
    }
}


int main()
{
    
auto h = Histogram("Lorem_ipsum.txt");
Show(h);
std::cout << std::endl;


}
