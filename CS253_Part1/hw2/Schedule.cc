#include "Schedule.h"

using namespace std;

size_t Schedule::size() const{
    return progSchedule.size();
}

bool Schedule::erase(int id){
    int i = -1;
    for(auto x : progSchedule){ //loop through the schedule vector 
        i++;
        if(x.id == id){ //if an id refers to a program in the schedule erase and return true
            progSchedule.erase(progSchedule.begin() + i);
            return true;
        }
    }
    return false;
}

int Schedule::add(string progName, string progChannel, int progStart, int progLength, bool progAdult){
    if(progStart < 0 || progLength < 0 || progStart > 96 || progStart + progLength > 96 || progName == "" || progChannel == ""){ //check for valid program
        return -1;
    }
    
    struct Program prog = Program(progName, progChannel, progStart, progLength, progAdult); //struct to store unadorned data
    
    if(progSchedule.empty()){ //if the schedules vector is empty put the first show in the vector
        progSchedule.push_back(prog);
    }
    else{
        for(size_t x = 0; x < progSchedule.size(); x++){ //loop through the vector of x amount of programs
            int timeStart1 = prog.start; 
            int timeEnd1 = prog.start + prog.length;
            int timeStart2 = progSchedule[x].start;
            int timeEnd2 = progSchedule[x].start + progSchedule[x].length;
            if((progSchedule[x].channel == prog.channel) && (timeEnd2 > timeStart1) && (timeEnd1 > timeStart2)){ //if the channels are the same cehck for time overlap
                return -1;
            }
        }
        
        progSchedule.push_back(prog); //if theres no overlap put program in vector
        
    }
    
    return prog.id;
}

void Schedule::print(ostream& shows) const{
    char censorFlag = '*';
    auto channelName = progSchedule[0].channel.length();

    for(size_t x = 0; x < progSchedule.size(); x++){ //loop through the schedule array 
        string displayTimes[3]; 
        int progTimes[3];
        progTimes[0] = progSchedule[x].start / 4; //calculates the hours coulmn starting time as one number i.e. 9, 10 
        progTimes[1] = (progSchedule[x].length / 4) + (progSchedule[x].start / 4); //grabs the hours column number for the end time as one number i.e. 9, 10
        progTimes[2] = ((progSchedule[x].length % 4) * 15); //calculates minutes column for end time in multiples of 15 (0, 15, 30, 45)
        
        for(int i = 0; i < 3; i++){ //loop through progTimes array and if value is less than 10 add a 0 for formatting
            if(progTimes[i] < 10){
                string tmp = to_string(progTimes[i]);
                displayTimes[i] = ("0" + tmp);
            }
            else {
                string tmp = to_string(progTimes[i]);
                displayTimes[i] = tmp;
            }
        }
        
        shows << displayTimes[0] << ":00-" << displayTimes[1] << ":" << displayTimes[2] << " " << progSchedule[x].channel;
        
        for(size_t i = 0; i < progSchedule.size(); i++){ //find the longest channel name that was added 
            if(progSchedule[i].channel.length() > channelName){
                channelName = progSchedule[i].channel.length();
            }
        }
        
        for(size_t i = 0; i < channelName - progSchedule[x].channel.length(); i++){ //add spaces to the smaller channel names to make them line up with the largest channel name
            shows << " ";
        }
        shows << " " << progSchedule[x].name;;
        if(progSchedule[x].adult){ //check for adult programs and add censorFlag to the print if true
            shows << censorFlag << '\n';
        }
        else {
            shows << '\n';
        }
    }
}
