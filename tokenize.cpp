#include <bits/stdc++.h>
#define kwordssize 7

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
                //  cout << str << endl ;
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

  map<int,vector<string> > m2 ;
  map<int,vector<string> > m3 ; 

    
    for( int i = 0 ; i < pos ; i++ )
      {
        vector<string> v = m1[i] ;
        vector<string> assign;
        vector<string> used;
	int eqpresent = 0 ;
        string kwords[]={"if","else","continue","switch","for","while","do"};
	for( int j = 0 ; j < v.size() ; j++ )
		{
		  if( v[j].compare("=") == 0 ) { eqpresent = 1 ; break ; }
		}
	
	if( eqpresent	== 0 ) { 
			for( int j = 0 ; j < v.size() ; j++ )
				{
				  int flag = 1 ;
				  for( int k = 0 ; k < kwordssize; k++ )
					{
					 if( v[j].compare(kwords[k]) == 0 ) { flag = 0 ; break ; }
					}
				  if( flag ) used.push_back( v[j] ) ;
					
				}
				}
	else {
		int flip = 0 ;
		for( int j = 0 ; j < v.size() ; j++ )
			{
			  if( v[j].compare("=") == 0 ) { flip = 1 ; continue ; }
			
				  int flag = 1 ;
				  for( int k = 0 ; k < kwordssize; k++ )
					{
					 if( v[j].compare(kwords[k]) == 0 ) { flag = 0 ; break ; }
					}

				  if( flag ) { if( flip ) used.push_back( v[j] ) ;
						else assign.push_back( v[j] ) ; 
						}
			}
		}
	
        
           m2[i]=assign;
           m3[i]=used;
      }


	cout << "Assigned" << endl ;
	for( int i = 0 ; i < pos ; i++ )
		{
		 vector<string> v = m2[i] ;
		 for( int j = 0 ; j < v.size() ; j++ )
			{
				cout << v[j] << " " ;
			}
		 cout << endl ;
		}		

	cout << endl << "Used" << endl ;
	for( int i = 0 ; i < pos ; i++ )
		{
		 vector<string> v = m3[i] ;
		 for( int j = 0 ; j < v.size() ; j++ )
			{
				cout << v[j] << " " ;
			}
		 cout << endl ;
		}		


  return 0 ;
  }
 
