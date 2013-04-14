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
    int test = 1;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    Brig shipsBrig(9);
    
    Dorc dorcs[5];
    Porc porcs[5];
    Borc borcs[3];

/*  TEST #1  */
        
    shipsBrig += porcs[0];
    shipsBrig += borcs[0];
    shipsBrig += dorcs[0];
    shipsBrig += borcs[1];
    (shipsBrig += porcs[1]) += porcs[2];
    
    cout << "Brig Test " << test++ << endl << endl
         << shipsBrig << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
/*  TEST #2  */
        
    List pirateShipment1;
    pirateShipment1 += dorcs[1];
    pirateShipment1 += dorcs[2];
    pirateShipment1 += porcs[3];
    
    shipsBrig += pirateShipment1 + dorcs[3];

    cout << "Test " << test++ << endl << endl
         << shipsBrig << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
/*  TEST #3  */
 
        
    shipsBrig -= porcs[2];
        
    cout << "Test " << test++ << endl << endl
         << shipsBrig << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
/*  TEST #4  */
    List pirateShipment2 = pirateShipment1;


    
    pirateShipment2 -= dorcs[2];


    shipsBrig -= pirateShipment2 - dorcs[1];

    cout << "Test " << test++ << endl << endl
         << shipsBrig << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

/*  TEST #5  */
      
    
    shipsBrig -= shipsBrig[1];

    cout << "Test " << test++ << endl << endl
         << shipsBrig << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

         /*  TEST #6  */
        
    //shipsBrig += pirateShipment1[1];

    cout << "Test " << test++ << endl << endl
         << shipsBrig << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

/*  TEST #7  */
        
    List pirateShipment3 = dorcs[1];

    cout << "Test " << test++ << endl << endl
         <<"Two shipments equal?  "<< 
          ((pirateShipment1 == pirateShipment2)?"yes":"no") << endl
         <<"Two shipments not equal?  "<< 
          ((pirateShipment1 != pirateShipment2)?"yes":"no") << endl
         <<"Two modified shipments equal?  "<< 
          ((pirateShipment1 == pirateShipment3+dorcs[2]+porcs[3])?"yes":"no") << endl
         <<"Shipment equal to itself?  "<< 
          ((pirateShipment2 == pirateShipment2)?"yes":"no") << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl <<endl;



    return 0;
}