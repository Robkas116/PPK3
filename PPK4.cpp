#include<iostream>
#include<vector>
void p1(){
     const int size = 10;
    int tab[size] = { 0 };
    int n;
    std::cout<<"n = ";
    std::cin>> n;
    for (int i = 0; i<n; ++i){
        std::cout<< i << "tab[" << i << "]" <<std::endl;
        std::cin>>tab[i];
    }

    for (int i = 0; i<n; ++i){
        std::cout<< i << tab[i] <<std::endl;
    }

}

void p2() {
    int n;
    std::cout<<"n = ";
    std::cin>> n;
    
    int* tab = nullptr; //wskaźnik (wizytowka), ta zmienna bedzie przechowywala adres na zmienna typu intiger
//nullptr oznacza ze dla komorki o wartosci 0 nie ma przypsanej wartosci
    tab = new int[n];
    for (int i = 0; i<n; ++i){
        std::cout<< i << "tab[" << i << "]" <<std::endl;
        std::cin>>tab[i];
    }

    for (int i = 0; i<n; ++i){
        std::cout<< i << tab[i] <<std::endl;
    }
    delete[] tab;
}

void p3(){
    int n;
    std::cout<<"n = ";
    std::cin>> n;
    
    std::vector<int> tab(n);

    for (int i = 0; i<n; ++i){
        std::cout<< i << "tab[" << i << "]" <<std::endl;
        std::cin>>tab[i];
    }

    for (int i = 0; i<n; ++i){
        std::cout<< i << tab[i] <<std::endl;
    }

    for (const auto el : tab){
        std::cout << el << std::endl; //zawsze wyswietli wszystkie elementy tablicy
    }

    for(auto it = tab.begin(); it != tab.end(); ++it){
        std::cout << *it << std::endl;
    }
}


void p4() {
    const int rows = 4;
    const int columns = 4;
    double tab[rows][columns] = {{1, 2}, {3, 4, 5}};
    int r,c;
    std::cout<< " rows = ";
    std::cin >> r;

    std::cout << "columns = ";
    std::cin>> c;

    for (int i = 0; i<r; ++i){
        for(int j = 0; j<c; ++j){
            std::cout << "m[" << i + 1 << "][" << j+1 << "] = ";
            std::cin >> tab[i][j];
        }
    }
/*
    for (int i = 0; i<r; ++i){
        for(int j = 0; j<c; ++j){
            std::cout << m[i][j];
            }
    }

*/


}

void p5(){
    int r,c;
    std::cout<< " rows = ";
    std::cin >> r;

    std::cout << "columns = ";
    std::cin>> c;
    double **m = new double*[r];
    for(int i = 0; i<r; ++i){
        m[i] = new double[c];
    }

    
    for (int i = 0; i<r; ++i){
        for(int j = 0; j<c; ++j){
            std::cout << "m[" << i + 1 << "][" << j+1 << "] = ";
            std::cin >> m[i][j];
        }
    }

    for (int i = 0; i<r; ++i){
        for(int j = 0; j<c; ++j){
            std::cout << m[i][j] << "\t";
            }
    }
    for(int i = 0; i<r; ++i){
        delete[] m[i];
    }
    delete[] m;

}
void p6(){
    int r,c;
    std::cout<< " rows = ";
    std::cin >> r;

    std::cout << "columns = ";
    std::cin>> c;

    std::vector<std::vector<double>> m(r, std::vector<double>(c));
    
    for (int i = 0; i<r; ++i){
        for(int j = 0; j<c; ++j){
            std::cout << "m[" << i + 1 << "][" << j+1 << "] = ";
            std::cin >> m[i][j];
        }
    }

    for (int i = 0; i<r; ++i){
        for(int j = 0; j<c; ++j){
            std::cout << m[i][j] << "\t";
            }
    }
    
    for (const auto& row : m){
        for(const auto el : row){
            std::cout << el << "\t";
            }
    }
    



}

void zad1(){
    int min, max;
    int imin, imax;
    int n;
    std::cout << "n= ";
    std::cin>> n;

    std::vector<int> tab(n);

    for(int i = 0; i<n; ++i){
        std::cout<< "tab[" << i << "] = ";
        std::cin>>tab[i];
    }
    for(int i = 0; i<n; ++i){
        if (tab[i] < min){
            min = tab[i];
            imin = i;
        }
        if(tab[i] > max){
            max = tab[i];
            imax = i;
        }
    }
    std::cout << "min = " << min << " indeks: " << imin << std::endl;
    std::cout << "max = " << max << " indeks: " << imax << std::endl;
}

void zad2(){
    float w, k;
    float min, max;
    float iminx, iminy, imaxx, imaxy;
    std::cout << "Liczba wierszy: ";
    std::cin>> w;

    std::cout<< "Liczba kolumn: ";
    std::cin>> k;

    std::vector<std::vector<double>> macierz(w, std::vector<double>(k));

    for(int i=0; i<w; ++i){
        for(int j = 0; j<k; ++j){
        std::cout << "macierz[" << i+1 << "][" << j+1 << "] = ";
        std::cin >> macierz[i][j];
        }
    }
      for (const auto& row : macierz){
        for(const auto el : row){
            std::cout << el << "\t";
            }
        std::cout << std::endl;
    }
   
    for (int i = 0; i<w; ++i){
        for(int j = 0; j<k; ++j){
            if (macierz[i][j]<min){
                min = macierz[i][j];
                iminx = i;
                iminy = j;
            }
            if (macierz[i][j]>max){
                max = macierz[i][j];
                imaxx = i;
                imaxy = j;
            }
            
            }
    }
    std::cout<< "max = " << max << " [" << imaxx << "," << imaxy << "]" << std::endl;
    std::cout << "min = " << min << "[" << iminx << "," << iminy << "]" << std::endl;
    
    

}




int main () {
   //p1();
   //p2();
   //p3();
    zad2();








}