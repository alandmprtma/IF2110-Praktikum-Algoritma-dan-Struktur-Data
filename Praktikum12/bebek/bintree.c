#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"
#include "boolean.h"

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef Address BinTree;

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) {
    Address rootNode = (Address) malloc (sizeof(TreeNode));
    if (rootNode != NULL) {
        ROOT(rootNode) = root;
        LEFT(rootNode) = left_tree;
        RIGHT(rootNode) = right_tree;
    }
    return rootNode;
}
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    *p = NewTree(root, left_tree, right_tree);
}
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val) {
    Address node = (Address) malloc (sizeof(TreeNode));
    if (node != NULL) {
        ROOT(node) = val;
        RIGHT(node) = NULL;
        LEFT(node) = NULL;
    }
    return node;
}
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p) {
    free(p);
}
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (BinTree p) {
    return (p == NULL);
}
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p) {
    return(!isTreeEmpty(p) && (RIGHT(p) == NULL) && (LEFT(p) == NULL));
}
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p) {
    return(!isTreeEmpty(p) && (LEFT(p) != NULL) && (RIGHT(p) == NULL));
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p) {
    return(!isTreeEmpty(p) && (LEFT(p) == NULL) && (RIGHT(p) != NULL));
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p) {
    return (!isTreeEmpty(p) && (LEFT(p) != NULL) && (RIGHT(p) != NULL));
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */
void printPreorder(BinTree p) {
    printf("(");
    if (p != NULL) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

void printInorder(BinTree p) {
    printf("(");
    if (p != NULL) {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");   
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

void printPostorder(BinTree p) {
    printf("(");
    if (p != NULL) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void printTreeR(BinTree p, int curr, int add) {
    if (p != NULL) {
        int i;
        for (i = 0; i < curr; i++) {
            printf(" ");
        }
        printf("%d\n", ROOT(p));

        printTreeR(LEFT(p), curr + add, add);
        printTreeR(RIGHT(p), curr + add, add);
    }
}

void printTree(BinTree p, int h) {
    printTreeR(p, 0, h);
}

/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/

// Menerima sebuah pohon biner
// Mengembalikan penjumlahan dari hasil kali antara bebek-bebek pada rute
int mod(int n) {
    return (n % 10000);
}

int hitungBebek(BinTree root, int n) {
    int res = 0;
    hitungBebekRekursif(root, &res, 1, 0, n);

    return res;
}

void hitungBebekRekursif(BinTree root, int* res, int prodPath, int sumPath, int n) {
    if (isTreeEmpty(root)) return;
    sumPath += ROOT(root);
    prodPath = mod(prodPath * mod(ROOT(root)));

    // If current tree is a leaf
    if (isOneElmt(root) && (sumPath == n)) 
        *res += prodPath;

    // Else if tree has children
    if (LEFT(root) != NULL) 
        hitungBebekRekursif(LEFT(root), res, prodPath, sumPath, n);
    if (RIGHT(root) != NULL) 
        hitungBebekRekursif(RIGHT(root), res, prodPath, sumPath, n);
}