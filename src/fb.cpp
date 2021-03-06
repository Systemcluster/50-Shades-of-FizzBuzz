//
// 50 variants of Fizz Buzz.
// Copyright (c) 2014 Christian Sdunek
//
// This file currently contains 30 variants, more will be added eventually.
//

#include <iostream>
#include <string> // for solutions 6, 7, 8, 9, 10, 13, 14, 15, 24, 25
#include <sstream> // for solution 13
#include <vector> // for solution 6
#include <unordered_map> // for solutions 7, 8, 22
#include <regex> // for solutions 9, 13
#include <functional> // for solution 19
#include <tuple> // for solution 27
#include <map> // for solutions 27, 30
#include <utility> // for solution 30


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

void fb22() {
    std::unordered_map<int, std::string> map;
    for(int i = 15; i <= 100; i+=15) map.emplace(i, "FizzBuzz");
    for(int i =  3; i <= 100; i+=3) map.emplace(i, "Fizz");
    for(int i =  5; i <= 100; i+=5) map.emplace(i, "Buzz");
    for(int i =  1; i <= 100; ++i) {
        if(map.count(i)) std::cout << map.at(i);
        else std::cout << i;
        std::cout << std::endl;
    }
}

void fb23() {
    for(int i = 1; i <= 100; ++i) {
        int t  = i / 3;
        int tr = i - t * 3;
        int f  = i / 5;
        int fr = i - f * 5;
        if(!tr) std::cout << "Fizz";
        if(!fr) std::cout << "Buzz";
        if(fr && tr) std::cout << i;
        std::cout << std::endl;
    }
}

void fb24() {
    for(int i = 1; i <= 100; ++i) {
        std::string res = "";
        if(!(i % 3)) res += "Fizz";
        if(!(i % 5)) res += "Buzz";
        std::cout << (res.empty() ? std::to_string(i) : res) << std::endl;
    }
}

void fb25() {
    for(int i = 1; i<=100; std::cout << (i++ % 5? "":"Buzz") << std::endl)
    {
        std::cout << (i % 3? i % 5? std::to_string(i) : "" : "Fizz");
    }
}

namespace fb26n {
    template <int N, int F, int B> struct P;
    template <int N>
    void process() {
        P<N, N%3, N%5>{};
    }
    template <int N, int F, int B>
    struct P: P<N-1, (N-1) % 3, (N-1) % 5> {
        P() { std::cout << N << std::endl; }
    };
    template <int N, int B>
    struct P<N, 0, B>: P<N-1, (N-1) % 3, (N-1) % 5> {
        P() { std::cout << "Fizz" << std::endl; }
    };
    template <int N, int F>
    struct P<N, F, 0>: P<N-1, (N-1) % 3, (N-1) % 5> {
        P() { std::cout << "Buzz" << std::endl; }
    };
    template <int N>
    struct P<N, 0, 0>: P<N-1, (N-1) % 3, (N-1) % 5> {
        P() { std::cout << "FizzBuzz" << std::endl; }
    };
    template <>
    struct P<0, 0, 0> {
        P() { }
    };
}
void fb26() {
    fb26n::process<100>();
}

void fb27() {
    std::map<std::tuple<bool, bool>, std::function<void(int)>> map {
        {{0, 0}, [](int) {
            std::cout << "FizzBuzz";
        }},
        {{0, 1}, [](int) {
            std::cout << "Fizz";
        }},
        {{1, 0}, [](int) {
            std::cout << "Buzz";
        }},
        {{1, 1}, [](int n) {
            std::cout << n;
        }},
    };
    for(int i = 1; i <= 100; ++i) {
        map.at({(bool)(i % 3), (bool)(i % 5)})(i);
        std::cout << std::endl;
    }
}

void fb28() {
    int i {0};
    goto l;
f:
    std::cout << "Fizz";
    if(i % 5) goto n;
b:
    std::cout << "Buzz";
n:
    std::cout << std::endl;
l:
    if(i++ == 100) return;
    if(!(i % 3)) goto f;
    if(!(i % 5)) goto b;
    std::cout << i;
    goto n;
}

namespace fb29n {
    struct P {
        static int i;
        int max;
        P(int max): max(max) {
            if(i++==max) throw 0;
            if(!(i % 3)) std::cout << "Fizz";
            if(!(i % 5)) std::cout << "Buzz";
            if(i % 3 && i % 5) std::cout << i;
            std::cout << std::endl;
        }
    };
    int P::i {0};
}
void fb29() {
    try {
        while(true) (void)fb29n::P{100};
    }
    catch(...) {}
}

void fb30() {
    const auto f = [](int) ->void { std::cout << "Fizz"; };
    const auto b = [](int) ->void { std::cout << "Buzz"; };
    const auto fb= [](int) ->void { std::cout << "FizzBuzz"; };
    const auto i = [](int i) ->void { std::cout << i; };
    std::map<std::pair<bool, bool>, std::function<void(int)>> map {
        {{0,0},fb},
        {{0,1},f },
        {{1,0}, b},
        {{1,1},i }
    };
    for(int i = 1; i <= 100; ++i) {
        map[{i%3,i%5}](i);
        std::cout << std::endl;
    }
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
    fb22();
    fb23();
    fb24();
    fb25();
    fb26();
    fb27();
    fb28();
    fb29();
    fb30();
    
    return 0;
}
