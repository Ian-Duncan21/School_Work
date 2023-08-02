#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include "Show.h"

// class Show{
// private:
//         std::string name1, channel1;
//         int start1, length1;
//         int id1 = rand() % 1000000 + 1;
//         bool adult1 = false;
//         Show();
//         
//     public:
//         Show& operator=(const Show &);
//         Show(std::string progName, std::string progChannel, int progStart, int progLength, bool progAdult);
//         Show(std::string progName, std::string progChannel, int progStart, int progLength);
//         Show(const Show &p){name1 = p.name1; channel1 = p.channel1; start1 = p.start1; length1 = p.length1; adult1 = p.adult1; id1 = p.id1;}
//         std::string name() const {return name1;}
//         std::string channel() const {return channel1;}
//         int start() const {return start1 * 15;}
//         int length() const {return length1 * 15;}
//         int id() const {return id1;}
//         bool adult() const {return adult1;}
// };
        

class Schedule {
    private:
        std::vector<Show> progSchedule;
        void add(Show prog);
        void erase(int id);
        
    public:
        Schedule();
        ~Schedule();
        Schedule(const Schedule &s){progSchedule = s.progSchedule;}
        Schedule& operator=(const Schedule& s1){progSchedule = s1.progSchedule; return *this;}
        Schedule& operator+=(const Show& rhs);
        Schedule& operator+=(const Schedule& rhs);
        Schedule operator+(const Schedule &);
        Schedule& operator-=(int id);
        Show operator[](size_t);
        [[nodiscard]] size_t size() const;
        std::ostream& print(std::ostream & shows) const;
        
        
};
std::ostream& operator<<(std::ostream &, Schedule &);

#endif /* SCHEDULE_H_ */
