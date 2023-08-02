#ifndef SHOW_H_
#define SHOW_H_
#include <string>
#include <stdexcept>

class Show{
private:
        std::string name1, channel1;
        int start1, length1;
        int id1 = rand() % 1000000 + 1;
        bool adult1 = false;
        Show();
        
    public:
        Show& operator=(const Show &);
        Show(std::string progName, std::string progChannel, int progStart, int progLength, bool progAdult);
        Show(std::string progName, std::string progChannel, int progStart, int progLength);
        Show(const Show &p){name1 = p.name1; channel1 = p.channel1; start1 = p.start1; length1 = p.length1; adult1 = p.adult1; id1 = p.id1;}
        std::string name() const {return name1;}
        std::string channel() const {return channel1;}
        int start() const {return start1 * 15;}
        int length() const {return length1 * 15;}
        int id() const {return id1;}
        bool adult() const {return adult1;}
};

#endif 
