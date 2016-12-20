//ASSUMPTION 1 ::::  Each line in the sample input contains only 1 statement


#include <bits/stdc++.h>
#define kwordssize 8
#define decwordssize 7
using namespace std;

typedef long long ll;

set<int> statedepend( vector<int> parents[] , string s , map<int,vector<string> > m2 , int cur)
			{
			  set<int> ans ;
			  for( int i = 0 ; i < m2[cur].size() ; i++ )
				{
				  if( m2[cur][i].compare(s) == 0 ) { ans.insert( cur ) ; return ans ; }
				}
			  
			 for( int i = 0 ; i < parents[cur].size() ; i++ )
				{
				 set<int> dup = statedepend( parents , s , m2 , parents[cur][i] ) ;
				 ans.insert( dup.begin() , dup.end()) ;
				}
			 return ans ;
			}


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

		//Added start Dec 7
				 if( s[k] == '{' ) { openbracket.push_back( i ) ; }
				 if( s[k] == '}' ) { 
							pair<int,int> pa ;
						        pa.first = openbracket[openbracket.size()-1] ;
							pa.second = i ;
							bracketpairs.push_back( pa ) ;
							int end = openbracket.size() - 1 ;
							openbracket.erase(openbracket.begin() + end ) ;
						}
		//Added end Dec 7        
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
	 string kwords[]={"if","else","continue","switch","for","while","do","return"};
	string decwords[] = {"int" , "long" , "float" , "double" , "struct" , "vector" , "char"} ;	

	if( v.size() > 1 && v[1].compare("#") == 0 ) { m2[i] = assign ; m3[i] = used ; continue ; } //To skip the line of '#'s
	
									//To skip the line of "for" ---- start
	if( v.size() > 1 && v[1].compare("for") == 0 ) 
							{
							int semicolcnt = 0 ;
								for( int j = 2 ; j < v.size() ; j++ )
									{
										if( v[j].compare(")") == 0 ) semicolcnt = 1 ; 
										if( v[j].compare(";") == 0 ) semicolcnt++ ;
										if( semicolcnt == 2 ) { 
												  int flag = 1 ;
				  for( int k = 0 ; k < kwordssize; k++ )
					{
					 if( v[j].compare(kwords[k]) == 0 ) { flag = 0 ; break ; }
					}
				  if( flag )  { usedpush( v[j] , used ) ;
						}
					
													}

									}
							 m2[i] = assign ; m3[i] = used ; continue ;

								}
									//To skip the line of "for" ---- end
	int eqpresent = 0 ;		
       
	for( int j = 0 ; j < v.size() ; j++ )
		{
		  if( v[j].compare("=") == 0 && !(v[j-1].compare("!") == 0 || v[j-1].compare("=") == 0 || v[j+1].compare("=") == 0 || v[j-1].compare(">") == 0 || v[j-1].compare("<") == 0 ) ) { eqpresent = 1 ; 
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

		//To find the path between nodes 
		//For proper understanding please check "Testing_WhiteBox" page number 27
		//START - Date 21/12/2016
		set<int> children[pos] ;
		int Start = bracketpairs[bracketpairs.size()-1].first ;
		string conditional[] = {"if" , "else" , "for" , "while"} ;
		for( int i = Start ; i <= bracketpairs[bracketpairs.size()-1].second ; i++ )
			{
			  		
					 int continflag = 0 ;
					 for( int k = 0 ; k < bracketpairs.size() ; k++ )
									{
										if( bracketpairs[k].second == i )
										 			{
													  continflag = 1 ; break ;
													}
									}
					if( continflag == 1 ) continue ;
					if( m1[i][1].compare("if") == 0 ) 
								{ 
								  children[i].insert(i+1) ;
								  int curblock = -1 ;
								  for( int k = 0 ; k < bracketpairs.size() ; k++ )
									{
										if( bracketpairs[k].first == i )
										 			{
													  curblock = k ; break ;
													}
									}
								  int nextblock = curblock ;
								  int laterelse = 0 ;
								  while( 1 ) 
									{
									  nextblock++ ;
				
									 if( m1[bracketpairs[nextblock].first][1].compare("else") == 0 && bracketpairs[nextblock].first > i ) { children[i].insert(bracketpairs[nextblock].first) ; laterelse++ ; }
									 else break ;		   
									}
								  
							          if( laterelse == 0 ) { children[i].insert(bracketpairs[curblock].second+1) ;
											 children[bracketpairs[curblock].second].insert(bracketpairs[curblock].second+1) ; }
								  else { 
										int commonchild = bracketpairs[nextblock-1].second + 1;
										int Dupnextblock = curblock ;
										while(Dupnextblock != nextblock )
											{
											  children[bracketpairs[Dupnextblock].second].insert(commonchild) ;
											  Dupnextblock++ ;
											}
								}

								}
					else if( m1[i][1].compare("while") == 0  || m1[i][1].compare("for") == 0)
								{
								  children[i].insert(i+1) ;
								  int curblock = -1 ;
								  for( int k = 0 ; k < bracketpairs.size() ; k++ )
									{
										if( bracketpairs[k].first == i )
										 			{
										
													  curblock = k ; break ;
													}
									}
								   children[i].insert(bracketpairs[curblock].second + 1) ;
								   children[bracketpairs[curblock].second].insert(bracketpairs[curblock].second+1) ;
								}
					else { children[i].insert(i+1) ; }

				}

		//END

		//Date 21/12/2016
		vector<int> childvector[pos] ;
		for( int i = 0 ; i < pos ; i++ )
			{
				childvector[i].assign(children[i].begin(),children[i].end()) ;
			}

		vector<int> parents[pos] ;
		for( int i = 0 ; i < pos ; i++ )
			{
			  for( int j = 0 ; j < childvector[i].size() ; j++ )
				{
				  int p = childvector[i][j] ;
				  if( p < pos ) parents[p].push_back( i ) ;
				}
			}
		
		/*for( int i = 0 ; i < pos ; i++ )
			{
			 cout << i << " -->" ;
			 for( int j = 0 ; j < parents[i].size() ; j++ )
				{
				 cout << parents[i][j] << " " ;
				}
			cout << endl ;
			}
*/
//Date 21/12/2016
	cout << "Assigned" << endl ;
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



	cout << endl << "Variable Dependency" << endl ;
	for( int i = 0 ; i < pos ; i++ )
		{
		 if( m2[i].size() == 0 ) continue ;
		 if( m3[i].size() == 0 ) continue ; 
		 cout << "(" << m2[i][0] << ", " << i <<") depends on : " ;
		 vector<string> v = m3[i] ;
		
		
		 for( int j = 0 ; j < v.size() ; j++ )
			{
				cout << v[j] << " " ;
			}

		 cout << endl ;
		}


// Start Date 21/12/2016
	 cout << endl << "Statement Dependency" << endl ;
	for( int i = 0 ; i < pos ; i++ )
		{
		 if( m2[i].size() == 0 ) continue ;
		 if( m3[i].size() == 0 ) continue ;
		 cout << i << " depends on : " ;
		 vector<string> v = m3[i] ;
		 set<int> sdepend ;
		for( int k = 0 ; k < v.size() ; k++ )
			{		 
			  int fl = 0 ; 
			  for( int j = 0 ; j < parents[i].size() ; j++ )
				{
				 set<int> dup = statedepend( parents , v[k] , m2 , parents[i][j] ) ;
				 sdepend.insert( dup.begin() , dup.end() ) ;
				}
			}
		 vector<int> vdepend ;
		 vdepend.assign( sdepend.begin() , sdepend.end() ) ;
		 for( int j = 0 ; j < vdepend.size() ; j++ )
			{
			 cout << vdepend[j] << " " ;
			}
		 cout << endl ;
		}		

//  End Date 21/12/2016



	cout << endl << "Blocks" << endl ;
	for( int i = 0 ; i < bracketpairs.size() ; i++ )
		{
		 cout << bracketpairs[i].first << " " << bracketpairs[i].second << endl ;
		}

	


  return 0 ;
  }
 
