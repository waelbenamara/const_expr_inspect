docker run --rm --cap-add=SYS_PTRACE -v ~/cjit_duckdb/libs/llvm-project-cxxjit:/jit:ro,z -v "$PWD":/w:z -w /w cjit-duckdb-devenv bash -c '
/jit/bin/clang++ -std=c++11 -fjit -O2 -g jit.cpp -o /tmp/jit && /tmp/jit &&
gdb -batch -ex "set disassembly-flavor intel" -ex start -ex "break exit" -ex continue -ex "x/2i f" /tmp/jit' 2>&1 | grep -E '^(x| )'
