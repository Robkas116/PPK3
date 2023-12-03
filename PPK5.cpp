#include <iostream>
#include <string>
#include<vector>
#include<cmath>
//Podprogramy

int GetSize(const std::string& text){
    int n;
    do {
        std::cout << text;
        std::cin >> n;
    } while (n < 1);
    return n;
}


std::vector<std::vector<double>> CreateMatrix(const size_t rows, const size_t cols){
    
    std::vector<std::vector<double>> m(rows, std::vector<double>(cols));
    return m;
}

void Show(std::vector<std::vector<double>>& matrix){
    for(const auto& row : matrix){
        for(const auto& el : row){
            std::cout<<el<<"\t";
        }
        std::cout<< std::endl;
    }
}


double Add(const double x, const double y);
void Swap(double x, double y);
void Swap1(double* x, double* y);
void Swap2(double& x, double& y);

double NWP(double x, double y){
    
    while(x!=y)
       if(x>y)
           x-=y; 
       else
           y-=x; 
    return x; 
}
double NWPR(double x, double y){
    if (x = y) return x;
    if(x>y)
        NWPR(x-y,y); 
    else
        NWPR(x,y-x);
}

double calkowanie(double a, double b, long double min, long double max, double n) {
    double ysin;
    double xsin = (max-min)/n;
    double suma = 0;
    for(int i = 0; i<n; i++){
        ysin = a*sin(i*xsin)+b;
        suma += xsin*ysin;
    }
    return suma;
}








int main(){
    /*
    int lw = GetSize(" n = ");
    int lk = GetSize(" m = ");
    auto m = CreateMatrix(lw,lk); //przekazywanie parametrów przez wartość
    Show(m); */

   // double a=13.0, b = 17;
    /*
    Swap(a,b);
    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;
    
    Swap1(&a, &b);
    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;
    
    std::cout << "Silnia(5) = " << Silnia(5) << std::endl;
    std::cout << "Silnia(5) = " << SilniaR(5) <<std::endl;
*/

/*
    double a,b,c;
    std::cout <<"a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
    std::cout << "Najwiekszy podzielnik a i b to: " << NWP(a,b) << std::endl;;
    std::cout << "Najwiekszy podzielnik a,b,c: " << NWP(NWP(a,b), c);
*/

    std::cout << calkowanie(2,0,0,2*M_PI,1000000) << std::endl;
}

int Silnia(const int n) {
    int result = 1;
    for(int i = 2; i<=n; i++){
        result *= i;
    }
}

int SilniaR(const int n) {
    if(n<2)
        return 1;
    return n * SilniaR(n-1);
    //return n < 2 ? 1 : n * SilniaR(n-1)
}





double Add(const double x, const double y) {
    return x+y;
}


void Swap1(double* x, double* y){
    double buff = *x;
    *x = *y;                            
    *y = buff;
}


void Swap(double x, double y){
    double buff = x;                        //nie dziala, nie zamienia a i b
    x = y;
    y = buff;
}

void Swap2(double& x, double& y){
    double buff = x;
    x = y;
    y = buff;
}




