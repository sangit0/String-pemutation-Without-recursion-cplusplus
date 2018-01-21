//Sangit0
//snagit0@yahoo.com
//Github.com/sangit0

#include<iostream>
using namespace std;

 string *word_holder;
void display(string input){
      cout<<input<<endl;
}
int factorial_calculate(string input){

       int size=input.length();
       int fact=1;
       for(int i=1;i<size;i++)
           fact=fact+fact*i;
    return fact;
}
void create_array_for_word_holder(int n){

    word_holder=new string [n];
}
void word_getter(string word,int index){

    word_holder[index]=word;
}
bool unique_checker(string word,int n){
    bool alarm=false;
    for(int i=0;i<n;i++){
        if(word_holder[i]==word)
            alarm=true;
    }
    return alarm;

}
void permantation(string input){

      int count=1;
      int num=1;
      int total_word_per_charac=0;
      int total_word=factorial_calculate(input);
      total_word_per_charac=total_word/input.length();
      create_array_for_word_holder(total_word);
      //cout<<total_word_per_charac;
      int word_coun=1;

      for(int j=0;j<=input.length()-1;++j){

     while(word_coun<=total_word_per_charac){

      for(int i=input.length()-1;i>=1;i--){
               if(i==1)
               {
               swap(input[i],input[input.length()-1]);
                 //  i=input.length()-1;
                  word_coun++;

               }
               else{
              swap(input[i],input[i-1]);
               word_coun++;
               }



        if(unique_checker(input,total_word)==false){
                 cout<<num<<".";
                 word_getter(input,num-1);
                 display(input);
                  num++;
            }

      }
 }
    swap(input[0],input[j+1]);
    word_coun=1;
      }

}

int main(void) {
    string a;
    cout<<"Enter a Word:"<<endl;
      cin>>a;
    cout<<"Word possible Sequence:"<<endl;
      permantation(a);

}
