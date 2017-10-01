#PROBLEM LINK:
[Practice](https://www.codechef.com/problems/INF16I) 

[Contest](https://www.codechef.com/ACM16INF/problems/INF16I)

**Author:** [Full name][4444] 

**Tester:** [Full name][5555] 

**Editorialist:** [Abhishek Kumar](https://www.codechef.com/users/abhi1shek1)

#DIFFICULTY:
EASY

#PREREQUISITES:
Flows

#PROBLEM:
Given a directed graph with at most one out going edge from any node, 
also having certain value at each node. Find maximum flow that can be passed 
from a given set of nodes to end nodes.

#QUICK EXPLANATION:
Find maximum flow from source to sink nodes.

#EXPLANATION:
This problem can be very intuitively modeled as a flow problem 
where node given in ultra-special set can be thought as source 
and end nodes as sink nodes, value at each node represents maximum flow 
that can pass through it.


# INSERT IMAGE


Max flow can be simply found by augmenting path from source to sink whenever 
we can find a path(i.e without using standard flow algorithms) as any 
back edges after augmenting the flow will never be used to re-direct the flow.  

#AUTHOR'S AND TESTER'S SOLUTIONS:
Author's solution can be found [here][333]. 

Tester's solution can be found [here][444]. 

Editorialist's solution [code](https://www.codechef.com/viewsolution/15576462)