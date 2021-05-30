//Funda Tan 21801861
#include "Reservation.h"

Reservation::Reservation( const int no = 0, const int numPas = 0){
    numPassengers = numPas;
    resNo = no;
    flightNo = no;
}

Reservation::Reservation(){
    numPassengers = 0;
    resNo = 0;
    flightNo = 0;
}

Reservation::~Reservation(){
}

void Reservation::setResNo(int no){
    resNo = no;
}

void Reservation::setFlightNumber(int no){
    flightNo= no;
}

void Reservation::setNumPassengers(int no){
    numPassengers= no;
}

void Reservation::setRowRes(int*& arr){
    rowRes = arr;
}

void Reservation::setColRes(char*& arr){
    colRes = arr;
}

int Reservation::getResNo(){
    return resNo;
}

int Reservation::getFlightNumber(){
    return flightNo;
}

int Reservation::getNumPassengers(){
    return numPassengers;
}

int* Reservation::getRowRes(){
    return rowRes;
}

char* Reservation::getColRes(){
    return colRes;
}

