
a)
EBNF:
startup → Beginner { statement } End
statement → ifsmt | loop | express
ifsmt → what'(' booLean ')' '{' statement '}' { statement } 
booLean → identifier (<|>|<=|>=|==|!) integer
loop → loop( booLean ) '{' statement '}' { statement }
express → terminol {(+ | *) terminol} 
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
Grammar: 
Program → Statement
Program → Subroutine
Subroutine → id (arguments) Statement
Statement → Assign
Statement → process
Assign → id = Expression
process → id (parameters)
Expression → car, cdr
cdr → operation expression
cdr → ∊
car → id
car → sub_call
car → ( expression )
Operation → (+ | *) , (- | / | % ) , =
Operation → (- | / | %), =
Operation → =
parameters → expression, arg_cdr
arg → parameters
arg → ∊
id → (;;; any alphanumeric token)

c)
Non-terminal		Input Symbol
		
Program     --> Program → Statement, Program → Subroutine
Statement	  --> Statement → Assign, Statement → process
Subroutine  --> Subroutine → id (arguments), Subroutine → Statement
id --> id   --> (;;; any alphanumeric token)
Assign      --> Assign → id = Expression                   
Expression  --> Expression → car, cdr
car         --> car → id, car → sub_call, car → ( expression )
cdr         --> cdr → ∊, cdr → operation expression
Operation   --> Operation → (+ | *) , (- | / | % ) , = | Operation →  (- | / | % ) , = | Operation → =
Parameters  --> parameters → expression, arg_cdr
arg         --> arg → ∊, arg → parameters


d)
This is LL(1) grammar, which makes the grammar unambiguous.

h)
![Part h 1](https://user-images.githubusercontent.com/118640495/202877310-8f882b45-ae25-42ff-910d-1a00c5fcb744.png)
![Part h 2](https://user-images.githubusercontent.com/118640495/202877313-43e618d6-50e0-4f23-b39c-ddc21ec6751c.png)


