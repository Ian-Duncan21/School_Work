#include "Schedule.h"
#include <cassert>
#include <string>
 
using namespace std;
 
int main() {
    Schedule s;
    s.add("CSU Tonight!", "CSU", 23*4, 4, true);
    int id = s.add("Secret Agent XN-14158139", "Spy Television", 0, 4);
    s.add("Keeping up with the Applins", "FCTV", 9*4, 2);
    s.add("Jeopardy"s, "FCTV", 0, 5);
    //s.add("newshow"s, "FCTV", 10*4, 5);
    s.print();
    cout << "---\n";
    assert(s.size() == 4);
    assert(!s.erase(-17));
    assert(s.size() == 4);
    assert(s.erase(id));
    assert(s.size() == 3);
    s.print(cout);
    return 0;
}
