# Product-of-SUM-
Product of Sum Satisfiability


 Sample input to your program: 
 • To represent the formula: (a+b)*(!a+!b) 
 • The input is (1,1),(-1,-1) 
 • Output from your program should be: • true, (1,0) • Or the program could also return: • true, (0,1) • 
 Why? Verify that a=1 and b=0 make (a+b)*(!a+!b) to evaluate to true. (similarly a=0, and b=1) •
 If the input is (a+b)*(!a+!b)*(!a+b)*(a+!b) then: • “false” 
 
 
 Why is this Program relevant? 

• Model checking 
• Equivalence checking between two circuit implementations 
• Formal verification of pipelines
• IO Function Maps 
• ATPG – Automatic Test Pattern Generation 
• Routing on FPGAs 
• Scheduling 

• This is a famous  problem (called the ‘satisfiability problem’, abbreviated ‘SAT’) 
 
 Which means there’s no known efficient solution 
 
• Sample inputs: 
• 2 variable POS: (1,1), (1,-1)
• 3 variable POS: (1,-1,0),(1,0,1),(-1,-1,0)
• 5 variable POS: (0,0,1,0,1),(0,0,-1,0,-1),(0,0,-1,0,0),(1,0,1,0,1) 


 In the input expression, each SUM is specified within ‘(‘ and ‘)’. • Eg: (1,0,-1) is a sum (ie, OR) of 3 variables – say a,b,c • ‘1’ indicates that the variable appears as-is • ‘-1’ indicates that the variables appears negated (eg: !c) • ‘0’ indicates that the variable does not appear • (1,0,-1) == a OR !c • The expression is a PRODUCT of SUMs • Eg: (1,0,-1),(0,1,1) stands for (a OR !c) AND (b OR c) 
 
• In the output, if your program decides that the expression can be satisfied, then it should output: • “true”, and an assignment of true/false values that makes it true • In the output, if your program decides that the expression can be satisfied, then it should output: • “false” 
