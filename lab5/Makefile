all:
	g++ -fPIC -c del.cpp -o del.o
	g++ -shared -olib_del.so del.o
	g++ -fPIC -c minus.cpp -o minus.o
	g++ -shared -olib_minus.so minus.o
	g++ -fPIC -c mod.cpp -o mod.o
	g++ -shared -olib_mod.so mod.o
	g++ -fPIC -c plus.cpp -o plus.o
	g++ -shared -olib_plus.so plus.o
	g++ -fPIC -c umno.cpp -o umno.o
	g++ -shared -olib_umno.so umno.o
	cp lib_minus.so lib_mod.so lib_plus.so lib_umno.so lib_del.so /usr/lib
	g++ main1.cpp -L. lib_minus.so lib_mod.so lib_plus.so lib_umno.so lib_del.so -o main1
	g++ main2.cpp -L. lib_minus.so lib_mod.so lib_plus.so lib_umno.so lib_del.so -o main2
	g++ main3.cpp -L. lib_minus.so lib_mod.so lib_plus.so lib_umno.so lib_del.so -o main3

rm:
	rm -rf *.o
