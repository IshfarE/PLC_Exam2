
a)

EBNF:

startup → beginner { statement } finisher

statement → if_stmt | loop | express

if_stmt → what'(' booLean ')' '{' statement '}' { statement } 

booLean → identifier (<|>|<=|>=|==|!) integer

loop → loop( booLean ) '{' statement '}' { statement }

express → terminol {(+ | *) terminol } 

terminol → comp {(- | / ) comp }

comp → equal_to {(<|>|<=|>=|==) equal_to }

equal_to → mod{(=|!=) mod }

mod → factor {(%|;) factor }

factor → id | int_constant | num identify | ( express ) | s_colon

glossary → new_Char id = value 

new_Char → new_Char

omitBlnk → extract

extract → extract

lex → lex( omitBlnk ) { new_Char & extract | error_0 }

error_0 → exit

b)

Production rules:

E --> E + T

E --> E - T

E --> T

T --> T * F

T --> T / F

T --> T % F

F --> (E)


Operators:

ADDITION - '+'

SUBTRACT - '-'

MULTIPLY - '*' 

DIVIDE - '/'

MODULUS - '%'

STARTPAR (left parenthese) - '('

ENDPAR (right parenthese) - ')'


Comparison:

SMALLER (less than) - '<'

LARGER (greater than) - '>'

SMALLERQ (less than or equal) - '<='

LARGERQ (greater than or equal) - '>='

EQUAL_V (equal) - '=='

NOTEQUAL - '!='

c)
Must pass pairwise disjoint test

startup → Beginner { statement } End

First( Startup ) = Beginner { ifsmt | loop | express }

= beginner { what | circ | identifier | integer | num identify | ( expr ) | s_colon }
All values different (pass pairwise disjoint test)
loop → loop( booLean ) '{' statement '}' { statement }

First(Loop)=circ

Pass

ifsmt → what'(' booLean ')' '{' statement '}' { statement }

First(ifsmt)=what

Pass

booLean → identifier (<|>|<=|>=|==|!) integer

First(booLean)=identifier

Pass

express → terminol { (+ | *) terminol }

First(express) = terminol = identifes | integer | num identify | ( < | s_colon 

Pass

comp → equal_to { (<|>|<=|>=|==) equal_to }

First(comp)= equal_to = identifes | integer | num identify | ( | s_colon

Pass

equal_to → mod { (=|!=) mod }

First(equal_to)= mod = identifes | integer | num identify | ( | s_colon

Pass

mod → factor { (%|;) factor }

First(mod)= factor  = identifes | integer | num identify | (| s_colon

Pass

factor  → identifes | integer | num identify idenfies s_colon | ( express) | s_colon

First(factor)= factor = identifes | integer | num identify | ( | s_colon

Pass

This confirms that there is no left-hand recusion.

d)

Everything passes pairwise disjoint, with no left recursion (nonterminal doesn’t repeat same nonterminal, all go to different nonterminals (all with an endpoint, and therefore avoid unnecessary recursion). This means that the grammar is completely unambiguous.


e)
Found on lex.h

f)
Found on syn.h

g)
Fully-functional programs are 
- errorfree.in
- errorfree2.in

Lexical errors are found in 
- lexerror.in

Syntax errors are found in 
- synerror.in

h)
Ruleset:

![Parse Ruleset](https://user-images.githubusercontent.com/118640495/205671509-2c699872-88c1-4b3a-a755-300bb3c23204.png)

Table: 

![Parse 1](https://user-images.githubusercontent.com/118640495/205671672-9268f947-9e32-4bf4-bed6-6c0c9d37bfcb.png)
![Parse 2](https://user-images.githubusercontent.com/118640495/205671675-0018b67c-51df-44cc-8e91-b6df23e6dc43.png)
![Parse 3](https://user-images.githubusercontent.com/118640495/205671621-c6b94737-a44d-4b1e-9fba-576b2d49aba1.png)
![Parse 4](https://user-images.githubusercontent.com/118640495/205671626-424f8925-b52f-40d5-bd1a-0b9028fadd84.png)
![Parse 5](https://user-images.githubusercontent.com/118640495/205671629-86390d74-ce7e-4039-addd-9e1497cd33a7.png)
![Parse 6](https://user-images.githubusercontent.com/118640495/205671631-51547ff4-c338-4417-974b-3716882e3c85.png)
![Parse 7](https://user-images.githubusercontent.com/118640495/205671634-ae88d6bb-0f50-45f6-8dc9-53c7b87b6f95.png)
![Parse 8](https://user-images.githubusercontent.com/118640495/205671636-2c7a477a-c7cc-4667-935f-9f5b305fb1bc.png)
![Parse 9](https://user-images.githubusercontent.com/118640495/205671638-ad554e50-0b2f-4ffc-915e-832b731e9d56.png)
![Parse 10](https://user-images.githubusercontent.com/118640495/205671642-33b9777a-9ff0-4088-b7d0-bfc171d06828.png)
![Parse 11](https://user-images.githubusercontent.com/118640495/205671643-db31a1c0-2a36-4d33-b7ab-f79b78816c63.png)
![Parse 12](https://user-images.githubusercontent.com/118640495/205671644-e77952a8-394c-4b12-97c8-a1251e75c2ca.png)
![Parse 13](https://user-images.githubusercontent.com/118640495/205671646-b67fda60-088c-4090-8ccd-3cc3c995765c.png)
![Parse 14](https://user-images.githubusercontent.com/118640495/205671670-3a1e6760-6e1d-429f-8a2a-8f9440279548.png)

Pass at step 21: 

![Parse Pass 1](https://user-images.githubusercontent.com/118640495/205672138-fe187696-f826-4461-9ee5-6a8065e322c4.png)

Pass at step 21: 

![Parse Pass 2](https://user-images.githubusercontent.com/118640495/205672180-2ec14a71-214e-4cf7-8c01-72cb9672bb14.png)

Fail at step 19: 

![Parse Fail 1](https://user-images.githubusercontent.com/118640495/205672352-d73f2255-3593-45cc-8357-9fa87e631f62.png)

Fail at step 21: 

![Parse Fail 2](https://user-images.githubusercontent.com/118640495/205672422-38471a4c-3c69-4862-a449-29fbb4b99acc.png)





