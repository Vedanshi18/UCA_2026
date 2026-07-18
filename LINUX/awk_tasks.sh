#!/bin/bash
# Name & Department
awk -F',' '{print $1, $2}' employees.txt
echo
#Filtering by row
awk -F"," '$2=="Engineering" {print}' employees.txt
echo
# Total Pay
awk -F',' '{print $1 " gross pay: " $3 * $4 }' employees.txt
echo
# Built-in variables 
# NR - Number of Records (Line no)
# NF - Number of Fields (Columns)
# $0 - Entire Record (Whole line)
awk -F',' '{print NR " (" NF " fields): " $0}' employees.txt
echo
# BEGIN, END, and Conditionals
awk -F',' ' BEGIN { total = 0 } $2=="Engineering" { total += ($3 * $4)} END { print "Total Engineering Payroll: " total } ' employees.txt