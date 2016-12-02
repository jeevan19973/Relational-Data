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
			str = "" ;
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
		 vector<string> sc;
             	for( int j = 0 ; j < v.size(); j++)
             	{
             	       string s=v[j];
		       string eg = "" ;
                     for(int k = 0 ; k < s.size() ; k++)
                     {
                          
                         
                         if(!(isalnum(s[k]))) //to check if not alphanumeric
                               { if( eg.compare("") != 0 ) sc.push_back(eg);
				eg = s[k] ;	
				sc.push_back(eg) ;
				eg = "";
				}

                         if(isalnum(s[k]))//to check num or upper,lower char
                                { 
                                 // string eg;
                                  eg+=s[k];
                                  continue;
                                 }
                               
                     }
			if( eg.compare("") != 0 ) { sc.push_back(eg) ; eg = "" ; } // added now
                    } 
                    m1[i]=sc;
                      
             }


		//PRINTING FROM MAP m1 - all split tokens ( completely ) 
		for( int i = 0 ; i < pos ; i++ )
			{
				vector<string> v = m1[i] ;
				for( int j = 0 ;j < v.size() ; j++ )
					{
						cout << v[j] << " " ;
					}
				cout << endl ;
			}



	return 0 ;
	}
 
