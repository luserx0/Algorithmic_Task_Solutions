/* Test Case for Harry Pantazis
 *

INPUT: The input of the tool are the customer sample input file (see chapter 1.2) and the full set of Extraction Files (see chapter 1.1).

OUTPUT:  The expected output from the tool will be a subset of the full extraction files
(CUSTOMER.CSV, INVOICE.CSV, INVOICE_ITEM.CSV) only including data for the
customers specified within CUSTOMER_SAMPLE.CSV file.

The output should be distributed in three files reflecting the original full extraction file-set structure (see chapter 1.1).

*/

#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct customer{
    string cust_code;
    string first_name;
    string last_name;
};

struct invoice{
    string cust_code;
    string invoice_code;
    double amount;
    string date;
};

struct invoice_item{
    string invoice_code;
    string item_code;
    double amount;
    long quantity;
};

/* For file manipulation use either the comp prog freopen structure || simple cpp stringstreams */
int main()
{
    return 0;
}
