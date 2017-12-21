F74056166 方嘉祥  資訊109 資料結構 HW6
(a)
you can imput a number to determine the number of nodes
the heightunion function has four input
	parent[],two node number(i,j),the height of two node;
if height i > height j		make i the parent of j
else 				make j the parent of i,

during print	if parent[n] < 0 
		we print "root"

this function run in O(1) time

(d)

in situation 1 :collapsing do nothing with yhe tree
		and the time complexity of heightedunion and weightedunion is same
		heightedunion and weightedunion are both useful in this situation

in situation 2 :let collapsing get the lowest node of the tree
		in average weightedunion may create higher tree
		so heightedUnion produces better results