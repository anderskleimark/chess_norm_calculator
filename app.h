#ifndef APP_H 
#define APP_H

#include <map>
#include <string>

class App
{
    public:
        App();
        void addPlayer(const std::string &name, const unsigned int &rating);
        double expectedPoints(const unsigned int &r1, const unsigned int &r2);

    private:
        std::map<std::string, unsigned int> players;
};



#endif
