/*
Words starting with a vowel are added a "hay" at the end, word starting with
consonants are added all the starting consonants at the end + "ay"
*/


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isVowel(char ch){
    if(ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U' or ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
        return 1;
    return 0;
}

void pigLatin(string str){
  stringstream s(str);
  string word;
  vector<string> vs;


  while(s>>word){
    if(isVowel(word[0])){
        word=word+"hay";
        vs.push_back(word);
        cout<<"Test 1"<<endl;
    }
    else{
        int i=0;
        string temp;
        while(!isVowel(word[i])){
            temp+=word[i];
            i++;
        }
        word.erase(0,i);
        word+=temp+"ay";
        vs.push_back(word); 
    }
  }
  for(auto i:vs){
    cout<<i<<" ";
  }
  cout<<endl;
}
int main()
{
    vector<string> v1;
    string s;
    getline(cin,s);
    while(s!="0"){
        v1.push_back(s);
        getline(cin,s);
    }
    int randNum = rand()%(v1.size() + 1);

    pigLatin(v1[randNum]);


    return 0;
}
