#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

void runDecToHex()
{
  int x = 2545;
  string hexa;
  while (x)
  {
    char c;
    int mod = x % 16;
    if(mod < 10)
      c = char(48+mod);
    else
      c = char(65 + mod - 10);  
    hexa += c;

    x = x/16;
  }
  
  string final = {rbegin(hexa),rend(hexa)};
  std::cout << final;
}

void runDecToBin()
{
  int x = 10;
  string bina;

  while (x)
  {
    char c;
    int mod = x % 2;
    c = char(48 + mod);
    bina += c;
    x = x / 2;
  }

  string fial = {rbegin(bina),rend(bina)};
  std::cout << fial;
}

void runDecToBinBitwise()
{
   int x = 31;
   string bina;
   while (x)
   {
     if(x&1)
      bina += char(49);
    else
      bina += char(48);

    x = x >> 1;
   }
   string fial = { rbegin(bina),rend(bina) };
   std::cout << fial;
}

void runBinToDec()
{
  int x = 100001;
  int dec=0;
  int incr = 0;
  while (x)
  {
    int mod = x%10;
    dec += mod * pow(2,incr++);
    x = x/10;
  }
  std::cout << dec;
}

void runBinToDecString()
{
  string x = "11111";
  long dec = 0;
  int incr = 0;
  for (auto itr = x.rbegin(); itr < x.rend(); itr++)
  {
    char c = *itr;
    dec += (c-48) * pow(2,incr++);
  }
  std::cout << dec;
}

void runHexToDec()
{
  int x = 0x43;
  string color = "#02f166";
  
  stringstream sstr;
  string str;
  for (auto itr = color.rbegin(); itr<color.rend()-1; itr+=2)
  {
    char c0 = *itr;
    char c1 = *(itr + 1);

    if (c0>c1)
    {
      string thisOne = "0x" + string(1,c1) + string(1, c0);
      string lowOne = "0x" + string(1, c1) + string(1, c1);
      string highOne = "0x" + string(1, c1+1) + string(1, c1+1);
      stringstream sstrlocal;
      int tO, lO, hO;
      sstrlocal << std::hex << thisOne  << " " << lowOne << " " << highOne;
      sstrlocal >> tO >> lO >> hO;


      if (abs(tO - lO) < abs(tO - hO))
        sstr << c1 << c1;
      else
        sstr << char(c1 + 1) << char(c1 + 1);
    }
    else if (c0 == c1)
      sstr << c1 << c1;
    else if (c0 < c1)
    {

      sstr << char(c1 - 1) << char(c1 - 1);
    }
  }
  sstr >> str;
  cout << string{ rbegin(str),rend(str) };
}
  
