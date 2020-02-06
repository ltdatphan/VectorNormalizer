# Vector Normalizer
A small C program that normalizes a vector from input. It does not have any GUI and all interactions are made using the terminal. 

## Getting Started
In order to run this program, make sure you have gcc installed. Refer to the guide below. 

### Installing
Note: the following guide is meant for Ubuntu systems.
To install the compiler, type the following command in your terminal:

```
sudo apt install gcc
```

Use the following command to check gcc version:
```
gcc --version
```

## Running the program

Change the working directory to the space where the files are. 
To compile the program, do the following:

```
gcc -o vectnorm vectnormmain.c vectnormfuncs.c -lm
```

In this case, I named my running program to be vectnorm. 
After compilation, use the following command to run the program. 

```
./vectnorm
```

### Example

Upon running the program, you would get a simple guide on how to use the program.
```
./vectnorm


=== Welcome to the Vector normalizer ===
Made by Dat Phan

Start by entering the size of your vector and followed by the values of each values in your array.
Once you have declared a vector size of n, the program will not show any output until you have provided enough arguments.
To exit, provide an input of 0 or interrupt using Ctrl + C or Ctrl + D.
```
Let's make try to normalize a vector of size 3 with numbers 1, 2, 3 as its elements.
To do so, we would provide the following input:

```
3 1 2 3
```
The output we would get is:

```
The size of this vector is: 3. The results are as follow:
VECTOR: [ 1.000, 2.000, 3.000 ] NORMALIZED: [ 0.267, 0.535, 0.802 ]
```

However, you can provide the size of the vector on 1 line, and provide the rest of its elements in different lines and the program would work as well.

For example:
```
3
1 2
3
The size of this vector is: 3. The results are as follow:
VECTOR: [ 1.000, 2.000, 3.000 ] NORMALIZED: [ 0.267, 0.535, 0.802 ]
```

If you want to exit the program, you can provide input of 0 or press Ctrl + C or Ctrl + D:
For example:
```
3 0 0 0
```
No matter the location of the zero is, either at the starting or ending of a line, the program will stop.

## Author

* **Dat Phan** - *Whole project* - [ltdphan](https://github.com/ltdatphan)


## Acknowledgments

* Template brought to you by [PurpleBooth](https://github.com/PurpleBooth)
