ulimit -s unlimited

gcc cpu_timer/CPUTimer.cpp Knapsack.cpp `pkg-config --cflags --libs glib-2.0 gobject-2.0 gio-2.0` -w -o Knapsack