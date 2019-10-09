#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int pazymiuSkaicius, pazymys, pazymiuKiekis = 0, pazymiuSuma = 0, maziausias = 10, didziausias = 0;
    float pazymiuVidurkis;

    ifstream read ("pazymiai.txt");
    ofstream write ("rez.txt");
    read >> pazymiuSkaicius;

    for(int i = 0; i < pazymiuSkaicius; i++) {
        read >> pazymys;
        if (pazymys >=0 && pazymys <= 10) {
            write << pazymys << " ";
            pazymiuSuma += pazymys;
            pazymiuKiekis++;
            pazymiuVidurkis = float(pazymiuSuma) / float(pazymiuKiekis);

            if(pazymys > didziausias) {
                didziausias = pazymys;
            } else if (pazymys < maziausias){
                maziausias = pazymys;
            }
        }
    }

    write << "\n";
    write << "Vidurkis: " << pazymiuVidurkis << "\n";
    write << "Didziausias pazymys: " << didziausias << "\n";
    write << "Maziausias pazymys: " << maziausias << "\n";

    read.close();
    write.close();
    return 0;
}
