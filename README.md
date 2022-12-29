# pushdown-automata
This program simulates a given Pushdown Automaton (PDA), showing the behavior of the stack at each step and the result of evaluating that string on the PDA.

## How to use

The first line of the input is an integer *C*, indicating the **number of test cases** to use on the PDA.

Then we need a pair *(N, T)* of integers, indicating the **number of states** and the **number of transitions** that make up the PDA respectively.

Subsequently, we input *T* lines representing the **transitions** of the PDA, in the form **O F L E D** indicating a transition from state *O* to state *F* by reading *L* in the input string, unstacking *E* from the stack, and stacking *D*, all separated by a space. 

Finally, *C* input strings will be received to be evaluated by the PDA.

## Constraints

● The initial state is always the state 0.

● There is only one final state, and this is always the last state (N-1).

● The beginning of the stack will be represented by the character Z.

● The lambda character (λ) will be given by the symbol '~'.

## How it works

Let's simulate a PDA, with 2 test cases 4 states and 6 transitions:

![image](https://user-images.githubusercontent.com/40966434/209950351-1144c9f8-95cc-4037-bee2-ec8c278d9c6f.png)

The input from the table above simulates a PDA like the following:

![image](https://user-images.githubusercontent.com/40966434/209949988-88c8e686-7df5-4db4-b908-1d48529c2335.png)

And the test cases for this PDA are "abb" and "" (empty string). 

The program will take each string to test and evaluate it in the PDA, by showing each time something is pushed or popped from the stack. If the string takes the PDA to the final state, then the program will output *ACCEPTED*, if not, it will output *REJECTED*.

![image](https://user-images.githubusercontent.com/40966434/209950896-5229ae05-d04b-414a-acc6-cf15b2cb64e2.png)



### Example Input
2

4 6

0 1 a Z ZAA

0 3 ~ Z Z

1 1 a A AAA

1 2 b A ~

2 2 b A ~

2 3 ~ Z Z

abb



### Example Output
Case 1:

Z

ZAA

ZA

Z

Z

ACCEPTED

Case 2:

Z

Z

ACCEPTED
