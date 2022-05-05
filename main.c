/*This program is user terminated only. Error handling is implemented to make it user friendly. */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct date{
    int d;
    int m;
    int y;
}d;

int validation(int d, int m, int y); //function to check if entered date is valid
void notes(int d, int m, int y); //function to check/Book events for a specific date
void events(); //function to take a date and open Events section
void opendate(); //function that asks user to enter a date any returns the day.
void cdisplay(); //function that takes the year as input and displays the different months.
void out(); //exit function that takes feedback
void main(); //main function


int validation(int d, int m, int y){
  int l;
    if (y<999 || y>9999){
        return (0);
    }
    if (m>12||m<1){
        return (0);
    }
    if (d<1){
        return(0);
    }

    int r4 = y%4;
    int r100 = y%100;
    int r400 = y%400;

    if(r4==0){
        if(r100==0){
            if (r400==0) l= 1;
            else l=0;
        }
        else l=1;
    }
    else l=0;


    if(m==2&&l==0){
        if(d>28){
             return (0);
        return (0);
            }
        }

    if(m==2&&l==1){
        if (d>29){
             return (0);
        return (0);
                 }
        }

    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
          if (d>31){
               return (0);
        return (0);
                 }
          }

    else if (d>30){
         return (0);
        return (0);
    }

    return(1);
}


void notes(int d, int m, int y){
    system("cls");
    int date = y+ 10000*m + 1000000*d;
    char name [15];
    char text[50];
    FILE *f;
    int c;
    sprintf(name, "%d", date); //name of the file is the date in character format
    therehere:
    printf("\n\nEnter your choice: \n\n 1. View Events 2. Add Events 3. Clear Events \n");
    scanf("%d", &c);
    switch (c){
     case 1:
         system("cls");
         f = fopen(name,"r");
            if (f == NULL){
                    fclose(f);
                int a;
                printf("No Notes Found.\n Enter your Choice:  1. Add notes 2. Check for another date 3. Return to Main Menu 4. Exit. \n");
                scanf("%d", &a);
                if(a==1) goto there;
                if(a==2) events();
                if(a==3) main();
                if(a==4) out();
                else {
                    system("cls");
                    printf("You have entered a wrong Input. You have been returned to main menu.\n");
                    main();
                }
            }
         char c= fgetc(f);
         printf("Notes For the date %d are:\n\n\n", date);
         while (c != EOF){
         printf ("%c", c);
         c = fgetc(f);
         }
         fclose(f);
         break;
    there:
    case 2:
         system("cls");
         f = fopen(name,"a");
         printf("Enter text to your note..\n");
         fgets(text, sizeof(text), stdin);
         fgets(text, sizeof(text), stdin);
         fputs("\n",f);
         fputs(text,f);
         fputs("\n",f);
         fclose(f);
         break;
     case 3:
         system("cls");
         f = fopen(name,"w");
         fclose(f);
         printf("Contents of the note have been cleared.\n\n");
         break;
     default: //error handling
            system("cls");
            printf("You have entered a wrong Input. The process has been re-initialized.\n");
            notes(d,m,y);
            break;
    }
    int a;
                printf("Enter 1 to Check for another Date ; Enter 2 to see more actions for the same date; Enter 3 goto Main Menu; Enter 4 to exit. \n");
                scanf("%d", &a);
                if(a==1) events();
                if(a==2) goto therehere;
                if(a==3) main();
                if(a==4) out();
                else {
                    system("cls");
                    printf("You have entered a wrong Input. You have been returned to main menu.\n");
                    main();
                }

}

void events(){
    system("cls");
    printf("\nEnter the date (dd): ");
    scanf("%d",&d.d);
    printf("\nEnter the month (mm): ");
    scanf("%d",&d.m);
    printf("\nEnter the year (yyyy): ");
    scanf("%d",&d.y);
    if(validation(d.d,d.m,d.y)==1)
        notes(d.d,d.m,d.y);
    else{
        printf("Invalid date entered. Process re-initialized.");
        events();
    }
}

