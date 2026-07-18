#!/bin/bash

echo "task1->"
awk -F',' '{print $1, $2}' employees.txt

echo "task2->"
awk -F',' '$2=="Engineering"' employees.txt

echo "Task 3: Gross Pay"
awk -F',' '{print $1, "gross pay: $" $3*$4}' employees.txt

echo "Task 4: Record Number and Field Count"
awk -F',' '{print NR, "(" NF " fields):", $0}' employees.txt

echo "Task 5: Total Engineering Payroll"
awk -F',' '
BEGIN { total=0 }
$2=="Engineering" { total += $3*$4 }
END { print "Total Engineering Payroll: $" total }
' employees.txt
