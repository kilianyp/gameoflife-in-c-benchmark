Game of Life in C

performance optimization  
500 iterations using 1000x1000 matrix  

ubuntu 15.04  
Intel Core 2 Duo CPU P8400 @ 2.26GHz * 2  
2.9 GiB RAM  

Version 1:  
working version including one testcase  
no parallelizations  
1st run: 41.36475s  
2nd run: 41.29861s  
3rd run: 41.31800s  

Version 1.1:  
check Fields using inline functions  
1st run: 38.26025s  
2nd run: 38.40372s  
3rd run: 38.39163s  

Version 2:  
switched algorithm to only be active if field is one  
1st run: 14.01448s (500084 ones in initial matrix)  
2nd run: 14.18841s (499864)  
3rd run: 14.25374s (499343)  

