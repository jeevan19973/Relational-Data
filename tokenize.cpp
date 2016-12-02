#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
	{
		fstream fp("xyz.cpp") ;
		string line ;
		map<int,vector<string> > m ;
		int pos = 0 ;
		 while( getline( fp , line) )
		 		{
		 		
		 		vector<string> v ;
                //   int i = 0;
		 			string str ;
		 			string dup = line ;
                    stringstream ssin(dup);
                  while (ssin.good() )
                  {
               		ssin >> str ;
               		v.push_back( str ) ;
               	//	cout << str << endl ;
               //    ++i;
                 }

                 string num = v[0] ; //to check if this line has been numbered in "xyz.cpp" or not
                 if(!(num[0] >= '0' && num[0] <= '9') ) continue ;
                 pos++ ;
                 m[pos] = v ;
               
               }

                 map<int,vector<string> > m1 ;
                   int p=0;      
              
             for( int i = 0 ; i < pos ; i++)
             {
             	vector<string> v = m[i];
             	for( int j = 0 ; j < v.size(); j++)
             	{
             	       string s=v[j];
                     for(int i = 0 ; i < s.size() ; i++)
                     {
                           vector<string> sc;
                         
                         if(!(isalpha(s[i]))) //to check if not alphanumeric
                               sc[i]=s[i];

                         if(isalnum(s[i]) )//to check num or upper,lower char
                                { 
                                  sring eg;
                                  eg[i]=s[i];
                                  continue;
                                 }
                               
                     }
                    } 
                    m1[i]=sc;
                     
                     
             	
             }


	return 0 ;
	}
 