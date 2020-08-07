#include <iostream>

using namespace std;

int strstr(const char *text, const char *pattern);

void test()
{
 (0  == strstr("","")) ? cout<<"OK : 1"<< " (" << 0 << " : " << (0  == strstr("","")) << " )" << endl : cout<< "Failed : 1"<< " (" << 0 << " : " << (0  == strstr("","")) << " )" << endl ;
  (0 == strstr("a", "")) ? cout<<"OK : 2"<< " (" << 0 << " : " <<   (0 == strstr("a", "")) << " )" << endl : cout<< "Failed : 2"<< " (" << 0 << " : " <<   (0 == strstr("a", "")) << " )" << endl ;
  (0 == strstr("a", "a")) ? cout<<"OK : 3"<< " (" << 0 << " : " <<   (0 == strstr("a", "a")) << " )" << endl : cout<< "Failed : 3"<< " (" << 0 << " : " <<   (0 == strstr("a", "a")) << " )" << endl ;
  (-1 == strstr("a", "b")) ? cout<<"OK : 4"<< " (" << -1 << " : " <<   (-1 == strstr("a", "b")) << " )" << endl : cout<< "Failed : 4"<< " (" << -1 << " : " <<   (-1 == strstr("a", "b")) << " )" << endl ;
               
  (0 == strstr("aa", "")) ? cout<<"OK : 5"<< " (" << 0 << " : " <<   (0 == strstr("aa", "")) << " )" << endl : cout<< "Failed : 5"<< " (" << 0 << " : " <<   (0 == strstr("aa", "")) << " )" << endl ;
  (0 == strstr("aa", "a")) ? cout<<"OK : 6"<< " (" << 0 << " : " <<   (0 == strstr("aa", "a")) << " )" << endl : cout<< "Failed : 6"<< " (" << 0 << " : " <<   (0 == strstr("aa", "a")) << " )" << endl ;
  (0 == strstr("ab", "a")) ? cout<<"OK : 7"<< " (" << 0 << " : " <<   (0 == strstr("ab", "a")) << " )" << endl : cout<< "Failed : 7"<< " (" << 0 << " : " <<   (0 == strstr("ab", "a")) << " )" << endl ;
  (1 == strstr("ba", "a")) ? cout<<"OK : 8"<< " (" << 1 << " : " <<   (1 == strstr("ba", "a")) << " )" << endl : cout<< "Failed : 8"<< " (" << 1 << " : " <<   (1 == strstr("ba", "a")) << " )" << endl ;
  (-1 == strstr("bb", "a")) ? cout<<"OK : 9"<< " (" << -1 << " : " <<   (-1 == strstr("bb", "a")) << " )" << endl : cout<< "Failed : 9"<< " (" << -1 << " : " <<   (-1 == strstr("bb", "a")) << " )" << endl ;
               
  (0 == strstr("aaa", "")) ? cout<<"OK : 10"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "")) << " )" << endl : cout<< "Failed : 10"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "")) << " )" << endl ;
  (0 == strstr("aaa", "a")) ? cout<<"OK : 11"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "a")) << " )" << endl : cout<< "Failed : 11"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "a")) << " )" << endl ;
  (1 == strstr("abc", "b")) ? cout<<"OK : 12"<< " (" << 1 << " : " <<   (1 == strstr("abc", "b")) << " )" << endl : cout<< "Failed : 12"<< " (" << 1 << " : " <<   (1 == strstr("abc", "b")) << " )" << endl ;
  (2 == strstr("abc", "c")) ? cout<<"OK : 13"<< " (" << 2 << " : " <<   (2 == strstr("abc", "c")) << " )" << endl : cout<< "Failed : 13"<< " (" << 2 << " : " <<   (2 == strstr("abc", "c")) << " )" << endl ;
  (-1 == strstr("abc", "d")) ? cout<<"OK : 14"<< " (" << -1 << " : " <<   (-1 == strstr("abc", "d")) << " )" << endl : cout<< "Failed : 14"<< " (" << -1 << " : " <<   (-1 == strstr("abc", "d")) << " )" << endl ;
               
  (-1 == strstr("a", "aa")) ? cout<<"OK : 15"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aa")) << " )" << endl : cout<< "Failed : 15"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aa")) << " )" << endl ;
  (-1 == strstr("a", "ba")) ? cout<<"OK : 16"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ba")) << " )" << endl : cout<< "Failed : 16"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ba")) << " )" << endl ;
  (-1 == strstr("a", "ab")) ? cout<<"OK : 17"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ab")) << " )" << endl : cout<< "Failed : 17"<< " (" << -1 << " : " <<   (-1 == strstr("a", "ab")) << " )" << endl ;
  (-1 == strstr("a", "bb")) ? cout<<"OK : 18"<< " (" << -1 << " : " <<   (-1 == strstr("a", "bb")) << " )" << endl : cout<< "Failed : 18"<< " (" << -1 << " : " <<   (-1 == strstr("a", "bb")) << " )" << endl ;
               
  (-1 == strstr("a", "aaa")) ? cout<<"OK : 19"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aaa")) << " )" << endl : cout<< "Failed : 19"<< " (" << -1 << " : " <<   (-1 == strstr("a", "aaa")) << " )" << endl ;
  (-1 == strstr("aa", "aaa")) ? cout<<"OK : 20"<< " (" << -1 << " : " <<   (-1 == strstr("aa", "aaa")) << " )" << endl : cout<< "Failed : 20"<< " (" << -1 << " : " <<   (-1 == strstr("aa", "aaa")) << " )" << endl ;
  (0 == strstr("aaa", "aaa")) ? cout<<"OK : 21"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "aaa")) << " )" << endl : cout<< "Failed : 21"<< " (" << 0 << " : " <<   (0 == strstr("aaa", "aaa")) << " )" << endl ;
  (0 == strstr("aaab", "aaa")) ? cout<<"OK : 22"<< " (" << 0 << " : " <<   (0 == strstr("aaab", "aaa")) << " )" << endl : cout<< "Failed : 22"<< " (" << 0 << " : " <<   (0 == strstr("aaab", "aaa")) << " )" << endl ;
  (1 == strstr("baaa", "aaa")) ? cout<<"OK : 23"<< " (" << 1 << " : " <<   (1 == strstr("baaa", "aaa")) << " )" << endl : cout<< "Failed : 23"<< " (" << 1 << " : " <<   (1 == strstr("baaa", "aaa")) << " )" << endl ;
  (1 == strstr("baaaa", "aaa")) ? cout<<"OK : 24"<< " (" << 1 << " : " <<   (1 == strstr("baaaa", "aaa")) << " )" << endl : cout<< "Failed : 24"<< " (" << 1 << " : " <<   (1 == strstr("baaaa", "aaa")) << " )" << endl ;
  (1 == strstr("baaab", "aaa")) ? cout<<"OK : 25"<< " (" << 1 << " : " <<   (1 == strstr("baaab", "aaa")) << " )" << endl : cout<< "Failed : 25"<< " (" << 1 << " : " <<   (1 == strstr("baaab", "aaa")) << " )" << endl ;
  (-1 == strstr("abd", "abc")) ? cout<<"OK : 26"<< " (" << -1 << " : " <<   (-1 == strstr("abd", "abc")) << " )" << endl : cout<< "Failed : 26"<< " (" << -1 << " : " <<   (-1 == strstr("abd", "abc")) << " )" << endl ;
               
  (2 == strstr("ababc", "abc")) ? cout<<"OK : 27"<< " (" << 2 << " : " <<   (2 == strstr("ababc", "abc")) << " )" << endl : cout<< "Failed : 27"<< " (" << 2 << " : " <<   (2 == strstr("ababc", "abc")) << " )" << endl ;
  (3 == strstr("abdabc", "abc")) ? cout<<"OK : 28"<< " (" << 3 << " : " <<   (3 == strstr("abdabc", "abc")) << " )" << endl : cout<< "Failed : 28"<< " (" << 3 << " : " <<   (3 == strstr("abdabc", "abc")) << " )" << endl ;

}

int strstr(const char *text, const char *pattern)
{
    if(*pattern == '\0')
        return 0;
    for(int i = 0; *(text+i) != '\0' ;i++)
        for(int j = 0; *(pattern+j) == *(text+(i+j));j++)
        {
            if(*(pattern+j+1)=='\0')
                return i;
            if(*(text+(i+j)) == '\0')
                return -1;
        }
return -1;
}


int main(int argc, const char *argv[])
{
    test();        


 //   cout << strstr("","") << endl;
    //cout << strstr("a","") << endl;
    cout << strstr("aaaaa","a") << endl;
   // cout << strstr("a","ab") << endl;
   // cout << strstr("a","ba") << endl;
   // cout << strstr("a","bba") << endl;
    return 0;
}
