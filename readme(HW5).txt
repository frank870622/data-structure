F74056166 方嘉祥 資訊109 資料結構 HW5

*輸入字串->以','為基準點切成多個數字
一一call function 來插入binary tree

*binary tree insert 裡判段
	if(空tree) 將輸入的值當作root
	if(輸入值 > 當前NODE的值) 以右子樹為準 call function
	if(輸入值 < 當前NODE的值) 以左子樹為準 call function

*印出tree
變數儲存總共有幾個node
使用queue 以level order 的方式 印出tree

*刪除NODE
	search樹裡是否有要求刪除的值 如果無 輸出n is not in the tree
	如果有 進入刪除function

*刪除function
	如果為leaf node 直接刪除

	如果不為leaf node 往下尋找(右子樹下的最小值node OR 左子樹下的最大值node)
	並將其值與欲刪除node的值調換，且刪除找到的node

*每次刪除之後	印出刪除後的tree

	
時間複雜度為(nlogn + logn)