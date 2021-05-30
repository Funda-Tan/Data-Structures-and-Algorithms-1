//Funda Tan 21801861
#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
#include "Flight.h"
#include "Reservation.h"
#include <string>
class ReservationSystem {
public:
    ReservationSystem();
    ~ReservationSystem();
    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );
    int makeReservation( const int flightNo, const int numPassengers,
    const int *seatRow, const char *seatCol );
    void cancelReservation( const int resCode );
    void showReservation( const int resCode );
    // ...
    // you may define additional member functions and data members, if necessary.
private:
    Flight* flights;
    std::string letters;
    Reservation* reservations;
    int numFlights;
    int numReservations;
    int count1;
};

#endif // RESERVATIONSYSTEM_H
