#ifndef PHOBIC_H_INCLUDED
#define PHOBIC_H_INCLUDED

#include <iostream>
#include <vector>
#include <initializer_list>


class Phobic {
   private:
        int number;
        std::vector<int> bad;
	Phobic(int x, std::vector<int> bad1){number = x; bad = bad1;}
	
   public:
	Phobic(){number = 0; bad.push_back(13);}
        Phobic(int x){number = x; bad.push_back(13);}
	Phobic(const Phobic &p1){number = p1.number; bad = p1.bad;}
	~Phobic(){}

	Phobic add(const Phobic &p1){Phobic temp = Phobic(*this); temp.add_to(p1); return temp;}
        Phobic sub(const Phobic &p1){Phobic temp = Phobic(*this); temp.sub_from(p1); return temp;}
        Phobic mul(const Phobic &p1){Phobic temp = Phobic(*this); temp.mul_by(p1); return temp;}
        Phobic div(const Phobic &p1){Phobic temp = Phobic(*this); temp.div_by(p1); return temp;}


	void add_to(const Phobic &p1){number += p1.number; for(auto val : p1.bad){ bad.push_back(val);}}
	void sub_from(const Phobic &p1){number -= p1.number; for(auto val : p1.bad){ bad.push_back(val);}}
	void mul_by(const Phobic &p1){number *= p1.number; for(auto val : p1.bad){ bad.push_back(val);}}
	void div_by(const Phobic &p1){number /= p1.number; for(auto val : p1.bad){ bad.push_back(val);}}
	
	
        bool eq(const Phobic &p1){return number == p1.number;}
	bool lt(const Phobic &p1){return number < p1.number;}
        int get();
	void make_scary(int int1){bad.push_back(int1);}
	void make_scary(int int1, int int2){bad.push_back(int1); bad.push_back(int2);}
	void make_scary(int int1, int int2, int int3){bad.push_back(int1); bad.push_back(int2); bad.push_back(int3);}
	void make_scary(int int1, int int2, int int3, int int4){bad.push_back(int1); bad.push_back(int2); bad.push_back(int3); bad.push_back(int4);}
void make_scary(int int1, int int2, int int3, int int4, int int5){bad.push_back(int1); bad.push_back(int2); bad.push_back(int3); bad.push_back(int4); bad.push_back(int5);}
void make_scary(int int1, int int2, int int3, int int4, int int5, int int6){bad.push_back(int1); bad.push_back(int2); bad.push_back(int3); bad.push_back(int4); bad.push_back(int5); bad.push_back(int6);}
void make_scary(int int1, int int2, int int3, int int4, int int5, int int6, int int7){bad.push_back(int1); bad.push_back(int2); bad.push_back(int3); bad.push_back(int4); bad.push_back(int5); bad.push_back(int6); bad.push_back(int7);}
void make_scary(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8){bad.push_back(int1); bad.push_back(int2); bad.push_back(int3); bad.push_back(int4); bad.push_back(int5); bad.push_back(int6); bad.push_back(int7); bad.push_back(int8);}
void make_scary(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8, int int9){bad.push_back(int1); bad.push_back(int2); bad.push_back(int3); bad.push_back(int4); bad.push_back(int5); bad.push_back(int6); bad.push_back(int7); bad.push_back(int8); bad.push_back(int9);}
void make_scary(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8, int int9, int int10){bad.push_back(int1); bad.push_back(int2); bad.push_back(int3); bad.push_back(int4); bad.push_back(int5); bad.push_back(int6); bad.push_back(int7); bad.push_back(int8); bad.push_back(int9); bad.push_back(int10);}
	bool is_scary(int n) const;
}; 


#endif
