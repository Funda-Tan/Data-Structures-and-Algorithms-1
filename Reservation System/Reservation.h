//Funda Tan 21801861
#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation
{
    public:
        Reservation( const int no, const int numPas);
        Reservation();
        ~Reservation();
        void setResNo(int no);
        void setFlightNumber(int no);
        void setNumPassengers(int no);
        void setRowRes(int*& arr);
        void setColRes(char*& arr);
        int getResNo();
        int getFlightNumber();
        int getNumPassengers();
        int* getRowRes();
        char* getColRes();

    private:
        int resNo;
        int numPassengers;
        int flightNo;
        int* rowRes;
        char* colRes;
};

#endif // RESERVATION_H
