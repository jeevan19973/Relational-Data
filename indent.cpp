#include <bits/stdc++.h>
#include <fstream>
#define ll long long

using namespace std;

int main()
        {
                string line ;
                fstream fp("inputf.in") ;
                fstream ofp("outputf.in") ;
                int cnt = 1 ;
                int flag = 0 ;
                int flag2 = 0 ;
                while( getline( fp , line))
                {
                        char c ;
                        int pos = 0 ;
                        // for( int i = 0 ; i < line.length() ; i++)
                        // {
                        //         c = line[i] ;
                        //         if( !isspace(c)){
                        //         ofp << cnt << " " ;
                        //         cnt++ ;
                        //                 break ;
                        //         }

                        // }

                        for( int i = 0 ; i < line.length() ; i++)
                        {
                        	c = line[i] ;
                        	if( !isspace(c) && flag2 == 1 ) { 
                        							if( c == ';'){ flag2 = flag = 0 ;}
                        							else { flag2 = 0 ;

ofp << '{' << endl ;
//ofp << cnt << " " ; cnt++ ;
                        							}
                        	}  
                        	if( !isspace(c) && c == '{' && flag == 1) { flag = 0 ; continue ;}
                        	ofp << c ;
                        	if( c == ')') { 
                        					flag2 = 1 ;
                        					flag = 1 ;
                        				  }
                        }
                        	ofp << endl ;
                      //  ofp << line << endl;
                 //     cnt++ ;
                }

  ifstream if2("outputf.in") ;
  ofstream ofp2("abc") ;
                while( getline( if2 , line))
                {
                	 char c ;
                        int pos = 0 ;
                        for( int i = 0 ; i < line.length() ; i++)
                        {
                                c = line[i] ;
                                if( !isspace(c)){
                                ofp2 << cnt << " " ;
                                cnt++ ;
                                        break ;
                                }

                        }
  ofp2 << line << endl;
                   //  cnt++ ;

                }



        return 0 ;
        }


