#ifndef HAIL_HPP
#define HAIL_HPP


#include<iostream>
#include<vector>
#include<fstream>
/*
 * Project description : - A datatype for c++ which provides high level tools for easier managment of structures like csv, dot, xlxs etc.
 * Author :- Imanpal Singh <imanpalsingh@gmail.com>
 * Date created : - 28-10-2019
 * Date modified :- 29-10-2019
 *
*/

/*
 * Change logs (0.0.1) :- Now using C-style I/O opertions for handling files.
 * Change logs (0.0.2) :- Now using C++ style I/O operations for handleing files.
 *						  Column names are now required.Negative indexig is now legal.
 						  Output of objects now show additional information.
*/


/*
 *
 * Class Name : -  Hail
 * Description : - This class handles all the loading of different various data formats and allocating memory to them
 * Functions : - get_csv, get_columns, get_data, version, operator[], cols,rows,size
 *
*/
class Hail
{
private:

	const std::string _version="0.0.0";	
public:

	
	//Variables
	 std::vector<std::vector<double> > _dataset;
	 std::vector<std::string> columns;

	//Utility functions
	 int cols() const;
	 int rows() const;
	 int size() const;
	 Hail get_csv(const std::string &filename="input.csv", const char &column_seperator=',', const char &row_seperator='\n');
	 void get_columns(Hail&,std::ifstream&,const char&, const char&);
 	 void get_data(Hail&,std::ifstream&,const char&, const char&);

	//Informative  functions
	 void version(const std::string&);

	//Opertional functions
	 Hail operator[] (int);
	


};


//Operator overloaded for displaying objects
std::ostream &operator<<(std::ostream&, const Hail&);

#endif