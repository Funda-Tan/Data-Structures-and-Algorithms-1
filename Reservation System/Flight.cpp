//Funda Tan 21801861
#include "Flight.h"
#include <iostream>
#include <string>
using namespace std;

Flight::Flight( const int no1 = 0, const int no2 = 0, const int no3 = 0){
    flightNo=no1;
    rowNo=no2;
    seatNo= no3;
    availableSeatNum=0;
    availableSeats = new char* [ no2];

    for( int i = 0; i < no2; i++){
        availableSeats[i] = new char[ no3];
    }

     for( int j = 0; j < no2; j++){
        for( int k = 0; k < no3; k++){
            availableSeats[j][k] = 'o';
            availableSeatNum++;
        }
    }
}

Flight::Flight(){
    flightNo = 0;
    rowNo = 0;
    seatNo = 0;
    availableSeatNum = 0;
    availableSeats = NULL;
}

Flight::~Flight(){
   if ( availableSeats ){
        for( int i = 0; i < rowNo;i++)
            delete[] availableSeats[i];

        delete[] availableSeats;
   }
}

Flight& Flight::operator=( const Flight& right ) {
    if ( &right != this ) { // to avoid self-assignment
        flightNo = right.flightNo;

        rowNo = right.rowNo;
        seatNo = right.seatNo;
        availableSeatNum = right.availableSeatNum;

        availableSeats = new char* [ rowNo];
        for( int i = 0; i < rowNo; i++){
            availableSeats[i] = new char[ seatNo];
        }

        for( int j = 0; j < rowNo; j++){
            for( int k = 0; k < seatNo; k++){
                availableSeats[j][k] = right.availableSeats[j][k];
            }
        }
    }
    return *this;
}

void Flight::editAvailableSeats( int no, int no1){
    availableSeats[no][no1] = 'x'; //reserved
}

void Flight::editAvailableSeatsFalse( int no, int no1){
    availableSeats[no][no1] = 'o'; //reserved
}

void Flight::setFlightNo( int no){
    flightNo = no;
}

void Flight::setRowNo( int no){
    rowNo = no;
}

void Flight::setSeatNo( int no){
    seatNo = no;
}

void Flight::setAvailableSeatNo(int no){
    availableSeatNum = no;
}

int Flight::getFlightNo(){
    return flightNo;
}

int Flight::getRowNo(){
    return rowNo;
}

int Flight::getSeatNo(){
    return seatNo;
}


int Flight::getAvailableSeatNo(){
    return availableSeatNum;
}

char**  Flight::getAvailableSeats(){
    return availableSeats;
}
