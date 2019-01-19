#include<cstdio>
#include<cstdlib>
#include<cmath>
#define aaa
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

struct BigInteger {
  static const int BASE = 100000000;
  static const int WIDTH = 8;
  vector<int> s;

  BigInteger(long long num = 0) { *this = num; } // 构造函数

  BigInteger operator = (long long num) { // 赋值运算符
    s.clear();
    do {
      s.push_back(num % BASE);
      num /= BASE;
    } while(num > 0);
    return *this;
  }
  BigInteger operator = (const string& str) { // 赋值运算符
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;  //?
    for(int i = 0; i < len; i++) {
      int _end = str.length() - i*WIDTH;
      int start = max(0, _end - WIDTH);
      sscanf(str.substr(start, _end-start).c_str(), "%d", &x);
      s.push_back(x);
    }
    return *this;
  }

  //以下为比较操作
  bool operator < (const BigInteger& b) const {
    if(s.size() != b.s.size()) return (s.size() < b.s.size());
    for(int i = s.size()-1; i >= 0; i--)
        if(s[i] != b.s[i]) return (s[i] < b.s[i]);
    return false; //相等;
  }
  bool operator > (const BigInteger& b) const { return (b < *this); }
  bool operator <= (const BigInteger& b) const { return !(b < *this); }
  bool operator >= (const BigInteger& b) const { return !(*this < b); }
  bool operator != (const BigInteger& b) const { return (b < *this) || (*this < b); }
  bool operator == (const BigInteger& b) const { return !(b < *this) && !(*this < b); }

  //以下为四则运算
  BigInteger operator + (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    for(int i = 0, g = 0; ; i++) {
      if(g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = g;
      if(i < s.size()) x += s[i];
      if(i < b.s.size()) x += b.s[i];
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c;
  }
  BigInteger operator - (const BigInteger& b) const {
      BigInteger c;
      c.s.clear();
      if(*this > b) {
      for(int i = 0, g = 0; ; i++) {
        if(g == 0 && i >= s.size() && i >= b.s.size())break;
        int x = g;
        g = 0;
        if(i < s.size()) x += s[i];
        if(i < b.s.size())x -= b.s[i];
        if(x >= 0)c.s.push_back(x);
        else{c.s.push_back(BASE + x);g--;}
      }
      b:
        int t = c.s.back();
        c.s.pop_back();
        if(t != 0)c.s.push_back(t);
        else goto b;}
      else if(*this == b) {
        c = 0;
        return c;
      }
      else {
        for(int i = 0, g = 0; ; i++) {
            if(g == 0 && i >= s.size() && i >= b.s.size())break;
            int x = g;
            g = 0;
            if(i < s.size()) x -= s[i];
            if(i < b.s.size())x += b.s[i];
            if(x >= 0)c.s.push_back(x);
            else{c.s.push_back(BASE + x);g--;}
        }
        a:
        int t = c.s.back();
        c.s.pop_back();
        if(t != 0)c.s.push_back(-t);
        else goto a;
        return c;
      }
  }
  BigInteger operator * (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    if(*this == 0|| b == 0) {
        c = 0;
        return c;
    }
    for(int j = 0; ; j++) {
        BigInteger d;
        d.s.clear();
        if(j >= b.s.size())break;
        for(int n = 0; n < j; n++)d.s.push_back(0);
        int p = b.s[j];
        long long g = 0;
        for(int i = 0; ; i++) {
            if(g == 0 && i >= s.size())break;
            long long x = 0;
            if(i < s.size()) {
                x += s[i];
                x *= p;}
            x += g;
            d.s.push_back(x % BASE);
            g = x / BASE;
        }
        c = c + d;
    }
    return c;
  }
  BigInteger operator / (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    if(*this < b) {
        c.s.push_back(0);
        return c;
    }
    else if(*this == b) {
        c.s.push_back(1);
        return c;
    }
    else {
        if(s.size() == 1) {
            c.s.push_back(s[0] / b.s[0]);
        }
        else {
            int i,head,tail,mid;
            BigInteger mod;
            mod.s.clear();
            mod = 0;
            for(int j = 0; j < s.size(); j++)c.s.push_back(0);
            for(i = s.size() - 1; i >= 0; i--) {
                mod = mod * BASE + s[i];
                for(head = 0, tail = BASE - 1; head < tail;) {
                    mid = (head + tail + 1) / 2;
                    if(b * mid <= mod )head = mid;
                    else tail = mid - 1;
                }
                mod = mod - b * head;
                c.s[i] = head;
            }
        }
        a:
        int t = c.s.back();
        c.s.pop_back();
        if(t != 0)c.s.push_back(t);
        else goto a;
        return c;}
    }
  BigInteger operator % (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    if(*this < b) {
        c = *this;
        return c;
    }
    else if(*this == b) {
        c.s.push_back(0);
        return c;
    }
    else {
        int i,head,tail,mid;
        c = 0;
        for(i = s.size() - 1; i >= 0; i--) {
            c = c * BASE+ s[i];
            for(head = 0, tail = BASE - 1; head < tail;) {
                mid = (head + tail + 1) / 2;
                if(b * mid <= c )head = mid;
                else tail = mid - 1;
            }
            c = c - b * head;
        }
        return c;
    }
 }
};

ostream& operator << (ostream &out, const BigInteger& x) {
  out << x.s.back();
  for(int i = x.s.size()-2; i >= 0; i--) {
    char buf[20];
    sprintf(buf, "%08d", x.s[i]);
    for(int j = 0; j < strlen(buf); j++) out << buf[j];
  }
  return out;
}

istream& operator >> (istream &in, BigInteger& x) {
  string s;
  if(!(in >> s)) return in;
  x = s;
  return in;
}


int main() {
    #ifdef sub
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // sub
    BigInteger a,b;
    cin>>a>>b;
    cout<<a + b<<endl;
    cout<<a - b<<endl;
    cout<<a * b<<endl;
    cout<<a / b<<endl;
    cout<<a % b<<endl;
    return 0;
}
