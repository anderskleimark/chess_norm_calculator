#include "app.h"

App::App()
{

}

void App::addPlayer(const std::string &name, const unsigned int &rating)
{
    players[name] = rating;
}

double App::expectedPoints(const unsigned int &r1, const unsigned int &r2)
{
    // Förväntad poäng för spelare 1 (med rating r1)
    return 1.0 / (1.0 + std::pow(10.0, static_cast<double>(r2 - r1) / 400.0));
}

