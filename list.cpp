#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //------------- YOUR CODE HERE -------------
    first(L) = NULL;

    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P= new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //------------- YOUR CODE HERE -------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //------------- YOUR CODE HERE -------------
    address Q;
    if (first(L) == NULL){
        first(L) = P;
        next(P) = NULL;
        prev (P) = P;
    }else{
    Q = first(L);
    while (next (Q) != first(L))
        Q = next(Q);
    next(P) = first(L);
    prev(first(L)) = P;
    first(L) = P;
    prev(P) = Q;
    next(Q) = P;
    }
}
    //----------------------------------------

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //------------- YOUR CODE HERE -------------
    if (first(L) == NULL){
        insertFirst(L, P);
    }else{
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(P)) = P;
        prev(first(L)) = P;
        }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P = first(L);
    while ((info(P).ID != x.ID) && (next(P) != first(L))){
        P = next(P);
    }
    if (info(P).ID == x.ID){
        return P;
    }
    else {
        P = NULL;
    }

    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
     P = first(L);
    while ((info(P).name != x.name) && (next(P) != first(L))){
        P = next(P);
    }
    if (info(P).name == x.name){
        return P;
    }
    else {
        P = NULL;
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    address Q;
    P = first(L);
    if (first(L) == NULL){
        cout<<"List Kosong"<<endl;
    }else if (next(P) == first(L)){
        first(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }else {
        P = first(L);
        Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = next(P);
        prev(next(P)) = Q;
        first(L) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }

    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if (next(first(L)) == first(L)){
        deleteFirst(L, P);
    }
    else{
        P = prev(first(L));
        prev(first(L)) = prev(P);
        next(prev(P)) = first(L);
        next(P) = NULL;
        prev(P) = NULL;
    }

    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //------------- YOUR CODE HERE -------------
    if (first(L) == NULL){
        insertFirst(L, P);
    }
    else {
        next(P) = next(Prec);
        prev(P) = Prec;
        next(Prec) = P;
        prev(next(P)) = P;
    }

    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    address R;
    R = prev(P);
    next(R) = next(P);
    prev(next(P)) = R;
    prev(P) = NULL;
    next(P) = NULL;
    //----------------------------------------
}

