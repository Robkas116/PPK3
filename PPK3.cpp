#include <iostream>
#include <conio.h>

int main () 
{


/*    int n;
    do{
        std:: cout << "n: "; //wyliczanie ile zajmuje dana linijka czasu do wykonania
        std::cin >> n;


    } while (n<1);





    for (int i = -10 ; i<11 ; i++) 
    {
    std::cout << i << std::endl; // i++ inkrementacja po uzyciu zmiennej
                                    ++i inkrementacja przed uzyciem zmiennej
    }


    int i = -10;
    while (i<11) {
        std::cout << i << std::endl;
        i++;

    }
*/

/*
    do {

//zawsze wykona sie przynajmniej raz


    } while ();


    int n;
    std::cin >> n;
    for (int i = -n; i<=n; i++){
        if (i==0) continue;  //mozna uzyc break ale wtedy if sie wyrzuca
        std::cout << 1.0/i << std::endl;
    }


    int i = 13;
    std::cout << "i = " << ++i << std::endl; //preinkrementacja
    std::cout << "i = " << i++ << std::endl; //przeciwienstwo inkrementacji to dekrementacja
    std::cout << "i = " << i << std::endl;

    int x = ++i; //i= i+1 , x=i
    int y = i++; //y = i, i = i + 1

    int z = i++ + i++;
*/
/*
//wartosc srednia z kilku ocen wprowadzonych przez uzytkownika ich suma i wartosci najweiksze i najmniejsze
double sum = 0, d, min = 1, max = 1;
for(int i = 0; i<n; ++i){
    std::cout << "ocena = ";
    std::cin >> d;
    if (d == 0) break;
    min = d < min ? d : min;
    max = d > max ? d : max;
    sum += d;
}
std::cout << "średnia = " << sum / n << std::endl;
std::cout << "Najwieksza ocena to " << max << std::endl;
std::cout << "Najmniejsza ocena to " << min << std::endl;
*/



//wylapywanie samoglosek z ciagu znakow

int getch (void);
unsigned char znak;
std::cout << "Podaj znak (Jesli wprowadzisz q lub Q to program sie skonczy): ";
std::cin >> znak;
do {
    znak = getch();
    std::cout << "znak: " << znak << " kod: " << static_cast < int >(znak) << std::endl;
    znak = static_cast < int >(znak);
    std::cout << znak << std::endl;
} while (znak != 81 or 113);













}