# MiniC Compiler

If you want proof that I am a good software engineer, then look no further:

This compiler is for MiniC, a subset/pseudo-code system of the C programming language taught at the University of Toronto, to the C Programming Language. 

This is a complete working implementation of the entire compilation pipeline, from lexical analysis, syntax tree generation and parsing, etc. 

What sets this implementation apart from basic academic compilers is its production-grade architecture: comprehensive semantic analysis with detailed error reporting, integration with industry-standard LLVM infrastructure for code generation as well as the fact that it uses ANTLR for parsing. Thus it is quite reliable. Further implementation details below

## Architecture

The compiler is designed as a multi-stage pipeline, with each stage performing a specific transformation on the input code.

### 1. Lexing and Parsing

The first stage of the compiler involves lexical analysis and parsing. This is handled by ANTLR4, a powerful parser generator.

**Grammar Definition**: The syntax of the MiniC language is defined in the `grammars/Minic.g4` file. This file contains both the lexer and parser rules that ANTLR4 uses to generate the parsing code.

**Parse Tree Generation**: When the compiler is run on a MiniC source file, the ANTLR4-generated parser consumes the stream of tokens produced by the lexer and builds a Parse Tree. This tree is a concrete representation of the input code, matching the grammar rules.

### 2. Abstract Syntax Tree (AST) Construction

The Parse Tree is then traversed to create an Abstract Syntax Tree (AST). The AST is a more abstract, hierarchical representation of the code's structure, which is more suitable for semantic analysis and code generation.

**AST Nodes**: Each node in the AST represents a construct in the source code, such as a declaration, an expression, or a statement. The structure of these nodes is defined in files like `src/Declarations.h`, `src/Exprs.h`, and `src/Statements.h`.

**AST Builder**: The `src/ASTBuilder.cpp` class is responsible for visiting the nodes of the Parse Tree and constructing the corresponding AST.

### 3. Semantic Analysis and Symbol Table

Once the AST is built, it's traversed by the `VerifyAndBuildSymbols` class to perform semantic checks and build symbol tables.

**Symbol Tables**: The compiler creates two types of symbol tables:
- A **Function Symbol Table** that maps function names to their corresponding `FuncSymbolEntry`
- A **Variable Symbol Table** for each scope, mapping variable names to their `VarSymbolEntry`

**Error Checking**: During the AST traversal, the compiler checks for various semantic errors, such as:
- Type mismatches in expressions and assignments
- Use of undeclared variables
- Duplicate declarations
- Incorrect function arguments

Any errors found are collected and reported to the user.

### 4. LLVM IR Generation

After the semantic analysis is complete, the compiler generates LLVM Intermediate Representation (IR) from the AST. LLVM is a powerful compiler infrastructure that provides a modern, high-level intermediate representation and a rich set of optimization passes.

**IR Generator**: The `IRGenerator` class, which is a derived class of `ASTVisitor`, traverses the AST and emits LLVM IR instructions for each node.

**LLVM API**: The compiler uses the LLVM C++ API to create LLVM modules, functions, basic blocks, and instructions. The generated IR is then written to a bitcode file (`.bc`).

### 5. Optimization

The final stage of the compiler is optimization. This project implements several optimization passes that are run on the generated LLVM IR.

**Memory to Register Promotion (alloca2reg)**: This is a crucial optimization that promotes local variables from memory (allocated on the stack with `alloca`) to virtual registers. This significantly improves performance by reducing the number of memory accesses.

**Open-ended Optimizations**: The project also includes other, more advanced IR optimizations designed to improve the performance of the generated code even further.

## How to Build and Run

### Prerequisites

- Ubuntu 20.04
- ANTLR4 4.11
- LLVM 15.0
- Clang 15.0
- CMake

### Building the Compiler

1. **Clone the repository:**
   ```bash
   git clone https://github.com/your-username/your-repo-name.git
   cd your-repo-name
   ```

2. **Create a build directory:**
   ```bash
   mkdir build
   cd build
   ```

3. **Run CMake and Make:**
   ```bash
   cmake ..
   make
   ```

   This will create the `minicc` executable in the `build/src` directory.

### Running the Compiler

1. **Compile a MiniC file:**
   ```bash
   ./build/src/minicc <your-input-file>.c -o output.bc
   ```
   This will generate an LLVM bitcode file named `output.bc`.

2. **Run the optimizer:**
   ```bash
   opt-15 -load build/src/liballoca2reg.so -alloca2reg output.bc -o output_opt.bc
   ```
   This will run the `alloca2reg` pass on the bitcode and create an optimized bitcode file named `output_opt.bc`.

3. **Generate an executable:**
   ```bash
   clang-15 output_opt.bc minicio/libminicio.a -o my_program
   ```

4. **Run the executable:**
   ```bash
   ./my_program
   ```

## Project Structure

- **`grammars/`**: Contains the ANTLR4 grammar for MiniC (`MiniC.g4`)
- **`src/`**: Contains the C++ source code for the compiler, including:
  - `main.cpp`: The entry point of the compiler
  - `AST*.cpp/h`: Files related to the Abstract Syntax Tree
  - `VerifyAndBuildSymbols.cpp/h`: The semantic analyzer
  - `IRGenerator.cpp/h`: The LLVM IR generator
  - `Alloca2Reg.cpp`: The memory-to-register optimization pass
- **`minicio/`**: Contains a small C library with I/O functions for MiniC
- **`tester/`**: Contains Python scripts for testing the compiler
- **`cmake/`**: Contains CMake modules
- **`build/`**: The directory where the compiler is built
