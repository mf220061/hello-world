list/list.cについてのドキュメント

構造体
- elememnt
  - value: 整数型
  - next:  element
  - prev:  element

- list
  - n:     整数型
  - head:  element
  - tail:  element

構造体elementとlistはかなり要素の内容が近いのでどちらか一つだけでも今回のプログラムを実現することは可能

関数
- create_list
要素をlistに追加しようとしたが、listが空っぽの時に最初の要素を追加する関数

- tail_add
要素をリストの最後に追加する関数

- head_add
要素をリストの最初に追加する関数

- delete
要素からi番目の要素を削除する関数(0<=i<=n-1)
（ただし、iが最初あるいは最後の要素の処理については未実装）

- insert
（未実装）

- show
リストの要素を最初から表示する関数

予備関数
- get_random
最大と最小の範囲内でランダムに数字を返す
