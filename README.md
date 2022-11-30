
a)

EBNF:

startup → Beginner { statement } End

statement → ifsmt | loop | express

ifsmt → what'(' booLean ')' '{' statement '}' { statement } 

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


d)

Everything passes pairwise disjoint, with no left recursion (nonterminal doesn’t repeat same nonterminal, all go to different nonterminals (all with an endpoint, and therefore avoid unnecessary recursion).


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
![Part h 1](https://user-images.githubusercontent.com/118640495/202877310-8f882b45-ae25-42ff-910d-1a00c5fcb744.png)
![Part h 2](https://user-images.githubusercontent.com/118640495/202877313-43e618d6-50e0-4f23-b39c-ddc21ec6751c.png)

Samples without failure are
- hGood1.in
- hGood2.in

Samples with failure to pass test are
- hError1.in
- hError2.in
