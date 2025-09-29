#include "app.h"
#include <iostream>
#include <iomanip>
#include <limits>

int main() 
{
    App app;
    std::string command;

    while (true) 
    {
        std::cout << "Ange kommando: ";
        std::getline(std::cin, command);

        if(command == "q") 
        {
            std::cout << "Avslutar programmet...\n";
            break;
        }
        else if(command == "add-player")
        {
            std::string name;
            unsigned int rating = 0;

            std::cout << "Ange namn: ";
            std::getline(std::cin, name);   // <-- ingen ignore här

            std::cout << "Ange elo-tal: ";
            std::cin >> rating;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            // ^ rensa resten av raden så nästa getline fungerar

            app.addPlayer(ChessPlayer(name, rating));
        }
        else if(command == "compute")
        {
            auto results = app.getNormsPoints();

            std::cout << std::fixed << std::setprecision(2);
            for (const auto &res : results) 
            {
                std::cout << res.name << ": IM = " << res.imPoints
                          << ", GM = " << res.gmPoints << " poäng\n";
            }
        }
    }
    
    return 0;
}


