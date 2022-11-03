#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    // Open the file
    ifstream inFile;
    inFile.open("business.txt");

    // Test for errors
    if (inFile.fail())
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    // Read the data from the file
    int numEmployees;
    inFile >> numEmployees;

    // Declare the arrays
    int *ids = new int[numEmployees];
    double *hours = new double[numEmployees];
    double *payRate = new double[numEmployees];
    double *wages = new double[numEmployees];

    // Loop through the file and store the data
    for (int i = 0; i < numEmployees; i++)
    {
        inFile >> ids[i];
        inFile >> hours[i];
        inFile >> payRate[i];

        // Calculate the wages
        wages[i] = hours[i] * payRate[i];
    }

    // Close the file
    inFile.close();

    // Output the data
    cout << "ID" << setw(10) << "Hours" << setw(10) << "Rate"
         << setw(10) << "Wages" << endl;

    for (int i = 0; i < numEmployees; i++)
    {
        cout << ids[i] << setw(10) << hours[i] << setw(10)
             << payRate[i] << setw(10) << wages[i] << endl;
    }

    // Clean up
    delete [] ids;
    delete [] hours;
    delete [] payRate;
    delete [] wages;

    return 0;
}