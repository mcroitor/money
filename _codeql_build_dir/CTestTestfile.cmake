# CMake generated Testfile for 
# Source directory: /home/runner/work/money/money
# Build directory: /home/runner/work/money/money/_codeql_build_dir
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(money_tests "/home/runner/work/money/money/_codeql_build_dir/money_tests")
set_tests_properties(money_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/runner/work/money/money/CMakeLists.txt;37;add_test;/home/runner/work/money/money/CMakeLists.txt;0;")
subdirs("_deps/catch2-build")
