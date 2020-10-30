#--------------------Env variables-----------------------
INCLUDE = -I./include
LIB = -L./lib
CFLAGS = -Wall -Wextra $(INCLUDE) -Winline -pipe
CFLAGS_LIB_STATIC = $(CFLAGS) -c
CFLAGS_LIB_DYNAMIC = $(CFLAGS) -c -fPIC
LDFLAGS = $(LIB) -ljulius

#----------------------Targets---------------------------
all : debug prod static lib-static lib-dynamic
prod : .exe
debug : debug.exe
static : static.exe debug_static.exe
lib-static : libjulius.a
lib-dynamic : libjulius.so

#---------------------Executables------------------------
# Dynamically linked executables
debug.exe : lib-dynamic
	gcc $(CFLAGS) examples/cesar.c -o build/cesar_debug.exe $(LDFLAGS) -D"DEBUG=true"
.exe : lib-dynamic
	gcc $(CFLAGS) examples/cesar.c -o build/cesar.exe $(LDFLAGS)

# Statically linked executables
static.exe : lib-static
	gcc $(CFLAGS) -static examples/cesar.c -o build/cesar_static.exe $(LDFLAGS)
debug_static.exe : lib-static
	gcc $(CFLAGS) -static examples/cesar.c -o build/cesar_debug_static.exe $(LDFLAGS) -D"DEBUG=true"

#----------------------Libraries---------------------------
# Dynamic library
julius_dynamic.o :
	gcc $(CFLAGS_LIB_DYNAMIC) src/julius.c -o lib/julius_dynamic.o
libjulius.so : julius_dynamic.o
	gcc -shared lib/julius_dynamic.o -o lib/libjulius.so

# Static library
julius_static.o :
	gcc $(CFLAGS_LIB_STATIC) src/julius.c -o lib/julius_static.o
libjulius.a : julius_static.o
	ar rcs lib/libjulius.a lib/julius_static.o

clean:
	rm -rf build/*.exe lib/*.so lib/*.a lib/*.o