@256
D=A
@SP
M=D
@Sys.init
0;JMP
(Class1.set)
@0
D=A
@SP
M=M+D
@func$0$Class1.set
D;JEQ
(func$Class1.set$0)
D=D-1
@LCL
A=M+D
M=0
@func$Class1.set$0
D;JGT
(func$0$Class1.set)
@ARG
D = M
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@StaticsTest2.0
M = D
@ARG
D = M
@1
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@StaticsTest2.1
M = D
@0
D = A
@SP
M = M + 1
A = M - 1
M = D
@5
D=A
@LCL
A=M-D
D=M
@R13
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M
@SP
M=D+1
@LCL
A=M-1
D=M
@THAT
M=D
@2
D=A
@LCL
A=M-D
D=M
@THIS
M=D
@3
D=A
@LCL
A=M-D
D=M
@ARG
M=D
@4
D=A
@LCL
A=M-D
D=M
@LCL
M=D
@R13
A=M
0;JMP
(Class1.get)
@0
D=A
@SP
M=M+D
@func$0$Class1.get
D;JEQ
(func$Class1.get$0)
D=D-1
@LCL
A=M+D
M=0
@func$Class1.get$0
D;JGT
(func$0$Class1.get)
@StaticsTest2.0
D = M
@SP
M = M + 1
A = M - 1
M = D
@StaticsTest2.1
D = M
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
@5
D=A
@LCL
A=M-D
D=M
@R13
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M
@SP
M=D+1
@LCL
A=M-1
D=M
@THAT
M=D
@2
D=A
@LCL
A=M-D
D=M
@THIS
M=D
@3
D=A
@LCL
A=M-D
D=M
@ARG
M=D
@4
D=A
@LCL
A=M-D
D=M
@LCL
M=D
@R13
A=M
0;JMP
(Class2.set)
@0
D=A
@SP
M=M+D
@func$0$Class2.set
D;JEQ
(func$Class2.set$0)
D=D-1
@LCL
A=M+D
M=0
@func$Class2.set$0
D;JGT
(func$0$Class2.set)
@ARG
D = M
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@StaticsTest2.0
M = D
@ARG
D = M
@1
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
@StaticsTest2.1
M = D
@0
D = A
@SP
M = M + 1
A = M - 1
M = D
@5
D=A
@LCL
A=M-D
D=M
@R13
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M
@SP
M=D+1
@LCL
A=M-1
D=M
@THAT
M=D
@2
D=A
@LCL
A=M-D
D=M
@THIS
M=D
@3
D=A
@LCL
A=M-D
D=M
@ARG
M=D
@4
D=A
@LCL
A=M-D
D=M
@LCL
M=D
@R13
A=M
0;JMP
(Class2.get)
@0
D=A
@SP
M=M+D
@func$0$Class2.get
D;JEQ
(func$Class2.get$0)
D=D-1
@LCL
A=M+D
M=0
@func$Class2.get$0
D;JGT
(func$0$Class2.get)
@StaticsTest2.0
D = M
@SP
M = M + 1
A = M - 1
M = D
@StaticsTest2.1
D = M
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
@5
D=A
@LCL
A=M-D
D=M
@R13
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M
@SP
M=D+1
@LCL
A=M-1
D=M
@THAT
M=D
@2
D=A
@LCL
A=M-D
D=M
@THIS
M=D
@3
D=A
@LCL
A=M-D
D=M
@ARG
M=D
@4
D=A
@LCL
A=M-D
D=M
@LCL
M=D
@R13
A=M
0;JMP
(Sys.init)
@0
D=A
@SP
M=M+D
@func$0$Sys.init
D;JEQ
(func$Sys.init$0)
D=D-1
@LCL
A=M+D
M=0
@func$Sys.init$0
D;JGT
(func$0$Sys.init)
@6
D = A
@SP
M = M + 1
A = M - 1
M = D
@8
D = A
@SP
M = M + 1
A = M - 1
M = D
@RETURN0
D=A
@SP
M=M+1
A=M-1
M=D
@LCL
D=M
@SP
M=M+1
A=M-1
M=D
@ARG
D=M
@SP
M=M+1
A=M-1
M=D
@THIS
D=M
@SP
M=M+1
A=M-1
M=D
@THAT
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@2
D=A+D
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class1.set
0;JMP
(RETURN0)
@0
D = A
@R5
D = A + D
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
@23
D = A
@SP
M = M + 1
A = M - 1
M = D
@15
D = A
@SP
M = M + 1
A = M - 1
M = D
@RETURN1
D=A
@SP
M=M+1
A=M-1
M=D
@LCL
D=M
@SP
M=M+1
A=M-1
M=D
@ARG
D=M
@SP
M=M+1
A=M-1
M=D
@THIS
D=M
@SP
M=M+1
A=M-1
M=D
@THAT
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@2
D=A+D
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class2.set
0;JMP
(RETURN1)
@0
D = A
@R5
D = A + D
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
@RETURN2
D=A
@SP
M=M+1
A=M-1
M=D
@LCL
D=M
@SP
M=M+1
A=M-1
M=D
@ARG
D=M
@SP
M=M+1
A=M-1
M=D
@THIS
D=M
@SP
M=M+1
A=M-1
M=D
@THAT
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@0
D=A+D
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class1.get
0;JMP
(RETURN2)
@RETURN3
D=A
@SP
M=M+1
A=M-1
M=D
@LCL
D=M
@SP
M=M+1
A=M-1
M=D
@ARG
D=M
@SP
M=M+1
A=M-1
M=D
@THIS
D=M
@SP
M=M+1
A=M-1
M=D
@THAT
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@0
D=A+D
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class2.get
0;JMP
(RETURN3)
(WHILE)
@WHILE
0;JMP
