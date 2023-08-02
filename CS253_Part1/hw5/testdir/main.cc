#include <iostream>
#include <string>
#include <vector> 
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <unistd.h>

using namespace std;

bool checkRepeat(string censorWord, vector<string> censorList){
    for(size_t x = 0; x < censorList.size(); x++){
        if(censorList[x] == censorWord){
            return true;
        }
    }
    return false;
}

bool checkAlpha(string censorWord){
    for(size_t x = 0; x < censorWord.size(); x++){
        if(isalpha(censorWord.at(x))){
            continue;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]){  
    bool flag = true;
    if(argc > 1){
        string var = argv[1];
        if (var.at(0) != '-'){
            flag = false;
        }
    }
    
    int c;
    int r = 0;
    string sub = "CENSORED";
    vector<string> badWords;
    
    while((c = getopt(argc, argv, "r:c:iv")) != -1 && flag){
        switch(c){
            case 'r':
                if(r > 0){
                    cerr << "Only use the flag -r one time in: " << argv[0] << '\n';
                    return 1; 
                }
                sub = optarg;
                ++r;
                break;
            case 'c':
                if(checkRepeat(optarg, badWords) || checkAlpha(optarg)){
                    cerr << argv[0] << ": argument was either a number or repeat argument\n";
                }
                badWords.push_back(optarg);
                break;
            case 'i': 
                break;
            case 'v':
                cout << "Program is reading from standard input\n";
                break;
            default:
                return 1;
                break;
        }
    }

    vector<string> fileList;
    
    if(argc > 1 && flag != true){
        for(int x = 1; x < argc; x++){
            string inputFile = argv[1];
            ifstream myFile(inputFile);
            
            if(!myFile.is_open()){
                cerr << argv[0] << ": " << argv[x] << " is an invalid file\n";
                return 1;
            }
            else{
               fileList.push_back(argv[x]);
            }
        }
    }
    else{
        while(optind < argc){
            string inputFile = argv[optind];
            ifstream myFile(inputFile);
            
            if(!myFile.is_open()){
                cerr << argv[0] << ": " << argv[optind] << " is an invalid file\n";
                return 1;
            }
            else{
                fileList.push_back(argv[optind]);
                ++optind;
            }
        }
    }
    
    vector<string> displayString;
    string input;
    
    if(fileList.size() == 0){
        while(getline(cin, input)){
            displayString.push_back(input);
        }
    }
    else{
        for(size_t i = 0; i < fileList.size(); i++){
            string inputFile = fileList[i];
            ifstream myFile(inputFile);
            string str;
            
            while (getline(myFile, str)){
                displayString.push_back(str);
            }
            myFile.close();
        }
    }    
    
    for(size_t x = 0; x < displayString.size(); x++){
        string tmp = displayString[x];
      
        for(size_t i = 0; i < badWords.size(); i++){
            string checkBad = badWords[i];
        
            while(tmp.find(checkBad) != string::npos){
                 if(tmp.find(checkBad) != 0 && isalpha(tmp.at(tmp.find(checkBad) - 1))){
                     break;
                 }
                 else if(tmp.find(checkBad) + checkBad.length() != tmp.length() && isalpha(tmp.at(tmp.find(checkBad) + checkBad.length()))){
                     break;
                 }
                    tmp.replace(tmp.find(checkBad), checkBad.length(), sub);
                
            }
        }

        displayString[x] = tmp;
        cout << displayString[x] << '\n';

    }
    
    return 0;
}
