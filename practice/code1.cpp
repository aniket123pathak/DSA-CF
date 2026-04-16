#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

struct book {
    string title;
    string author;
    int price;
    book* left;
    book* right;
};

book* createBook (string title,string author,int price){
    book* newBook = new book();
    newBook->title = title;
    newBook->author = author;
    newBook->price = price;
    return newBook;
}

book* insert(book* root ,string title,string author,int price ){
    if(root==NULL){
        return createBook(title,author,price);
    }
    if(title<root->title){
        root->left = insert(root->left,title,author,price);
    }
    else{
        root->right = insert(root->right , title,author , price);
    }
    return root;
}

book* search(book* root,string title){
    if(root==NULL || title==root->title){
        return root;
    }
    if(title<root->title){
        return search(root->left , title);
    }
    else{
        return search(root->right,title);
    }
}

void inorder(book* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->title<<" "<<root->author<<" "<<root->price<<" ";
    inorder(root->right); 
}





int main() {
   
    return 0;
}