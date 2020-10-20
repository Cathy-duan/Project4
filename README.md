In this project, you will implement a set of functions that can be used to retrieve information from a list of real estate transactions stored in a CSV (comma-separated values) file. The CSV file consists of 12 columns with the following column names and types.
•	street (a string).
•	city (a string).
•	zip (a string).
•	state (a string).
•	beds (a number).
•	baths (a number).
•	sq_ft (square feet, a number).
•	type (a string).
•	sale_date (a string).
•	price (a number).
•	latitude (a number).
•	longitude (a number).
For simplicity, assume the order of these 12 columns is fixed exactly as shown above. The first row (or line) of the CSV file is the header row that consists of column names. Each following row represents a real estate transaction. Some values of a row/transaction could be blank (unknown). A row will be excluded from a calculation if the calculation involves its blank value or a test condition involves its blank value (to be explained later). The maximum number of transactions or the order of transactions in the file is unknown in advance.

You are asked to implement the following six functions in the functions.c file. Every function to be implemented has two parameters, testc and testv, that can be used to test whether a row should be included or excluded in a calculation. testc and testv are similar to argc and argv in command line arguments of the main function. The difference is testv will contain 3*testc strings. testc is the number of test conditions. testv contains three strings for each test condition. The first string will always be one of 12 column names in the header, as listed above. The second string is one of the six relational operators (“==”, “!=”, “>=”, “<=”, “>”, and “<”). The third string is the reference value to be compared with. For example, assume testc=2, and testv contains six strings: “beds” “>=” “3” “baths” “>=” “2”. If a property has at least three bedrooms and at least two bathrooms, the property will be evaluated to be true for both conditions and it will be included in the computation. If a property does not have a value (blank) for the number of bedrooms or the number of bathrooms, the property will automatically be evaluated to be false and it will be excluded in the computation. If testc=0, it means every row/property will be automatically included in the computation.
•	void printAddr(char csvfile[], int testc, char *testv[]); Given a CSV file, print out the addresses (street, city, state and zip) of the properties that satisfy all the specified conditions.
•	void printCoor(char csvfile[], int testc, char *testv[]); Given a CSV file, print out the coordinates (latitude and longitude) of the properties that satisfy all the specified conditions.
•	int getCount(char csvfile[], int testc, char *testv[]); Given a CSV file, return the number of the properties that satisfy all the specified conditions.
•	void getMin(char csvfile[], char column[], int testc, char *testv[], double *pMin, int *pCount); Given a CSV file, return the minimum of the specified column from the properties that satisfy all the specified conditions through the pMin pointer. A property that has a blank value for the specified column will also be excluded from the calculation. The number of the properties that are included in the computation will be returned through the pCount pointer.
•	void getMax(char csvfile[], char column[], int testc, char *testv[], double *pMin, int *pCount); Given a CSV file, return the maximum of the specified column from the properties that satisfy all the specified conditions through the pMax pointer. A property that has a
 
blank value for the specified column will also be excluded from the calculation. The number of the properties that are included in the computation will be returned through the pCount pointer.
•	void getAvg(char csvfile[], char column[], int testc, char *testv[], double *pAvg, int *pCount); Given a CSV file, return the average of the specified column from the properties that satisfy all the specified conditions through the pAvg pointer. A property that has a blank value for the specified column will also be excluded from the calculation. The number of the properties that are included in the computation will be returned through the pCount pointer.

When implementing the above functions, you can assume csvfile is a valid CSV file as described above and it can always be opened for reading. When implementing the getMin, getMax, and getAvg functions, you can assume column is a valid column name and it is of numerical type. You can also assume the test conditions specified by testc and testv will also be valid and in correct form, as specified above. In addition, you are allowed to add helper functions in the functions.c file.
We recommend you use the fgets function to read a line from the CSV file, and you use the strsep function instead of the strtok function to extract each field from the line because a CSV file could contain blank cells. You can assume that each line does not exceed 300 characters in length and each field does not exceed 100 characters in length. strsep is destructive, please make a copy of the line before calling strsep if you need to reuse the line. The strsep function is a bit hard to use. Please search the web to find out how to use the strsep function properly, and it is probably a good idea to write a small program to test out the strsep function first.

For consistency, a numeric value is also stored as a string in a cell or in a test condition, you need to use atoi or atof to convert a numeric string to a number before comparison or computation. For a non-numeric string type, you shall use the strcmp function to perform case-sensitive comparison between two strings.

You can download main.c from Blackboard and you shall not modify anything in main.c. To compile this project, use the following command.
gcc -Wall -std=gnu99 main.c functions.c
Testing: a CSV file named Sacramentorealestatetransactions.csv can be downloaded from Blackboard for testing. You can test the program using the following command, and a sample execution of the program is shown at the end of this document.
./a.out Sacramentorealestatetransactions.csv
To verify whether you have implemented a function correctly, you can post the corresponding test commands and their results to Piazza and ask whether others agree with your results. 
