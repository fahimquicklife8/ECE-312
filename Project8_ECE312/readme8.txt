====================================================
Program: Plagiarism Checker
Author: Fahim Imtiaz
EID: fmi89
====================================================

Description:
------------
This program checks for plagiarism in a set of documents by comparing sequences of words (of length `p`) between each pair of documents. 
Documents with a number of common sequences above a specified threshold (`m`) are flagged as potentially plagiarized.

How to Run on MobaXterm:
-------------------------

1. First, you need to unzip the provided `sm_doc_set.zip`:

2. Compile the program. If you're using a `makefile`, simply use the command:

3. Run the program:use linux command make

Replace `6` and `200` with your desired sequence length and plagiarism threshold, respectively.

4. To check for runtime: time ./main sm_doc_set 200 

   the runtime will give you idea on how long you should wait for the output to show up! 
5. In short unzip folders on directory and use linux commands 

    cd [directory name] -> make -> ./main sm_doc_set 6 200 
