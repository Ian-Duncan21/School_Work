#ifndef PHOBIC_H_INCLUDED
#define PHOBIC_H_INCLUDED

#include <iostream>
#include <initializer_list>
#include <set>
#include <stdexcept>
#include <vector>

class CountSort {
   private:
        int x;
        int y;
        std::vector<int> num;
        int invLastIndex = 0;
        std::vector<int> invNum; 
        int total = 0;
        std::string invRange = "Invalid range ";

   public:
        int &operator()(int n){
            n += x;
            
            if (n > y) {
                std::string error = "Index out of range: ";
                error.append(std::to_string(n - x));
                throw std::range_error(error);
            }
            
            if (n < 0) {
                return invNum[abs(n)];
            }
            
            return num[n];
        }
        
        CountSort(int x1, int y1){
            x = x1;
            y = y1;
            
            if (x > y){
                invRange += std::to_string(y) + "< " + std::to_string(x); throw std::invalid_argument(invRange);
            } 
            
            std::vector<int> temp(y,0);
            num = temp;
            
            if(x < 0){
                std::vector<int> temp1(x,0);
                invNum = temp1;
                invLastIndex = abs(x);
            }else{
                    std::vector<int> temp2;
                    invNum = temp2;
            } 
            
            
        }
        
        void insert(int p){
            if(p < x || p > y) {
                std::string error = "Input out of range: ";
                error.append(std::to_string(p));
                throw std::range_error(error);
            } 	
            
            if(p >= 0){
                total++;
                num[p]++; 
            }else{
                total++;
                invNum[abs(p)]++;
            }
        }
        
        void insert() {
          return;
        }
        template<class T, class... OtherArgs> void insert(T&& var, OtherArgs&&... args) {
          auto val1 = std::forward<T>(var);
          // if val < x || val > y {
          //   // throw error
          // }
          if (val1 < 0) {
            invbad[abs(val1)]++;
          } else {
            bad[val1]++;
          }
          insert(std::forward<OtherArgs>(args)...);
        }
        
        int& operator[](int index) {
            if (index < 0 && index > x){
                return invNum[abs(index)];
            }else if (index >= 0 && index < y){
                return num[index];
            }
            
            std::string error = "Index out of range: ";
            error.append(std::to_string(index));
            throw std::range_error(error);
            
        }
        
        int min() const{
            return x;
        }
        
        int max() const{
            return y;
        }
        
        int width() const{
            return y + abs(x);
        }
        
        int size() const{
            return total;
        }
        
        bool empty(){
            return total == 0;
        }
        
        void clear(){
            std::vector<int> temp(y,0);
            num = temp;
            
            if (x < 0){
                std::vector<int> temp1(x,0);
                invNum = temp1;
            }
            
            total = 0;
        }
        
        
        
        class iterator{
        public:
        iterator() : base(nullptr), index(0) {}
        iterator(const CountSort *b,const size_t i) : base(b), index(i) { }
        iterator &operator++(){
            index++;
            return *this;
        }
        iterator operator++(int){
            auto temp = *this;
            index++;
            return temp;
        }
        iterator &operator--(){
            index--;
            return *this;
        }
        iterator operator--(int){
            auto temp = this;
            index--;
            return temp;
        }
        bool operator==(const iterator& iter) const{
            iterator curr = iter;
            const int e = (base)[index];
            const int e2 = curr;
            return e == e2;
        }
        bool operator!=(const iterator& iter) const{
            iterator curr = iter;
            const int e = (base)[index];
            const int e2 = curr;
            return e != e2;
        }

        int operator() const{
            const int curr = (*base)[index];
            return curr;
        }
        private:
        const CountSort *base;
        size_t index;
        };

        iterator begin() const{
            return iterator(this, 0);
        }
        iterator end() const{
            return iterator(this, bad.size());
        }
};

#endif
