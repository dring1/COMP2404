/* * * * * * * * * * * * * * *
 COURSE:  COMP2404
 ASSMT:   Assignment #3
 DATE:    February 2, 2012
 * * * * * * * * * * * * * * */

#include "Brig.h"
#include "List.h"
#include "Dorc.h"
#include "Borc.h"
#include "Porc.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	Brig brig(9);
	Dorc d;
	Borc b;
	Porc p;


	brig+=d;
	//brig+=d;
	brig+=b;
	brig+=p;
	//cout<<brig<<endl;

	//brig-=d;

	cout<<brig<<endl;

	brig-=b;


	cout<<brig<<endl;
	
	//brig-=p;

	//cout<<brig<<endl;
	
}

