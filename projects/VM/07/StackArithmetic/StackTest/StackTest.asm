@17
D = A
@SP
M = M + 1
A = M - 1
M = D
@17
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE0
D;JEQ
D = 0
@CONTINUE0
0;JMP
(RET_TRUE0)
D = -1
(CONTINUE0)
@SP
A = M - 1
M = D
@17
D = A
@SP
M = M + 1
A = M - 1
M = D
@16
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE1
D;JEQ
D = 0
@CONTINUE1
0;JMP
(RET_TRUE1)
D = -1
(CONTINUE1)
@SP
A = M - 1
M = D
@16
D = A
@SP
M = M + 1
A = M - 1
M = D
@17
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE2
D;JEQ
D = 0
@CONTINUE2
0;JMP
(RET_TRUE2)
D = -1
(CONTINUE2)
@SP
A = M - 1
M = D
@892
D = A
@SP
M = M + 1
A = M - 1
M = D
@891
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE3
D;JLT
D = 0
@CONTINUE3
0;JMP
(RET_TRUE3)
D = -1
(CONTINUE3)
@SP
A = M - 1
M = D
@891
D = A
@SP
M = M + 1
A = M - 1
M = D
@892
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE4
D;JLT
D = 0
@CONTINUE4
0;JMP
(RET_TRUE4)
D = -1
(CONTINUE4)
@SP
A = M - 1
M = D
@891
D = A
@SP
M = M + 1
A = M - 1
M = D
@891
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE5
D;JLT
D = 0
@CONTINUE5
0;JMP
(RET_TRUE5)
D = -1
(CONTINUE5)
@SP
A = M - 1
M = D
@32767
D = A
@SP
M = M + 1
A = M - 1
M = D
@32766
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE6
D;JGT
D = 0
@CONTINUE6
0;JMP
(RET_TRUE6)
D = -1
(CONTINUE6)
@SP
A = M - 1
M = D
@32766
D = A
@SP
M = M + 1
A = M - 1
M = D
@32767
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE7
D;JGT
D = 0
@CONTINUE7
0;JMP
(RET_TRUE7)
D = -1
(CONTINUE7)
@SP
A = M - 1
M = D
@32766
D = A
@SP
M = M + 1
A = M - 1
M = D
@32766
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@RET_TRUE8
D;JGT
D = 0
@CONTINUE8
0;JMP
(RET_TRUE8)
D = -1
(CONTINUE8)
@SP
A = M - 1
M = D
@57
D = A
@SP
M = M + 1
A = M - 1
M = D
@31
D = A
@SP
M = M + 1
A = M - 1
M = D
@53
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = M + D
@112
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = M - D
@SP
A = M - 1
M = -M
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = D & M
@82
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = D | M
@SP
A = M - 1
M = !M
