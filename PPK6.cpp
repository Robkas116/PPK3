#include <iostream>
#include <string>
#include <vector>



//struktury danych służą do przechowywania danych
struct PersonalData {
    std::string firstName;
    std::string lastName;
    int age;
};

void Show(const PersonalData& pd) { //referencje
    std::cout << "Imie " << pd.firstName << std::endl;
    std::cout << "Nazwisko " << pd.lastName << std::endl;
    std::cout << "Wiek " << pd.age << std::endl;   
}

void Show1(const PersonalData* const pd){ //ani jedno ani drugie nie moze byc modyfikowane
    std::cout << "Imie " << pd->firstName << std::endl;
    std::cout << "Nazwisko " << pd->lastName << std::endl;
    std::cout << "Wiek " << pd->age << std::endl; // "." to operator dostępu bezposredniego, a strzałka przekazuje adres z jakiego nalezy zczytać wartość
 //   std::cout << "Imie " << (*pd).age << std::endl; 
}
/*
PersonalData Read(PersonalData& dp) { 
    std::cout << "Imie: ";
    std::cin >> dp.firstName;
    std::cout << "Nazwisko: ";
    std::cin >> dp.lastName;
    std::cout << "Wiek: ";
    std::cin >> dp.age;
    return dp;
}
*/
PersonalData Read(){
    PersonalData pd;
    std::cout << "Imie: ";
    std::cin >> pd.firstName;
    std::cout << "Nazwisko: ";
    std::cin >> pd.lastName;
    std::cout << "Wiek: ";
    std::cin >> pd.age;
    return pd;
}

void Show(const std::vector<PersonalData>& v){
    for(const auto &el : v){
        Show(el);
        std::cout << std::endl;
    }
}

std::vector<PersonalData> Read(const int size){
    std::vector<PersonalData> v(size);

    for(int i = 0; i < size; i++){
        v[i] = Read();
        //pd = Read();
        //v.push_back(pd);
        std::cout << std::endl;
    }
    return v;
}



int main() {
    //PersonalData pd;
    PersonalData pd {"Jan", "Kowalski", 12};
    //pd.firstName = "Jan";
    //pd.lastName = "Kowalski";
    //pd.age = 40;
    std::cout << "---------------------------" << std::endl;
    //Show(pd);
    //std::cout << std::endl;
  //  Show1(&pd);
    
    std::vector<PersonalData> pds = Read(2);
    Show(pds);




















}