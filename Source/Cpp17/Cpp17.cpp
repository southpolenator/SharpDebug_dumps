// Cpp17.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

#ifdef _WIN32
  #define NO_INLINE __declspec(noinline)
#else
  #define NO_INLINE
#endif

#include <any>
#include <variant>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <memory>

using namespace std;

#pragma auto_inline(off)

struct BigTest
{
    char text[256];

    BigTest()
    {
        strcpy(text, "meow meow meow");
    }
};

#pragma optimize("", off)
NO_INLINE void CauseDump()
{
    // Generate the dump
    //throw std::bad_exception();
    int* a = nullptr;
    *a = 4;
}

NO_INLINE void TestAny()
{
    std::any a_int = 1729;
    std::any a_double = 3.14;
    std::any a_string = std::string("meow");
    std::any a_vector = std::vector<int>{};
    std::any a_list = std::list<int>();
    std::any a_map = std::map<int, int>();
    std::any a_bigTest = BigTest();
    std::any a_pair = std::make_pair(std::string("meow"), 3.14);
    std::any a_shared = std::make_shared<std::any>(a_pair);
    std::any a_empty;

    CauseDump();
}

NO_INLINE void TestVariant()
{
    std::variant<int, float> if1 = 42, if2 = 42.0f;
    std::variant<std::string, std::wstring> s1 = "ansiFoo", s2 = L"Foo";
    std::variant<double, int, std::string> e;

    TestAny();
}

NO_INLINE int main()
{
    TestVariant();
    return 0;
}
#pragma optimize("", on)
