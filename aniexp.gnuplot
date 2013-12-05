plot 'exp.dat' using 1:2 index i with l lw 4 title sprintf("Time: %f",(i+1)*0.001)
i = i+1
if(i<n) reread