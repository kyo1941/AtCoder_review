## 公式解説
### [**解説1 : A ~ E**](https://qiita.com/drken/items/dc53c683d6de8aeacf5a)
### [**解説2 : F ~ J**](https://qiita.com/drken/items/03c7db44ccd27820ea0d)

## F - [LCS](https://atcoder.jp/contests/dp/tasks/dp_f)

- **(i-1, j - 1) → (i, j)** のみ文字の追加が行われ，(i-1, j), (i, j-1)からの文字の追加はない（末尾の重複が発生するため）
- 復元の際に，(i-1, j), (i, j-1)を(i-1, j-1)よりも優先する
    - 文字の追加が行われたときに(i-1, j), (i, j-1)からの進行は起こりえない
        - ***dp[i][j] == dp[i-1][j-1]+1* ⇒ *dp[i][j] != dp[i-1][j] && dp[i][j] != dp[i][j-1]*** は必ず成立する一方で,<br>
        ***dp[i][j] == dp[i-1][j] || dp[i][j] == dp[i][j-1]* ⇒ *dp[i][j] == dp[i-1][j-1]+1*** もあり得てしまう（順不同だとこれで狂う）