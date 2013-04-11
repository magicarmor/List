/**@mainpage
*   Titov Roman Group IU 8 -21
*   Laboratory  "Dynamic structures of data. List"
*/
/************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
/************************************************************************/
struct book
{
	char fio[75];
	char title[50];
	char pub_house[25];
	unsigned int year;
	unsigned int quan_pages;
	book *next;
}*begin = 0 ,*end = 0;
/************************************************************************/
/**@brief functional prototypes*/
///{
void add_list( void );
char question( void );
void read_list( void );
unsigned char write_list( void );
void add_null_item( void );
void sort_list( void );
void delete_list( void );
inline void work_with_list( void );
void find ( void );
///}
/************************************************************************/
///                        MAIN FUNCTION                               ///
void main()
{
	work_with_list();
	return;
	
}
//////////////////////////////////////////////////////////////////////////
/************************************************************************/

/// Function add_list @brief (Add an element in the list)
/// {
void add_list( void )
{  
	
	/// @brief Mark out memory for the current link of the list
	/// {
	register book *cur ;
	cur = ( book*)malloc( sizeof ( book ));	
	/// }

	/// @brief Input value of elements of this link
	/// {
	fflush( stdin );
	printf("________________________________________________________________________________\n");
	printf( "\n" );
	printf( "Enter information on the book ...\n\n\n" );	
	
	printf ( "Enter a full name  of the author ... " );
	scanf ( "%s" , &cur -> fio );
	
	printf ( "Enter a title of the book ... " );
	scanf ( "%s" , &cur -> title );
	
	printf ( "Enter a name of the publishing house ... " );
	scanf ( "%s" , &cur -> pub_house );
	
	printf ( "Enter year of the edition of the book ... " );
	scanf ( "%d" , &cur -> year );
	
	printf ( "Enter quantity of pages in the book ... " );
	scanf ( "%d" , &cur -> quan_pages );
	printf("________________________________________________________________________________\n");
	/// }

	/// @brief We include the current link in the list 
	/// {
	if (( begin == 0) & ( end == 0 )){ /// @brief List is empty
		begin = cur ;
	}
	else{ /// @brief We include the current link in the nonempty list 
		end -> next = cur;
	}
	end = cur;
	end -> next = 0;
	/// }
	fflush( stdin );	
}
/// }

/// Function question @brief (Whether to ask the user he wants to add 1 more element in the list)
/// {
char question( void )
{
	char resolve;
	printf("********************************************************************************\n");
	printf( "Do you want to enter information on one more book ? (Y/N) ... \n" );
	fflush( stdin );
	
	while(( resolve = getchar()) != '\n'){
		if(( resolve == 'Y') || ( resolve == 'y') || ( resolve == 'N') || ( resolve == 'n')){
			break;
		}
		else{
			printf ( "\n\nError : Input incorect !!!  Please try the following start !!!\n");
			resolve = 'N';
			break;
		}
	}
	printf("********************************************************************************\n");
	return resolve;
}
/// }

/// Function read_list @brief(Creation of all list)
/// { 
void read_list( void )
{
	char resolve;
	do
	{		
		add_list();
		resolve = question();

	}while(( resolve == 'Y' ) || ( resolve == 'y' ));
}
/// }

/// function write_list @brief(Conclusion of all elements of the list)
/// {
unsigned char write_list( void )
{
	register book *cur = begin;
	if ( begin ){
		printf("_______________________________________________________________________________\n");
		printf("|             FIO              |       title       |publishing house|year|pages|\n");
		printf("|______________________________|___________________|________________|____|_____|\n");

		if( cur->title[0]=='☺'){
			cur = cur -> next;
		}
		while ( cur ){
			printf("|%30s|%19s|%16s|%4d|%5d|\n", cur -> fio, cur -> title , cur -> pub_house ,       
                   cur -> year , cur -> quan_pages );
			printf("|______________________________|___________________|________________|____|_____|\n");
			cur = cur -> next;
		}
		return 1;
		
	}
	else{
		printf ("List is empty");
		return 0;
	}
}
/// }

/// Function add_null_item @brief (Add a zero element in the beginning)
/// {
void add_null_item( void )
{
	register book *cur;
	cur = ( book*)malloc( sizeof ( book ));	
	cur -> next = begin;
	cur -> title[0] = '☺';
	begin = cur;	
	cur = begin -> next;
}
/// }

/// Function sort_list @brief (Sorting according the name)
/// {
void sort_list( void )
{
	unsigned char flag = 1 ;
	register book *cur;
	cur = begin -> next;
	
	while (flag)
	{
		flag = 0;
		register book *tmp1 , *tmp2 ;
		cur = begin;
		while ( cur -> next -> next )
		{
			if ( strcmp(( cur -> next -> title ),( cur-> next -> next -> title ))>0)
			{
				flag = 1;
				tmp1 = cur -> next;
				tmp2 = cur -> next -> next;
				tmp1-> next = tmp2 -> next;
				cur -> next = tmp2;
				cur -> next -> next = tmp1;
			}
			cur = cur -> next;
		}
	}	
}
/// }

/// @brief Function Delete full list
/// {
void delete_list( void )
{
	register book *cur ;
	while (begin){
		cur = begin;
		begin = begin -> next;
		free ( cur );
	}
}
/// }

/// @page Work with list
/// {
inline void work_with_list( void )
{
	read_list();
	find();
	printf("-----------------------------List before sorting--------------------------------\n");
	write_list();
	getch();
	add_null_item();
	printf("-----------------------------List sorting......---------------------------------\n");
	sort_list( );
	find();
	printf("-----------------------------List after sorting---------------------------------\n");
	write_list();
	delete_list();
	getch();
}
/// }

/// Function find @brief (Find current element)
/// {
void find ( void )
{
	char resolve;
	
	do {
		
		unsigned int q = 0, number = 0;
		printf("Enter number of elements for searching ");
		fflush(stdin);
		scanf("%d", &number);
		register book *cur = begin;

		if ( begin ){
			printf("\n\n");
			printf("Element interesting for you\n");
			printf("_______________________________________________________________________________\n");
			printf("|             FIO              |       title       |publishing house|year|pages|\n");
			printf("|______________________________|___________________|________________|____|_____|\n");
			
			if( cur->title[0]=='☺'){
				cur = cur -> next;
			}
			while ( cur ){
				++q;
				if ( q == number) {
					printf("|%30s|%19s|%16s|%4d|%5d|\n", cur -> fio, cur -> title , cur -> pub_house , cur -> year , cur -> quan_pages );
					printf("|______________________________|___________________|________________|____|_____|\n");
				}
				else
					cur = cur -> next;
			}
			return;
		}
		else{
			printf ("List is empty");
			return;
		}
		resolve = question();
	}while(( resolve == 'Y' ) || ( resolve == 'y' ));
}
/// }
/************************************************************************/
