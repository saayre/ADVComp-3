set terminal gif animate delay 1 optimize font 'times' 16 size 800,600
set output 'imp.gif'
set xrange[0:1]
set yrange[-5:5]
set xlabel "Position"
set ylabel "Probability Density"
i = 0
n = 100
load "aniimp.gnuplot"