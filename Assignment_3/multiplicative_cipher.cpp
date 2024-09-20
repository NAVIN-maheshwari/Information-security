#include<iostream>

using namespace std;
const int key = 7;
const int mod = 26;

int multiplicativeInverse(int n)
{
    for(int i = 1;i<=mod;i++)
    {
        if((n*i)%mod == 1)return i;
    }
}


string toCipher(string s)
{
   string cypher;

   for(int i = 0;i< s.size();i++)
   {
      if(s[i]>=97 && s[i] < 123)
      {
           int p = s[i]-97; 
           int c = (p*key)%mod;
           cypher.push_back(c+97);
      }
      else if(s[i]>=65 && s[i] < 91)
      {
        int p = s[i]-65; 
        int c = (p*key)%mod;
        cypher.push_back(c+65);
      }
      else
      {
        cypher.push_back(s[i]);
      }
   }

   return cypher;
}


string toPlain(string s)
{
   int keyInverse = multiplicativeInverse(key);
    
   string deCypher ;


   for(int i = 0;i< s.size();i++)
   {
      if(s[i]>=97 && s[i]<=123)
      {
           int c = s[i]-97; 
           int p = (c*keyInverse)%mod;
           deCypher.push_back(p+97);
      }
      else if(s[i]>=65 && s[i] < 91)
      {
           int c = s[i]-65; 
           int p = (c*keyInverse)%mod;
           deCypher.push_back(p+65);
      }
      else
      {
        deCypher.push_back(s[i]);
      }
   }

   return deCypher;
}

int main()
{
    
    string givenText;

    cout<<"Enter plain text"<<endl;

    
    getline(cin,givenText);

    string cypher = toCipher(givenText);

    cout<<"Encripted text :- "<<cypher<<endl;

    string decriptMessage = toPlain(cypher);

    cout<<"Decripted text :- "<<decriptMessage<<endl;

    return 0;
}