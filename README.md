# graphing-calculator
Graphing calculator that runs c++ code. Very much in development

## Compiling
Use make to compile within the src/ directory
```bash
$ make
```

## Executing
Execute the resulting Main file after compiling

```bash
$ ./Main
```

## Usage
Currently there is no user interface, so you must enter the polynomials to graph in the Main.cpp file.

Graphing a function or plotting a point:
<ol>
  <li>Create a cartesian plane using the Cartesian constructor and pass in the desired length and width</li>
  <li>FOR FUNCTIONS: Create a vector containing each coefficient with zeros as placeholders (v[0] is x^0 coefficient, v[1] is x^1, so on)</li>
  <li>Pass the vector to the Polynomial constructor or if plotting a point pass the x and y to the Coordinate constructor</li>
  <li>Pass the polynomial or coordinate to the Cartesian.plot() function</li>
  <li>Repeat the above steps as many times as desired</li>
  <li>Run the Cartesian.print() function to print the graph</li>
</ol>

## Example Output
```
f(x) = + 0.25x^2 + 0.00x^1 + 0.00x^0 
                              |                              
                              |                              
                              |                              
                       *      |      *                       
                              |                              
                              |                              
                        *     |     *                        
                              |                              
                              |                              
                         *    |    *                         
                              |                              
                          *   |   *                          
                              |                              
                           *  |  *                           
                            * | *                            
-----------------------------***-----------------------------
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
                              |                              
```

## Contributing
If you would like to contribute, you may make a pull request. It will be helpful if you first open an issue describing the change that you are interested in contributing.

## License
[MIT](https://choosealicense.com/licenses/mit/)
