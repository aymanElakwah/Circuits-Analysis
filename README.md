# Circuits-Analysis
_It can solve a circuit with any number of loops and in any formation
---------------------------------------
There are two versions:
1- Online version
2- Desktop version:
	There are two ways to start the program:
		1) Through command line: analyze.exe path/to/file (eg. analyze.exe C:/Users/Example/file.txt)
		2) Double click on the exe file. (It will ask you about the path of the netlist file)
-------
Input file formation:
---------------------
1-omega
2-circuit elements in this formation 

the first character(or two) of element should be :
(C->for capacitor,R->for Resistor,L->for Inductor,Cs->for current source,Vs for voltage source)

Input format (without brackets[])
[VsName] [start node] [end node] [r] [phase in degrees]	--> for voltage source (start node is the positive side)
[CsName] [start node] [end node] [r] [phase in degrees]	--> for current source (start node is the positive side)
[LName] [start node] [end node] [Inductance in henry]	--> for inductors
[CName] [start node] [end node] [Capacitance in farad]	--> for capacitors
[RName] [start node] [end node] [Resistance in ohms]	--> for resistors

Note: The name is optional

Input Sample:
1
Vs1 1 0 15 0
R1 1 2 10
R2 2 3 20
R3 3 4 15
R4 3 9 30
Vs2 9 8 60 60
R5 3 5 20
C1 5 6 10
L1 6 7 100
Cs1 8 7 25 30
R6 8 0 100
Cs2 4 0 30 0

---------------------------------------
output file formation
---------------------
1-current:
----------
element's name : I(start,end) = current in cartesian complex form (direction from start to end).
2-voltage:
----------
V(node number) : voltage at the node in cartesian complex form.
Note: The ground is the node which has the least number.
----------------------------------------

Output Sample:
Vs1: I(1,0) = 20.4093-2.01899j
R1: I(2,1) = 20.4093-2.01899j
R2: I(3,2) = 20.4093-2.01899j
R3: I(3,4) = -30
R4: I(9,3) = 12.0599+10.481j
Vs2: I(8,9) = 12.0599+10.481j
R5: I(3,5) = 21.6506+12.5j
C1: I(5,6) = 21.6506+12.5j
L1: I(6,7) = 21.6506+12.5j
Cs1: I(8,7) = -21.6506-12.5j
R6: I(0,8) = -9.59074-2.01899j
Cs2: I(0,4) = 30
V(0) 0
V(1) 15
V(2) 219.093-20.1899j
V(3) 627.278-60.5697j
V(4) 1077.28-60.5697j
V(5) 194.265-310.57j
V(6) 193.015-308.405j
V(7) 1443.01-2473.47j
V(8) 959.074+201.899j
V(9) 989.074+253.861j
