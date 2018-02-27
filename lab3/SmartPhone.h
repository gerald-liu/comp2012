
#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include "CellularPhone.h"
#include "OS.h"


class SmartPhone : public CellularPhone {

public:
    /**
     * Constructor.
     * @param vendor The name of its vendor.
     * @param num The phone number assigned to this cellular phone.
     */
    SmartPhone(const string& vendor, int num);

    /**
     * Constructor.
     * @param vendor The name of its vendor.
     * @param num The phone number assigned to this cellular phone.
     * @param os_name The name of its operating system.
     * @param os_ver The version of its operating system.
     */
    SmartPhone(const string& vendor, int num, const string& os_name, int os_ver);

    /**
     * Destructor.
     */
    ~SmartPhone();

    /**
     * Browse a website.
     * @param url The url of the website.
     */
    void browse_web(const string& url);

    /**
     * Upgrade the embedded operating system.
     * You may invoke directly the "upgrade" function in the "os" object.
     */
    void upgrade_os();

    /* getter */
    const OS* get_os() const;

private:
    /**
     * The operating system installed on the smartphone.
     */
    OS* os;

};


#endif //SMARTPHONE_H
