Run the stub generator:
======================
```bash
python -m utils.stubgen --output-dir tmp pyllvm
```

Generate Bindings
===============

- First install `Binder` [Guide]()
- Create `config.cfg` file with 
```
+include <pybind11/stl.h>
-namespace std
+class llvm::PassManager
```

- Create `generate_bindings.sh` with
```bash

# grep -rh "#include" clang/llvm/include/* | sort -u > all_bash_includes.hpp

# Makde bindings dir from scratch \
rm -rf ./bash_bindings_w_stl/ && mkdir bash_bindings_w_stl/

pybase=`which python3`

~/binder/bin/binder 						\
  --root-module PassManager 				\
  --prefix $PWD/bash_bindings_w_stl/ 		\
  --config config.cfg --annotate-includes 	\
  all_bash_includes.hpp 					\
  -- -std=c++17 							\
  -I$PWD/clang/llvm/include 				\
  -I/lib/clang/15.0.7/include 				\
  -DNDEBUG -iwithsysroot=/lib/clang/15.0.7/include

# --bind llvm 
# -I/usr/include 
```
