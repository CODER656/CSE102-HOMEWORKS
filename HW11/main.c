#include <stdio.h>
#include <stdlib.h>


typedef struct table {
  char **field;
  char **type;
  int  *isNull; /*I changed bool to int because there is no format specifier for boolean values*/
  int  *isKey;
}table;

typedef struct tables {
  table * t;
  struct tables *next;
}tables;

typedef struct database{
  tables *tList; /*to be implemented as a linked list*/
  int n;        /* num of entries  */
  char * name; /*  table name     */
}database;

/*flush function for discarding remaining strings in input buffer*/
void my_fflush()
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

/*
   Function: create_node_for_tables
   creating node for linked list
   used dynamic memory allocation
*/
tables* create_node_for_tables()
{
   tables *temp;
   temp = (tables*)malloc(sizeof(tables));/*allocating memory*/
   temp->next = NULL; /*making next pointer null*/

   return temp;
}

/*
    Function: add_node_for_tables
    it adds nodes to the database
    inputs:
      head : head of the linked list
      value: value to be added to linked list
      n: how many fields user will enter
*/
tables* add_node_for_tables(tables* head,char *value,int n)
{
    int i=0;
    tables *temp,*p; /*tables variables */
    temp = create_node_for_tables(); /*creating(allocating memory) node for temp variable*/
    temp->t=(table*)malloc(sizeof(struct table)); /*allocating memory for t variable,it is in tables list*/
    database *d = (database*)malloc(sizeof(struct database));/*allocating memory for database*/
    temp->t->field = (char**)calloc(n+1,sizeof(char*));/*allocating memory for double pointer inside structs,it is array of structs*/

    for(int i=0; i<n; i++ )
        temp->t->field[i] = (char*)malloc(50*sizeof(char));/*allocating memory for every cell */


    temp->t->field[i] = value; /*pushing value to linked list*/

    if (head==NULL)
      head=temp; /*if head is null, now head is filled*/
    else
    {
       p = head; /*p is the head*/
       while (p->next!=NULL)/*traversing linked list*/
         p = p->next;

       p->next = temp;/*change the last node's next pointer */
    }
    i++;
    return head;
}

/*
    Function: insert_table
    its creates a table that taken from user and adds to linledlist
    inputs:
      databse *d: database struct for linked list
      table *t: table struct for infos like field,type
      char *name: name of the table

*/


void insert_table(database *d, table *t,char *name){

    FILE *fp;
    fp=fopen("database.txt","a+");

    if (fp==NULL)
    {
       printf("An error occured while opening the file\n"); /*checking file succesfully opened*/
       return;
    }
    /*stylish prints for file representation*/
    fprintf(fp, "                           %s                                \n",name);
    fprintf(fp, "\n\n----------------------------------------------------------\n");
    fprintf(fp, "|    Field    ||     Type    ||     Null    ||     Key   |\n");
    fprintf(fp, "---------------------------------------------------------|\n");

    /*allocating memory for table lists and database*/
    d = (database*)malloc(sizeof(struct database));
    t = (table*)malloc(sizeof(struct table));
    tables *table_list = (tables*)malloc(sizeof(tables));
    table_list->t=(table*)malloc(sizeof(struct table));


    printf("\nPlease enter how many field you will need for the table:");
    scanf("%d",&(d->n)); /*getting fields number from user*/

    table_list->t->field = (char**)calloc((d->n)+1,sizeof(char*));/*field allocation according to field number*/
    table_list->t->type = (char**)calloc((d->n)+1,sizeof(char*));/*type allocation according to field number*/
    table_list->t->isNull = (int*)malloc(sizeof(int)); /*simple alocation for null checking*/

    for(int i=0; i<(d->n)+1; i++) /*memory allocation for every element in field array*/
        table_list->t->field[i] = (char*)malloc(50*sizeof(char));

    for(int i=0; i<(d->n)+1; i++)/*memory allocation for every element in type array*/
        table_list->t->type[i] = (char*)malloc(50*sizeof(char));


    printf("Please enter field names: \n");
    for (int i = 0; i < d->n; i++)
    {
       scanf("%s",table_list->t->field[i]);/*getting field names*/
       fprintf(fp, "|   %7s   |",table_list->t->field[i]);/*writing to file*/
       my_fflush();
       printf("What is the type of %s: ", table_list->t->field[i]);
       scanf("%s",table_list->t->type[i]);/*getting type names*/
       fprintf(fp, "|   %7s   |",table_list->t->type[i]);
       my_fflush();
       printf("Is %s null:(1:yes 0:no) ",table_list->t->field[i]);
       scanf("%d",table_list->t->isNull);
       fprintf(fp, "|   %7d   |",*table_list->t->isNull);
       if (i==d->n-1)
         printf(" ");/*if last time don't ask the next field name*/
       else
         printf("\nEnter the other field name:\n");
       my_fflush();
       add_node_for_tables(table_list,(table_list->t->field[i]),d->n);/*adding nodes to linked list */
       add_node_for_tables(table_list,(table_list->t->type[i]),d->n);/*adding nodes to linked list */
       add_node_for_tables(table_list,((char*)table_list->t->isNull),d->n);/*adding nodes to linked list */
       fprintf(fp, "\n");
    }
    fprintf(fp, "----------------------------------------------------------\n");
    fclose(fp);
}

 /*
     Function: create_database
     input:
       char* name: name of the table
      it creates the linked list
 */
void create_database(char *name)
{
  database *d,*temp;
  table *table_t;
  d = (database *)malloc(sizeof(struct database));
  table_t = (table *)malloc(sizeof(struct table));
  d->name = (char*)calloc(50,sizeof(char));

  d->tList = (tables*)malloc(sizeof(tables));

  insert_table(d,table_t,name);
}

void describe_table(database *d)
{
   /*This function prints every table */
   FILE *fp;
   fp=fopen("database.txt","a+");

   char a = fgetc(fp);
   while (a != EOF)
   {
      printf ("%c", a);
      a = fgetc(fp);
   }
   fclose(fp);

}

int main()
{
   int select,table_select;
   database *datas;
   datas = (database *)malloc(sizeof(struct database));
   datas->name = (char*)calloc(50,sizeof(char));

   printf("\nWELCOME TO THE DATABASE PROGRAM\n\n");
   printf("1.Create a database\n");
   printf("2.Describe tables\n");
   printf("3.Exit\n\n");
   printf("Please enter what you want to do: ");
   scanf("%d",&select);

   switch (select)
   {
       case 1:
          printf("Please give a name for your table: ");
          scanf("%s",datas->name);

          create_database(datas->name);
       break;

       case 2:
          describe_table(datas);
       break;

       case 3:
          break;
       break;

       default:
         printf("Next time please only select from numbers above.\n");
       break;
   }

  return 0;
}
