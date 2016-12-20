1 #include<iostream>

2 int main()
3 	{

4 	 int x , y , z , pow ;
5 	 x = 0 ;
6 	 y = 0 ;
7 	 z = 0 ;
8 	 pow = 0 ;
9 	 if( y < 0 ) {
10  pow = 0 - y ; }

11 	 else {
12  pow = y ; }

13 	 z = 1 ;
14 	 while( pow != 0 ){

15 		 z = z * x ;
16 		 pow = pow - 1 ; 
17 		}

18 	 if( y < 0 ){

19 		 z = 4 + z ; 
20 		}

21 	  return 0 ;
22 	}

