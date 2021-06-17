#include<stdio.h>
#include<string.h>
struct book{
  int acc_no;
  char title[50];
  char auth_name[50];
  char pub_name[50];
  float price;
  int year_pub;
  int copies;
  int flag;
} b[11]={{1,"The_Remains_of_The Day","Kazuo_Ishiguro","Penguin_Books",299.00,1989,1,0},{2,"Little_Women","Louisa_May_Alcott","Penguin_Books",399.00,1868,1,0},{3,"The_Twentieth_Wife","Indu_Sundaresan","Penguin_Books",299.00,2002,1,0},{4,"Never_Let_Me_Go","Kazuo_Ishiguro","Penguin_Books",299.00,2005,1,0},{5,"The_Feast_of_Roses","Indu_Sundaresan","Penguin_Books",299.00,2003,1,0},{6,"Shadow_Princess","Indu_Sundaresan","Penguin_Books",299.00,2010,1,1},{7,"Night","Elie Weisel","Penguin_Books",299.00,1956,1,0},{8,"Dawn","Elie Weisel","Penguin_Books",299.00,1956,1,0},{9,"Day","Elie Weisel","Penguin_Books",299.00,1956,1,0},{10,"A_Vindication_of_The_Rights_of_Woman","Mary Wollstonecraft","Penguin_Books",299.00,1792,1,0},{11,"Blank","Blank","Blank",0,0,0,0}};
struct member{
  int reg_no;
  char name[50];
  int issued;//total number of books issued;
  int returned;
  char book_issued[11][50];
  int defaulter;//number of times book returned late;
} m[3]={{1,"Priyal_Malviya",1,1,{"Shadow_Princess"},0},{2,"Kushagra_Malviya",0,0,"",0},{3,"Pankita_Malviya",0,0,"",0}};
struct author{
  char name[50];
  int books;
  char book[11][50];
} a[5]={{"Kazuo_Ishiguro",2,{"The_Remains_of_The_Day","Never_Let_Me_Go"}},{"Louisa_May_Alcott",1,{"Little_Women"}},{"Indu_Sundaresan",3,{"The_Twentieth_Wife","The_Feast_of_Roses","Shadow_Princess"}},{"Elie_Weisel",3,{"Night","Dawn","Day"}},{"Mary_Wollstonecraft",1,{"A_Vindication_of_The_Rights_of_Woman"}}};
int main()
{
  char ans_1,book_title[50],status[11][15],auth_title[50],book_issue[50],member_issuing[50],book_return[50],member_dues[50],book[50];
  int i,j,k,d,days_issued;
  float charge,dues;
  for(i=0;i<11;i++){
    if(b[i].flag==0){
      strcpy(status[i],"Not_issued");
    }
    if(b[i].flag==1){
      strcpy(status[i],"Issued");
    }
  }
  printf("Hello!\nWhat would you like to do today?\nA.Search for a book\nB.Add a new book\nC.Display all books by a particular author\nD.Display book of a particular title\nE.Display the number of books in the library\nF.Display details of members\nG.Issue a book\nH.Return a book\nI.Display dues to be paid by a member\nJ.Display details of member who has issued a book\n");
  scanf("%c",&ans_1);
  switch(ans_1){
    case'a':
    printf("Enter the title of the book:\n");
    scanf("%s",book_title);
    for(i=0;i<11;i++){
      if(strcmp(book_title,b[i].title)==0){
        printf("Found\nAccession no.:%d\nAuthor's name: %s\nPublisher's name: %s\nPrice: %f\nYear of Publication: %d\nNo. of copies: %d\nStatus: %s",b[i].acc_no,b[i].auth_name,b[i].pub_name,b[i].price,b[i].year_pub,b[i].copies,status[i]);
      }
      else{
        printf("\n");
      }
    }
    break;
    case'b':
    printf("Enter the details of the book:\nTitle:");
    scanf("%s",b[10].title);
    printf("\nAuthor's name:");
    scanf("%s",b[10].auth_name);
    printf("\nPublisher's name:");
    scanf("%s",b[10].pub_name);
    printf("\nYear of Publication:");
    scanf("%d",&b[10].year_pub);
    printf("\nNo. of copies:");
    scanf("%d",&b[i].copies);

    printf("%s - book successfully added to records!",b[10].title);
    break;
    case'c':
    printf("Enter the name of the author:\n");
    scanf("%s",auth_title);
    for(i=0;i<5;i++){
      if(strcmp(auth_title,a[i].name)==0){
        printf("Found\nNo. of books: %d,namely:\n",a[i].books);
        for(j=0;j<a[i].books;j++){
          printf("%s\n",a[i].book[j]);
        }
      }
      else{
        printf("\n");
      }
    }
    break;
    case'd':
    printf("Enter the title of the book:\n");
    scanf("%s",book_title);
    for(i=0;i<11;i++){
      if(strcmp(book_title,b[i].title)==0){
        printf("Found\n");
      }
      else{
        printf("\n");
      }
    }
    break;
    case'e':
    printf("The number of books in the library: %lu",sizeof(b));
    break;
    case'f':
    printf("The details of the existing members is:\n");
    for(i=0;i<3;i++){
      printf("\n%d.\nName: %s\nRegistration Number: %d\nNo. of books issued: %d\nBook(s) issued:%s\nNo. of times book returned: %d\nNo. of times book returned late: %d\n",i+1,m[i].name,m[i].reg_no,m[i].issued,m[i].book_issued[0],m[i].returned,m[i].defaulter);
    }
    case'g':
    printf("Enter the name of book:\n");
    scanf("%s",book_issue);
    for(i=0;i<11;i++){
      if(strcmp(book_issue,b[i].title)==0){
        printf("Found: Accession No.: %d",b[i].acc_no);
        printf("Enter name of member:\n");
        scanf("%s",member_issuing);
        for(j=0;j<3;j++){
          if(strcmp(member_issuing,m[j].name)){
            if(m[j].defaulter==0&&m[j].returned==m[j].issued){
              printf("No pending charge, no books issued currently\nYou are allowed to issue the book");
              b[i].flag=1;
              m[j].issued++;
              strcpy(m[j].book_issued[m[j].issued],book_issue);
            }
            if(m[j].defaulter!=0&&m[j].returned==m[j].issued){
              printf("Warning: You have one late return in record. Late fees will be levied after two weeks.");
              b[i].flag=1;
              m[j].issued++;
              strcpy(m[j].book_issued[m[j].issued],book_issue);
            }
            if(m[j].returned<m[j].issued){
              printf("Sorry, you are not allowed to issue a book till you have no pending returns.\nPlease return the previous book before retrying.");
            }
          }
        }
      }
    }
    case'h':
    printf("Enter title of book:\n");
    scanf("%s",book_return);
    for(i=0;i<3;i++){
      for(j=0;j<m[i].issued;i++){
        if(strcmp(book_return,m[i].book_issued[j])){
          printf("Thank you for returning the book.\nEnter number of days the book was issued for:\n");
          scanf("%d",&days_issued);
          if(days_issued<=14){
            charge = days_issued*1.50;
          }
          if(days_issued>14){
            printf("Book returned late. Late fine of Rs 3 per day will be imposed.");
            charge = 14*1.50 + (days_issued-14)*3.00;
            m[i].defaulter++;
          }
          printf("Total charge: %f",charge);
          m[i].returned++;
          for(k=0;k<11;k++){
            if(strcmp(book_return,b[k].title)==0){
              b[k].flag = 0;
            }
            else{
              printf("\n");
            }
          }
        }
        else{
          printf("This book was not issued from the library.\n");
        }
      }
    }
    break;
    case'i':
    printf("Enter the name of member:\n");
    scanf("%s",member_dues);
    for(i=0;i<3;i++){
      if(strcmp(member_dues,m[i].name)==0){
        int books_issued_currently = (m[i].issued-m[i].returned);
        if(books_issued_currently!=0){
          printf("Enter number of days since book has been issued:\n");
          scanf("%d",&d);
          if(d<=14){
            dues = d*1.50;
          }
          if(d>14){
            dues = 14*1.50 + (d-14)*3.00;
          }
        }
        else{
          printf("No pending charges");
        }
      }
      else{
        printf("This member is not found in library records.");
      }
    }
    break;
    case'j':
    printf("Enter title of book:\n");
    scanf("%s",book);
    for(i=0;i<11;i++){
      for(j=0;j<3;j++){
        for(k=0;k<m[j].issued;k++){
          if(strcmp(book,m[j].book_issued[k])){
            printf("This book has been issued by %s",m[j].name);
            printf("\nRegistration No.: %d\n",m[j].reg_no);
          }
          else{
            printf("This book has either not been issued or is not present in library records\n");
          }
        }
      }
    }
  }
}
