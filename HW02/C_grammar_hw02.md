C grammar for Homework 02
=================

&nbsp;&nbsp;&nbsp;&nbsp;*prgm* **::=** *incls* *defns* *main*  
&nbsp;&nbsp;&nbsp;&nbsp;*incl* **::=** `#include <iostream>` | `#include <string>`  
&nbsp;&nbsp;&nbsp;&nbsp;*defn* **::=** *stru* | *func* | *proc*   
&nbsp;&nbsp;&nbsp;&nbsp;*stru* **::=** `struct` *name*`{`*var-dec*`;`,...`};`  
&nbsp;&nbsp;&nbsp;&nbsp;*func* **::=**
*type* *name*`(`*var-dec*`,`...`) {`*blck*`}`  
&nbsp;&nbsp;&nbsp;&nbsp;*proc* **::=** 
`void` *name*`(`*var-dec*`,`...`) {`*blck*`}`  
&nbsp;&nbsp;&nbsp;&nbsp;*main* **::=** `int main(void) {`*blck*`}`  

&nbsp;&nbsp;&nbsp;&nbsp;*stmt* **::=**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
*L-val* `=` *expn*`;`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
**|** *var-dec*`;` **|** *var-dec* `=` *expn*`;` **|** *var-dec* = `{` *expn*`,`...`};`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
**|** *cndl* **|** *loop* **|** *updt*  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** `std::cout <<`
*expn* `<<` **...** `<<` *expn*`;`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** `std::cin >>`
*L-val*`;`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|**
`return` *expn*`;` **|** `return;`  

&nbsp;&nbsp;&nbsp;&nbsp;*L-val* **::=**  *name* **|** *L-val*`[`*expn*`]` **|** *L-val*`.`*name*  

&nbsp;&nbsp;&nbsp;&nbsp;*var-dec* **::=** *type* *name*  
&nbsp;&nbsp;&nbsp;&nbsp;*type* **::=** `int` **|** `bool` **|** `double`  **|** `char` **|** *type*`*`  
&nbsp;&nbsp;&nbsp;&nbsp;*name* **::=** `x` **|** `i` **|** `y0`  **|** `sum` **|** `doThis` **|** **...**  

&nbsp;&nbsp;&nbsp;&nbsp;*updt* **::=**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *L-val*`++;` **|**  *L-val*`--;`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** *L-val* *op*`=` *expn*`;`  
  
&nbsp;&nbsp;&nbsp;&nbsp;*cndl* **::=**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `if (`*expn*`) {`*blck*`}`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** `if (`*expn*`) {`*blck*`} else {`*blck*`}`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** `if (`*expn*`) {`*blck*`}`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** `if (`*expn*`) {`*blck*`} else if (`*expn*`) {`*blck*`}`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** `if (`*expn*`) {`*blck*`} else if (`*expn*`) {`*blck*`} else {`*blck*`}`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** &nbsp;...  
      
&nbsp;&nbsp;&nbsp;&nbsp;*loop* **::=**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `while (`*expn*`) {`*blck*`}`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** `do {`*blck*`} while (`*expn*`);`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**|** `for (`*stmt*`;`*expn*`;`*stmt*`) {`*blck*`}`  
  
&nbsp;&nbsp;&nbsp;&nbsp;*expn* **::=**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *expn* *op* *expn*  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **|** *unop* *expn*  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **|** *lit-val*  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **|** *L-val*  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **|** `new` *type*`[`*expn*`]`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **|** `(`*expn*`)`  
&nbsp;&nbsp;&nbsp;&nbsp;*op* **::=** *arit* **|** *logc* **|** *cmpn* **|** *shft*   
&nbsp;&nbsp;&nbsp;&nbsp;*arit* **::=** `+` **|** `-` **|** `*` **|** `/` **|** `%`  
&nbsp;&nbsp;&nbsp;&nbsp;*logc* **::=** `&&` **|** `||`  
&nbsp;&nbsp;&nbsp;&nbsp;*shft* **::=** `<<` **|** `>>`   
&nbsp;&nbsp;&nbsp;&nbsp;*cmpn* **::=** `=` **|** `!=` **|** `>` **|** `>=` **|** `<` **|** `<=`   
&nbsp;&nbsp;&nbsp;&nbsp;*unop* **::=** `-` **|** `!`  
&nbsp;&nbsp;&nbsp;&nbsp;*lit-val* **::=** *int-val* **|** *bool-val* **|** *str-val* **|** *chr-val* **|** *dbl-val*  
&nbsp;&nbsp;&nbsp;&nbsp;*int-val* **::=** **...** **|** `-2` **|** `-1` **|** `0` **|** `1` **|** `2` **|** **...**  
&nbsp;&nbsp;&nbsp;&nbsp;*bool-val* **::=** `true` **|** `false`  
&nbsp;&nbsp;&nbsp;&nbsp;*str-val* **::=** `"hello"` **|** **...**  
&nbsp;&nbsp;&nbsp;&nbsp;*char-val* **::=** `'h'` **|** **...**  
&nbsp;&nbsp;&nbsp;&nbsp;*dbl-val* **::=** `42.0` **|** `3.14159` **|** **...**  
