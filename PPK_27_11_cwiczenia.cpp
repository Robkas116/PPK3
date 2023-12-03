#include<iostream>
#include<string>
#include<fstream>
#include<fstream>
#include<map>
#include<iomanip>
#include<algorithm>

std::map<std::pair<std::string, std::string>, int> Histogram2(const std::string &fileName){
    std::map<std::pair<std::string, std::string>, int> h;
    std::ifstream in(fileName);
    if (in){
        std::pair<std::string, std::string> words;
        std::string word;
        std::string slowo;
        for(int i = 0; i<2; i++){
            if(i){
                if(in >> word){
                    words.first = word;
                    word.erase(word.begin(), word.end());
                }
            }
            else {
                if(in >> word){
                    words.second = word;
                    slowo = word;
                    word.erase(word.begin(), word.end());
                }
            }
        }
        ++h[words];
        
        while(in >> word){
            words.first = slowo;
            words.second = word;
            ++h[words];
            slowo = words.second;

        }
        in.close();
    }
    return h;
}

void Show(std::map<std::pair<std::string, std::string>, int>& h){
    for(const auto& el : h){
        std::cout << std::setw(30) << el.first.first << " " << el.first.second << " | " << el.second << std::endl;
    }
}



std::map<std::pair<std::string, std::string>, int> Histogram3(const std::string &fileName){
    std::map<std::pair<std::string, std::string>, int> h;
    std::ifstream in(fileName);
    if (in){
        std::pair<std::string, std::string> words;
        std::string word, word2;
            if(in >> word){
                words.first = word;
                word.erase(word.begin(), word.end());
             }
        while(in >> word){
            word2 = word;
            ++h[{word, word2}];
            word = word2;
        }
        in.close();
    }
    return h;
}







int main() {
auto h = Histogram2("Lorem_ipsum.txt");
Show(h);
}