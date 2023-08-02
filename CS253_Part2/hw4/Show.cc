#include "Show.h"

using namespace std;

void validShow(string progName, string progChannel, int progStart, int progLength){
    if(progStart < 0 || progLength < 0 || progStart > 96 || progStart + progLength > 96 || progName == "" || progChannel == ""){ //check for valid program
        throw runtime_error("Show name, channel name, start time, or show length is Invalid");
    }
}

Show::Show(string name2, string channel2, int start2, int length2){
    validShow(name2, channel2, start2, length2);
    name1 = name2;
    channel1 = channel2;
    start1 = start2;
    length1 = length2;
}

Show::Show(string name2, string channel2, int start2, int length2, bool adult2){
    validShow(name2, channel2, start2, length2);
    name1 = name2;
    channel1 = channel2;
    start1 = start2;
    length1 = length2;
    adult1 = adult2;
}

Show &Show::operator=(const Show &s) = default;
