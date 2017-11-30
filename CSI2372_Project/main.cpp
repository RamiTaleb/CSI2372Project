#include <iostream>
#include "Dice.h"
#include "Colour.h"
#include "RollOfDice.h"
#include "QwintoRow.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Dice d(Colour::RED,3);
	d.roll();
	std::cout<< d <<std::endl;
	RollOfDice r;
    
    r.roll();
    
    std::cout << r << std::endl;
    
    std::cout <<  r.getSum() << std::endl;
    
    RollOfDice b = r.pair(1, 2);
    
    std::cout << b << std::endl;
    
    for ( Dice &d : r ) {
        std::cout << d << std::endl;
    }
    
    QwintoRow<Colour::RED> qr;
    
//    std::cout << qr.operator<<(std::cout) << std::endl;
    
	return 0;
}
