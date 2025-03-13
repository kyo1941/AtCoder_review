## B - [Overlapping sheets](https://atcoder.jp/contests/abc318/tasks/abc318_b)

- O(10^6)で愚直に解けるが，2次元配列のいもす法でO(10^4)で解ける
- 2次元のいもす法では，左上と**右下**に加算，右上と左下に減算を施す
    - 横方向に累積計算 → 縦方向に累積計算（各計算にO(HW)だけ要する）
    - O(HW)の計算を配列の各要素に対して実行しないといけない場合に有効

## D - [General Weighted Max Matching](https://atcoder.jp/contests/abc318/tasks/abc318_d)

- ビットdpを使う
    - 各頂点の選択を0-1で全通りのテーブルを作成する
    - 論理和を用いて次の要素に遷移する