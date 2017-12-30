F74056166 方嘉祥 資訊109 資料結構 HW9 readme

use 3 array to  start vertex, end vertex, activity require

a.
earliest(e) time
	create array earliest[] and set it to  0
	if	earliest[end vertex] < earliest[start vertex] + activity require
            	earliest[end vertex] = earliest[start vertex] + activity require;

latest(l) time
	create array latest[] and set it to the max of earliest time
	if	latest[start vertex] > latest[end vertex] - activity require
		latest[start vertex] = latest[end vertex] - activity require;

b.

early(e) times
	creare early[] and set it to 0
	if 	early[] < earliest[start vertex]
		early[] = earliest[start vertex];

late(t) times
	create late[] and set it to the max of early(e) times
	if 	late[] > latest[end vertex] - activity require
		late[] = latest[end vertex] - activity require