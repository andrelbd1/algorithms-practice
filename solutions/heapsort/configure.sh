ulimit -s unlimited

gcc Heapsort.cpp `pkg-config --cflags --libs glib-2.0 gobject-2.0 gio-2.0` -w -g -o Heapsort