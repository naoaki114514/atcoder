#include<string>
#include<iostream>

class Radix {
private:
  const char* s;
  int a[128];
public:
  Radix(const char* s = "0123456789ABCDEF") : s(s) {
    int i;
    for(i = 0; s[i]; ++i)
      a[(int)s[i]] = i;
  }
  std::string to(long long p, int q) {
    int i;
    if(!p)
      return "0";
    char t[64] = { };
    for(i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return std::string(t + i + 1);
  }
  std::string to(const std::string& t, int p, int q) {
    return to(to(t, p), q);
  }
  long long to(const std::string& t, int p) {
    int i;
    long long sm = a[(int)t[0]];
    for(i = 1; i < (int)t.length(); ++i)
      sm = sm * p + a[(int)t[i]];
    return sm;
  }
};

int main() {
    Radix r;
    // 10 進数を n 進文字列に
    std::cout << r.to(255, 10) << std::endl; // => "255"
    std::cout << r.to(255, 12) << std::endl; // => "193"
    std::cout << r.to(255, 16) << std::endl; // => "FF"

    // n 進文字列を 10 進数に
    std::cout << r.to("255", 10) << std::endl; // => 255
    std::cout << r.to("255", 14) << std::endl; // => 467

    // n 進文字列を m 進文字列に
    std::cout << r.to("255", 7, 11) << std::endl; // => "116"
    std::cout << r.to("255", 11, 7) << std::endl; // => "611"
    return 0;
}