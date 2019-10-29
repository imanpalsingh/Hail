
#include "Hail.hpp"
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
 * Variable name :- _version
 * Description : -  _version stores the version information which is helpful in determining compatibility
 *
*/


/*
 *
 * Function name:- get_csv
 * Description : -  Function loads filename specified or "input.csv" by defualt and first finds the column names and then stores the 
 * 					values in vector of vectors of double type and an object containing these members in returned
 *
*/

Hail Hail::get_csv(const std::string& filename, const char &column_seperator, const char &row_seperator)

{
	
	Hail data;

	//Opening the file
	std::ifstream csv(filename);

	if(!csv)
	{
		std::cout<<"<In function get_csv> InternalError : File '"<<filename<<"' either doesn't exist or cannot be accessed.\n";
		return data;
	}

	//Getting column list
	get_columns(data,csv,column_seperator,row_seperator);

	//Checking if no columns were found
	if(data.columns.size()==0)
		{
			std::cout<<"<In function get_csv> Error : No column names were found. Column names are required in version 0.0.2.\n";
			return data;

		}

	//Getting the data
	get_data(data,csv,column_seperator,row_seperator);
	return data;
	
}

/*
 *
 * Function name:- get_columns
 * Description : - Function uses the ifstream object to get the column names which are assumed to be in the first line and then   
 * 				   updates the columns vector. The size of row is restricted to the number of columns eariler found. If the row size
 *				   is bigger than number of columns than unexcepted vector behaviour may occur. (not fixed in 0.0.2)
 *
*/

void Hail::get_columns(Hail &data,std::ifstream &file,const char &column_seperator, const char &row_seperator)
{
	std::string column_line;
	std::string current="";
	std::getline(file,column_line,row_seperator);
	
	for(auto column:column_line)
	{
		if(column==column_seperator || column==row_seperator)
		{
			
			if(current!="")
				data.columns.push_back(current);
			current="";
			continue;
		}

		current+=column;
		

	}
	if(current!="")
	data.columns.push_back(current);
}

/*
 *
 * Function name:- get_data
 * Description : - Function then stores all the numeric values into the dataset vector of vecors in the format of rows and columns    
 * 				   where each vector is a row.
 *
*/

void Hail::get_data(Hail &data,std::ifstream &file,const char &column_seperator, const char &row_seperator)
{
	
	std::vector<double> row;
	row.resize(data.columns.size());
	
	
	char c;
	int col=0;
	int current;
	while(file>>current)
	{
		row[col] = current;
		col+=1;
		
		file.get(c);
		if(c == row_seperator || file.peek()==EOF)
		{	data._dataset.push_back(row);
			
			row.clear();
			row.resize(data.columns.size());
			col=0;

			
		}


	}
	row.clear();

}

/*
 *
 * Function name:- rows
 * Description : - Function to calculate number of rows in the dataset i.e the number of vectors allocated. 
 *
*/

int Hail::rows() const
{
	return _dataset.size();
}

/*
 *
 * Function name:- cols
 * Description : - Function to calculate number of columns in the dataset i.e the size of each vector 
 *
*/

int Hail::cols() const
{
	//If there actually are values present in the dataset.
	if(_dataset.size()>0)
		return _dataset[0].size();
	else
		return 0;
}

/*
 *
 * Function name:- size
 * Description : - Function to calculate total number  of values/observations present in the dataset.
 *
*/

int Hail::size() const
{
	return rows()*cols();
}

/*
 *
 * Function name:- version
 * Description : - Function to define version and raise a warning if the defined version is not as the required version.
 *
*/

void Hail::version(const std::string &version_)
{
	if(version_!=_version)
		std::cout<<"WARNING ! Version set is not same as the module's version. Compatibility issues may arise.\n";
}


/*
 *
 * Function name:- operator[]
 * Description : - Operator overloading to provide indexing of dataset object, also optimized for negative indexing.
 *
*/

Hail Hail::operator[](int index)
{
	if(index>rows())
	{
		std::cout<<"Index illegal";
	}

	if(index<0)
		index=rows()+index;

	Hail new_data;
	auto row = _dataset[index];
	new_data._dataset.push_back(row);

	return new_data;

}

/*
 *
 * Function name:- operator[]
 * Description : - Operator overloading to provide displaying of object
 *
*/

std::ostream &operator<<(std::ostream &os, const Hail &object)
{
	for(auto row:object.columns)
	{
		std::cout<<row<<" ";
	}
	std::cout<<"\n";

	for(auto row:object._dataset)
	{
		for(auto col:row)
		{
			os<<col<<" ";
		}
		os<<"\n";
	}

	os<<"\nNumber of rows = "<<object.rows()<<"\n";
	os<<"Number of cols = "<<object.cols()<<"\n";
	os<<"Number of Observations = "<<object.size()<<"\n";

	return os;
}

