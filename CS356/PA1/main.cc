#include<iostream>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<streambuf>

using namespace std;

void SC(char in[], char key[], int strLen, char out[]){
    int keyIndex = 0;
    int index = 0;
    while(index < strLen){
        out[index] = in[index] ^ key[keyIndex];
        keyIndex = (keyIndex + 1) % 16;
        index++;
    }

}

int main(int argc, char *argv[]){
    if(argc != 6 || argc == 1){ //check for 5 arguments
        cerr << "Please provide 5 arguments\n";
        return -1; 
    }
    
    char alg = *argv[1]; //type of algorithm either 'B' or 'S' 
    
    if(alg != 'B' && alg != 'S'){ //makes sure first argument is a 'B' or 'S'
        cerr << "The input " << argv[1] << " should be set to B for block cipher or S for stream cipher\n";
        return -1; 
    } 
    
    ifstream in; //input file
    char byte[100];
    
    
    in.open(argv[2]);

    if(!in){ //make sure input file name is valid/exists
        cerr << argv[2] << " is not a valid input file name\n";
        return -1;
    }
    
    in >> noskipws;
    
    int index = 0;
    while(!in.eof()){
        in >> byte[index];
        index++;
    }
    index--;
    
    in.close();
     
    ofstream out(argv[3]); //output file

    ifstream keyfile; //keyfile
    char keyByte[100];
    int keyIndex = 0;

    keyfile.open(argv[4]);

    if(!keyfile){ //make sure keyfile is valid/exists
        cerr << argv[4] << " is not a valid keyfile\n";
        return -1; 
    }
    
    while(!keyfile.eof()){
        keyfile >> keyByte[keyIndex];
        keyIndex++;
    }
    
    keyfile.close();
    
    char mode = *argv[5]; //mode: either encryption or decryption
    
    if(mode != 'E' && mode != 'D'){ //makes sure last argument is set to 'E' or 'D'
        cerr << "The input " << argv[5] << " should be set to E for encrypt and D for decrypt\n";
        return -1; 
    } 
    
    if(alg == 'B' && mode == 'E'){ //block cipher encryption
        char outStr[index];
    
        SC(byte, keyByte, index, outStr);
        
        out << outStr;
        
        cout << "Converted String: ";
        for(int i = 0; i < index; i++){
            cout << outStr[i];
        }
        
        cout << "\n";
    }
    else if(alg == 'B' && mode == 'D'){ //block cipher decryption
        char outStr[index];
    
        SC(byte, keyByte, index, outStr);
        
        out << outStr;
        
        cout << "Converted String: ";
        for(int i = 0; i < index; i++){
            cout << outStr[i];
        }
    }
    else if(alg == 'S'){ //stream cipher
        char outStr[index];
    
        SC(byte, keyByte, index, outStr);
        
        out << outStr;
        
        cout << "Converted String: ";
        for(int i = 0; i < index; i++){
            cout << outStr[i];
        }
        
        out.close();
        
        cout << "\n";
        
    }
    
    return 0;
}
