# Hail


<h4> Introduction </h4>
The datastructure is build on the STL library of c++17 standard.Vectors are used as building block of this structure. The datastruture provides useful functions to extract data from files, manipulate it and save files. While currently being in the development stage it can only do a bit.

<h4>Implementation</h4>
 
 Using Hail in programs is just easy as other pre-built datastrucures or even easier.
 
 To initialise an variable , create an object of the class Hail
 
 ```cpp
 Hail object;
 ```
 
 <h4> Functions </h4>
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
 
 
 
 
