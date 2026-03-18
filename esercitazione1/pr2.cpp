#include <fstream>
#include <iostream>
#include <string>

using namespace std

int main(int argc, const char *argv[]) 
{
    if (argc < 2) 
    {
        cerr << "Errore: il nome del file deve essere indicato." << "\n";
        return 1;
    }

    ifstream file(argv[1]);

    if (!file.is_open()) 
    {
        cerr << "Errore: impossibile aprire correttamente il file indicato" << "\n";
        return 1;
    }

    string città;
    double t1, t2, t3, t4;

    while (file >> città >> t1 >> t2 >> t3 >> t4) 
    {
        double media = (t1 + t2 + t3 + t4) / 4.0;
        cout << città << " " << media << "\n";
    }

    return 0;
}