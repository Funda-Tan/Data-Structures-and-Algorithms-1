//Funda Tan 21801861
#include <iostream>
#include <string>
#include "ReservationSystem.h"
#include "Flight.h"
#include "Reservation.h"
using namespace std;

ReservationSystem::ReservationSystem(){
    int count2 = 0;
    int count3= 0;
    numFlights = 0;
    int count1 = 0;
    numReservations = 0;
    flights = NULL;
    reservations = NULL;
    letters = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

ReservationSystem::~ReservationSystem(){
        if (flights){
            delete[] flights;
        }

        if (reservations){
            delete[] reservations;
        }
}

void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo){
    bool flag = true;
    for(int i = 0; i < numFlights; i++){
        if(flightNo == flights[i].getFlightNo()){
            flag = false;
            cout << "Flight " <<  flights[i].getFlightNo() << " already exists" << endl;
        }
    }

    if(rowNo < 0){
        flag = false;
    }

    if(seatNo < 0){
        flag = false;
    }

    if(flag == true){
        Flight* temp = flights;
        flights = new Flight[numFlights+1];

        for( int i = 0; i < numFlights; i++)
            flights[i] = temp[i];

        numFlights++;
        flights[numFlights-1].setAvailableSeatNo(rowNo*seatNo);
        flights[numFlights-1] = Flight(flightNo, rowNo, seatNo);

        delete[] temp;
        cout << "Flight " << flightNo << " has been added" << endl;
    }
}

void ReservationSystem::cancelFlight( const int flightNum ){
    bool flag = false;

    for(int i = 0; i < numFlights; i++){
        if(flightNum == flights[i].getFlightNo())
            flag = true;
    }

    if(flag == false)
        cout << "Flight " << flightNum << " does not exist" << endl;

    else{
        Flight* temp = flights;
        if(numFlights == 1){
            flights = NULL;
        }

        else{
            int index = 0;
            flights = new Flight[numFlights-1];
            for( int i = 0; i < numFlights; i++){
                if(temp[i].getFlightNo()!=flightNum){
                    flights[index]=temp[i];
                    index++;
                }

                for(int i = 0; i < numReservations; i++){
                    for( int i = 0; i < numReservations; i++){
                            for( int j = 0; j < numFlights; j++){
                                if(flights[j].getFlightNo() == reservations[i].getFlightNumber()){
                                    int count1 = 0;
                                    while(count1< reservations[i].getNumPassengers()) {
                                        int a1 = (reservations[i].getRowRes())[count1];

                                        int k = 0;
                                        for(int m = 0; m < 27;m++){
                                            if((letters.at(m))==(reservations[i].getColRes())[count1])
                                            k = m;
                                        }
                                        int a2 = k;

                                        flights[j].editAvailableSeatsFalse(a1-1, a2-1);
                                        count1++;
                                    }
                                }
                            }
                    }

                    Reservation* temp = reservations;
                    if(numReservations==1){
                        reservations = NULL;
                    }

                    else{
                        int index = 0;
                        reservations = new Reservation[numReservations-1];
                        for( int i = 0; i < numReservations; i++){
                            if(temp[i].getResNo()!= reservations[i].getResNo()){
                                reservations[index]=temp[i];
                                index++;
                            }
                        }
                    }

                    numReservations--;
                    delete[] temp;
                }
            }
        }

        numFlights--;
        cout << "Flight " <<flightNum << " and all of its reservations are canceled" << endl;
        delete[] temp;
    }
}


void ReservationSystem::showAllFlights(){
    if(numFlights == 0)
        cout << "No flights exist" << endl ;

    else{
        cout << endl;
        cout << "Flights currently operated:" << endl;

        for( int i = 0; i < numFlights; i++){
            cout << "Flight " << flights[i].getFlightNo() << " (" <<flights[i].getAvailableSeatNo()<< " available seats)" << endl;
        }
    }
    cout << endl;
}

void ReservationSystem::showFlight(const int flightNo){
    cout << endl;
    bool flag = false;

    for(int i = 0; i < numFlights; i++){
        if(flightNo == flights[i].getFlightNo())
            flag = true;
    }

    if(flag == false)
        cout << "Flight " << flightNo << " does not exist" << endl;

    if(flag == true){
        int i = 0;
        while( flightNo != flights[i].getFlightNo()){
            i++;
        }

        cout << "Flight " << flights[ i].getFlightNo() << " has " << flights[ i].getAvailableSeatNo() << " available seats" << endl;

        for(int j = 1; j < flights[i].getSeatNo()+1; ++j)
            cout << letters.at(j) << " ";

        cout << "\n";

        for(int j = 0; j < flights[i].getRowNo(); ++j){
            cout << j + 1<< " ";
            for(int k = 0; k < flights[i].getSeatNo(); ++k){
                char m = (flights[i].getAvailableSeats())[j][k];
                cout << m << " ";
            }
        cout << "\n";
        }
    }
}

