#include <iostream>
#include <string.h>
#include <fstream>
#include "battleHistory.hpp"
using namespace std;

 TsingleList :: TsingleList(){
 head = tail = NULL;
 cnt = 0;
 }

 TsingleList :: ~TsingleList(){
 lst_el * el;

 while(head){
 el = head->next;
 delete head;
 head = el;
 }
 }

 //Method returning list size
 unsigned  TsingleList :: size(){
 return cnt;
 }

 //Method adding an element at the front of the list
 lst_el *  TsingleList :: push_head(lst_el * el){
 el->next = head;
 head = el;
 if(!tail) tail = head;
 cnt++;
 return head;
 }

 //Method adding an element at the end of the list
 lst_el *  TsingleList :: push_tail(lst_el * el){
 if(tail) tail->next = el;
 el->next = NULL;
tail = el;
 if(!head) head = tail;
 cnt++;

 return tail;
 }

 //Method adding an element (el1) after an element (el2)
 lst_el *  TsingleList :: insert(lst_el * el1, lst_el * el2){
 el1->next = el2->next;
 el2->next = el1;
 if(!(el1->next)) tail = el1;
 cnt++;
 return el1;
 }

 //Method deleting the first element of the list
 lst_el *  TsingleList :: rmHead(){
 lst_el * el;

 if(head){
 el = head;
 head = head->next;
 if(!head) tail = NULL;
 cnt--;
 return el;
 }
 else return NULL;
 }

 //Method deleting the last element of the list
 lst_el *  TsingleList :: rmTail(){
 lst_el * el;

 if(tail){
 el = tail;
 if(el == head) head = tail = NULL;
 else{
tail = head;
 while(tail->next != el) tail = tail->next;
 tail->next = NULL;
 }
 cnt--;
 return el;
 }
 else return NULL;
}


 //Method deleting the el element of the list
 lst_el *  TsingleList :: erase(lst_el * el){
 lst_el * el1;

 if(el == head) return rmHead();
 else{
 el1 = head;
 while(el1->next != el) el1 = el1->next;
 el1->next = el->next;
 if(!(el1->next)) tail = el1;
 cnt--;
 return el;
 }
 }

//Method returns nth element of the list
 lst_el *  TsingleList :: index(int n){
 lst_el * el;

if((!n) || (n > cnt)) return NULL;
 else if(n == cnt) return tail;
 else{
 el = head;
while(--n) el = el->next;
 return el;
 }
 }

 //Methods used to display data stored in the list
 void  TsingleList :: showKeys(){
 lst_el * el;

 if(!head) cout << "List is empty." << endl;
 else{
 el = head;
 while(el){
 cout << el->key << " ";
el = el->next;
 }
 cout << endl;
 }
 }


 void  TsingleList :: showNames(){
 lst_el * el;

 if(!head) cout << "List is empty." << endl;
else{
 el = head;
 while(el){
 cout << el->name << " ";
 el = el->next;
 }
cout << endl;
 }
 }

 void  TsingleList :: showElements(string ss){
 lst_el * el;

 if(!head) cout << "List is empty." << endl;
 else{
 el = head;
 while(el){
 cout <<" "<< ss << " " << el->battleResult<<" against "<<el->mname1<<" "<<el->mname2<<endl;
 el = el->next;
 }
 cout << endl;
 }
 }

 void  TsingleList :: saveElements(string ss){
 lst_el * el;
 ofstream files(("/home/imirgrp/kuliga/oopsie/RPG/charHistory/" + ss + "History.txt").c_str());
 if(!head) cout << "List is empty." << endl;
 else{
 el = head;
 while(el){
 files<<el->battleResult<<" "<<el->mname1<<" "<<el->mname2<<endl;
 el = el->next;
 }
 }
 }

 void  TsingleList :: loadElements(string ss){
 lst_el * el;
 string i[11];
 int z=1;
 ifstream files((ss + ".txt").c_str());
 if(!head) cout << "List is empty." << endl;
 else{
 el = head;
 while(files>>i[z]){

 }
 }
 }

void TsingleList :: hist_save(string imie,string imiep,string imiep2,string res)
{
  lst_el * el;
  string i[11],a[11],b[11];
  ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/charHistory/" + imie + "History.txt").c_str());
  int z=1;
    while(file>>i[z]>>a[z]>>b[z])
    {
      el = new lst_el;
      el->battleResult = i[z];
      el->mname1 = a[z];
      el->mname2 = b[z];
      el->key = z;
      if(tail) tail->next = el;
      el->next = NULL;
      tail = el;
      if(!head) head = tail;
      cnt++;
      z++;
    }
    if(cnt<10)
    {
      el = new lst_el;
      el->battleResult = res;
      el->mname1 = imiep;
      el->mname2 = imiep2;
      if(tail) tail->next = el;
      el->next = NULL;
      tail = el;
      if(!head) head = tail;
      cnt++;
      z++;
    }
    else
    {
      if(head){
      el = head;
      head = head->next;
      if(!head) tail = NULL;
      cnt--;
      }
      el = new lst_el;
      el->battleResult = res;
      el->mname1 = imiep;
      el->mname2 = imiep2;
      if(tail) tail->next = el;
      el->next = NULL;
      tail = el;
      if(!head) head = tail;
      cnt++;
      z++;
    }
    ofstream files(("/home/imirgrp/kuliga/oopsie/RPG/charHistory/" + imie + "History.txt").c_str());
    if(!head) cout << "List is empty." << endl;
    else{
    el = head;
    while(el){
    files<<el->battleResult<<" "<<el->mname1<<" "<<el->mname2<<endl;
    el = el->next;
    }
    }
}


 void TsingleList :: hist_load(string ss)
 {
   lst_el * p;
   string i[11],a[11],b[11];
   fstream file(("/home/imirgrp/kuliga/oopsie/RPG/charHistory/" + ss + "History.txt").c_str());
   int z=1;
     while(file>>i[z]>>a[z]>>b[z])
     {
       p = new lst_el;
       p->battleResult = i[z];
       p->mname1 = a[z];
       p->mname2 = b[z];
       p->key = z;
       {
       p->next = head;
       head = p;
       if(!tail) tail = head;
       cnt++;
       z++;
     }
     }
     if(!head) cout << "List is empty." << endl;
     else{
     p = head;
     while(p){
     cout <<" "<< ss << " " << p->battleResult<<" against "<<p->mname1<<" "<<p->mname2<<endl;
     p = p->next;
     }
     cout << endl;
 }
}
