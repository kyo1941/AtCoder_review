## C - [Avoid K Palindrome 2](https://atcoder.jp/contests/abc363/tasks/abc363_c)

- 与えられた文字列の並び替えの全通りについて操作を要する問題
- `next_permutation`で配列の全通りを行う場合、昇順ソートが必須

## D - [Palindromic Number](https://atcoder.jp/contests/abc363/tasks/abc363_d)

- 回文となる数字の数え上げ
- 桁数を求めた後、100...001からの大きさを求める際に、回文であることばかり意識して混乱してしまった
    - 回文の上半分の上下関係が、回文全体の上下関係と一致することさえわかれば簡単に求められる