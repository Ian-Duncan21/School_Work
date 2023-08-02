#include <iostream>
#include <string>
#include <vector> 

using namespace std;

int main(int argc, char *argv[]){
    if( argc > 1 ){
        cerr << argv[0] << ": Do not provide arguments\n";
        return 1;
    }
    
    vector<string> badWords = {"alpha", "beta", "gamma","delta"};
    vector<string> censorString;
    
    string input;
    string sub = "CENSORED";
    
    while(cin >> input){
        censorString.push_back(input);
    }
    
    for(size_t x = 0; x < censorString.size(); x++){
        string tmp = censorString[x];
    
        for(int p = 0; p < 4; p++){
            string checkBad = badWords[p];
            
            while(tmp.find(checkBad) != string::npos){
                if(tmp.find(checkBad) != 0 && isalpha(tmp.at(tmp.find(checkBad) - 1))){
                    break;
                }
                else if(tmp.find(checkBad) + checkBad.length() + 1  != string::npos && isalpha(tmp.at(tmp.find(checkBad) + checkBad.length()))){
                    break;
                }
                
                tmp.replace(tmp.find(checkBad), checkBad.length(), sub);
            }
        }
        
        censorString[x] = tmp;
    }
    
    for(size_t q = 0; q < censorString.size(); q++){
        if(q == censorString.size() - 1 && censorString[q].empty()){
                break;
        }
        cout << censorString[q] << '\n';
    }
    
    return 0;
}
