#include<iostream>
#include<string>
#include<vector>
using namespace std;

int numUniqueEmails(vector<string>& emails);




void runCustomString()
{
  string email1= "raj.bh@gmail.com";
  string email2 = "raj.b.h@gmail.com";
  string email3 = "raj.b.h+chirag@gmail.com";
  string email4 = "raj.b.hchirag@gmail.com";
  string email5 = "rajbhchirag@gmail.com";
  string email6 = "rajbhchirag@gmail.com";

  std::vector<string> emails;

  emails.push_back(email1);
  emails.push_back(email2);
  emails.push_back(email3);
  emails.push_back(email4);
  emails.push_back(email5);
  emails.push_back(email6);
  
  std::cout << numUniqueEmails(emails);
  std::cin.get();
}

int numUniqueEmails(vector<string>& emails)
{
  int numberOfUniqueEmails = 0;
  std::vector<string> UniqueEmails;

  for (int i = 0; i<emails.size(); i++)
  {
    std::string temp = "";
    int atHit = 0;
    for (int j = 0; j<emails[i].length();)
    {

      if (emails[i][j] != '.')
      {
        temp += emails[i][j];
        j++;

        if (emails[i][j] == '+')
        {
          j++;

          while (emails[i][j] != '@')
            j++;
        }

        if (emails[i][j] == '@')
          atHit = 1;
      }

      if (emails[i][j] == '.')
      {
        if (atHit == 1)
          temp += emails[i][j];

          j++;
      }
    }

    if (i == 0)
      UniqueEmails.push_back(temp);
    else
    {
      int dupe = 0;
      for (int f = 0; f<UniqueEmails.size(); f++)
      {
        if (UniqueEmails[f] == temp)
          dupe++;
      }
      if (dupe == 0)
        UniqueEmails.push_back(temp);
    }
  }
  numberOfUniqueEmails = UniqueEmails.size();
  return numberOfUniqueEmails;
}

