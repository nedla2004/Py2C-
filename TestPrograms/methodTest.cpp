#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <sstream>
#include <stdarg.h>
#include <algorithm>

auto len(int a[]) {
    // std::vector<int> v(std::begin(a), std::end(a));
    std::cout << *(a + 1) - *a << std::endl;
}
auto len(std::vector<int> a) {
    return a.size();
}
auto len(std::string s) {
    return s.length();
}
template <typename T>
void print(T t) {
    std::cout << t << std::endl;
}
template<typename T, typename... Args>
void print(T t, Args... args) {
    std::cout << t << " ";
    print(args...);
}
void print(std::vector<int> v) {
    std::cout << "[";
    for (int index=0; index<len(v)-1; index++) {
        std::cout << v[index] << ", ";
    }
    std::cout << v[len(v)-1] << "]" << std::endl;
}

std::string str(int val) {
    return std::to_string(val);
}
std::string str(std::string val) {
    return val;
}
std::string str(std::stringstream val) {
    std::string result(val.str());
    return result;
}

std::vector<int> range(int end) {
    std::vector<int> result;
    for (int i=0; i<end; i++) {
        result.push_back(i);
    }
    return result;
}
std::vector<int> range(int start, int end) {
    std::vector<int> result;
    for (int i=0; i<end-start; i++) {
        result.push_back(i+start);
    }
    return result;
}
std::vector<int> range(int start, int end, int step) {
    std::vector<int> result;
    for (int i=0; i<(end-start)/step; i++) {
        result.push_back(i*step + start);
    }
    return result;
}

template <typename T>
std::string input(T t) {
    std::string result;
    std::cout << t;
    std::cin >> result;
    return result;
}
std::string input() {
    std::string result;
    std::cin >> result;
    return result;
}

auto toBool(std::vector<int> v) {
    return !!len(v);
}
auto toBool(int i) {
    return !!i;
}
auto toBool(std::string s) {
    return s.empty();
}

auto toInt(int i) {
    // std::cout << "toInt(int) " << i << std::endl;
    return i;
}
auto toInt(std::string s) {
    // std::cout << "toInt(string) " << s << std::endl;
    return std::stol(s, nullptr);
}
auto toInt(std::string s, int base) {
    // std::cout << "toInt(string, int) " << s << " " << base << std::endl;
    return std::stol(s, nullptr, base);
}

std::string bin(int n) {
    std::string r;
    bool neg = n < 0;
    n = abs(n);
    while (n!=0) {
        r = str(n % 2) + r;
        n /= 2;
    }
    r = "0b" + r;
    if (neg) {
        r = "-" + r;
    }
    return r;
}

std::string hex(int n) {
    std::stringstream stream;
    stream << std::hex << n;
    std::string s(stream.str());
    return "0x" + s;
}

std::string oct(int n) {
    std::stringstream stream;
    stream << std::oct << n;
    std::string s(stream.str());
    return "0o" + s;
}

int ord(std::string s) {
    return (int)s[0];
}

std::string chr(int n) {
    std::string result;
    result.push_back(n);
    return result;
}

int max(std::vector<int> v) {
    int currentMax = v[0];
    for (auto& item : v) {
        if (item > currentMax) {
            currentMax = item;
        }
    }
    return currentMax;
}
template <typename T>
int max(T a, T b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
template<typename T, typename... Args>
int max(T a, T b, Args... args) {
    if (a > b) {
        return max(a, args...);
    } else {
        return max(b, args...);
    }
}

int min(std::vector<int> v) {
    int currentMin = v[0];
    for (auto& item : v) {
        if (item < currentMin) {
            currentMin = item;
        }
    }
    return currentMin;
}
template <typename T>
int min(T a, T b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
template<typename T, typename... Args>
int min(T a, T b, Args... args) {
    if (a < b) {
        return min(a, args...);
    } else {
        return min(b, args...);
    }
}

std::vector<int> sorted(std::vector<int> v) {
    std::vector<int> result;
    result = v;
    std::sort(result.begin(), result.end());
    return result;
}


auto random_randint(auto a, auto b) {
    return rand() % (b - a) + a;
}auto random_choice(auto seq) {
    int index = 0;
    index = random_randint(0, len(seq));
    return seq[index];
}auto random_randrange(auto stop) {
    return random_choice(range(stop));
}auto random_randrange(auto start, auto stop) {
    return random_choice(range(start, stop));
}auto random_randrange(auto start, auto stop, auto step) {
    return random_choice(range(start, stop, step));
}auto random_random() {
    return (rand() * 1.0) / (RAND_MAX);
}auto random_seed() {
    srand(time(NULL));
}auto random_seed(auto a) {
    srand(a);
}
//SPLT@@@\n

//SPLT@@@
int main() {


std::string a = "hello there EvErYbOdY!";
auto b = METHOD_upper(a);
print(b, METHOD_lower("Hi$"));
print(METHOD_split(a));
print(random_randint(10, 20));

}