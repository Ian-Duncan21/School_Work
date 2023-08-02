#ifndef PHOBIC_H_INCLUDED
#define PHOBIC_H_INCLUDED

#include <iostream>
#include <initializer_list>
#include <set>
#include <stdexcept>

class Phobic {
   private:
        int number;
        std::set<int> bad;
        Phobic(int x, std::set<int> bad1){number = x; bad = bad1;}

   public:
        Phobic(){number = 0; bad.insert(13);}
        Phobic(int x){number = x; bad.insert(13);}
        Phobic(const Phobic &p1){number = p1.number; bad = p1.bad;}
        ~Phobic(){}

//         void show() const{
//           std::cout << "---" << number << "---\n";
//             for (auto val : bad) {
//                 std::cout << val << '\n';
//             }
//        }


    Phobic operator+(const Phobic &p1){Phobic temp = Phobic(*this); temp+=(p1); temp.get(); return temp;}
    Phobic operator-(const Phobic &p1){Phobic temp = Phobic(*this); temp-=(p1); temp.get(); return temp;}
    Phobic operator*(const Phobic &p1){Phobic temp = Phobic(*this); temp*=(p1); temp.get(); return temp;}
    Phobic operator/(const Phobic &p1){if (p1.number == 0){throw std::runtime_error("div by 0");}Phobic temp = Phobic(*this); temp/=(p1); temp.get(); return temp;}

    friend Phobic operator+(const Phobic& p1, const Phobic& p2) {return Phobic(p1.number + p2.number);}
    friend Phobic operator-(const Phobic& p1, const Phobic& p2) {return Phobic(p1.number - p2.number);}
    friend Phobic operator*(const Phobic& p1, const Phobic& p2) {return Phobic(p1.number * p2.number);}
    friend Phobic operator/(const Phobic& p1, const Phobic& p2) {if (p1.number == 0){throw std::runtime_error("div by 0");}return Phobic(p1.number / p2.number);}

    void operator+=(const Phobic &p1){number += p1.number; for(auto val : p1.bad){ bad.insert(val);}}
    void operator-=(const Phobic &p1){number -= p1.number; for(auto val : p1.bad){ bad.insert(val);}}
    void operator*=(const Phobic &p1){number *= p1.number; for(auto val : p1.bad){ bad.insert(val);}}
    void operator/=(const Phobic &p1){if (p1.number == 0){throw std::runtime_error("div by 0");}number /= p1.number; for(auto val : p1.bad){ bad.insert(val);}}


    friend bool operator==(const Phobic& p1, const Phobic &p2){return p1.number == p2.number;}
    friend bool operator!=(const Phobic& p1, const Phobic &p2){return p1.number != p2.number;}
    friend bool operator>(const Phobic& p1, const Phobic &p2){return p1.number > p2.number;}
    friend bool operator<(const Phobic& p1, const Phobic &p2){return p1.number < p2.number;}
    friend bool operator<=(const Phobic& p1, const Phobic &p2){return p1.number <= p2.number;}
    friend bool operator>=(const Phobic& p1, const Phobic &p2){return p1.number >= p2.number;}

    int get();
    Phobic operator<<(int int1){bad.insert(int1); return *this;}
    void make_scary(int int1, int int2){bad.insert(int1); bad.insert(int2);}
  	void make_scary(int int1, int int2, int int3){bad.insert(int1); bad.insert(int2); bad.insert(int3);}
  	void make_scary(int int1, int int2, int int3, int int4){bad.insert(int1); bad.insert(int2); bad.insert(int3); bad.insert(int4);}
    void make_scary(int int1, int int2, int int3, int int4, int int5){bad.insert(int1); bad.insert(int2); bad.insert(int3); bad.insert(int4); bad.insert(int5);}
    void make_scary(int int1, int int2, int int3, int int4, int int5, int int6){bad.insert(int1); bad.insert(int2); bad.insert(int3); bad.insert(int4); bad.insert(int5); bad.insert(int6);}
    void make_scary(int int1, int int2, int int3, int int4, int int5, int int6, int int7){bad.insert(int1); bad.insert(int2); bad.insert(int3); bad.insert(int4); bad.insert(int5); bad.insert(int6); bad.insert(int7);}
    void make_scary(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8){bad.insert(int1); bad.insert(int2); bad.insert(int3); bad.insert(int4); bad.insert(int5); bad.insert(int6); bad.insert(int7); bad.insert(int8);}
    void make_scary(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8, int int9){bad.insert(int1); bad.insert(int2); bad.insert(int3); bad.insert(int4); bad.insert(int5); bad.insert(int6); bad.insert(int7); bad.insert(int8); bad.insert(int9);}
    void make_scary(int int1, int int2, int int3, int int4, int int5, int int6, int int7, int int8, int int9, int int10){bad.insert(int1); bad.insert(int2); bad.insert(int3); bad.insert(int4); bad.insert(int5); bad.insert(int6); bad.insert(int7); bad.insert(int8); bad.insert(int9); bad.insert(int10);}
  	bool is_scary(int n) const;
    };


#endif
