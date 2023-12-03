#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>

typedef std::vector<double> Vector;
typedef std::vector<std::vector<std::string>> Matrix;

Matrix tlumaczenie(const std::string& fileName, std::string slowo){
    Matrix m;
    std::ifstream in(fileName);
    //std::cout << "Podaj słowo do przetluamczenia: ";
    //std::cin >> y;
    if(in) {
        std::string line;
        while(std::getline(in, line)){
            //m.push_back(Vector());
            std::stringstream ss(line);
            std::string x;
            //while(std::getline(ss, x, ' ')){
              //  m.back().push_back(std::stod(x));
            //    if(x == slowo){
              //      std::cout << x;
                //}
           /* }
        for(int i = 0; i<4; i++){
           // if(m[0][i]==y)
                std::cout << m[1][i];

        } */
        }
        in.close();
        
    }
    return m;
    
}

void Show(const Matrix& m) {
    for(const auto& row : m){
        for(const auto el: row) {
            std::cout << el << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    tlumaczenie("slownik.txt", "pies");
    Show(tlumaczenie("slownik.txt", "pies"));
}