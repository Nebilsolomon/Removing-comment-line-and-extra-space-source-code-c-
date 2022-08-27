//
//  main.cpp
//  Prog3


//
//  main.cpp
//  nebil
//
//  Created by nebil on 6/4/22.
//









#include<iostream>
#include<fstream>

using namespace std;

ifstream readFile;
ofstream writeFile;
string line;

int main(){
   
    string file1,file2;
    file1 = "data.txt";
    file2 = "newData.txt";
    
  
    readFile.open("data.txt");
    writeFile.open("newData.txt");
    

  
  
    
    
   string newLine;
    
    // read each line of file and delete comment and delete space and put one space from each token.
    
   while (getline(readFile, newLine))
   {
       
       
       // check each char in each string if it has comment delete it and add in removeCommentString string
   if(newLine!=""){
      
       string removeCommentString="";
       int count=0;
       
       for(int i=0;i<newLine.length();i++){
          
           if(newLine[i] =='/'){
               count++;
               if(count==2){
                   break;
                   }
               }
               else{
                   count = 0;
                   removeCommentString+=newLine[i];
               }
           }
       
   
       
       
       
       //     delete empty lines
       
       if(removeCommentString!=""){

           string   deleteEmptySpaceString="";
           for(int i=0;i<removeCommentString.length()-1;i++){
                   char ch=removeCommentString.at(i);
                   if(ch==' '){
                       char ch1=removeCommentString.at(i+1);
                       if(ch1!=' '){
                           if(deleteEmptySpaceString!=""){
                                   deleteEmptySpaceString+=' ';
                               }
                       }
                   }
                   else{
                       deleteEmptySpaceString+=ch;
                   }
               }
               deleteEmptySpaceString+=removeCommentString.at(removeCommentString.length()-1);
      
           
       // set comma , and assign
           
           
       string   setCommaString="";
           for(int i=0;i<deleteEmptySpaceString.length()-1;i++){
                   char ch=deleteEmptySpaceString.at(i);
                   if(ch==' '){
                       char ch1=deleteEmptySpaceString.at(i+1);
                       if(ch1=='=' || ch1==',' || ch1==';'){
                           if(ch1=='='){
                               setCommaString+="=";
                               i++;
                           }
                           if(ch1==','){
                               setCommaString+=",";
                               i++;
                           }
                          
                       }
                       else{
                           setCommaString+=" ";
                       }
                   }
                   else{
                           setCommaString+=ch;
                   }
               }
       setCommaString+=deleteEmptySpaceString.at(deleteEmptySpaceString.length()-1);
      
           
           // Delete Space After =
   string   removeSpaceAfterEquelSign="";
           for(int i=0;i<setCommaString.length();i++){
                   char ch=setCommaString.at(i);
                   if(ch=='='){
                       char ch1=setCommaString.at(i+1);
                       removeSpaceAfterEquelSign+="=";
                       if(ch1==' '){
                           i++;
                       }
                   }
                   else{
                       removeSpaceAfterEquelSign+=ch;
                   }
               }
      
       // split line
           string   spliteLine="";
           for(int i=0;i<removeSpaceAfterEquelSign.length();i++){
                   char ch=removeSpaceAfterEquelSign.at(i);
                   if(ch==';'){
                       spliteLine+=";";
                       writeFile<<spliteLine;
                   writeFile<<endl;
                   spliteLine="";
                   }
                   else{
                   if(!(ch==' ' && spliteLine==""))               {
                       spliteLine+=ch;
                   }
                      
                   }
               }
          
               if(spliteLine!="")                           {
                       writeFile<<spliteLine;
           writeFile<<endl;
               }
                      
           }

       }
   }
  
  
   readFile.close();
   writeFile.close();
  
  
   // displaying each file
    
    
    cout<<"source code"<<file1<<"\n";
    readFile.open(file1.c_str());
    cout<<"=================================\n";
    cout<<"==============================\n";
    cout<<"==============================\n";
    while (getline(readFile, newLine))
    {
        cout<<newLine<<endl;
    }
    
    
    
    
    cout<<"==============================\n";
    cout<<"==============================\n";
    cout<<"==============================\n";
    readFile.close();
    cout<<"delete space and comment code "<<file2<<"\n";
    cout<<"==============================\n";
    
    
    readFile.open(file2.c_str());
    while (getline(readFile, newLine))
    {
        cout<<newLine<<endl;
    }
    cout<<"------------------------------\n";
    readFile.close();
    
    
    
   return 0;
}








