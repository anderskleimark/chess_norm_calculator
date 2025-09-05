#ifndef APP_H 
#define APP_H

#include <vector>
#include <string>

class ChessPlayer
{
    private:
        const std::string name;
        const unsigned int rating;

    public:
        ChessPlayer(const std::string &name, const unsigned int &rating):
            name(name), rating(rating) {}
        std::string getName() const {return name; }
        unsigned int getRating() const { return rating; }
};

/**
    En struktur för att hantera beräkningsreultat från beräkningen av normpoäng.
*/
struct NormResult 
{
    std::string name;
    double imPoints;
    double gmPoints;
};

class App
{
    public:
        App();
        void addPlayer(const ChessPlayer &player);
        double getExpectedPoint(const unsigned int &r1, const unsigned int &r2);
        std::vector<NormResult> getNormsPoints() const;

    private:
        std::vector<ChessPlayer> players;
};



#endif
