analyze_article:
Given an English news article , count the following:
Number of space characters (a space character is ASCII 0x20 (32))
Number of Whitespace characters (whitespace characters as defined by http://www.cplusplus.com/reference/cctype/isspace/)
Number of lowercase
Number of uppercase
Number of digit
Number of case-insensitive letters
Bytes (the size of this file)
Number of words (separated by "Whitespace")
The total number of lines (Line) (the definition of a line is that have more than 0 character)

analyze_article_v2:
Given an English news article, output the following:
If the first word appears more than twice on the line, output the line
Print the longest word and its length
If there are words of the same length, they will be output in sequence according to the time of appearance; if there are repeated words, it will be skipped.
Output all words in the article (with white space, comma (,), period (.), double quotation mark ("), colon (:), exclamation mark (!), question mark (?), opening bracket '(' and Close parenthesis ')' to separate)
Output in sequence according to the appearance time of the words.

score:
Please write a program that reads data from stdin and performs actions according to different parameters.
i Add data
e.g. i n: sandy m: 99 e: 98 p: 100
    n represents the data as NAME
    m represents MATHSCORE
    e represents the data as ENGLISHSCORE
    p stands for PROGSCORE
    d delete, delete and compare the same data
    u update, update the data
    p print out data

sort:
Please write a sorting program. The program provides the following parameters, the default sorting order is from small to large
-h --help usage
-n use numeric comparison
-r reverse output
