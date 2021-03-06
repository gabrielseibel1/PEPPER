set term wxt title 'RL Charge'
set multiplot                       # multiplot mode (prompt changes to 'multiplot')
set size 1, 0.5

set origin 0.0,0.5
set ylabel "Voltage (V)"
set xlabel "Time (s)"
plot 'rl_charge.dat' using 1:2 title 'V(Source)', 'rl_charge.dat' using 1:3 title 'V(Ind)'

set origin 0.0,0.0
set ylabel "Current (A)"
set xlabel "Time (s)"
plot 'rl_charge.dat' using 1:4 title 'I(Source/Ind)'

unset multiplot                     # exit multiplot mode (prompt changes back to 'gnuplot')