 g++ -c libfoo.cpp
 ar cr libfoo.a libfoo.o
 g++ -shared -fPIC libbar.cpp -o libbar.so -L. -lfoo
 g++ -shared -fPIC libnewbar.cpp -o libnewbar.so -L. -lfoo
 g++ libtest.cpp -L. -lbar -lnewbar
