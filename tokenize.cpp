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


              // PRINTING THE CONTENTS OF MAP to check
             for( int i = 0 ; i < pos ; i++)
             {
             	vector<string> v = m[i] ;
             	for( int j = 0 ; j < v.size() ; j++)
             	{
             		cout << v[j] << " " ;
             	}
             	cout << endl ;
             }


	return 0 ;
	}
 