#include <iostream>
#include <string>
#include <vector> 
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>

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

// string censor(vector<string> words, string body){
//     string tmp = body;
//     string output = body;
//     size_t index;
//     
//     for(string x : words){
//         while(tmp.find(x) != string::npos){
//             index = tmp.find(x);
//             if(!isalpha(output[index - 1]) && !isalpha(output[index] + 1)){
//                 output.replace(index, x.length(), "CENSORED");
//                 tmp.replace(index, x.length(), "CENESORED");
//             }
//             else {
//                 string rep(x.length(), '*');
//                 tmp.replace(index, x.length(), rep);
//             }
//         }
//     }
//     return output;
// }

int main(int argc, char *argv[]){  
    if( argc < 2 ){
        cerr << argv[0] << ": Provide at least a hyphen as an argument\n";
        return 1;
    }
        
    bool checkHyphen = true;
    
    for(int x = 1; x < argc; x++){
        if(*argv[x] == '-'){
            checkHyphen = false;
        }
    }
    if(checkHyphen == true){
        cerr << argv[0] << ": Please include a dash\n";
        return 1;
    }
    
    vector<string> badWords = {"alpha", "beta", "gamma","delta"};
    vector<string> displayString;
    vector<string> fileList;
    
    
    //string input;
    string sub = "CENSORED";
    
    int hyphen = 0;
    
    for(int x = 1; x < argc; x++){
        if(*argv[x] == '-'){
           hyphen = x + 1;
           break;
        }
        if(checkRepeat(argv[x], badWords) == true){
            cerr << argv[0] << ": " << argv[x] << " is a repeat argument\n";
            return 1;
        }
        if(checkAlpha(argv[x]) == true){
            cerr << argv[0] << ": " << argv[x] << " is not alphabetical\n";
            return 1;
        }
         badWords.push_back(argv[x]);
    }
             
    for(int x = hyphen; x < argc; x++){
        string inputFile = argv[x];
        ifstream myFile(inputFile);
        if(myFile.is_open()){
            fileList.push_back(argv[x]);
        }
        else{
            cerr << argv[0] << ": " << argv[x] << " is an invalid file\n";
            return 1;
        }
    }      
    
    string input;
    
    if(fileList.size() == 0){
        while(getline(cin, input)){
            for(size_t x = 0; x < displayString.size(); x++){
                //input = censor(displayString, input);
                cout << input << '\n';
            }
            displayString.push_back(input);
        }
        for(size_t p = 0; p < displayString.size(); p++){
            cout << displayString[p] << '\n';
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
