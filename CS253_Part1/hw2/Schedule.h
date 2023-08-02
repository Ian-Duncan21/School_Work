#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

class Program{
    public:
        std::string name, channel;
        int start, length;
        int id = rand() % 9000 + 1000;
        bool adult = false;
        Program(std::string progName, std::string progChannel, int progStart, int progLength, bool progAdult){name = progName; channel = progChannel; start = progStart; length = progLength; adult = progAdult;}
            
};
        

class Schedule {
    private:
        std::vector<Program> progSchedule;
        
    public:
        Schedule(){}
        ~Schedule(){}
        Schedule(const Schedule &s){progSchedule = s.progSchedule;}
        Schedule& operator=(const Schedule s1){progSchedule = s1.progSchedule; return *this;}
        int add(std::string progName, std::string progChannel, int progStart, int progLength, bool progAdult = false); 
        [[nodiscard]] size_t size() const;
        bool erase(int id);
        void print() const{Schedule::print(std::cout);}
        void print(std::ostream& shows) const;
        
};

#endif /* SCHEDULE_H_ */
