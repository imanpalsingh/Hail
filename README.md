# Hail


<h2> Introduction </h2>
The datastructure is build on the STL library of c++17 standard.Vectors are used as building block of this structure. The datastruture provides useful functions to extract data from files, manipulate it and save files. While currently being in the development stage it can only do a bit.

<h2>Implementation</h2>
 
 Using Hail in programs is just easy as other pre-built datastrucures or even easier.
 
 To initialise an variable , create an object of the class Hail
 
 ```cpp
 Hail object;
 ```
 
 <h2> Functions </h2>
 This object can be used to call variety of I/O functions (though only csv supported yet).
 
<h3>1) get_csv </h3>
 
 To load a csv file, call the get_csv function with the name/address of the file.
  
Format:- 
```cpp
Hail get_csv(const std::string &filename="input.csv", const char &column_seperator=',', const char &row_seperator='\n');
```
Example :- 

```cpp
 Hail object;
 auto dataset = object.get_csv(Filename);
 ```
 Parameters : -
 1) filename - >  Name or location of the csv file
 1) column_seperator - > Which defines what character marks end of the line ('\n' default)
 2) row_seperator -> Which defines which character distinguishes one value from another (',' default)
 
 If no parameters are specified then the data structure loads a file name 'input.csv' (if available) by default.
 
 <h3>2) version</h4>
 
 This function can be used to set the version required (if required). If the version of the data structure is not same as the required one a warning will be raised.
 
 Format :-
 ```cpp
 void version(const std::string&);
 ```
 Example :-
 
 ```cpp
 Hail object
 object.version("0.0.2");
 ```
 Parameters : -
 1) version - > version as a string
 
 <h3> 3) rows </h3>
 
 This function returns the number of rows in the dataset
 
 Format:-
 
 ```cpp
 int rows() const;
 ```
 Example
 
 ```cpp
 dataset.rows()
 ```
 
 No parameters required.
 
 <h3> 4) cols </h3>
 
 This function returns the number of columns in the dataset
 
 Format:-
 
 ```cpp
 int cols() const;
 ```
 Example
 
 ```cpp
 dataset.cols()
 ```
 
 No parameters required.
 
 <h3> 3) size </h3>
 
 This function returns the number of values/observations in the dataset
 
 Format:-
 
 ```cpp
 int size() const;
 ```
 Example
 
 ```cpp
 dataset.size()
 ```
 
 No parameters required.
 
 <h2> Overloaded functions </h2>
 
 <h3> 1) Extraction operator (<<) </h3>
 
 The insertion operator is overloaded. Meaning that the datastructure can be directly printed.
 
 For example
 
 ```cpp
 #include "Hail.hpp"
 #include<iostream>
 
 
 int main()
 {
    Hail object;
    auto Dataset = object.read_csv("Price.csv");
    std::cout<<Dataset;
    return 0;
 }
 
 ```
 
 The output depending on the csv file would be
 
 ```
 Id Price
 1 20 
 2 30
 4 50
 6 90
 7 85
 
 Number of rows = 5
 Number of columns = 2
 Number of Observations = 10
 ```
 
 <h3> 1) Indexing ([]) </h3>
 
 Objects of the Hail class can be index and be used to obtain subsets from the parent object. The modification through indexing is not yet supported
 
 For example
 
 ```cpp
 #include "Hail.hpp"
 #include<iostream>
 
 
 int main()
 {
    Hail object;
    auto Dataset = object.read_csv("Price.csv");
    auto Dataset_second = Dataset[0];
    std::cout<<Dataset_second;
    return 0;
 }
 ```
 
The outout of the program would be

```
 Id Price
 1 20 
 
 Number of rows = 1
 Number of columns = 2
 Number of Observations = 2
 
 ```
 
  > This project is under development
 
 
 
