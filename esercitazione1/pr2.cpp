#include <fstream>
#include <iostream>
#include <string>


int main(int argc, const char *argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Errore: il nome del file deve essere indicato." << "\n";
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open()) 
    {
        std::cerr << "Errore: impossibile aprire correttamente il file indicato" << "\n";
        return 1;
    }

    std::string città;
    double t1, t2, t3, t4;

    while (file >> città >> t1 >> t2 >> t3 >> t4) 
    {
        double media = (t1 + t2 + t3 + t4) / 4.0;
        std::cout << città << " " << media << "\n";
    }

    return 0;
}

// è stata impiegata l'intelligenza artificiale per capire come costruire alcune parti
// del codice non chiare a causa di una prolungata e indesiderata assenza dalle lezioni e 
// a una chiarezza ritenuta scarsa delle slides, a causa del livello di partenza del sottoscritto
// davvero estremamente basso. esempi : riga 15, riga 17, riga 26, riga 29. Le informazioni 
// suggerite, una volta comprese, sono state poi riformulate da zero.