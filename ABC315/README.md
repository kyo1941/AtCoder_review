## E - [Prerequisites](https://atcoder.jp/contests/abc315/tasks/abc315_e)

- 有向非巡回グラフ（DAG）に対する探索はトポロジカルソートが有効（E-1.cpp）
    - グラフの入次数を管理し，探索するなかで入次数をデクリメントしていき，in[next] == 0になれば進行するようにする

- また，メモ化再帰による探索も有効（E-2.cpp）
    - 各頂点（順不同）を始点とする探索でdpを行う．探索済みの頂点に結合する際に，dpテーブルからメモされた値を受け取る

- どちらの解法も **EDPC-G** [**Longest Path**](https://atcoder.jp/contests/dp/tasks/dp_g) がかなり似ているので参考になる