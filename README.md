# Termites Solution

This is a solution of the Termites [A] problem. (Task: http://main.edu.pl/en/archive/pa/2010/ter)

The full solution is described in the article: http://www.mimuw.edu.pl/~idziaszek/termity/termity.pdf

# 1 <=  n <= 1 000 000 && 0 <= l[i] <= 1 000 000 00

# Example input:                    
 8                            
 1 2 0 3 7 4 0 9

#output:
 17 9


#Explanation of the example: 
The fence consisted of 8 planks, out of which 2 have already been eaten. The first termite in his first turn can choose between planks of heights 2, 3, 4 and 9. During the optimal game, in the consecutive turns, termites will eat planks of heights 9, 2, 1, 4, 7 and 3.
