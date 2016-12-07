#include <bits/stdc++.h>
#define kwordssize 8
#define decwordssize 7
using namespace std;

typedef long long ll;

void usedpush( string s , vector<string> &used) 
		{
			
			int notnum = 0 ;
			for( int i = 0 ; i < s.length() ; i++ )
				{
				 if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )
					{ notnum = 1 ;
					  break ;
					}
				}
			if( notnum ) used.push_back( s ) ;

		}

void assignpush( string s , vector<string> &assign)
		{
			
			int notnum = 0 ;
			for( int i = 0 ; i < s.length() ; i++ )
				{
				 if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )
					{ notnum = 1 ;
					  break ;
					}
				}
			if( notnum ) assign.push_back( s ) ;

		}


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
               //   cout << str << " " ;
               //    ++i;
                 }
		 // cout << endl ;
                 string num = v[0] ; //to check if this line has been numbered in "xyz.cpp" or not
                 if(!(num[0] >= '0' && num[0] <= '9') ) continue ;
                 pos++ ;
                 m[pos] = v ;
               
               }

                 map<int,vector<string> > m1 ;
		 vector<int> openbracket ;  //added 7th Dec
		 vector<pair<int,int> > bracketpairs ; //added 7th Dec
                   int p=0;      
              
             for( int i = 0 ; i <= pos ; i++)
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
				 if( s[k] == '{' ) { openbracket.push_back( i ) ; }
				 if( s[k] == '}' ) { 
							pair<int,int> pa ;
						        pa.first = openbracket[openbracket.size()-1] ;
							pa.second = i ;
							bracketpairs.push_back( pa ) ;
							int end = openbracket.size() - 1 ;
							openbracket.erase(openbracket.begin() + end ) ;
						}
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
	
	if( v.size() > 1 && v[1].compare("#") == 0 ) { m2[i] = assign ; m3[i] = used ; continue ; } //To skip the line of '#'s

	int eqpresent = 0 ;
        string kwords[]={"if","else","continue","switch","for","while","do","return"};
	string decwords[] = {"int" , "long" , "float" , "double" , "struct" , "vector" , "char"} ;
	for( int j = 0 ; j < v.size() ; j++ )
		{
		  if( v[j].compare("=") == 0 ) { eqpresent = 1 ; 
						 break ; }
		}
	
	if( eqpresent == 0 ) { 

				//added 5 lines here, to check if there are no '='s and there are declarations
				int noused = 0 ;
		for( int k = 0 ; k < decwordssize ; k++ )
			{
			  if( v.size() > 1 && v[1].compare(decwords[k]) == 0 ) { noused = 1 ; break ; }
			} 
		if( noused) continue ;
			for( int j = 0 ; j < v.size() ; j++ )
				{
				  int flag = 1 ;
				  for( int k = 0 ; k < kwordssize; k++ )
					{
					 if( v[j].compare(kwords[k]) == 0 ) { flag = 0 ; break ; }
					}
				  if( flag )  { usedpush( v[j] , used ) ;
						}
					
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
				for( int k = 0 ; k < decwordssize ; k++ )
					{
			  		if( v[j].compare(decwords[k]) == 0 ) { flag = 0 ; break ; }
					}		 

				  if( flag ) { if( flip )  {usedpush( v[j] , used ) ;}
						else  { assignpush( v[j] , assign) ; }
						}
			}
		}
	
        
           m2[i]=assign;
           m3[i]=used;
      }


/*	cout << "Assigned" << endl ;
	for( int i = 0 ; i < pos ; i++ )
		{
		 vector<string> v = m2[i] ;
		 cout << i << " " ;
		 for( int j = 0 ; j < v.size() ; j++ )
			{
				cout << v[j] << " " ;
			}
		 cout << endl ;
		}		

	cout << endl << "Used" << endl ;
	for( int i = 0 ; i < pos ; i++ )
		{
		 cout << i << " " ;
		 vector<string> v = m3[i] ;
		 for( int j = 0 ; j < v.size() ; j++ )
			{
				cout << v[j] << " " ;
			}
		 cout << endl ;
		}

*/

	cout << endl << "Dependent Equal" << endl ;
	for( int i = 0 ; i < pos ; i++ )
		{
		 if( m2[i].size() == 0 ) continue ; 
		 cout << m2[i][0] << " depends on : " ;
		 for( int j = 0 ; j < m3[i].size() ; j++ )
			{
				cout << m3[i][j] << " " ;
			}
		 cout << endl ;
		}		

	cout << endl << "Blocks" << endl ;
	for( int i = 0 ; i < bracketpairs.size() ; i++ )
		{
		 cout << bracketpairs[i].first << " " << bracketpairs[i].second << endl ;
		}


  return 0 ;
  }
 
