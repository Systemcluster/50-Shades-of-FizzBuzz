//
// 50 variants of Fizz Buzz.
// Copyright (c) 2014 Christian Sdunek
//
// This file currently contains 21 variants, more will be added eventually.
//

#include <iostream>
#include <string> // for solutions 6, 7, 8, 9, 10, 13, 14, 15
#include <sstream> // for solution 13
#include <vector> // for solution 6
#include <unordered_map> // for solutions 7, 8
#include <regex> // for solutions 9, 13
#include <functional> // for solution 19


void fb01() {
    for(int i = 1; i <= 100; ++i) {
        if(!(i % 15)) std::cout << "FizzBuzz";
        else if(!(i % 3)) std::cout << "Fizz";
        else if(!(i % 5)) std::cout << "Buzz";
        else std::cout << i;
        std::cout << std::endl;
    }
}

void fb02() {
    for(int i = 1; i <= 100; ++i) {
        if(i % 3 && i % 5) std::cout << i;
        else if(i % 3) std::cout << "Buzz";
        else if(i % 5) std::cout << "Fizz";
        else std::cout << "FizzBuzz";
        std::cout << std::endl;
    }
}

void fb03() {
    for(int i = 1; i <= 100; ++i) {
        if(!(i % 3)) std::cout << "Fizz";
        if(!(i % 5)) std::cout << "Buzz";
        if(i % 3 && i % 5) std::cout << i;
        std::cout << std::endl;
    }
}

void fb04() {
    for(int i = 1; i <= 100; ++i) {
        if(!(i % 3)) {
            std::cout << "Fizz";
            if(!(i % 5)) std::cout << "Buzz";
        }
        else if(!(i % 5))
            std::cout << "Buzz";
        else std::cout << i;
        std::cout << std::endl;
    }
}

void fb05() {
    for(int i = 1; i <= 100; ++i) {
        switch(i % 15) {
            case 0:
                std::cout << "FizzBuzz";
                break;
            case 3:
            case 6:
            case 9:
            case 12:
                std::cout << "Fizz";
                break;
            case 5:
            case 10:
                std::cout << "Buzz";
                break;
            default:
                std::cout << i;
        }
        std::cout << std::endl;
    }
}

void fb06() {
    const std::vector<std::string> lookup {
        "FizzBuzz",
        "","",
        "Fizz",
        "",
        "Buzz",
        "Fizz",
        "", "",
        "Fizz",
        "Buzz",
        "",
        "Fizz",
        "",""
    };
    for(int i = 1; i <= 100; ++i) {
        if(lookup.at(i % 15).empty()) std::cout << i;
        else std::cout << lookup.at(i % 15);
        std::cout << std::endl;
    }
}

void fb07() {
    const std::unordered_map<int, std::string> lookup {
        {0,  "FizzBuzz"},
        {3,  "Fizz"},
        {5,  "Buzz"},
        {6,  "Fizz"},
        {9,  "Fizz"},
        {10, "Buzz"},
        {12, "Fizz"}
    };
    for(int i = 1; i <= 100; ++i) {
        if(lookup.count(i % 15)) std::cout << lookup.at(i % 15);
        else std::cout << i;
        std::cout << std::endl;
    }
}

void fb08() {
    const std::unordered_map<int, std::string> lookup {
        {0,  "FizzBuzz"},
        {3,  "Fizz"},
        {5,  "Buzz"},
        {6,  "Fizz"},
        {9,  "Fizz"},
        {10, "Buzz"},
        {12, "Fizz"}
    };
    for(int i = 1; i <= 100; ++i) {
        try { std::cout << lookup.at(i % 15); }
        catch(std::out_of_range&) { std::cout << i; }
        std::cout << std::endl;
    }
}

void fb09() {
    const std::regex r {"^15$"};
    const std::regex f {"^(3|6|9|12)$"};
    const std::regex b {"^(5|10)$"};
    const std::regex a {"^([0-9]+)$"};
    for(int i = 1; i <= 100; ++i) {
        std::string x {std::to_string(i % 15)};
        x = std::regex_replace(x, r, "FizzBuzz");
        x = std::regex_replace(x, f, "Fizz");
        x = std::regex_replace(x, b, "Buzz");
        x = std::regex_replace(x, a, std::to_string(i));
        std::cout << x << std::endl;
    }
}

void fb10() {
    for(int i = 1; i <= 100; ++i) {
        std::cout << (std::string {"FizzBuzz"}).append(std::to_string(i)).
        substr(!(i % 3) ? 0 : !(i % 5) ? 4 : 8, !(i % 15) ? 8 : 4)
        << std::endl;
    }
}

void fb11() {
    for(int i = 1; i <= 100; ++i) {
        std::cout << (!(i % 15) ? "FizzBuzz" : !(i % 5) ? "Buzz" : !(i % 3) ? "Fizz" : std::to_string(i)) << std::endl;
    }
}

void fb12() {
    for(int i = 1; i <= 100; ++i) {
        std::cout << (!(i % 3) ? "Fizz" : "") << (!(i % 5) ? "Buzz" : "") << (i % 3 && i % 5 ? std::to_string(i) : "") << std::endl;
    }
}

