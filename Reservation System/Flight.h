//Funda Tan 21801861
#ifndef FLIGHT_H
#define FLIGHT_H

class Flight{
    public:
        Flight( int flightNo, int rowNo, int seatNo);
        Flight();
        ~Flight();
        Flight& operator=( const Flight& right);
        void editAvailableSeats( int no, int no1);
        void editAvailableSeatsFalse( int no, int no1);
        void setFlightNo( int no);
        void setRowNo( int no);
        void setSeatNo( int no);
        void setAvailableSeatNo( int no);
        int getFlightNo();
        int getRowNo();
        int getSeatNo();
        int getAvailableSeatNo();
        char** getAvailableSeats();

    private:
        int flightNo;
        int rowNo;
        int seatNo;
        char** availableSeats;
        int availableSeatNum;
};

#endif // FLIGHT_H
