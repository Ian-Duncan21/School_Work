#include "Schedule.h"

using namespace std;

// void validShow(string progName, string progChannel, int progStart, int progLength){
//     if(progStart < 0 || progLength < 0 || progStart > 96 || progStart + progLength > 96 || progName == "" || progChannel == ""){ //check for valid program
//         throw runtime_error("Show name, channel name, start time, or show length is Invalid");
//     }
// }
// 
// Show::Show(string name2, string channel2, int start2, int length2){
//     validShow(name2, channel2, start2, length2);
//     name1 = name2;
//     channel1 = channel2;
//     start1 = start2;
//     length1 = length2;
// }
// 
// Show::Show(string name2, string channel2, int start2, int length2, bool adult2){
//     validShow(name2, channel2, start2, length2);
//     name1 = name2;
//     channel1 = channel2;
//     start1 = start2;
//     length1 = length2;
//     adult1 = adult2;
// }
// 
// Show &Show::operator=(const Show &s) = default;

Schedule::Schedule() = default;
Schedule::~Schedule() = default;

[[nodiscard]]size_t Schedule::size() const{
    return progSchedule.size();
}

void Schedule::erase(int id){
    int i = -1;
    for(auto x : progSchedule){ //loop through the schedule vector 
        i++;
        if(x.id() == id){ //if an id refers to a program in the schedule erase
            progSchedule.erase(progSchedule.begin() + i);
            break;
//             return true;
        }
        else{
            throw runtime_error("Show does not exist in the schedule");
        }
    }
    
//     return false;
}

void Schedule::add(Show prog){
    if(progSchedule.empty()){ //if the schedules vector is empty put the first show in the vector
        progSchedule.push_back(prog);
    }
    else{
        for(size_t x = 0; x < progSchedule.size(); x++){ //loop through the vector of x amount of programs
            int timeStart1 = prog.start(); 
            int timeEnd1 = prog.start() + prog.length();
            int timeStart2 = progSchedule[x].start();
            int timeEnd2 = progSchedule[x].start() + progSchedule[x].length();
            if((progSchedule[x].channel() == prog.channel()) && (timeEnd2 > timeStart1) && (timeEnd1 > timeStart2)){ //if the channels are the same cehck for time overlap
                throw runtime_error("Time Conflict!");
            }
        }
        
        progSchedule.push_back(prog); //if theres no overlap put program in vector
        
    }
}

ostream& Schedule::Schedule::print(ostream& shows) const{
    char censorFlag = '*';
    auto channelName = progSchedule[0].channel().length();

    for(size_t x = 0; x < progSchedule.size(); x++){ //loop through the schedule array 
        string displayTimes[4]; 
        int progTimes[4];
        progTimes[0] = (progSchedule[x].start() / 15) / 4; 
        progTimes[1] = ((progSchedule[x].start() / 15) % 4) * 15; 
        progTimes[2] = ((progSchedule[x].length() / 15) / 4) + (progSchedule[x].start() / 15) / 4; 
        progTimes[3] = (((progSchedule[x].length() / 15) % 4) * 15) + ((progSchedule[x].start() / 15) % 4) * 15;
        
        if(progTimes[3] >= 60){
            progTimes[2] += progTimes[3] / 60;
            progTimes[3] = progTimes[3] % 60;
        }
        
        for(int i = 0; i < 4; i++){ //loop through progTimes array and if value is less than 10 add a 0 for formatting
            if(progTimes[i] < 10){
                string tmp = to_string(progTimes[i]);
                displayTimes[i] = ("0" + tmp);
            }
            else {
                string tmp = to_string(progTimes[i]);
                displayTimes[i] = tmp;
            }
        }
        
        shows << displayTimes[0] << ":" << displayTimes[1] << "-" << displayTimes[2] << ":" << displayTimes[3] << " " << progSchedule[x].channel();
        
        for(size_t i = 0; i < progSchedule.size(); i++){ //find the longest channel name that was added 
            if(progSchedule[i].channel().length() > channelName){
                channelName = progSchedule[i].channel().length();
            }
        }
        
        for(size_t i = 0; i < channelName - progSchedule[x].channel().length(); i++){ //add spaces to the smaller channel names to make them line up with the largest channel name
            shows << " ";
        }
        shows << " " << progSchedule[x].name();
        if(progSchedule[x].adult()){ //check for adult programs and add censorFlag to the print if true
            shows << censorFlag << '\n';
        }
        else {
            shows << '\n';
        }
    }
    return shows;
}

Schedule& Schedule::operator+=(const Show &rhs){
    add(rhs);
    return *this;
}

Schedule& Schedule::operator+=(const Schedule &rhs){
    for(size_t x = 0; x < rhs.progSchedule.size(); x++){
        progSchedule.push_back(rhs.progSchedule[x]);
    }
    
    return *this;
}

Schedule Schedule::operator+(const Schedule &rhs){
    vector<Show> newProgSchedule = progSchedule;
    Schedule tmp = Schedule(*this);
    
    for(size_t x = 0; x < rhs.progSchedule.size(); x++){
        tmp.progSchedule.push_back(rhs.progSchedule[x]);
    }
    
    return tmp;
}

Schedule& Schedule::operator-=(int id){
    erase(id);
    return *this;
}

Show Schedule::operator[](size_t i){
    if(i > progSchedule.size()){
        string tmp = "";
        tmp.append("There are only ");
        tmp.append(to_string(progSchedule.size()));
        tmp.append(" shows in the schedule, you tried to access ");
        tmp.append(to_string(i));
        throw range_error(tmp);
    }
    return progSchedule[i];
}

ostream& operator<<(ostream &os, Schedule &s){
    return s.print(os);
}
