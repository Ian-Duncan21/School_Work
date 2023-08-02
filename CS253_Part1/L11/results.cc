#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    void dump() const {
	for (const auto &val : data)
	    cout << right << setw(10) << val.first << ' '
		 << string(val.second, '*') << '\n';
        cout << '\n';
    }
    
    template<typename T1>
    friend ostream &operator<<(ostream &out, const BarGraph<T1> &datum);
    
  private:
    map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
    unsigned false_count = 0, true_count = 0;
  public:
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
    friend ostream &operator<<(ostream &out, const BarGraph<bool> &datum); 
    void dump() const {
        cout << "     false " << string(false_count, '*') << "\n"
                "      true " << string(true_count,  '*') << "\n\n";
    }
};

template <typename T>
ostream &operator<<(ostream &os, const BarGraph<T> &datum) {
    for (const auto &num : datum.data) {
        os << right << setw(10) << num.first << ' '
         << string(num.second, '*') << '\n';
        
    }
        os << '\n';
        return os;
    
}

ostream &operator<<(ostream &os, const BarGraph<bool> &val) {
    os << "     false " << string(val.false_count, '*') << "\n"
            "      true " << string(val.true_count,  '*') << "\n\n";
    return os;
}

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta;

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    cout << gamma;

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    cout << delta;
    return 0;
}
