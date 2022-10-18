# PatternCheckCLA-
A C program that gets a pattern string from command line arguments, receives multiple 
lines from standard input stream, then manipulates and prints out the lines containing the pattern string. 




Command Line Arguments (CLA)
 -n: prints out the line numbers that contain the pattern string. Please note that line-numbering starts from 1.
  
  
  
 -x: prints out the lines that do not contain the pattern string (or, excludes the lines containing the pattern string)
  
  
  
 -s: prints out the lines in alphabetical order (default order is FIFO).
  
  
  
-r: prints out the lines in the reverse order (the line that appears last in stdin will appear first in stdout). Please note that you must make sure that user does not use -s and -r flags at the same time. If user wants to use both -s and -r flags, your program must get terminated after giving proper error message to the user.
      
      
      
-m: finds the pattern string only if it matches the whole word. You can assume that words are separated by white-space character only.
  
  
  
-c: ignores the case when finding the pattern string.
  
  
  
-f: prints out the index of the first occurrence of pattern string in each line. Please note that you must make sure that user does not use -f and -x flags at the same time. If user wants to use both -f and -x flags, your program must get terminated after giving proper error message to the user.
      
      
      
-p: partially prints out each line containing the pattern. To print out each line partially, you need to print the first 10 characters of the line,        followed by an ellipsis (. . . ), followed by the pattern followed by another ellipsis, followed by the last five characters of the line. You can remove  the first ellipsis if the pattern overlaps the first 10 characters.  Also, you can remove the second ellipsis if the pattern overlaps the last five  characters. Additionally, you can print the whole sentence if the length of sentence is not greater than the pattern legnth plus 15.
     
