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
	//Pirate p;

	Dorc d;
	Dorc d2;
	Dorc d3;
	Dorc d5 = d3;
	///cout <<p<<endl;

	cout << d<<endl;

	List l(d);
	l+d2+d3+d2;
	cout<<l.getSize()<< endl;
	l-d2;
	cout<<l.getSize()<< endl;
	l+= d2;
	l+d5+d3;
	l+d5+d5;
	cout<<l.getSize()<< endl;
	l-=d5;
	cout<<l.getSize()<<"\n\n"<< endl;

	List l2(d);
	l2+d+d+d+d;
	cout<<l2.getSize()<< endl;
	l2-d;
	cout<<l2.getSize()<< endl;


	List l3(d);
	l3+d+d+d5;


	List l4(d);
	l4+d+d+d5;

	cout<<((l4==l3)?"Yes":"False")<<endl;


	List list(d);
	List list2(d2);
	list+d2+d3;
	cout<<list.getSize()<< endl;
	cout<<list2.getSize()<< endl;

	list2 = list + d;

	cout<<list.getSize()<< endl;
	cout<<list2.getSize()<< endl;

	List list3(list);
	cout<<list3.getSize()<< endl;

	cout <<((list==list3)?"YES":"NO")<<endl;
	cout <<((list!=list3)?"YES":"NO")<<endl;
	list.superPrint();


	Cell c(1,5);
	c+=d; 
		
    return 0;
}

