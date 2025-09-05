#include "app.h"
#include <cmath>

App::App()
{

}

void App::addPlayer(const ChessPlayer &player)
{
    players.push_back(ChessPlayer(player.getName(), player.getRating()));
}

double App::getExpectedPoint(const unsigned int &r1, const unsigned int &r2)
{
    // Förväntad poäng för spelare 1 (med rating r1)
    return 1.0 / (1.0 + std::pow(10.0, static_cast<double>(r2 - r1) / 400.0));
}

std::vector<NormResult> App::getNormsPoints() const
{
    const double IM_NORM = 2450.0;
    const double GM_NORM = 2600.0;

    std::vector<NormResult> results;
    int totalPlayers = players.size();

    for (size_t i = 0; i < players.size(); ++i) 
    {
        // Beräkna snittrating för motståndarna (alla utom denna spelare)
        unsigned int totalRating = 0;
        for (size_t j = 0; j < players.size(); ++j) 
        {
            if (i != j) 
            {
                totalRating += players[j].getRating();
            }
        }

        int rounds = totalPlayers - 1;
        double avgRating = static_cast<double>(totalRating) / rounds;

        auto calcPoints = [&](double normRating) 
        {
            return 0.5 * rounds + ((normRating - avgRating) * rounds) / 800.0;
        };

        results.push_back
        ({
            players[i].getName(),
            calcPoints(IM_NORM),
            calcPoints(GM_NORM)
        });
    }

    return results;
}
