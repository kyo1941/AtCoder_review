## E - [Prerequisites](https://atcoder.jp/contests/abc315/tasks/abc315_e)

- 有向非巡回グラフ（DAG）に対する探索はトポロジカルソートが有効
    - グラフの入次数を管理し，探索するなかで入次数をデクリメントしていき，in[next] == 0になれば進行するようにする