void fb13() {
    const auto get = [](int nr) -> const std::string {
        std::stringstream ss;
        for(int i = 0; i < nr; ++i) ss << "0";
        return ss.str();
    };
    const auto match = [&get](int nr, int i) -> bool {
        const std::regex match {"^(0{"+std::to_string(nr)+"})+$"};
        return std::regex_match(get(i), match);
    };
    for(int i = 1; i <= 100; ++i) {
        if(match(15, i)) std::cout << "FizzBuzz";
        else if(match(3, i)) std::cout << "Fizz";
        else if(match(5, i)) std::cout << "Buzz";
        else std::cout << i;
        std::cout << std::endl;
    }
}

void fb14() {
    for(int i = 1; i <= 100; ++i) {
        try {
            if(!(i % 15))throw std::string{"FizzBuzz"};
            if(!(i % 3)) throw std::string{"Fizz"};
            if(!(i % 5)) throw std::string{"Buzz"};
            throw std::to_string(i);
        } catch(std::string& e) {
            std::cout << e << std::endl;
        }
    }
}

void fb15() {
    const std::string r {"FizzBuzz            Fizz    BuzzFizz        FizzBuzz    Fizz        "};
    for(int i = 1; i <= 100; ++i) {
        std::string x {r.substr(i % 15 * 4 + (i % 15 ? 8 : 0), i % 15 ? 4 : 8)};
        x.erase(std::remove_if(x.begin(), x.end(), isspace), x.end());
        std::cout << x;
        if(x.empty()) std::cout << i;
        std::cout << std::endl;
    }
}

void fb16(int i = 1) {
    if(!(i % 15)) std::cout << "FizzBuzz";
    else if(!(i % 3)) std::cout << "Fizz";
    else if(!(i % 5)) std::cout << "Buzz";
    else std::cout << i;
    std::cout << std::endl;
    if(i <= 100) fb16(++i);
}

void fb17() {
    for(int i = 1; i <= 100; ++i) {
        bool f = i / 3.0 == i / 3;
        bool b = i / 5.0 == i / 5;
        if(f) std::cout << "Fizz";
        if(b) std::cout << "Buzz";
        if(!(f|b)) std::cout << i;
        std::cout << std::endl;
    }
}

void fb18() {
    int f {0}, b {0};
    for(int i = 1; i <= 100; ++i) {
        ++f;
        ++b;
        if(f != 3 && b != 5) {
            std::cout << i;
        }
        else {
            if(f == 3) {
                std::cout << "Fizz";
                f = 0;
            }
            if(b == 5) {
                std::cout << "Buzz";
                b = 0;
            }
        }
        std::cout << std::endl;
    }
}

void fb19() {
    const auto f = [](int) ->void { std::cout << "Fizz"; };
    const auto b = [](int) ->void { std::cout << "Buzz"; };
    const auto fb= [](int) ->void { std::cout << "FizzBuzz"; };
    const auto i = [](int i) ->void { std::cout << i; };
    const std::function<void(int)> lookup[15] {fb, i, i, f, i, b, f, i, i, f, b, i, f, i, i};
    for(int i = 1; i <= 100; ++i) {
        lookup[i%15](i);
        std::cout << std::endl;
    }
}

namespace fb20n {
    template<int N>
    void print(int i)  {
        std::cout << i;
    }
    template<>
    void print<0>(int i) {
        std::cout << "FizzBuzz";
    }
    template<>
    void print<5>(int i) {
        std::cout << "Buzz";
    }
    template<>
    void print<10>(int i) {
        std::cout << "Buzz";
    }
    template<>
    void print<3>(int i) {
        std::cout << "Fizz";
    }
    template<>
    void print<6>(int i) {
        std::cout << "Fizz";
    }
    template<>
    void print<9>(int i) {
        std::cout << "Fizz";
    }
    template<>
    void print<12>(int i) {
        std::cout << "Fizz";
    }
    template<int N>
    void process() {
        process<N-1>();
        print<N%15>(N);
        std::cout << std::endl;
    }
    template<>
    void process<0>() {
    }
}
void fb20() {
    fb20n::process<100>();
}

namespace fb21n {
    template <int N, int F, int B> struct P;
    template <int N>
    void process() {
        P<N, N%3, N%5>::print();
    }
    template <int N, int F, int B>
    struct P {
        static void print() {
            process<N-1>();
            std::cout << N << std::endl;
        }
    };
    template <int N, int B>
    struct P<N, 0, B> {
        static void print() {
            process<N-1>();
            std::cout << "Fizz" << std::endl;
        }
    };
    template <int N, int F>
    struct P<N, F, 0> {
        static void print() {
            process<N-1>();
            std::cout << "Buzz" << std::endl;
        }
    };
    template <int N>
    struct P<N, 0, 0> {
        static void print() {
            process<N-1>();
            std::cout << "FizzBuzz" << std::endl;
        }
    };
    template <>
    struct P<0, 0, 0> {
        static void print() {}
    };
}
void fb21() {
    fb21n::process<100>();
}


int main(int argc, const char * argv[]) {
    
    fb01();
    fb02();
    fb03();
    fb04();
    fb05();
    fb06();
    fb07();
    fb08();
    fb09();
    fb10();
    fb11();
    fb12();
    fb13();
    fb14();
    fb15();
    fb16();
    fb17();
    fb18();
    fb19();
    fb20();
    fb21();
    
    return 0;
}
