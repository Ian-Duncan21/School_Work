#include <iostream>
#include "Phobic.h"
#include <stdarg.h>
#include <initializer_list>

using namespace std;

int Phobic::get()  {
bool is_bad = is_scary(number); 
   while(is_bad){
      number++;
      is_bad = is_scary(number);
   } 
 
return number;
}

bool Phobic::is_scary(int n) const{  
 for (auto val : bad){
      if(val == n){
	return true;
      }	
   }
   return false;
}





