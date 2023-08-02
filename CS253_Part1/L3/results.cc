    #include<iostream>
    #include<vector>
	#include <string>
	#include <set>
	#include <fstream>

    using namespace std;

    int main() {
	vector<int> vector;
	int i;

    cin >> i;      
	  while (i != 0) {      
	    vector.push_back(i);
	    cin >> i;  
	  }        
	
	  cout << "vector test: \n";
          for (auto val : vector) {
            cout << val << "\n";
          }   

	  ifstream file;
   	    file.open("/etc/resolv.conf");
            string str;
            char x;
    	    while(file.get(x)) {
              str += x;
    	    }
	  
	  multiset<char> ms;
	    for(auto val : str){
	      ms.insert(val);
	    }
	  set<char> s;
	    for(auto val : ms){
	      s.insert(val);
	    }
	
	//QUESTION 7 
	
	/*The output is different because strings are unordered where as
     * a multiset is. When it is read into the multiset it becomes ordered 
     * and then the set proceeds to read in characters, except it does not 
     * read the duplicate characters so size is changed.*/
	
    cout << "string: size=" << str.size() << " " << str;
	cout << "set: size=" << s.size() << " " << str;
	cout << "multiset: size=" << ms.size() << " " << str;

    
	}