void opendate(){
    printf("\nEnter the date (dd): ");
    scanf("%d",&d.d);
    printf("\nEnter the month (mm): ");
    scanf("%d",&d.m);
    printf("\nEnter the year (yyyy): ");
    scanf("%d",&d.y);
    if(validation(d.d,d.m,d.y)==0){
        printf("Invalid date entered. Process re-initialized.");
        opendate();
    }

     static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    d.y -= d.m < 3;

    int day =  ( d.y + d.y/4 - d.y/100 + d.y/400 + t[d.m-1] + d.d) % 7;

    if (day==0){
        printf("\nThe day is SUNDAY.");
    }
     if (day==1){
        printf("\nThe day is MONDAY.");
    }
     if (day==2){
        printf("\nThe day is TUESDAY.");
    }
     if (day==3){
        printf("\nThe day is WEDNESDAY.");
    }
     if (day==4){
        printf("\nThe day is THURSDAY.");
    }
     if (day==5){
        printf("\nThe day is FRIDAY.");
    }
     if (day==6){
        printf("\nThe day is SATURDAY.");
    }
    int v;
    here:
    printf("\n\nEnter your choice: \n 1. Check/Book Events 2. Switch/Change date 3. Return to Main Menu 4. Exit\n");
    scanf("%d", &v);
    switch (v){
    case 1:
        notes(d.d,d.m,d.y);
        break;
    case 2:
        system("cls");
        opendate();
        break;
    case 3:
        system("cls");
        main();
        break;
    case 4:
        out();
        break;
     default: //error handling
            system("cls");
            printf("You have entered a wrong Input. The process has been re-initialized.\n");
            goto here;
            break;

    }

}


void cdisplay(){
    int year,month,day,counter=0,startingDay ;
    printf("Enter the desired Year for getting the Calendar: ");
    scanf("%d",&year);
    if(year>9999||year<999){
        printf("You have entered an invalid year {999>YYYY>9999}. Process re-initialized.\n");
        cdisplay();
    }
    int daysInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

    if ((year%4==0&&year%100!=0)||year%400==0){     //to check if its a leap year.
        daysInMonth[1]=29 ;
    }

    startingDay= (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;

    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};

    for (month = 0 ; month<12;month++){

         printf("\n\n====================%s=========================\n",months[month]);
         printf("\n  SUN  MON  TUE  WED  THU  FRI  SAT\n");

         for (counter=0;counter<startingDay;counter++){
            printf("     ");
         }

         for (day=1 ; day <=daysInMonth[month];day++){
            printf("%5d",day);
            counter++;
            if (counter>6){
                printf("\n");
                counter=0 ;
            }
            startingDay=counter;
         }

    }
}

 void out(){
    system("cls");
    FILE *fd = fopen ("feedback.txt","a+");
    char feedback[20];
    printf("Thank you for using Calendar 1.0 \nDevelopers: Satyajit Satyaprakash Shivam. \n\nPlease give your feedback.\n");
    fgets(feedback, sizeof(feedback), stdin);
    fgets(feedback, sizeof(feedback), stdin);
    fputs(feedback,fd);
    fputs("\n_________________________________________\n",fd);
    fclose(fd);
    exit(1);
 }

void main(){
    int choice;
    FILE *fd;
    time_t t;   // not a primitive datatype
    time(&t);
    fd = fopen ("feedback.txt","a");
    fputs("\t\tNew Run\n",fd);
    fputs(ctime(&t),fd);
    fputs("\n",fd);
    fclose(fd);


    printf("        WELCOME TO CALENDAR 1.0\n          ____________________\n\nEnter your Choice: \n\n 1. View Calendar 2. Search for a Date. 3. Check/Book Events 4. Exit.\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            system("cls");
            cdisplay();
            break;
        case 2:
            system("cls");
            opendate();
            break;
        case 3:
            system("cls");
            events();
            break;
        case 4:
            system("cls");
            out();
            break;
        default: //error handling
            system("cls");
            printf("You have entered a wrong Input. The process has been re-initialized.\n");
            main();
            break;
        }
    //program does not end unless the user wants
    printf("\nEnter your Choice:\n\n1. Return to Main Menu  2. Exit\n");
    scanf("%d",&choice);
    switch (choice){
        case 1:
            system("cls");
            main();
            break;
        case 2:
            system("cls");
            out();
            break;
        default: //error handling
            system("cls");
            printf("You have entered a wrong Input. The program has been re-initialized.\n");
            main();
            break;
    }
}
