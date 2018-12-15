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
#include <array>
#include <filesystem>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>

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

NO_INLINE void TestOptional()
{
    std::optional<int> i = 5;
    std::optional<int> emptyInt;
    std::optional<bool> bFalse = false;
    std::optional<bool> bTrue = true;
    std::optional<bool> bEmpty;

    CauseDump();
}

NO_INLINE void TestPath()
{
    auto pathSeparator = std::filesystem::path::preferred_separator;
    std::filesystem::path root = "/my/test";
    std::filesystem::path child = root / "child";
    std::filesystem::path wroot = L"/my/test";
    std::filesystem::path wchild = root / L"child";

    TestOptional();
}

NO_INLINE void TestBoolContainers()
{
    bool carray[] = { true, true, false, false, true, false, true, true, false };
    std::array<bool, sizeof(carray)/sizeof(carray[0])> array;
    std::copy(std::begin(carray), std::end(carray), std::begin(array));
    std::vector<bool> vector(array.begin(), array.end());

    TestPath();
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

    TestBoolContainers();
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