int ReservationSystem::makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol ){
    bool flag = false;
    for(int i = 0; i < numFlights; i++){
        if(flightNo == flights[i].getFlightNo())
        flag = true;
    }

    if(flag == false)
        cout << "Flight " << flightNo << " does not exist" <<endl;

    if(flag == true){
        int i = 0;
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        static int no3 = 0;
        bool flag1 = true;
        while(flightNo != flights[i].getFlightNo()&& i < numFlights+1){
             i++;
        }

        if(i == numFlights + 1)
            return -1;

        while(count0 < numPassengers){
            int a1 = seatRow[count1];

            int j = 0;

            for(int i = 0; i < 27;i++){

                if((letters.at(i))==seatCol[count1])
                    j = i;
            }

            int a2 = j;
            if( ((flights[i].getAvailableSeats()))[a1-1][a2-1] == 'x' ){
                    cout << seatRow[count1]<<seatCol[count1] << " ";
                    count2++;
                flag1 = false;
            }
            count1++;
            count0++;
        }

        if(flag1==false){
            if(count2 < 2)
                cout  << "is not available" << endl;
            else
                cout  << "are not available" << endl;
            return -1;
        }

        i = 0;
        count0 = 0;
        count1 = 0;

        while( count0 < numPassengers){
            int a1 = seatRow[count1];

            int j = 0;

            for(int i = 0; i < 27;i++){
                if((letters.at(i))==seatCol[count1])
                    j = i;
            }

            int a2 = j;
            int sub1 = a1-1;
            int sub2=a2-1;
            flights[i].editAvailableSeats(a1-1, a2-1);
            flights[i].setAvailableSeatNo(flights[i].getAvailableSeatNo()-1);

            count1++;
            count0++;
        }

        Reservation* temp2 = reservations;
        reservations = new Reservation[numReservations+1];

        for( int i = 0; i < numReservations; i++){
            reservations[i] = temp2[i];
        }

        numReservations++;
        no3++;
        reservations[ numReservations - 1].setFlightNumber(flights[i].getFlightNo());

        int* no1 = new int[numPassengers];
        char* no2 = new char[numPassengers];
        for(int i = 0; i < numPassengers; i++)
            no1[i] = seatRow[i];

        for(int i = 0; i < numPassengers; i++)
            no2[i] = seatCol[i];

        reservations[numReservations - 1].setRowRes(no1);
        reservations[numReservations - 1].setColRes(no2);
        reservations[numReservations - 1].setResNo(no3);
        reservations[numReservations - 1].setNumPassengers(numPassengers);

        delete[] temp2;

        return  reservations[numReservations - 1].getResNo();
    }
}

void ReservationSystem::cancelReservation( const int resCode ){
        bool flag = false;
        for( int i = 0; i < numReservations; i++){
            if(reservations[i].getResNo() == resCode){
                cout << "Reservation for the seats ";
                for( int j = 0; j < numFlights; j++){
                    if(flights[j].getFlightNo() == reservations[i].getFlightNumber()){
                        int count1 = 0;
                        while(count1< reservations[i].getNumPassengers()) {
                            int a1 = (reservations[i].getRowRes())[count1];
                            cout << a1;
                            int k = 0;
                            for(int m = 0; m < 27;m++){
                                if((letters.at(m))==(reservations[i].getColRes())[count1])
                                k = m;
                            }

                            cout << (reservations[i].getColRes())[count1] << " ";
                            int a2 = k;

                            flights[j].editAvailableSeatsFalse(a1-1, a2-1);
                            flights[j].setAvailableSeatNo(flights[j].getAvailableSeatNo()+1);
                            count1++;
                        }
                    }
                }
                cout << " is canceled in Flight " << reservations[i].getFlightNumber();
                flag = true;
            }
        }

        if(flag == true){
            Reservation* temp = reservations;
            if(numReservations==1){
                reservations = NULL;
            }

            else{
                int index = 0;
                reservations = new Reservation[numReservations-1];
                for( int i = 0; i < numReservations; i++){
                    if(temp[i].getResNo()!=resCode){
                        reservations[index]=temp[i];
                        index++;
                    }
                }
            }

            numReservations--;
            delete[] temp;
        }

        if(flag == false)
             cout << "No reservations are found under Code " << resCode << endl;

}
void ReservationSystem::showReservation( const int resCode ){
    bool flag = false;
    int c = 0;

    for( int i = 0; i < numReservations; i++){
        if(reservations[i].getResNo() == resCode)
            flag = true;
        c=i-1;
    }

    if(flag==true){
        cout << "Reservations under Code " << reservations[c].getResNo() <<
                " in Flight " << reservations[c].getFlightNumber() << ": ";

        for( int a = 0; a < reservations[c].getNumPassengers(); a++){
        cout<< (reservations[c].getRowRes())[a];
        cout<< (reservations[c].getColRes())[a] ;
        cout << " ";
        }
        cout << endl;
    }

    else
        cout << "No reservations under Code " << resCode << endl;
}
