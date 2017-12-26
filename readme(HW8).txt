F74056166 方嘉祥 資訊109 資料結構 HW8 readme

預先輸入了adjacency matrix : cost
graph 非直接連接的地方以距離10000代替

一開始令distance[i] 是起點到i點最短路徑，起點設為零，其他為10000

重複下列步到完成shortest path tree
	取一個在與起點連接的tree之外且最近的點，加入tree
	設剛剛加入的點為a，在取另一點b，以distance[b] = distance[a]+cost[a][b] 代入
	因為要找最短路徑，distance[a]+cost[a][b]越小越好
	以parent[]存取tree中vertrice的parent


輸出distance[g] 代表起點(v) 到終點(f) 之最短路徑
    以parent[]找出路徑
