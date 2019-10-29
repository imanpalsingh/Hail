# Hail


<h5> Introduction </h5>
The datastructure is build on the STL library of c++17 standard.Vectors are used as building block of this structure. The datastruture provides useful functions to extract data from files, manipulate it and save files. While currently being in the development stage it can only do a bit.

<Implementation>
 
 Using Hail in programs is just easy as other pre-built datastrucures or even easier.
 
 To initialise an variable , create an object of the class Hail
 
 ```cpp
 Hail object;
 ```
 This object can be used to call variety of I/O functions (though only csv supported yet). To load a csv file, call the get_csv function with the name/address of the file.
 
 ```cpp
 Hail object;
 auto dataset = object.get_csv(Filename);
 ```
 If no parameters are specified then the data structure loads a file name 'input.csv' (if available) by default.
 Two additional parameters are available
 For line seperator - > Which defines what character marks end of the line ('\n' default)
 For value seperator -> Which defines which character distinguishes one value from another (',' default)
 
