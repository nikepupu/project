#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
string array;
int type;
int k;
void replacement(string &output, ostream& out);
void reset(string &output, int curPos);
bool test(string& output);
int findIndex(char c);


int main(int argc, char ** argv){
  
  if (argc != 3)
  {
    cout << "usage: ./attackGenerator.out {type:1 or 2}, {min_length}\n";
    return 0;
  }
  
  const int MAX_NUM = 10;
  const int MIN_NUM = atoi(argv[2]);
  type = atoi(argv[1]);
  string output;
  char temp;
 
 
  ofstream out("attackDictionary.txt");
  if (type == 1)
  {
    temp = '0';
    while(temp <= '9')
      array.push_back(temp++);
  }
  
  else if (type == 2)
  {
    temp = '0';
    while(temp <= '9')
      array.push_back(temp++);
    
    temp = 'a';
    while(temp <= 'z')
      array.push_back(temp++);
    
    temp = 'A';
    while(temp <= 'Z')
      array.push_back(temp++);
  }
  
  k = (type == 1)? 10 : 62;
  
  for (int i = MIN_NUM; i <= MAX_NUM; i++)
  {
    output.clear();
    
    // initialize string
    for (int k = 0; k < i; k++)
      output.push_back(array[0]);
    
    cout << "length: " << output.length() << endl;
    replacement(output, out);
    
  }
  
  out.close();
}

bool test(string& output)
{
  
  
  for (int i = 0; i < output.length(); i++)
  {
    if (output[i] != array[k-1] )
      return 1;
  }
  return 0;
}

int findIndex(char c)
{
  
  for(int i = 0; i < k; i++)
    if(c == array[i])
      return i;
  
  return 0;
}

void reset(string &output, int curPos)
{
  int index;
  
  
  while(output[curPos] == array[k-1])
  {
    output[curPos] = '0';
    curPos = curPos - 1;
  }
  
  if(curPos >= 0)
  {
    index = findIndex(output[curPos]);
    output[curPos] = array[index + 1];
  }
}

void replacement(string &output, ostream& out)
{
  int curPos = output.length() - 1;
 
  while (test(output))
  {
    reset(output, curPos);
    for(int i = 0; i < k; i++)
    {
      output[curPos] = array[i];
      out << output << endl;
    }

  }
  
}