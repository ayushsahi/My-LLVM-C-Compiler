; ModuleID = 'output.bc'
source_filename = "output.bc"
target triple = "x86_64-pc-linux-gnu"

declare i32 @getint()

declare void @putint(i32)

declare void @putnewline()
