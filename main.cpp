#include "app.h"
#include <iostream>
#include <iomanip>

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
            std::string name = "";
            unsigned int rating = 0;

            std::cout << "Ange namn:";
            std::cin >> name;
            std::cout << "Ange elo-tal:";
            std::cin >> rating;

            app.addPlayer(ChessPlayer (name, rating));

        }
        
        // Här kan du lägga till logik för olika kommandon
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


