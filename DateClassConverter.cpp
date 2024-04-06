#include <iostream>
#include <string>


using namespace std;

class DateFormatter {
private:
    int dd, mm, yyyy;

public:
    void setDate(string inputDate) {
        sscanf_s(inputDate.c_str(), "%d-%d-%d", &dd, &mm, &yyyy);
    }

    long getFormattedDate() {
        long x;
        x = (yyyy * 10000) + (mm * 100) + dd;
        return x;
    }
};
