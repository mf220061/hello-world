#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
 * 色々考えたが、リストを操作する関数の戻り値の指定をやめるのが一番手っ取り早い気がする。
 * 黒岩先生の授業では、C++を使っていたので、リストをオブジェクトとして一つのまとまりで扱うことができた。
 * 同様にlist構造体を作ることで同じようにできる気もするが、何となく処理が遅くなりそうで気が進まない。
 * ただ、逆にelement構造体のパラメータを減らす事で処理が早くなりそうな気もするので、どちらがいいのかはわからない。
 */

struct element {
  int id;               // ID:     要素のリスト内での位置を示す。（不要なら削除する）
  int value;            // 値:     要素の持つ値を示す。
  //bool head, tail;      // フラグ: 要素がリストの初め、あるいは最後の要素であるかを示す。（つまり、リストの始まりと終わりを示す）（不要なら削除する）
  struct element* next; // next:   リストの次の要素へのポインタ
  struct element* prev; // prev:   リストの前の要素へのポインタ（不要なら削除する）
};

struct list {
  int n;                // リストの要素数
  struct element* head; // リストの始まり
  struct element* tail; // リストの終わり
};
