# AmbiMorse
Given a string of arbitrary length which contains continuous Morse encoded only in dots (.) and dashes (-), find all combinations (permutations?) of possible translations.

## WIP Short tail
```
><0> ./ambimorse
*:..---
curr=0, next=3, mLen=3
 :..-[U]#
curr=3, next=5, mLen=2
 :   --[M]#
curr=3, next=4, mLen=1
 :   -[T]#
0: PASS : ..---
UMT
```

## WIP Recursive
```
*:..---
 :..---[2]
*:..---
 :..--
*:..---
 :..-[U]
 :   --[M]
 :   -[T]
 :    -[T]
*:..---
 :..[I]
 :  --[M]
 :    -[T]
 :  -[T]
 :   -[T]
 :    -[T]
*:..---
 :.[E]
 : .[E]
 :  -[T]
 :   -[T]
 :    -[T]
0: PASS : ..---
2U
MTTIM
TTTTEETTT
```