GeneExpressionProgramming
=========================

Little tool to search equation from data.

For example, with this data :
R	= A	+ B
_____________
3	|1	|2	|
8	|2	|6	|
11	|3	|8	|
16	|4	|12	|
17.5|5	|12.5|
-------------

tool found :


Manual
======

To use this command => gep [-r] <file_data.csv>
Description of CSV data file :
	The number of column in row must be same.
	First column is result of equation.
	Other column are variables' value.
	The separator is ';'.