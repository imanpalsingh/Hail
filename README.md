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
 This object can be used to call variety of I/O functions (though only csv supported yet). To load a csv file, call the get_csv function with the name/address of the file.
 
<h3>1)  get_csv </h3>
 
Format:- 
```cpp
getcsv(filename,column_seperator,row_seperator)
```
Example :- 

```cpp
 Hail object;
 auto dataset = object.get_csv(Filename);
 ```
 If no parameters are specified then the data structure loads a file name 'input.csv' (if available) by default.
 
 Two additional parameters are available
 1) For column seperator - > Which defines what character marks end of the line ('\n' default)
 2) For row seperator -> Which defines which character distinguishes one value from another (',' default)
 
