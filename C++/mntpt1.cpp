/* Homework 4 - CSCE 121 - Summer 2016 - Distance
* Solution not using classes or exceptions
* dilma@cse.tamu.edu
* compiled at a Mac OS with
* clang++ -std=c++11 -stdlib=libc++  map.cpp
* Updated solution
* jmichael@cse.tamu.edu
* Compiled on Windows 10 with Visual Studio
*
* v2:
* - input data
* - determines max and min values in the input file
* - implemented fillUniformGrayscale that generates RGB values file with
*   a single color on every cell
* v3:
* - output now in PPM format
* - changed input to be nrows, ncolumns, and input file name
* v4:
* - update to use 2D vector for colors
* - removed assumption that elevations are positive
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

void printMapNumbers(ostream& out, vector<vector<int> >& m)
{
    for (int i = 0; i < m.size(); i++) {
        out << "Row " << i << endl;
        for (int j = 0; j < m.at(i).size(); j++) {
            out << m.at(i).at(j) << " ";
        }
        out << endl;
    }
}

void printPPMFile(ofstream& file, int nrows, int ncols,
                  vector<vector<int> > r_values, vector<vector<int> > g_values,
                  vector<vector<int> > b_values)
{
    // TODO check for output error
    file << "P3" << endl;
    file << ncols << " " << nrows << endl << "255" << endl;
    for (int i = 0; i < r_values.size(); i++) {
        for (int j = 0; j < r_values.at(i).size(); j++) {
            file << r_values.at(i).at(j) << " " << g_values.at(i).at(j) << " " << b_values.at(i).at(j) << " ";
        }
        file << endl;
    }
}

int main()
{
    int nrows, ncols;
    cout << "Enter number of rows and columns:\n";
    cin >> nrows;
    if (!cin.good()) {
        cout << "Error: invalid input. bye!\n";
        return -1;
    }
    cin >> ncols;
    if (!cin.good()) {
        cout << "Error: invalid input. bye!\n";
        return -1;
    }

    cout << "Enter name of input file:\n";
    string data_file_name;
    cin >> data_file_name;
    if (!cin.good()) {
        cout << "Error: Failed to read name of input file. Giving up, bye!\n";
        return 1;
    }

    ifstream in_file{ data_file_name };
    if (!in_file.is_open()) {
        cout << "Error: Failed to open input file " << data_file_name << ". Giving up, bye!\n";
        return 1;
    }

    vector<vector<int> > map(nrows, vector<int>(ncols));
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            in_file >> map.at(i).at(j);
            if (!in_file.good()) { // error in the input
                cout << "Error: during input from file (i is " << i << ", j is " << j << "). Giving up, bye!\n";
                //printMapNumbers(cout, map);
                return -2;
            }
        }
    }

    // determine min and max
    int max = 0; // We know 0 is lowest possible value
    int min = map.at(0).at(0);
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (map.at(i).at(j) > max) {
                max = map.at(i).at(j); // set new max
            }
            if (map.at(i).at(j) < min) {
                min = map.at(i).at(j); // set new min
            }
        }
    }
    cout << "min is " << min << "; max is " << max << endl;

    vector<vector<int> > r_values(nrows, vector<int>(ncols));
    vector<vector<int> > g_values(nrows, vector<int>(ncols));
    vector<vector<int> > b_values(nrows, vector<int>(ncols));

    // compute gray scale values and put in color vectors
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            int elev = map.at(i).at(j);
            // ensure we get accurate results by using floating point division rather
            //  than integer division, so cast numerator and denominator to double
            double delev = static_cast<double>(elev - min) / static_cast<double>(max - min) * 255;
            //cout << "delev " << delev << " ";
            int scaled_value = static_cast<int>(delev); // cast double to an int color value
            // assign color value to each color vector
            r_values.at(i).at(j) = g_values.at(i).at(j) = b_values.at(i).at(j) = scaled_value;
        }
    }

    ofstream rgb_file{ data_file_name + ".ppm" };

    printPPMFile(rgb_file, nrows, ncols, r_values, g_values, b_values);

    //printMapNumbers(cout, map);

    //file closes automatically

}