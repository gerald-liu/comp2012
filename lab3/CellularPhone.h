
#ifndef CELLULARPHONE_H
#define CELLULARPHONE_H

#include <iostream>

using namespace std;


class CellularPhone {

public:
    /**
     * Constructor.
     * @param vendor The name of its vendor.
     * @param num The phone number assigned to this cellular phone
     */
    CellularPhone(const string& vendor, int num);

    /**
     * Destructor.
     */
    ~CellularPhone();

    /**
     * Turn on the phone.
     */
    void turn_on();

    /**
     * Turn off the phone.
     */
    void turn_off();

    /**
     * Make a phone call.
     * @param num The phone number dialed.
     */
    void call(int num);

    /**
     * Check whether the phone is available.
     * We say the phone is available if it is on and the battery is above 0.0.
     * @return
     */
    bool is_available() const;

    /**
     * Print the current information of the phone.
     */
    void print() const;

    /* getter and setter */
    string get_vendor() const;
    int get_num() const;
    float get_battery() const;
    void set_battery(float battery);

private:
    /**
     * The name of the vendor.
     */
    string vendor;

    /**
     * The phone number itself.
     */
    int num;

    /**
     * The current status of the phone.
     * For a newly created CellularPhone object, it should be turned off.
     * true: the phone is turned on; false: the phone is turned off.
     */
    bool status{false};

    /**
     * The percentage of battery remaining.
     * For a newly created CellularPhone object, the battery should be full (=1.0).
     * We assume that each operation (which does not include turning on/off and print) costs 1% battery.
     */
    float battery{1.0f};

};


#endif //CELLULARPHONE_H
