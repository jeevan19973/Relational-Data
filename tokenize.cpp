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
<<<<<<< HEAD
                       str = "" ;
                  ssin >> str ;
      
                  v.push_back( str ) ;
                //  cout << str << endl ;
=======
			str = "" ;
               		ssin >> str ;
			
               		v.push_back( str ) ;
               	//	cout << str << endl ;
>>>>>>> 53a5e4abfc18069f27dc0fff01b783dd554bb5c3
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
<<<<<<< HEAD
              vector<string> v = m[i];
               vector<string> sc;
              for( int j = 0 ; j < v.size(); j++)
              {
                     string s=v[j];
                     string eg = "" ;
=======
             	vector<string> v = m[i];
		 vector<string> sc;
             	for( int j = 0 ; j < v.size(); j++)
             	{
             	       string s=v[j];
		       string eg = "" ;
>>>>>>> 53a5e4abfc18069f27dc0fff01b783dd554bb5c3
                     for(int k = 0 ; k < s.size() ; k++)
                     {
                          
                         
                         if(!(isalnum(s[k]))) //to check if not alphanumeric
                               { if( eg.compare("") != 0 ) sc.push_back(eg);
<<<<<<< HEAD
                                   eg = s[k] ; 
                                   sc.push_back(eg) ;
                                    eg = "";
        }
=======
				eg = s[k] ;	
				sc.push_back(eg) ;
				eg = "";
				}
>>>>>>> 53a5e4abfc18069f27dc0fff01b783dd554bb5c3

                         if(isalnum(s[k]))//to check num or upper,lower char
                                { 
                                 // string eg;
                                  eg+=s[k];
                                  continue;
                                 }
                               
                     }
<<<<<<< HEAD
      if( eg.compare("") != 0 ) { sc.push_back(eg) ; eg = "" ; } // added now
=======
			if( eg.compare("") != 0 ) { sc.push_back(eg) ; eg = "" ; } // added now
>>>>>>> 53a5e4abfc18069f27dc0fff01b783dd554bb5c3
                    } 
                    m1[i]=sc;
                      
             }
 map<int,vector<string> > m2 ;
  map<int,vector<string> > m3 

    
    for( int i = 0 ; i < pos ; i++ )
      {
        vector<string> v = m1[i] ;
        vector<string> assign;
        vector<string> used;
        string kwords[]={"if","else","continue","switch","for","while","do"};
        for( int j = 0 ;j < v.size() ; j++ )
          {
            for(int k=0;k<kwords.size();k++)
             {
                  if(v[j]!=kwords[k]&&v[j]!='=')
                   {
                      assign.push_back(v[j]);
                   }

                   if(v[j]!=kwords[k]&&v[j]=='=')
                    {
                        used.push_back(v[j+1]);

<<<<<<< HEAD
                    }
              }
           }
           m2[i]=assign;
           m[i]=used;
      }
  return 0 ;
  }
 
=======
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
 
>>>>>>> 53a5e4abfc18069f27dc0fff01b783dd554bb5c3
