#!/usr/bin/python

# ./plot-accuracy.py /aux/yu239/codetection-results-without-sentence/accuracy-vs-IoU.sc="\textbf{SIM}" /aux/yu239/codetection-results-withonly-flow/accuracy-vs-IoU.sc="\textbf{FLOW}" /aux/yu239/codetection-results-withonly-movement/accuracy-vs-IoU.sc="\textbf{SIM+FLOW}" /aux/yu239/codetection-results-without-similarity/accuracy-vs-IoU.sc="\textbf{SENT}" /aux/yu239/codetection-results/accuracy-vs-IoU.sc="\textbf{SIM+SENT}"

from matplotlib import pyplot as plt
import sys
import numpy as np

def plot_accuracy(xs, ys, methods):
   plt.figure()
   plt.rc('text', usetex=True)
   plt.rc('font', family='serif')
   plt.rc('legend', fontsize=12)

   colors = ['g', 'r', 'b', 'k', 'm', 'y', 'c']
   markers = ['o', 'v', 's', '^', '*', 'p', '.']
   for i in range(len(xs)):
       plt.plot(xs[i], ys[i], colors[i], marker=markers[i], 
                markevery=50, markersize=7, label=methods[i], linewidth=2)

   plt.rc('axes', linewidth=5)

   fontsize = 12
   ax = plt.gca()
   for tick in ax.xaxis.get_major_ticks():
       tick.label1.set_fontsize(fontsize)
   for tick in ax.yaxis.get_major_ticks():
       tick.label1.set_fontsize(fontsize)
   
   plt.xlabel(r'IoU threshold', fontsize=fontsize)
   plt.ylabel(r'Acc', fontsize=fontsize)
   plt.xticks(np.arange(0, 1.1, 0.1))
   plt.yticks(np.arange(0, 1.1, 0.1))
   plt.legend()
#   plt.grid()
   plt.show()

## useage
# ./plot-accuracy.py filepath1=method1 filepath2=method2 ...
# each filepath points to a file which contains data
# [x1 y1]
# [x2 y2]
# ...
#
# each method is a string used to label the drawn curve
#
if __name__ == "__main__":
    xs = []
    ys = []
    methods = []
    for file in sys.argv[1:]:
        [filename, method] = file.split('=')
        methods.append(method)
        with open(filename) as f:
            content = f.readlines()
        content = [[float(val) for val in l.replace("(","").replace(")","").split(' ')] \
                      for l in content]
        [tmp_x, tmp_y] = zip(*content)
        xs.append(tmp_x)
        ys.append(tmp_y)
    plot_accuracy(xs, ys, methods)
